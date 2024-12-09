#pragma once

#ifdef PLATFORM_WINDOWS
#include "Application.h"

extern SWRD::Application& SWRD::GetApplicationInstance();
int main()
{
	auto& app = SWRD::GetApplicationInstance();
	app.Run();
	return 0;
}

#endif