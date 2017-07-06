#pragma once

#include "Entity.h"
#include "Factory.h"

namespace ECS
{
    namespace Adders
    {
        static class ComponentAdders
        {
            public:
                static bool AddTransformComponent(const Entity & e, const ECS::Factory::ComponentInfo & info);
        };
    }
}


