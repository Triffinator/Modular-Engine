#pragma once

#include <lua.hpp>
#include <luabind/luabind.hpp>
#include <iostream>
#include <fstream>
//#include <queue>
//#include <map>
#include <memory>

namespace ECS 
{
	namespace Script 
	{
		class LuaStateManager
		{
			public:
				LuaStateManager();
				~LuaStateManager();

				void PrintError(std::string& variableName, std::string& reason);
				lua_State * GetLuaState();
				void TestJSONRead();
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
				//std::map<int, lua_State>
				//std::queue<std::string> execQueue;
		};			
	}
}
