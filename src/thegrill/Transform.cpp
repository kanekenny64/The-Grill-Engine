#include "Transform.h"

namespace thegrill {
	

	glm::mat4 Transform::get_model() const
	{
		glm::mat4 rtn(1.0f);
		rtn = glm::translate(rtn, m_position);
		rtn = glm::rotate(rtn, glm::radians(m_rotation.y), glm::vec3(0, 1, 0));
		rtn = glm::rotate(rtn, glm::radians(m_rotation.x), glm::vec3(1, 0, 0));
		rtn = glm::rotate(rtn, glm::radians(m_rotation.z), glm::vec3(0, 0, 1));
		rtn = glm::scale(rtn, m_scale);

		return rtn;
	}

}