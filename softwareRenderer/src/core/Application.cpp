#include "core/Application.h"
#include "math/rd_math.h"

#include <iostream>
#include <functional>

//�˲���������ʱ���ԣ��´μ���Layer������֮�󣬽������ϵ�Layer����Ⱦ�¼���
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

			//ִ����Ⱦ
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);


			m_Window->OnUpdate();

			
		}
		std::cout << "over, time:####-##-##, ##:##:##" << std::endl;
		//��Ⱦ������������־
	}

	void Application::OnEvent(Event& e)
	{
		Dispatcher dispatch(e);
		dispatch.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNC(OnWindowClose));

		//����зֲ������δ�ܴ�����¼����⵽�ڴ��ݣ�ֱ���䱻����Ϊֹ
		while (false);
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		std::cout << e.ToString() << std::endl;
		return true;
	}

	

}
