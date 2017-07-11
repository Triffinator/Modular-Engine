#pragma once

#include <cstdlib>
#include <iostream>
#include <chrono>

#include "Factory.h"
#include "Streams.h"
#include "SDLWindow.h"

namespace ECS
{
    #define MS_PER_UPDATE 16

    class Engine
    {
        public:
            Engine();
            ~Engine();

            void Awake();
            void Start();

            void UpdateLoop();
            
            void End();
            void Sleep();

        private:
            std::vector<ECS::Entity> m_entityVector;
            ECS::Factory * m_factory;

            std::chrono::time_point<std::chrono::system_clock> m_previous;

            ECS::Core::Window * m_window;

            void Update();
            void FixedUpdate();
            void LateUpdate();
    };
}