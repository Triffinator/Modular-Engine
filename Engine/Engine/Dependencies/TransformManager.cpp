#include "TransformManager.h"

ECS::TransformManager::TransformManager()
{
}


ECS::TransformManager::~TransformManager()
{
}

void ECS::TransformManager::DestroyComponentData(Entity & e)
{
    unsigned long EID = e.GetEID();

    m_dataMap->erase(EID);
}
