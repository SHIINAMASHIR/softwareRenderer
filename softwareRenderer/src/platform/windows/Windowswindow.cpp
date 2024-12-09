#include "Windowswindow.h"
#include "event/WindowEvent.h"


#include <iostream>


namespace SWRD
{
	Window* Window::CreateWindow(const WindowProps& props)
	{
		return new Windowswindow(props);
	}

	Windowswindow::Windowswindow(const WindowProps& props)
		:m_Data(new WindowData())
	{
		Init(props);
	}

	void Windowswindow::Init(const WindowProps& props)
	{
		m_Data->Title = props.Title;
		m_Data->Width = props.Width;
		m_Data->Height = props.Height;

		//glfw初始化
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

		m_Window = glfwCreateWindow(m_Data->Width, m_Data->Height, m_Data->Title.c_str(),
			nullptr, nullptr);

		if (m_Window == nullptr)
		{
			std::cout << "window create failed" << std::endl;
			exit(0);
		}

		glfwMakeContextCurrent(m_Window);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		//加载版本的日志

		//将自定义的窗体data传入glfw的用户自定义指针
		glfwSetWindowUserPointer(m_Window, (void*)m_Data);

		//设置各类回调函数（配合事件系统使用）
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data->EventCallback(event);
		});
	}

	void Windowswindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void Windowswindow::SetEventCallback(const EventCallbackFn& callback)
	{
		m_Data->EventCallback = callback;
	}

	void* Windowswindow::GetNativeWindow() const
	{
		return static_cast<void*>(m_Window);
	}

	void Windowswindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}


}