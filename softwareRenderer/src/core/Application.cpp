#include "core/Application.h"
#include "math/rd_math.h"

#include <iostream>
#include <functional>

//此部分用于临时调试，下次加入Layer管理器之后，将其整合到Layer的渲染事件中
#include "glad/glad.h"
#include "GLFW/glfw3.h"


#define BIND_EVENT_FUNC(x) std::bind(&Application::x, this, std::placeholders::_1)

namespace SWRD
{
	Application::Application()
	{
		m_Window = Window::CreateWindow();
		m_Window->SetEventCallback(BIND_EVENT_FUNC(OnEvent));

	}

	void Application::Run()
	{
		while(m_Running)
		{

			//执行渲染
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);


			m_Window->OnUpdate();

			
		}
		std::cout << "over, time:####-##-##, ##:##:##" << std::endl;
		//渲染器正常结束日志
	}

	void Application::OnEvent(Event& e)
	{
		Dispatcher dispatch(e);
		dispatch.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNC(OnWindowClose));

		//如果有分层管理，则将未能处理的事件由外到内传递，直到其被处理为止
		while (false);
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		std::cout << e.ToString() << std::endl;
		return true;
	}

	

}
