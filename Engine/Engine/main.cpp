#include "Dependencies/Engine.h"
#include "Dependencies/LuaStateManager.h"

int main(int argc, char ** argv)
{
    ECS::Engine * e = new ECS::Engine();

	ECS::Script::LuaStateManager s;
	s.TestJSONRead();

    e->Start();
    return 0;
}