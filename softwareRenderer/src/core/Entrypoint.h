#pragma once

#ifdef PLATFORM_WINDOWS
#include "Application.h"

extern SWRD::Application& SWRD::getApplicationInstance();
int main()
{
	auto& app = SWRD::getApplicationInstance();
	app.Run();
	return 0;
}

#endif