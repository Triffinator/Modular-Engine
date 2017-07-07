#include "Factory.h"

void ECS::Factory::Init(const unsigned long maxID)
{
    for(unsigned long i = 0; i < maxID; i++)
    {
        m_freeIndices.push(i);
    }

    m_AddComponentHandlers["TransformComponent"] = std::bind(&Factory::AddTransformComponent, this, std::placeholders::_1, std::placeholders::_2);
    //m_AddComponentHandlers["PhysicsComponent"] = std::bind(&Factory::AddPhysicsComponent, this, std::placeholders::_1, std::placeholders::_2);
    //m_AddComponentHandlers["RenderComponent"] = std::bind(&Factory::AddRenderComponent, this, std::placeholders::_1, std::placeholders::_2);
    //m_AddComponentHandlers["CameraComponent"] = std::bind(&Factory::AddCameraComponent, this, std::placeholders::_1, std::placeholders::_2);
    //m_AddComponentHandlers["AIComponent"] = std::bind(&Factory::AddAIComponent, this, std::placeholders::_1, std::placeholders::_2);
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

void ECS::Factory::DestroyData(Entity & e)
{
    m_transformComponentManager.DestroyComponentData(e);
}

void ECS::Factory::DestroyEntity(const Entity & e)
{
    Entity temp = e;

    m_freeIndices.push(temp.GetEID());//Add EID to Queue
    //Destroy Component Data
    delete &e;
}

bool ECS::Factory::AddComponent(Entity & e, const std::string & type, ComponentInfo info)
{
    auto it = m_AddComponentHandlers.find(type);//search component type map for component and function

    if (it != m_AddComponentHandlers.cend())//if found
    {
        return it->second(e, info);//Runs function selected
    }

    std::cout << "Program exiting, non-valid component added!" << std::endl;
    exit(1);//not found 

    return false;
}

bool ECS::Factory::RemoveComponent(const Entity & e, const std::string & type)
{
    return false;
}

ECS::TransformManager & ECS::Factory::GetTransformComponentManager()
{
    return m_transformComponentManager;
}

ECS::Factory::queue ECS::Factory::GetQueue()
{
    return m_freeIndices;
}

bool ECS::Factory::AddTransformComponent(Entity & e, const ComponentInfo & info)
{
    int eid = e.GetEID();

    std::cout << "Adding Transform Component to Entity: " << eid << std::endl;
    
    ECS::Maths::MathFacade mf;

    ECS::Maths::vec3 position(0);
    ECS::Maths::vec3 rotation(0);
    ECS::Maths::vec3 scale(1);

    if (info.find("position") != info.cend())
    {
        position = ToVec3(info.at("position")[0]);
    }

    if (info.find("rotation") != info.cend())
    {
        rotation = ToVec3(info.at("rotation")[0]);
        rotation.x = mf.radians(rotation.x);
        rotation.y = mf.radians(rotation.y);
        rotation.z = mf.radians(rotation.z);
    }

    if (info.find("scale") != info.cend())
    {
        scale = ToVec3(info.at("scale")[0]);
    }

    ECS::Maths::quat rotq = glm::normalize(ECS::Maths::quat(rotation));
    //Create component and assign data
    
    bool completed = m_transformComponentManager.CreateComponentForEntity(e);

    if(completed)
    {
        m_transformComponentManager.SetTranslation(e, position);
        m_transformComponentManager.SetScale(e, scale);
        m_transformComponentManager.SetRotation(e, rotq);
    }

    return completed;
}