#include "LuaStateManager.h"

ECS::Script::LuaStateManager::LuaStateManager()
{
	//Initialise Lua
	luaState = luaL_newstate();
	luabind::open(luaState);
	luaL_openlibs(luaState);
}

ECS::Script::LuaStateManager::~LuaStateManager()
{
	if (luaState)
	{
		lua_close(luaState);
	}
}

void ECS::Script::LuaStateManager::PrintError(std::string& variableName, std::string& reason)
{
	std::cout << "Error: can't get [" << variableName << "]. " << reason << std::endl;
}

lua_State * ECS::Script::LuaStateManager::GetLuaState(){
	return luaState;
}

void ECS::Script::LuaStateManager::TestJSONRead() {
	//std::fstream TestOutput;
	//TestScript.open("JSONTest")

	luaL_dofile(luaState, "JSONTest.lua");
	luaL_loadfile(luaState, "JSONTest.lua");

	lua_settop(luaState, 0);
	lua_getglobal(luaState, "main");
	//std::cout << "LuaState: " << luaState << std::endl;
	lua_call(luaState, 0, 1);

	//Theres only 1 cause it doesnt decode
	//std::cout << lua_tostring(luaState, -2) << std::endl;
	std::cout << lua_tostring(luaState, -1) << std::endl;
	//luaL_dofile(luaState, "JSONTest.lua");



}

//void ECS::Script::LuaStateManager::AddToExecQueue(std::string scriptName)
//{
//	execQueue.push(scriptName);
//}

void ECS::Script::LuaStateManager::Awake()
{

}

void ECS::Script::LuaStateManager::Start()
{

}

void ECS::Script::LuaStateManager::Update()
{

}

void ECS::Script::LuaStateManager::LateUpdate()
{

}

void ECS::Script::LuaStateManager::FixedUpdate()
{

}

void ECS::Script::LuaStateManager::End()
{

}

void ECS::Script::LuaStateManager::Sleep()
{

}