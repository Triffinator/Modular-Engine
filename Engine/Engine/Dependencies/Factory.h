#pragma once
#include <ios>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <map>
#include <functional>
#include <queue>
#include <iostream>

//Base Entity
#include "Entity.h"

//Managers
#include "TransformManager.h"

#define greater std::greater<unsigned long>

inline std::istream& operator >> (std::stringstream& str, ECS::Maths::vec3& value)
{
    return str >> value.x >> value.y >> value.z;
}

inline int ToInt(const std::string& str)
{
    int value;
    std::stringstream(str) >> value;
    return value;
}

inline float ToFloat(const std::string& str)
{
    float value;
    std::stringstream(str) >> value;
    return value;
}

inline ECS::Maths::vec2 ToVec2(const std::string& str)
{
    ECS::Maths::vec2 vec;
    std::stringstream(str) >> vec.x >> vec.y;
    return vec;
}

inline ECS::Maths::vec3 ToVec3(const std::string& str)
{
    ECS::Maths::vec3 vec;
    std::stringstream(str) >> vec.x >> vec.y >> vec.z;
    return vec;
}

inline ECS::Maths::mat3 ToMat3(const std::string& str)
{
    float temp[9];
    ECS::Maths::mat3 mat;
    std::stringstream(str) >> temp[0] >> temp[1] >> temp[2] >> temp[3] >> temp[4] >> temp[5] >> temp[6] >> temp[7] >> temp[8];
    mat = glm::make_mat3(temp);
    return mat;
}

namespace ECS
{
    class Factory
    {
        public:
            typedef std::map<std::string, std::vector<std::string>> ComponentInfo;
            typedef std::priority_queue<unsigned long, std::vector<unsigned long>, greater> queue;
            typedef std::function<bool(Entity&, const ComponentInfo&)> AddComponentHandler;
 
            void Init(const unsigned long maxID);

            Factory();
            ~Factory();

            const unsigned long GetNextEID();           

            void DestroyEntity(const Entity& e);
            bool AddComponent(Entity & e, const std::string & type, ComponentInfo info);
            bool RemoveComponent(const Entity& e, const std::string& type);
            
            TransformManager& GetTransformComponentManager();
            //RenderManager& GetRendercomponentManager();
            //CameraManager& GetCameraComponentManger();
            //PhysicsManager& GetPhysicsComponentManager();
            //ScriptManager& GetAIComponentManager();

            queue GetQueue();
            
        private:

            std::map<std::string, AddComponentHandler> m_AddComponentHandlers;

            queue m_freeIndices;
            
            TransformManager m_transformComponentManager;
            //PhysicsManager m_physicsComponentManager;
            //RenderManager m_renderComponentManager;
            //CameraManager m_cameraComponentManager;
            //ScriptManager m_scriptComponentManager;
                             
            //MaterialManager* m_materialManager;

            bool AddTransformComponent(Entity & e, const ComponentInfo & info);
            //bool AddRenderComponent(const Entity& e, const ComponentInfo& info);
            //bool AddCameraComponent(const Entity& e, const ComponentInfo& info);
            //bool AddPhysicsComponent(const Entity& e, const ComponentInfo& info);
            //bool AddScriptComponent(const Entity& e, const ComponentInfo& info);

            void DestroyData(const Entity & e);
    };
}