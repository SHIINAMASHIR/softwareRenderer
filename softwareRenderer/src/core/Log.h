#pragma once

#include "core/core.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace SWRD
{
	class Log 
	{
	public:
		static void Init();

		inline static Ref<spdlog::logger>& GetUserLogger() { return s_UserLogger; }
		inline static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }

	private:
		static Ref<spdlog::logger> s_UserLogger;
		static Ref<spdlog::logger> s_CoreLogger;
	};
}

#define CORE_ERROR(...)		::SWRD::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CORE_WARN(...)		::SWRD::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CORE_INFO(...)		::SWRD::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CORE_TRACE(...)		::SWRD::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define USER_ERROR(...)		::SWRD::Log::GetUserLogger()->error(__VA_ARGS__)
#define USER_WARN(...)		::SWRD::Log::GetUserLogger()->warn(__VA_ARGS__)
#define USER_INFO(...)		::SWRD::Log::GetUserLogger()->info(__VA_ARGS__)
#define USER_TRACE(...)		::SWRD::Log::GetUserLogger()->trace(__VA_ARGS__)