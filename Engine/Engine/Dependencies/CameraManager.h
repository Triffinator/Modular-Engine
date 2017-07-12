#pragma once

#include <map>

#include "Entity.h"
#include "MathFacade.h"

#define ECS_INIT_POSITION  (ECS::Maths::vec3(0,0,0))
#define ECS_INIT_FORWARD   (ECS::Maths::vec3(0.0f, 0.0f, -1.0f))
#define ECS_INIT_UP        (ECS::Maths::vec3(0.0f, 1.0f, 0.0f))

#define ECS_INIT_ASPECT    (16.0f/9.0f)
#define ECS_INIT_FOV       54.0f
#define ECS_INIT_NEAR      0.1f
#define ECS_INIT_FAR       5000.0f

#define ECS_MIN_FOV        5.0f
#define ECS_MAX_FOV        180.0f
#define ECS_MIN_ASPECT     0.02f
#define ECS_MAX_ASPECT     50.0f
#define ECS_MIN_NEAR       0.1f
#define ECS_MAX_FAR        2000.0f

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

            ECS::Maths::mat4 GetProjectionMatrix(const Entity& e);

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

            void Look(const Entity & e, ECS::Maths::vec3 eulerDelta, ECS::Maths::vec3 up_forced);

            const ComponentMap& GetMap() const;
    };
}