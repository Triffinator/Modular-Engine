#pragma once

namespace ECS
{
    class Entity
    {
        public:
            /**
            * @brief: CTOR for Entities. Creates Entity with an EID
            * @param: newEID    unsigned long. Entity identification number.
            */
	        Entity(unsigned long newEID);

            /**
            * @brief:
            */
	        ~Entity();

	        /**
	        * @brief: get method for the EID
	        * @return: EID      unsigned long. Entity ID
	        */
	        const unsigned long GetEID() { return m_EID; }

        private:
	        /**
	        * The identification number of the entity
	        */
	        unsigned long m_EID;
    };
}