#include "Log.h"

namespace SWRD
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_UserLogger;

	void Log::Init() 
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("RenderCore");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_UserLogger = spdlog::stdout_color_mt("User");
		s_UserLogger->set_level(spdlog::level::trace);
	}
}