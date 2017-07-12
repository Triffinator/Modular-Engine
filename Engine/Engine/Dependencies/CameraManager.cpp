#include "CameraManager.h"

ECS::CameraManager::CameraManager()
{
    m_cameraMap = ComponentMap();
}

ECS::CameraManager::~CameraManager()
{
    m_cameraMap.clear();
}

bool ECS::CameraManager::CreateComponentForEntity(const Entity & e)
{
    ECS::Maths::MathFacade mf;

    if(EntityHasComponent(e))
    {    
        return false;
    }
    else
    {
        InstanceData inst;

        inst.m_degFOV = ECS_INIT_FOV;
        inst.m_aspectRatio = ECS_INIT_ASPECT;
        inst.m_nearPlane = ECS_INIT_NEAR;
        inst.m_farPlane = ECS_INIT_FAR;
        
        inst.m_viewMatrix = glm::lookAt(
            ECS_INIT_POSITION,
            ECS_INIT_FORWARD + ECS_INIT_POSITION,
            ECS_INIT_UP
        );

        inst.m_projectionMatrix = mf.perspective(
            mf.radians(ECS_INIT_FOV),
            ECS_INIT_ASPECT,
            ECS_INIT_NEAR,
            ECS_INIT_FAR
        );

        m_cameraMap[e.GetEID()] = inst;
        return true;
    }                   
}

bool ECS::CameraManager::DestroyComponentData(const ECS::Entity & e)
{
    if (!EntityHasComponent(e))
    {
        return false;
    }

    m_cameraMap.erase(e.GetEID());
    return true;
}

bool ECS::CameraManager::EntityHasComponent(const Entity & e)
{
    return m_cameraMap.find(e.GetEID()) != m_cameraMap.end();
}

unsigned int ECS::CameraManager::GetNumberOfComponents()
{
    return m_cameraMap.size();
}

ECS::Maths::mat4 ECS::CameraManager::GetViewMatrix(const Entity & e)
{
    return m_cameraMap.at(e.GetEID()).m_viewMatrix;
}

ECS::Maths::mat4 ECS::CameraManager::GetProjectionMatrix(const Entity & e)
{
    return m_cameraMap.at(e.GetEID()).m_projectionMatrix;
}

ECS::Maths::vec3 ECS::CameraManager::GetPosition(const Entity & e)
{
    ECS::Maths::mat4 temp = m_cameraMap.at(e.GetEID()).m_viewMatrix;

    return ECS::Maths::vec3(temp[0][3], temp[1][3], temp[2][3]);
}

ECS::Maths::vec3 ECS::CameraManager::GetForward(const Entity & e)
{
    ECS::Maths::mat4 temp = m_cameraMap.at(e.GetEID()).m_viewMatrix;

    return ECS::Maths::vec3(temp[0][2], temp[1][2], temp[2][2]);
}

ECS::Maths::vec3 ECS::CameraManager::GetUp(const Entity & e)
{
    ECS::Maths::mat4 temp = m_cameraMap.at(e.GetEID()).m_viewMatrix;

    return ECS::Maths::vec3(temp[0][1], temp[1][1], temp[2][1]);
}

float ECS::CameraManager::GetFieldOfView(const Entity & e)
{
    return m_cameraMap.at(e.GetEID()).m_degFOV;
}

float ECS::CameraManager::GetAspectRatio(const Entity & e)
{
    return m_cameraMap.at(e.GetEID()).m_aspectRatio;
}

float ECS::CameraManager::GetNearPlane(const Entity & e)
{
    return m_cameraMap.at(e.GetEID()).m_nearPlane;
}

float ECS::CameraManager::GetFarPlane(const Entity & e)
{
    return m_cameraMap.at(e.GetEID()).m_farPlane;
}

void ECS::CameraManager::SetPosition(const Entity & e, ECS::Maths::vec3 position)
{
    ECS::Maths::mat4 tempView = m_cameraMap.at(e.GetEID()).m_viewMatrix;

    tempView[0][3] = -position.x;
    tempView[1][3] = -position.y;
    tempView[2][3] = -position.z;

    m_cameraMap[e.GetEID()].m_viewMatrix = tempView;
}

void ECS::CameraManager::SetForward(const Entity & e, ECS::Maths::vec3 forward)
{
    ECS::Maths::mat4 tempView = m_cameraMap.at(e.GetEID()).m_viewMatrix;

    tempView[0][2] = -forward.x;
    tempView[1][2] = -forward.y;
    tempView[2][2] = -forward.z;

    m_cameraMap[e.GetEID()].m_viewMatrix = tempView;
}

void ECS::CameraManager::SetUp(const Entity & e, ECS::Maths::vec3 up)
{
    ECS::Maths::mat4 tempView = m_cameraMap.at(e.GetEID()).m_viewMatrix;

    tempView[0][1] = -up.x;
    tempView[1][1] = -up.y;
    tempView[2][1] = -up.z;

    m_cameraMap[e.GetEID()].m_viewMatrix = tempView;
}

void ECS::CameraManager::SetFieldOfView(const Entity & e, float fov)
{
    m_cameraMap.at(e.GetEID()).m_degFOV = fov;
    UpdateProjectionMatrix(e);
}

void ECS::CameraManager::SetAspectRatio(const Entity & e, float aspectRatio)
{
    m_cameraMap.at(e.GetEID()).m_aspectRatio = aspectRatio;
    UpdateProjectionMatrix(e);
}

void ECS::CameraManager::SetNearPlane(const Entity & e, float near)
{
    m_cameraMap.at(e.GetEID()).m_nearPlane = near;
    UpdateProjectionMatrix(e);
}

void ECS::CameraManager::SetFarPlane(const Entity & e, float far)
{
    m_cameraMap.at(e.GetEID()).m_farPlane = far;
    UpdateProjectionMatrix(e);
}

void ECS::CameraManager::UpdateProjectionMatrix(const Entity & e)
{
    ECS::Maths::MathFacade mf;

    InstanceData inst = m_cameraMap.at(e.GetEID());
    ECS::Maths::mat4 proj = inst.m_projectionMatrix;

    proj = mf.perspective(inst.m_degFOV, inst.m_aspectRatio, inst.m_nearPlane, inst.m_farPlane);

    m_cameraMap.at(e.GetEID()).m_projectionMatrix = proj;
}

void ECS::CameraManager::Move(const Entity & e, ECS::Maths::vec3 translation)
{
    ECS::Maths::mat4 tempView = m_cameraMap.at(e.GetEID()).m_viewMatrix;

    ECS::Maths::vec3 tempRight(tempView[0][0], tempView[1][2], tempView[2][0]);
    ECS::Maths::vec3 tempFwd(tempView[0][2], tempView[1][2], tempView[2][2]);
    ECS::Maths::vec3 tempUp(tempView[0][1], tempView[1][1], tempView[2][1]);
    ECS::Maths::vec3 tempPos(tempView[0][3], tempView[1][3], tempView[2][3]);

    tempPos = tempPos + normalize(tempRight) * translation.x;
    tempPos = tempPos + normalize(tempUp) * translation.y;
    tempPos = tempPos + normalize(tempFwd) * translation.z;

    ECS::Maths::mat4 tranM = translate(ECS::Maths::mat4(1.0f), -tempPos);

    m_cameraMap.at(e.GetEID()).m_viewMatrix *= tranM;
}

void ECS::CameraManager::Look(const Entity & e, ECS::Maths::vec3 eulerDelta, ECS::Maths::vec3 up_forced)
{
    ECS::Maths::mat4& view = m_cameraMap.at(e.GetEID()).m_viewMatrix;
    ECS::Maths::mat4 model = glm::inverse(view);
    ECS::Maths::quat orig_rot(model);

    bool force = glm::l1Norm(up_forced) > 0.0f;

    ECS::Maths::quat y = glm::angleAxis(-eulerDelta.x, force ? up_forced : ECS::Maths::MathFacade::UpVector(orig_rot));
    ECS::Maths::quat p = glm::angleAxis(-eulerDelta.y, ECS::Maths::MathFacade::RightVector(orig_rot));
    ECS::Maths::quat r = glm::angleAxis(eulerDelta.z, ECS::Maths::MathFacade::ForwardVector(orig_rot));

    ECS::Maths::quat rotation = y * p * r * orig_rot;

    if (force)
    {
        rotation = glm::normalize(rotation);

        ECS::Maths::vec3 up = ECS::Maths::MathFacade::UpVector(rotation);

        static const float correction = 0.1f;

        float factor = glm::half_pi<float>() - correction;

        float dot = glm::dot(up, up_forced);
        if (dot < correction)
        {
            float adjustment = acosf(dot) - factor;
            adjustment *= glm::dot(up_forced, ECS::Maths::MathFacade::ForwardVector(rotation)) < 0.0f ? 1 : -1;
            ECS::Maths::quat adj = glm::angleAxis(adjustment, ECS::Maths::MathFacade::RightVector(rotation));
            rotation = adj * rotation;
        }
    }

    ECS::Maths::mat4 model_new = glm::mat4_cast(rotation);

    model_new[3][0] = model[3][0];
    model_new[3][1] = model[3][1];
    model_new[3][2] = model[3][2];

    view = glm::inverse(model_new);
}

const ECS::CameraManager::ComponentMap & ECS::CameraManager::GetMap() const
{
    return m_cameraMap;
}
