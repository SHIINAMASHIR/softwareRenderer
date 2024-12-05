#pragma once
#include <string>

namespace SWRD
{
	class Application
	{
	public:

		friend Application& getApplicationInstance();

		virtual ~Application() {}

		void Run();
		void OnEvent();

	protected:
		Application(){}
	private:
		Application(const Application&) = delete;
		Application& operator=(const Application&) = delete;

	private:
		bool m_Running = true;
	};

	Application& getApplicationInstance();
}

