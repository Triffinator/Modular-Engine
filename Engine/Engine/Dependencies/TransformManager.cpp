#include "TransformManager.h"

ECS::TransformManager::TransformManager()
{
}

ECS::TransformManager::~TransformManager()
{
    m_transformMap.clear();
}

bool ECS::TransformManager::EntityHasComponent(const Entity & e)
{
    return m_transformMap.find(e.GetEID()) != m_transformMap.end();
}

bool ECS::TransformManager::CreateComponentForEntity(const Entity & e)
{
    if (EntityHasComponent(e))
    {
        return false;
    }

    InstanceData data;
    data.rotation = ECS::Maths::quat(ECS::Maths::vec3(0, 0, 0));
    data.scale = ECS::Maths::vec3(1, 1, 1);
    data.translation = ECS::Maths::vec3(0, 0, 0);
    m_transformMap[e.GetEID()] = data;
    UpdateTransformM(e);

    return true;
}

bool ECS::TransformManager::DestroyComponentData(const Entity & e)
{
    if (!EntityHasComponent(e))
    {
        return false;
    }

    m_transformMap.erase(e.GetEID());
    return true;
}

unsigned int ECS::TransformManager::GetNumberOfComponents()
{
    return m_transformMap.size();;
}

const ECS::Maths::vec3 & ECS::TransformManager::GetScale(const Entity & e) const
{
    return m_transformMap.at(e.GetEID()).scale;
}

const ECS::Maths::quat & ECS::TransformManager::GetRotation(const Entity & e) const
{
    return m_transformMap.at(e.GetEID()).rotation;
}

const ECS::Maths::vec3 & ECS::TransformManager::GetTranslation(const Entity & e) const
{
    return m_transformMap.at(e.GetEID()).translation;
}

const bool ECS::TransformManager::SetScale(const Entity & e, const ECS::Maths::vec3 & scale)
{
    if (!EntityHasComponent(e))
    {
        return false;
    }

    m_transformMap.at(e.GetEID()).scale = scale;
    UpdateTransformM(e);
    return true;
}

const bool ECS::TransformManager::SetRotation(const Entity & e, const ECS::Maths::quat & rotation)
{
    if (!EntityHasComponent(e))
    {
        return false;
    }

    m_transformMap.at(e.GetEID()).rotation = glm::normalize(rotation);
    UpdateTransformM(e);
    return true;
}

const bool ECS::TransformManager::SetTranslation(const Entity & e, const ECS::Maths::vec3 & translation)
{
    if (!EntityHasComponent(e))
    {
        return false;
    }

    m_transformMap.at(e.GetEID()).translation = translation;
    UpdateTransformM(e);
    return true;
}

const bool ECS::TransformManager::IncScale(const Entity & e, const ECS::Maths::vec3 & scale)
{
    if (!EntityHasComponent(e))
    {
        return false;
    }

    m_transformMap.at(e.GetEID()).scale += scale;
    UpdateTransformM(e);
    return true;
}

const bool ECS::TransformManager::IncRotation(const Entity & e, const ECS::Maths::quat & rotation)
{
    if (!EntityHasComponent(e))
    {
        return false;
    }

    m_transformMap.at(e.GetEID()).rotation += rotation;
    UpdateTransformM(e);
    return true;
}

const bool ECS::TransformManager::IncTranslation(const Entity & e, const ECS::Maths::vec3 & translation)
{
    if (!EntityHasComponent(e))
    {
        return false;
    }

    m_transformMap.at(e.GetEID()).translation += translation;
    UpdateTransformM(e);
    return true;
}

void ECS::TransformManager::UpdateTransformM(const Entity & e)
{
    auto& data = m_transformMap.at(e.GetEID());

    ECS::Maths::mat4 translate = glm::translate(ECS::Maths::mat4(1), data.translation);
    ECS::Maths::mat4 rotate = glm::mat4_cast(glm::normalize(data.rotation));
    ECS::Maths::mat4 scale = glm::scale(ECS::Maths::mat4(1), data.scale);

    data.tranMatrix = translate * rotate * scale;
}

ECS::Maths::mat4 ECS::TransformManager::GetTransformM(const Entity & e) const
{
    return m_transformMap.at(e.GetEID()).tranMatrix;
}

const ECS::TransformManager::ComponentMap & ECS::TransformManager::GetMap() const
{
    return m_transformMap;
}

void ECS::TransformManager::toString(const Entity & e)
{
    if(EntityHasComponent(e))
    {
        std::cerr << "Outputting transform matrix." << std::endl;
        ECS::Maths::mat4 temptest = m_transformMap.at(e.GetEID()).tranMatrix;
        std::cerr << temptest[3][0] << ",\t" << temptest[3][1] << ",\t" << temptest[3][2] << ",\t" << temptest[3][3] << std::endl;
        std::cerr << temptest[2][0] << ",\t" << temptest[2][1] << ",\t" << temptest[2][2] << ",\t" << temptest[2][3] << std::endl;
        std::cerr << temptest[1][0] << ",\t" << temptest[1][1] << ",\t" << temptest[1][2] << ",\t" << temptest[1][3] << std::endl;
        std::cerr << temptest[0][0] << ",\t" << temptest[0][1] << ",\t" << temptest[0][2] << ",\t" << temptest[0][3] << std::endl;
    }
}

ECS::Maths::vec3 * ECS::TransformManager::GetTranslation_Ptr(unsigned int id)
{
    return &m_transformMap[id].translation;
}

ECS::Maths::vec3 * ECS::TransformManager::GetTranslation_Ptr(const Entity & e)
{
    return &m_transformMap[e.GetEID()].translation;
}

ECS::TransformManager::InstanceData * ECS::TransformManager::GetComponent(unsigned int id)
{
    auto it = m_transformMap.find(id);	// search component type map for component and function
    if (it != m_transformMap.cend())	// if found
    {
        return &it->second;
    }
    return nullptr;
}
