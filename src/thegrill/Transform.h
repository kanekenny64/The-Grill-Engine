#ifndef THEGRILL_TRANSFORM_H
#define	THEGRILL_TRANSFORM_H



#include "Component.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>


namespace thegrill {

	struct Entity;

	/**
	 * @brief The Transform compoenent represents the position, rotation, and scale of an entity.
	 */

	struct Transform : Component
	{
		glm::mat4 get_model() ;

		void set_rotation(glm::vec3 _rotation);
		void set_position(glm::vec3 _position);
		void Move(glm::vec3 _amount);

		/**
		 * @brief Gets the position of the transform recursively including the position of parents if found.
		 * @return The position.
		 */
		glm::vec3 get_position();

		/**
		* @brief Gets the rotation of the transform recursively including the rotation of parents if found.
		* @return The rotation.
		*/
		glm::vec3 get_rotation();

		/**
		* @brief Gets the scale of the transform recursively including the scale of parents if found.
		* @return The scale.
		*/
		glm::vec3 get_scale();

		std::shared_ptr<Entity> get_parent();
		void set_parent(std::shared_ptr<Entity> _parent);

	private:
		glm::vec3 m_position = { 0.0,0.0,-10.0 };
		glm::vec3 m_rotation = { 0.0,0.0,0.0 };
		glm::vec3 m_scale = { 1.0,1.0,1.0 };

		std::weak_ptr<Entity> m_Parent;
	};

	
	
}

#endif // !THEGRILL_TRANSFORM_H