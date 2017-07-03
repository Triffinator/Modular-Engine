#pragma once
#include <cstdlib>
#include <vector>
#include <map>
#include <functional>
#include <queue>

//#include "Entity.h"

namespace ECS
{
    class Factory
    {
        public:
            typedef std::map<std::string, std::vector<std::string>> ComponentInfo;
 
            //void Init();

            Factory();
            ~Factory();
            //void DestroyEntity(const Entity& e);
            //bool AddComponent(const Entity& e, ComponentInfo info);
            //bool RemoveComponent(const Entity& e, const std::string& componentType);
            
            //TransformComponentManager& GetTransformComponentManager();
            //RenderComponentManager& GetRendercomponentManager();
            //CameraComponentManager& GetCameraComponentManger();
            //PhysicsComponentManager& GetPhysicsComponentManager();
            //ScriptComponentManager& GetAIComponentManager();

        private:
            //typedef std::function<bool(const Entity&, const ComponentInfo&)> AddComponentHandler;
            //std::map<std::string, AddComponentHandler> m_AddComponentHandlers;
            
            std::queue<unsigned long> m_freeIndices;
            
            //TransformComponentManager m_transformComponentManager;
            //PhysicsComponentManager m_physicsComponentManager;
            //RenderComponentManager m_renderComponentManager;
            //CameraComponentManager m_cameraComponentManager;
            //ScriptComponentManager m_scriptComponentManager;
                             
            //MaterialManager* m_materialManager;

            //bool AddTransformComponent(const Entity& e, const ComponentInfo& info);
            //bool AddRenderComponent(const Entity& e, const ComponentInfo& info);
            //bool AddCameraComponent(const Entity& e, const ComponentInfo& info);
            //bool AddPhysicsComponent(const Entity& e, const ComponentInfo& info);
            //bool AddScriptComponent(const Entity& e, const ComponentInfo& info);
    };
}