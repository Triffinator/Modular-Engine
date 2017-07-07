#include "MathFacade.h"

const ECS::Maths::vec3 ECS::Maths::MathFacade::UnitUp(0, 1, 0);
const ECS::Maths::vec3 ECS::Maths::MathFacade::UnitRight(1, 0, 0);
const ECS::Maths::vec3 ECS::Maths::MathFacade::UnitForward(0, 0, -1);

ECS::Maths::mat4 ECS::Maths::MathFacade::setTranslationRotationScaling(const ECS::Maths::vec3& translation, const ECS::Maths::quat& rotation, const ECS::Maths::vec3& scaling)
{
    ECS::Maths::mat4 lhs;
    float x = rotation.x;
    float y = rotation.y;
    float z = rotation.z;
    float w = rotation.w;

    lhs[0][0] = scaling[0] * (1.0f - 2.0f * (y * y + z * z));
    lhs[0][1] = scaling[1] * (2.0f * (x * y - z * w));
    lhs[0][2] = scaling[2] * (2.0f * (x * z + y * w));
    lhs[0][3] = translation[0];

    lhs[1][0] = scaling[0] * (2.0f * (x * y + z * w));
    lhs[1][1] = scaling[1] * (1.0f - 2.0f * (x * x + z * z));
    lhs[1][2] = scaling[2] * (2.0f * (y * z - x * w));
    lhs[1][3] = translation[1];

    lhs[2][0] = scaling[0] * (2.0f * (x * z - y * w));
    lhs[2][1] = scaling[1] * (2.0f * (z * y + x * w));
    lhs[2][2] = scaling[2] * (1.0f - 2.0f * (x * x + y * y));
    lhs[2][3] = translation[2];

    lhs[3][0] = lhs[3][1] = lhs[3][2] = 0.0f;
    lhs[3][3] = 1.0f;

    return(lhs);
}

ECS::Maths::vec2 ECS::Maths::MathFacade::vec2()
{
    return glm::vec2();
}

ECS::Maths::vec2 ECS::Maths::MathFacade::vec2(float x, float y)
{
    return glm::vec2(x, y);
}

ECS::Maths::vec3 ECS::Maths::MathFacade::vec3()
{
    return glm::vec3();
}

ECS::Maths::vec3 ECS::Maths::MathFacade::vec3(float x, float y, float z)
{
    return glm::vec3(x, y, z);
}

ECS::Maths::vec4 ECS::Maths::MathFacade::vec4()
{
    return glm::vec4();
}

ECS::Maths::vec4 ECS::Maths::MathFacade::vec4(float x, float y, float z, float w)
{
    return glm::vec4(x, y, z, w);
}

ECS::Maths::mat4 ECS::Maths::MathFacade::mat4()
{
    return glm::mat4();
}

ECS::Maths::mat4 ECS::Maths::MathFacade::mat4(float a)
{
    return glm::mat4(a);
}

ECS::Maths::quat ECS::Maths::MathFacade::quat()
{
    return glm::quat();
}

ECS::Maths::vec3 ECS::Maths::MathFacade::cross(ECS::Maths::vec3 a, ECS::Maths::vec3 b)
{
    return glm::cross(a, b);
}

ECS::Maths::vec3 ECS::Maths::MathFacade::normalize(ECS::Maths::vec3 a)
{
    return glm::normalize(a);
}

ECS::Maths::mat4 ECS::Maths::MathFacade::scale(ECS::Maths::mat4 m, ECS::Maths::vec3 v)
{
    return glm::scale(m, v);
}

ECS::Maths::mat4 ECS::Maths::MathFacade::rotate(ECS::Maths::mat4 m, float s, ECS::Maths::vec3 v)
{
    return glm::rotate(m, s, v);
}


ECS::Maths::mat4 ECS::Maths::MathFacade::translate(ECS::Maths::mat4 m, ECS::Maths::vec3 v)
{
    return glm::translate(m, v);
}

ECS::Maths::mat4 ECS::Maths::MathFacade::lookAt(ECS::Maths::vec3 e, ECS::Maths::vec3 c, ECS::Maths::vec3 u)
{
    return glm::lookAt(e, c, u);
}


ECS::Maths::mat4 ECS::Maths::MathFacade::perspective(float fov, float aspect, float near, float far)
{
    return glm::perspective(fov, aspect, near, far);
}

float ECS::Maths::MathFacade::radians(float s)
{
    return glm::radians(s);
}


ECS::Maths::quat ECS::Maths::MathFacade::angleAxis(float s, ECS::Maths::vec3 v)
{
    return glm::angleAxis(s, v);
}

ECS::Maths::mat4 ECS::Maths::MathFacade::mat4_cast(ECS::Maths::quat q)
{
    return glm::mat4_cast(q);
}

float *ECS::Maths::MathFacade::value_ptr(ECS::Maths::mat4 m)
{
    return glm::value_ptr(m);
}

float *ECS::Maths::MathFacade::value_ptr(ECS::Maths::vec3 v)
{
    return glm::value_ptr(v);
}

//Overloads
ECS::Maths::quat ECS::Maths::operator* (ECS::Maths::quat a, ECS::Maths::quat b)
{
    return a *= b;
}

ECS::Maths::mat4 ECS::Maths::operator* (ECS::Maths::mat4 a, ECS::Maths::mat4 b)
{
    return a *= b;

}

ECS::Maths::mat4 ECS::Maths::operator+ (ECS::Maths::mat4 a, ECS::Maths::mat4 b)
{
    return a += b;
}

ECS::Maths::mat4 ECS::Maths::operator/ (ECS::Maths::mat4 a, ECS::Maths::mat4 b)
{
    return a /= b;
}

ECS::Maths::mat4 ECS::Maths::operator- (ECS::Maths::mat4 a, ECS::Maths::mat4 b)
{
    return a -= b;
}

ECS::Maths::vec2 ECS::Maths::operator* (ECS::Maths::vec2 a, ECS::Maths::vec2 b)
{
    return a *= b;
}

ECS::Maths::vec2 ECS::Maths::operator+ (ECS::Maths::vec2 a, ECS::Maths::vec2 b)
{
    return a += b;
}

ECS::Maths::vec2 ECS::Maths::operator/ (ECS::Maths::vec2 a, ECS::Maths::vec2 b)
{
    return a /= b;
}

ECS::Maths::vec2 ECS::Maths::operator- (ECS::Maths::vec2 a, ECS::Maths::vec2 b)
{
    return a -= b;
}

ECS::Maths::vec3 ECS::Maths::operator* (ECS::Maths::vec3 a, ECS::Maths::vec3 b)
{
    return a *= b;
}

ECS::Maths::vec3 ECS::Maths::operator+ (ECS::Maths::vec3 a, ECS::Maths::vec3 b)
{
    return a += b;
}

ECS::Maths::vec3 ECS::Maths::operator/ (ECS::Maths::vec3 a, ECS::Maths::vec3 b)
{
    return a /= b;
}

ECS::Maths::vec3 ECS::Maths::operator- (ECS::Maths::vec3 a, ECS::Maths::vec3 b)
{
    return a -= b;
}

ECS::Maths::vec4 ECS::Maths::operator* (ECS::Maths::vec4 a, ECS::Maths::vec4 b)
{
    return a *= b;
}

ECS::Maths::vec4 ECS::Maths::operator+ (ECS::Maths::vec4 a, ECS::Maths::vec4 b)
{
    return a += b;
}

ECS::Maths::vec4 ECS::Maths::operator/ (ECS::Maths::vec4 a, ECS::Maths::vec4 b)
{
    return a /= b;
}

ECS::Maths::vec4 ECS::Maths::operator- (ECS::Maths::vec4 a, ECS::Maths::vec4 b)
{
    return a -= b;
}