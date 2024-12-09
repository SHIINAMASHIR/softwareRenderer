#pragma once
#include <string>
#include <functional>

#include "event/Event.h"

//事件系统尚未完成

namespace SWRD
{
	struct WindowProps
	{
		std::string Title;
		uint32_t Width, Height;
		WindowProps(const std::string& title = "MyWindow",
			uint32_t width = 1024,
			uint32_t height = 720)
			:Title(title), Width(width), Height(height)
		{}
	};

	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual void OnUpdate() = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
		virtual void SetWidth(uint32_t) = 0;
		virtual void SetHeight(uint32_t) = 0;

		virtual void SetEventCallback(const EventCallbackFn&) = 0;
		virtual void* GetNativeWindow() const = 0;

		static Window* CreateWindow(const WindowProps& props = WindowProps());
	};
}