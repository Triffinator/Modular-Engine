#include "Engine.h"

ECS::Engine::Engine()
{
    m_window = new ECS::Core::SDLWindow();
}


ECS::Engine::~Engine()
{
    SAFE_DELETE(m_window);
}

void ECS::Engine::Awake()
{
    //Read Configs
    //Create Managers
}

void ECS::Engine::Start()
{
    m_window->Initialize();
    m_window->Set("Enginey McEngineFace", 1280, 720, 32, false);
    m_window->VSync(1);
    m_window->Apply(true);

    m_factory = new ECS::Factory();
    m_factory->Init(200);

    ECS::Entity * e1 = new ECS::Entity(m_factory->GetNextEID());
    ECS::Entity * e2 = new ECS::Entity(m_factory->GetNextEID());

    std::cout << *(e1) << std::endl;
    std::cout << *(e2) << std::endl;

    std::map<std::string, std::vector<std::string>> componentData;

    //Populate e1's transform data
    {
        componentData["position"].push_back("0 15 0");
        componentData["scale"].push_back("10 10 10");
        componentData["rotation"].push_back("0 0 0");
        m_factory->AddComponent(*(e1), "TransformComponent", componentData);
        componentData.clear();
    }

    m_entityVector.push_back(*(e1));
    m_entityVector.push_back(*(e2));

    std::cout << *(e1) << std::endl; 
    m_factory->GetTransformComponentManager().toString(*(e1));

    m_previous = std::chrono::system_clock::now();
}

void ECS::Engine::UpdateLoop()
{
    //std::chrono::duration<int, std::ratio<60*60*24>> dur;
    double lag = 0.0;

    while(1)
    {
        auto current = std::chrono::system_clock::now();

        std::chrono::duration<double> difference = current - m_previous;
        m_previous = current;

        lag += difference.count();

        while (lag >= (MS_PER_UPDATE/1000))
        {
            Update();
            LateUpdate();
            lag -= (MS_PER_UPDATE/1000);
        }

        FixedUpdate();

        //std::cout << difference.count() << std::endl;
    }
}

void ECS::Engine::FixedUpdate()
{
}

void ECS::Engine::LateUpdate()
{
}

void ECS::Engine::End()
{
}

void ECS::Engine::Sleep()
{
}

void ECS::Engine::Update()
{
    for (unsigned int i = 0; i < m_entityVector.size(); ++i)
    {
        ECS::Maths::vec3 * vec = new ECS::Maths::vec3(1, 1, 1);
        m_factory->GetTransformComponentManager().IncTranslation(m_entityVector[i], *(vec));
        //m_factory->GetTransformComponentManager().toString(m_entityVector[i]);
    }

    //int pause;
    //std::cin >> pause;
}
