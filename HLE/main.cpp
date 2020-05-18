
#include "core/Application.hpp"

#include "lua/lua/lua.hpp"
#include "lua/sol/sol.hpp"

int main()
{
	try
	{
		hle::Application app;
		app.run();
	}
	catch (std::exception& e)
	{
		printf("Engine Exception: %s\n", e.what());
	}
	return 0;
}