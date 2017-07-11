#include "ScriptHandler.h"

ECS::Script::ScriptHandler::ScriptHandler() 
{
	//Initialise Lua
	luaState = luaL_newstate();
	luabind::open(luaState);
	luaL_openlibs(luaState);

}

ECS::Script::ScriptHandler::~ScriptHandler() 
{
	if (luaState) 
	{
		lua_close(luaState);
	}
}

void ECS::Script::ScriptHandler::PrintError(std::string& variableName, std::string& reason) 
{
	std::cout << "Error: can't get [" << variableName << "]. " << reason << std::endl;
}

//void ECS::Script::ScriptHandler::AddToExecQueue(std::string scriptName)
//{
//	execQueue.push(scriptName);
//}

void ECS::Script::ScriptHandler::Awake() 
{

}

void ECS::Script::ScriptHandler::Start() 
{

}

void ECS::Script::ScriptHandler::Update() 
{

}

void ECS::Script::ScriptHandler::LateUpdate() 
{

}

void ECS::Script::ScriptHandler::FixedUpdate() 
{

}

void ECS::Script::ScriptHandler::End() 
{

}

void ECS::Script::ScriptHandler::Sleep() 
{

}