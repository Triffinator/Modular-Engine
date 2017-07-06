#include "Factory.h"

void ECS::Factory::Init(const unsigned long maxID)
{
    for(int i = 0; i < maxID; i++)
    {
        m_freeIndices.push(i);
    }
}

ECS::Factory::Factory()
{
}


ECS::Factory::~Factory()
{
}

const unsigned long ECS::Factory::GetNextEID()
{
    unsigned long eid = m_freeIndices.top();
    m_freeIndices.pop();
    return eid;
}

void ECS::Factory::DestroyEntity(const Entity & e)
{
    Entity temp = e;

    m_freeIndices.push(temp.GetEID());//Add EID to Queue
    //Sort();//Sort Queue
    delete &e;
}

bool ECS::Factory::AddComponent(const Entity & e, ComponentInfo info)
{
    return false;
}

bool ECS::Factory::RemoveComponent(const Entity & e, const std::string & componentType)
{
    return false;
}

TransformManager & ECS::Factory::GetTransformComponentManager()
{
    return m_transformComponentManager;
}

ECS::Factory::queue ECS::Factory::GetQueue()
{
    return m_freeIndices;
}

bool ECS::Factory::AddTransformComponent(const Entity & e, const ComponentInfo & info)
{
    return false;
}
