#pragma once

#pragma warning(push)
#pragma warning(disable : 4201)

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtx/quaternion.hpp>
#include <gtc/type_ptr.hpp>

#pragma warning(pop) 

namespace ECS
{
    namespace Maths
    {
        typedef glm::vec2 vec2;                                                                                               
        typedef glm::vec3 vec3;
        typedef glm::vec4 vec4;
        typedef glm::mat3 mat3;
        typedef glm::mat4 mat4;
        typedef glm::quat quat;

        class MathFacade
        {
            public:
                static mat4 setTranslationRotationScaling(const vec3& translation, const quat& rotation, const vec3& scaling);
                static const ECS::Maths::vec3 UnitUp;
                static const ECS::Maths::vec3 UnitRight;
                static const ECS::Maths::vec3 UnitForward;

                static ECS::Maths::vec3 UpVector(const ECS::Maths::quat& q)
                {
                    return glm::normalize(glm::rotate(q, UnitUp));
                }
                static ECS::Maths::vec3 RightVector(const ECS::Maths::quat& q)
                {
                    return glm::normalize(glm::rotate(q, UnitRight));
                }
                static ECS::Maths::vec3 ForwardVector(const ECS::Maths::quat& q)
                {
                    return glm::normalize(glm::rotate(q, UnitForward));
                }

                ECS::Maths::vec2 vec2();
                ECS::Maths::vec2 vec2(float, float);

                ECS::Maths::vec3 vec3();
                ECS::Maths::vec3 vec3(float, float, float);

                ECS::Maths::vec4 vec4();
                ECS::Maths::vec4 vec4(float, float, float, float);

                ECS::Maths::mat4 mat4();
                ECS::Maths::mat4 mat4(float);

                ECS::Maths::quat quat();

                ECS::Maths::vec3 cross(ECS::Maths::vec3, ECS::Maths::vec3);
                ECS::Maths::vec3 normalize(ECS::Maths::vec3);

                ECS::Maths::mat4 scale(ECS::Maths::mat4, ECS::Maths::vec3);
                ECS::Maths::mat4 rotate(ECS::Maths::mat4, float, ECS::Maths::vec3);
                ECS::Maths::mat4 translate(ECS::Maths::mat4, ECS::Maths::vec3);

                ECS::Maths::mat4 lookAt(ECS::Maths::vec3, ECS::Maths::vec3, ECS::Maths::vec3);
                ECS::Maths::mat4 perspective(float fov, float aspect, float near, float far);

                float radians(float);
                ECS::Maths::quat angleAxis(float, ECS::Maths::vec3);

                ECS::Maths::mat4 mat4_cast(ECS::Maths::quat);
                float *value_ptr(ECS::Maths::mat4);
                float *value_ptr(ECS::Maths::vec3);
        };

        ECS::Maths::quat operator* (ECS::Maths::quat, ECS::Maths::quat);

        ECS::Maths::mat4 operator* (ECS::Maths::mat4, ECS::Maths::mat4);
        ECS::Maths::mat4 operator+ (ECS::Maths::mat4, ECS::Maths::mat4);
        ECS::Maths::mat4 operator/ (ECS::Maths::mat4, ECS::Maths::mat4);
        ECS::Maths::mat4 operator- (ECS::Maths::mat4, ECS::Maths::mat4);

        ECS::Maths::vec2 operator* (ECS::Maths::vec2, ECS::Maths::vec2);
        ECS::Maths::vec2 operator+ (ECS::Maths::vec2, ECS::Maths::vec2);
        ECS::Maths::vec2 operator/ (ECS::Maths::vec2, ECS::Maths::vec2);
        ECS::Maths::vec2 operator- (ECS::Maths::vec2, ECS::Maths::vec2);

        ECS::Maths::vec3 operator* (ECS::Maths::vec3, ECS::Maths::vec3);
        ECS::Maths::vec3 operator+ (ECS::Maths::vec3, ECS::Maths::vec3);
        ECS::Maths::vec3 operator/ (ECS::Maths::vec3, ECS::Maths::vec3);
        ECS::Maths::vec3 operator- (ECS::Maths::vec3, ECS::Maths::vec3);

        ECS::Maths::vec4 operator* (ECS::Maths::vec4, ECS::Maths::vec4);
        ECS::Maths::vec4 operator+ (ECS::Maths::vec4, ECS::Maths::vec4);
        ECS::Maths::vec4 operator/ (ECS::Maths::vec4, ECS::Maths::vec4);
        ECS::Maths::vec4 operator- (ECS::Maths::vec4, ECS::Maths::vec4);
    }
}