#include <cstdlib>
#include <iostream>

#include "Dependencies/Factory.h"

inline std::ostream& operator<<(std::ostream& os, ECS::Entity& e)
{
    os << "Entity: " << e.GetEID();
    return os;
}

inline std::ostream& operator<<(std::ostream& os, ECS::Factory::queue& q)
{
    std::vector<unsigned long> v;
    int size = q.size();

    for(int i = 0; i < size; i++)
    {
        v.push_back(q.top());

        os << "Number: " << q.top() << "\n";
        
        q.pop();
    }

    for (int i = 0; i < size; i++)
    {
        q.push(v.at(i));
    }

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

    std::cout << "Deleting: " << *(e1) << std::endl;
    f->DestroyEntity(*(e1));

    int pause;
    std::cin >> pause;

    return 0;
}