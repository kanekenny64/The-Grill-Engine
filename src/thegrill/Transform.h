#ifndef THEGRILL_TRANSFORM_H
#define	THEGRILL_TRANSFORM_H



#include "Component.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>


namespace thegrill {
	struct Transform : Component
	{
		

		glm::mat4 get_model() const;

		glm::vec3 get_position() const;

		void set_position(glm::vec3 _position) {
			m_position = _position;
		}

	private:
		glm::vec3 m_position = { 0.0,0.0,-10.0 };
		glm::vec3 m_rotation = { 0.0,0.0,0.0 };
		glm::vec3 m_scale = { 1.0,1.0,1.0 };
	};

	
	
}

#endif // !THEGRILL_TRANSFORM_H