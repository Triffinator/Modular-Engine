#include "Engine.h"

ECS::Engine::Engine()
{
}


ECS::Engine::~Engine()
{
}

void ECS::Engine::Awake()
{
}

void ECS::Engine::Start()
{
    ECS::Factory * f = new ECS::Factory();
    f->Init(200);

    ECS::Entity * e1 = new ECS::Entity(f->GetNextEID());
    ECS::Entity * e2 = new ECS::Entity(f->GetNextEID());

    std::cout << *(e1) << std::endl;
    std::cout << *(e2) << std::endl;

    ECS::Factory::ComponentInfo inf;

    f->AddComponent(*(e1), "TransformComponent", inf);

    /*std::cout << "Deleting: " << *(e1) << std::endl;
    f->DestroyEntity(*(e1));*/

    int pause;
    std::cin >> pause;
}

void ECS::Engine::Update()
{
}

void ECS::Engine::FixedUpdate()
{
}

void ECS::Engine::Lateupdate()
{
}

void ECS::Engine::Sleep()
{
}

void ECS::Engine::End()
{
}
