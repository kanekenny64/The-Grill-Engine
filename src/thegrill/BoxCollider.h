#include "Component.h"
#include "Collider.h"
#include <glm/glm.hpp>


namespace thegrill {

	struct MeshCollider;

	/**
	 * @brief The BoxCollider class represents a rectangular collider used to test for collision with other colliders.
	 */
	struct BoxCollider : Collider
	{
		void on_initialize();
		/**
		 * @brief Checks for a collision with another BoxCollider.
		 * @param _other The other BoxCollider to check for collision.
		 * @return True if a collision occurs, false otherwise.
		 */
		bool colliding(const BoxCollider& _other);

		/**
		 * @brief Calculates the collision response vector when colliding with another BoxCollider.
		 * @param _other The other BoxCollider to calculate the response against.
		 * @return The collision response vector.
		 */
		glm::vec3 get_collisionResponse(BoxCollider& _other);

		/**
		 * @brief Calculates the collision response vector when colliding with a MeshCollider.
		 * @param _other The MeshCollider to calculate the response against.
		 * @return The collision response vector.
		 */
		glm::vec3 get_collisionResponse(MeshCollider& _other);

		glm::vec3 get_offset() const { return m_offset; }
		glm::vec3 get_size() const { return m_size; }

		void set_offset(glm::vec3 _offset);
		void set_size(glm::vec3 _size);

		

		

	private:
		glm::vec3 m_size; ///< The size of the BoxCollider.
		glm::vec3 m_offset; ///< The offset of the BoxCollider.

		
		
	};

}