#include "RenderManager.h"

bool ECS::RenderManager::DestroyComponentData(const Entity & e)
{
    if (!EntityHasComponent(e))
    {
        return false;
    }

    m_renderMap.erase(e.GetEID());
    return true;
}

bool ECS::RenderManager::EntityHasComponent(const Entity & e)
{
    return m_renderMap.find(e.GetEID()) != m_renderMap.end();
}
