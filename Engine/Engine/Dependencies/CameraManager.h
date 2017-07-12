#pragma once

#include <map>

#include "Entity.h"

namespace ECS
{
    class CameraManager
    {
        public:
            struct InstanceData
            {
                  float m_degFOV;
                  float m_aspectRatio;
                  float m_nearPlane;
                  float m_farPlane;

                  ECS::Maths::mat4 m_viewMatrix;
                  ECS::Maths::mat4 m_projectionMatrix;
            };
    
        private:
            typedef std::map<unsigned long, InstanceData> ComponentMap;
            ComponentMap m_cameraMap;

        public:
            CameraManager();

            ~CameraManager();

            bool CreateComponentForEntity(const Entity& e);

            bool DestroyComponentData(const Entity &e);

            bool EntityHasComponent(const Entity& e);

            unsigned int GetNumberOfComponents();

            ECS::Maths::mat4 GetViewMatrix(const Entity& e);

            ECS::Maths::vec3 GetPosition(const Entity& e);

            ECS::Maths::vec3 GetForward(const Entity& e);
        
            ECS::Maths::vec3 GetUp(const Entity& e);

            float GetFieldOfView(const Entity& e);

            float GetAspectRatio(const Entity& e);

            float GetNearPlane(const Entity& e);

            float GetFarPlane(const Entity& e);

            void SetPosition(const Entity& e, ECS::Maths::vec3 position);

            void SetForward(const Entity& e, ECS::Maths::vec3 forward);

            void SetUp(const Entity& e, ECS::Maths::vec3 up);

            void SetFieldOfView(const Entity& e, float fov);

            void SetAspectRatio(const Entity& e, float aspectRatio);

            void SetNearPlane(const Entity& e, float near);

            void SetFarPlane(const Entity& e, float far);

            void UpdateProjectionMatrix(const Entity& e);

            void Move(const Entity& e, ECS::Maths::vec3 translation);

            void Look(const Entity& e, ECS::Maths::vec3 eulerDelta);

            const ComponentMap& GetMap() const;
    };
}