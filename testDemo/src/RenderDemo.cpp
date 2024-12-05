#include <renderer.h>

class RenderDemo : public SWRD::Application
{
	friend SWRD::Application& SWRD::getApplicationInstance();
};

SWRD::Application& SWRD::getApplicationInstance()
{
	static RenderDemo app;
	return app;
}