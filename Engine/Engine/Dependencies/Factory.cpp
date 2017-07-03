#include "Factory.h"

void ECS::Factory::Init(const unsigned long maxID)
{
    for(int i = 0; i < maxID; ++i)
    {
        m_freeIndices.push(i);
    }
}

ECS::Factory::Factory()
{
}


ECS::Factory::~Factory()
{
}

const unsigned long ECS::Factory::GetNextEID()
{
    unsigned long eid = m_freeIndices.front();
    m_freeIndices.pop();
    return eid;
}
