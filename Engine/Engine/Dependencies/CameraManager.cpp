#include "CameraManager.h"

bool ECS::CameraManager::DestroyComponentData(const ECS::Entity & e)
{
    if (!EntityHasComponent(e))
    {
        return false;
    }

    m_cameraMap.erase(e.GetEID());
    return true;
}

bool ECS::CameraManager::EntityHasComponent(const Entity & e)
{
    return m_cameraMap.find(e.GetEID()) != m_cameraMap.end();
}
