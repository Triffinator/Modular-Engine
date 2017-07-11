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

    std::map<std::string, std::vector<std::string>> componentData;

    //Populate e1's transform data
    {
        componentData["position"].push_back("0 15 0");
        componentData["scale"].push_back("0 0 0");
        componentData["rotation"].push_back("0 0 0");
        f->AddComponent(*(e1), "TransformComponent", componentData);
        componentData.clear();
    }

    std::cout << *(e1) << std::endl; 
    f->GetTransformComponentManager().toString(*(e1));

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
