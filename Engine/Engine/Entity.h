#pragma once

namespace ECS
{
    class Entity
    {
        public:
	        Entity(unsigned long newEID);
	        ~Entity();

	        /**
	        * Get method for the EID
	        * Returns: unsigned long
	        */
	        const unsigned long GetEID() { return m_EID; }

        private:
	        /**
	        * The identity number of the entity
	        */
	        unsigned long m_EID;
    };
}