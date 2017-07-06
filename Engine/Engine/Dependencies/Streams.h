#pragma once

//Definitions of all stream operators for classes

#include <iostream>

#include "Entity.h"
#include "Factory.h"
#include "TransformComponent.h"
#include "TransformManager.h"

inline std::ostream& operator<<(std::ostream& os, ECS::Entity& e)
{
    os << "Entity: " << e.GetEID();
    return os;
}

inline std::ostream& operator<<(std::ostream& os, ECS::Factory::queue& q)
{
    std::vector<unsigned long> v;
    int size = q.size();

    for (int i = 0; i < size; i++)
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