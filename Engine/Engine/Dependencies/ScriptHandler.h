#pragma once

#include <lua.hpp>
#include <luabind/luabind.hpp>
#include <iostream>
#include <queue>

namespace ECS 
{
	namespace Script 
	{
		class ScriptHandler
		{
			public:
				ScriptHandler();
				~ScriptHandler();

				void PrintError(std::string& variableName, std::string& reason);
				//void AddToExecQueue(std::string scriptName);

				void Awake();
				void Start();
				void Update();
				void LateUpdate();
				void FixedUpdate();
				void End();
				void Sleep();

			private:
				lua_State *luaState;
				//std::queue<std::string> execQueue;
		};			
	}
}
