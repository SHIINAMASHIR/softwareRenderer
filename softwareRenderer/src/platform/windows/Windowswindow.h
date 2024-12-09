#pragma once
#include <string>

#include "core/Window.h"
#include "core/core.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"


namespace SWRD
{
	class Windowswindow : public Window
	{
	public:
		Windowswindow(const WindowProps& props);
		virtual void OnUpdate() override;

		virtual uint32_t GetWidth() const override { return m_Data->Width; }
		virtual uint32_t GetHeight() const override { return m_Data->Height; }
		virtual void SetWidth(uint32_t data) override { m_Data->Width = data; }
		virtual void SetHeight(uint32_t data) override { m_Data->Height = data; }

		virtual void* GetNativeWindow() const;
		virtual void SetEventCallback(const EventCallbackFn&) override;


	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	private:
		struct WindowData
		{
			std::string Title;
			uint32_t Width, Height;
			EventCallbackFn EventCallback;
		};
		GLFWwindow* m_Window;
		WindowData* m_Data;
	};
}
