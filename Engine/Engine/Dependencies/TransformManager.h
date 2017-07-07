#pragma once

#include <map>
#include <iostream>

#include "Entity.h"
#include "TransformComponent.h"
#include "MathFacade.h"

namespace ECS
{
    class TransformManager
    {
        public:

            struct InstanceData
            {
                Maths::vec3 scale;
                Maths::quat rotation;
                Maths::vec3 translation;
                Maths::mat4 tranMatrix;
            };

        private:
            typedef std::map<unsigned long, InstanceData> ComponentMap;
            ComponentMap m_transformMap;

        public:
            /**
            *  Component manager constructor.
            *
            *  @post    Constructs a Transform Component Manager
            */
            TransformManager();

            /**
            *  Component manager destructor.
            *
            *  @post    Destructs a Transform Component Manager
            */
            ~TransformManager();

            /**
            *  Checks whether an Entity has transform component.
            *
            *  @post    Will search map for this entity ID.
            *
            *  @param    e, Entity to be searched.
            *  @return    true if the id was found.
            */
            bool EntityHasComponent(const Entity& e);

            /**
            *  Creates transform component for this entity.
            *
            *  @post    Will add Instance data to map with the
            *            entity ID as key
            *
            *  @param    e, Entity component should be added to.
            *  @return    true, if successfully created.
            */
            bool CreateComponentForEntity(const Entity& e);

            /**
            *  Removes transform component from Entity
            *
            *  @post    Will remove Instance data from map
            *            with the entity ID as key.
            *
            *  @param    e, Entity component should be removed from.
            *  @return    True, if component successfully removed.
            */
            bool DestroyComponentData(Entity& e);

            /**
            *  Returns the number of transform components this manager contains.
            *
            *  @post    Returns the size of the transform map.
            *
            *  @return    The amount of components stored.
            */
            unsigned int GetNumberOfComponents();

            /**
            *  Returns the scale of the transform component.
            *
            *  @post    returns scale value of associated entity ID.
            *
            *  @param    e, Entity that id is used
            *  @return    The scale of associated entity.
            */
            const Maths::vec3 &GetScale(const Entity& e) const;

            /**
            *  Returns the rotation of the transform component.
            *
            *  @post    returns rotation value of associated entity ID.
            *
            *  @param    e, Entity that id is used
            *  @return    The rotation of associated entity.
            */
            const Maths::quat &GetRotation(const Entity& e) const;

            /**
            *  Returns the translation of the transform component.
            *
            *  @post    Returns translation value of associated entity ID.
            *
            *  @param    e, Entity that id is used
            *  @return    The translation of associated entity.
            */
            const Maths::vec3 &GetTranslation(const Entity& e) const;

            /**
            *  Sets the value of the scale with associated entity.
            *
            *  @post    Sets scale to param scale.
            *
            *  @param    e, Entity that id is used.
            *  @param    Sets scale to this value.
            *  @return    Returns true if correctly set.
            */
            const bool SetScale(const Entity& e, const Maths::vec3 &scale);

            /**
            *  Sets the value of the rotation with associated entity.
            *
            *  @post    Sets rotation to param rotation.
            *
            *  @param    e, Entity that id is used.
            *  @param    Sets scale to this value.
            *  @return    Returns true if correctly set.
            */
            const bool SetRotation(const Entity& e, const Maths::quat &rotation);

            /**
            *  Sets the value of the translation with associated entity.
            *
            *  @post    Sets translation to param translation.
            *
            *  @param    e, Entity that id is used.
            *  @param    Sets scale to this value.
            *  @return    Returns true if correctly set.
            */
            const bool SetTranslation(const Entity& e, const Maths::vec3 &translation);

            /**
            *  Increments the value of the scale with associated entity.
            *
            *  @post    Increments scale to param scale.
            *
            *  @param    e, Entity that id is used.
            *  @param    Increments scale to this value.
            *  @return    Returns true if correctly incremented.
            */
            const bool IncScale(const Entity& e, const Maths::vec3 &scale);

            /**
            *  Increments the value of the translation with associated entity.
            *
            *  @post    Increments rotation to param rotation.
            *
            *  @param    e, Entity that id is used.
            *  @param    Increments scale to this value.
            *  @return    Returns true if correctly incremented.
            */
            const bool IncRotation(const Entity& e, const Maths::quat &rotation);

            /**
            *  Increments the value of the translation with associated entity.
            *
            *  @post    Increments translation to param translation.
            *
            *  @param    e, Entity that id is used.
            *  @param    Increments scale to this value.
            *  @return    Returns true if correctly incremented.
            */
            const bool IncTranslation(const Entity& e, const Maths::vec3 &translation);

            void UpdateTransformM(const Entity& e);

            Maths::mat4 GetTransformM(const Entity& e) const;

            const ComponentMap& GetMap() const;

            void toString(const Entity& e) const;

            Maths::vec3* GetTranslation_Ptr(unsigned int id);
            Maths::vec3* GetTranslation_Ptr(const Entity& e);

            TransformManager::InstanceData* GetComponent(unsigned int id);
    }; 
}

