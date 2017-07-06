#pragma once
#include <cstdlib>
#include <vector>
#include <map>
#include <functional>
#include <queue>

//Base Entity
#include "Entity.h"

//Managers
#include "TransformManager.h"

#define greater std::greater<unsigned long>

namespace ECS
{
    class Factory
    {
        public:
            typedef std::map<std::string, std::vector<std::string>> ComponentInfo;
            typedef std::priority_queue<unsigned long, std::vector<unsigned long>, greater> queue;
            typedef std::function<bool(const Entity&, const ComponentInfo&)> AddComponentHandler;
 
            void Init(const unsigned long maxID);

            Factory();
            ~Factory();

            const unsigned long GetNextEID();

            void DestroyEntity(const Entity& e);
            bool AddComponent(const Entity& e, ComponentInfo info);
            bool RemoveComponent(const Entity& e, const std::string& componentType);
            
            TransformManager& GetTransformComponentManager();
            //RenderComponentManager& GetRendercomponentManager();
            //CameraComponentManager& GetCameraComponentManger();
            //PhysicsComponentManager& GetPhysicsComponentManager();
            //ScriptComponentManager& GetAIComponentManager();

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

            bool AddTransformComponent(const Entity& e, const ComponentInfo& info);
            //bool AddRenderComponent(const Entity& e, const ComponentInfo& info);
            //bool AddCameraComponent(const Entity& e, const ComponentInfo& info);
            //bool AddPhysicsComponent(const Entity& e, const ComponentInfo& info);
            //bool AddScriptComponent(const Entity& e, const ComponentInfo& info);
    };
}