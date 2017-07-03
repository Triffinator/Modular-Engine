#include <cstdlib>
#include <iostream>

#include "Dependencies/Factory.h"

inline std::ostream& operator<<(std::ostream& os, ECS::Entity& e)
{
    os << "Entity: " << e.GetEID();
    return os;
}

int main(int argc, char ** argv)
{
    ECS::Factory * f = new ECS::Factory();
    f->Init(200);

    ECS::Entity * e1 = new ECS::Entity(f->GetNextEID());
    ECS::Entity * e2 = new ECS::Entity(f->GetNextEID());

    std::cout << *(e1) << std::endl;
    std::cout << *(e2) << std::endl;

    int pause;
    std::cin >> pause;

    return 0;
}