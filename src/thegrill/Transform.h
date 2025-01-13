#ifndef THEGRILL_TRANSFORM_H
#define	THEGRILL_TRANSFORM_H



#include "Component.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>


namespace thegrill {

	struct Entity;

	struct Transform : Component
	{
		glm::mat4 get_model() ;

		glm::vec3 get_position() const;

		void set_position(glm::vec3 _position) {
			m_position = _position;
		}

		glm::vec3 get_rotation() {
			return m_rotation;
		}

		std::shared_ptr<Entity> get_parent();
		void set_parent(std::shared_ptr<Entity> _parent);

		void Move(glm::vec3 _amount);


	private:
		glm::vec3 m_position = { 0.0,0.0,-10.0 };
		glm::vec3 m_rotation = { 0.0,0.0,0.0 };
		glm::vec3 m_scale = { 1.0,1.0,1.0 };

		std::weak_ptr<Entity> m_Parent;
	};

	
	
}

#endif // !THEGRILL_TRANSFORM_H