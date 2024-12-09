#include <renderer.h>

class RenderDemo : public SWRD::Application
{
	friend SWRD::Application& SWRD::GetApplicationInstance();
};

SWRD::Application& SWRD::GetApplicationInstance()
{
	static RenderDemo app;
	return app;
}