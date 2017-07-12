#pragma once

#include <map>
#include "Entity.h"

namespace ECS
{
    class RenderManager
    {
        public:
            struct InstanceData
            {
            };

        private:
            typedef std::map<unsigned long, InstanceData> ComponentMap;
            ComponentMap m_renderMap;

        public:
            bool DestroyComponentData(const Entity &e);

            bool EntityHasComponent(const Entity& e);
    };
}