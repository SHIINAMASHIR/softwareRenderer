#pragma once
#include <string>
#include <sstream>

#include "event/Event.h"
namespace SWRD 
{
	class WindowCloseEvent : public Event 
	{
	public:
		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(WindowEvent)

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowCloseEvent: " << GetName();
			return ss.str();
		}
	};

	class WindowResizeEvent : public Event 
	{
	public:
		WindowResizeEvent(uint32_t width, uint32_t height)
			:m_Width(width), m_Height(height)
		{}
		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(WindowEvent)

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResize: " << "width = " << m_Width << ", height = " << m_Height;
			return ss.str();
		}
	private:
		uint32_t m_Width, m_Height;
	};
}