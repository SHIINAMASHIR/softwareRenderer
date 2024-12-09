#pragma once
#include <string>

#include "core/Window.h"
#include "event/Event.h"
#include "event/WindowEvent.h"

namespace SWRD
{
	class Application
	{
	public:

		friend Application& GetApplicationInstance();

		virtual ~Application() {}

		void Run();
		void OnEvent(Event& e);

	protected:
		Application();
	private:
		Application(const Application&) = delete;
		Application& operator=(const Application&) = delete;

		bool OnWindowClose(WindowCloseEvent& e);

	private:
		bool m_Running = true;
		Window* m_Window;
	};

	Application& GetApplicationInstance();
}

