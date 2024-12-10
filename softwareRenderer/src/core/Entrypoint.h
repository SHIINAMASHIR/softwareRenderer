#pragma once

#ifdef PLATFORM_WINDOWS


extern SWRD::Application& SWRD::GetApplicationInstance();
int main()
{
	SWRD::Log::Init();
	time_t tm;
	time(&tm);
	CORE_WARN("Initialized Logger");
	CORE_WARN("Welcome to My SoftwareRenderer !");
	CORE_WARN("------Version: {0}", "v0.1 beta");
	CORE_WARN("------Time: {0}", ctime(&tm));
	auto& app = SWRD::GetApplicationInstance();
	app.Run();
	return 0;
}

#endif