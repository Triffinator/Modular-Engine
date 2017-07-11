#pragma once

#include <cstdlib>
#include <iostream>

#include "Factory.h"
#include "Streams.h"

namespace ECS
{
    class Engine
    {
        public:
            Engine();
            ~Engine();

            void Awake();
            void Start();

            void Update();
            void FixedUpdate();
            void Lateupdate();
            
            void End();
            void Sleep();
    };
}