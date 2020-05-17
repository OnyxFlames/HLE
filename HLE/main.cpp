
#include "core/Application.hpp"

#include "lua/lua/lua.hpp"
#include "lua/sol/sol.hpp"

int main()
{
	hle::Application app;

	app.run();
	return 0;
}