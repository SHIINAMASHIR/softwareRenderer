#pragma once
#include <string>
#include <functional>

//事件系统尚未完成
class Event 
{};

namespace SWRD
{
	struct WindowProps
	{
		std::string Title;
		uint32_t Width, Height;
		WindowProps(const std::string& title = "MyWindow",
			uint32_t width = 1600,
			uint32_t height = 900)
			:Title(title), Width(width), Height(height)
		{}
	};

	class Window
	{
		using EventCallbackFn = std::function<void(Event&)>;
		virtual ~Window() = 0;

		virtual void onUpdate() = 0;

		virtual uint32_t getWidth() = 0;
		virtual uint32_t getHeight() = 0;
		virtual void setHeight() = 0;
		virtual void setHeight() = 0;

		virtual void setEventCallback(const EventCallbackFn&) = 0;


	};
}