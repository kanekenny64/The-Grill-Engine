#include "Transform.h"
#include "Entity.h"
#include <iostream>

namespace thegrill {
	

	glm::mat4 Transform::get_model() 
	{
		glm::mat4 rtn(1.0f);
		rtn = glm::translate(rtn, m_position);
		rtn = glm::rotate(rtn, glm::radians(m_rotation.y), glm::vec3(0, 1, 0));
		rtn = glm::rotate(rtn, glm::radians(m_rotation.x), glm::vec3(1, 0, 0));
		rtn = glm::rotate(rtn, glm::radians(m_rotation.z), glm::vec3(0, 0, 1));
		rtn = glm::scale(rtn, m_scale);

		if (auto Parent = m_Parent.lock())
		{
			rtn = Parent->get_transform()->get_model() * rtn;
		}


		return rtn;
	}

	glm::vec3 Transform::get_position()
	{
		if (auto Parent = m_Parent.lock())
		{
			return Parent->get_transform()->get_position() + m_position;
		}
		else
		{
			return m_position;
		}
	}

	glm::vec3 Transform::get_rotation()
	{
		if (auto Parent = m_Parent.lock())
		{
			return Parent->get_transform()->get_rotation() + m_rotation;
		}
		else
		{
			return m_rotation;
		}
	}

	glm::vec3 Transform::get_scale()
	{
		if (auto Parent = m_Parent.lock())
		{
			return Parent->get_transform()->get_scale() * m_scale;
		}
		else
		{
			return m_scale;
		}
	}



	std::shared_ptr<Entity> Transform::get_parent() 
	{
		return m_Parent.lock();
	}

	void Transform::set_parent(std::shared_ptr<Entity> _parent)
	{
		m_Parent = _parent;
	}
	void Transform::Move(glm::vec3 _amount)
	{
		m_position += _amount;
	}
}