#pragma once

#include <map>

#include "Entity.h"
#include "TransformComponent.h"

namespace ECS
{
    class TransformManager
    {
        public:
            TransformManager();
            ~TransformManager();

            void DestroyComponentData(Entity & e);

        private:
            std::map<unsigned long, TransformComponent> * m_dataMap;
    }; 
}

