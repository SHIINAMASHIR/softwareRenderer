#pragma once
#include <string>
#include <functional>

#include "core/core.h"
namespace SWRD 
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFoucs, WindowLostFoucs,
		MouseMovement, MouseButton, MouseScroll,
		KeyBoradPress, KeyBoradRelease,
		AppUpdate, AppTick
	};

	enum EventCategory
	{
		None = 0,
		WindowEvent = BIT(0),
		MouseEvent = BIT(1),
		KeyboradEvent = BIT(2),
		AppEvent = BIT(3)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class Event
	{
	public:
		friend class Dispatcher;

		virtual const char* GetName() const = 0;
		virtual EventType GetEventType() const = 0;

		inline bool isInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

		virtual std::string ToString() const = 0;
		virtual int GetCategoryFlags() const = 0;
	private:
		bool m_Handled = false;
	};

	class Dispatcher 
	{
	public:
		template<typename T>
		using EventFn = std::function<bool(T&)>;

		Dispatcher(Event& e)
			:m_Event(e)
		{}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				//向下强转 *(T*)
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

}

