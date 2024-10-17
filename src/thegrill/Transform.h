#include "Component.h"
#include <glm/glm.hpp>


namespace thegrill {
	struct Transform : Component
	{
		glm::vec3 m_position = { 0.0,0.0,0.0 };
		glm::vec3 m_rotation = { 0.0,0.0,0.0 };
		glm::vec3 m_scale = { 1.0,1.0,1.0 };
	};
}