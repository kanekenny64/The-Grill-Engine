#include "BoxCollider.h"
#include "Entity.h"
#include "Transform.h"
#include <iostream>


namespace thegrill {
	void BoxCollider::on_initialize()
	{
		m_size = glm::vec3(1.5f);
		m_offset = glm::vec3(0.0f);
		
	}
	bool BoxCollider::colliding(const BoxCollider& _other)
	{
		
		glm::vec3 a = get_entity()->get_transform()->get_position() + getOffset();
		glm::vec3 b = _other.get_entity()->get_transform()->get_position() + _other.getOffset();
		glm::vec3 ahs = m_size / 2.0f;
		glm::vec3 bhs = _other.m_size / 2.0f;

		//x
		if (a.x > b.x)
		{
			if (b.x + bhs.x < a.x - ahs.x)
			{
				return false;
			}
		}
		else
		{
			if (a.x + ahs.x < b.x - bhs.x)
			{
				return false;
			}
		}
		//y
		if (a.y > b.y)
		{
			if (b.y + bhs.y < a.y - ahs.y)
			{
				return false;
			}
		}
		else
		{
			if (a.y + ahs.y < b.y - bhs.y)
			{
				return false;
			}
		}
		//z
		if (a.z > b.z)
		{
			if (b.z + bhs.z < a.z - ahs.z)
			{
				return false;
			}
		}
		else
		{
			if (a.z + ahs.z < b.z - bhs.z)
			{
				return false;
			}
		}

		return true;
		
	}
	glm::vec3 BoxCollider::getCollisionResponse(const BoxCollider& _other)
	{
		float amount = 0.1f;
		float step = 0.1f;
		glm::vec3 position = get_entity()->get_transform()->get_position();


		//position is not being used by the colliding function, it is using the entity's position instead
		//the entities position is not being updated and the position variable is not used resulting in infinite loop 


		while (true)
		{
			if (!colliding(_other)) break;

			position.x +=  amount;
			get_entity()->get_transform()->set_position(position);
			position = get_entity()->get_transform()->get_position();
			if (!colliding(_other)) break;
			position.x -= amount;
			position.x -= amount;
			get_entity()->get_transform()->set_position(position);
			position = get_entity()->get_transform()->get_position();
			if (!colliding(_other)) break;
			position.x += amount;
			position.z += amount;
			get_entity()->get_transform()->set_position(position);
			position = get_entity()->get_transform()->get_position();
			if (!colliding(_other)) break;
			position.z -= amount;
			position.z -= amount;
			get_entity()->get_transform()->set_position(position);
			position = get_entity()->get_transform()->get_position();
			if (!colliding(_other)) break;
			position.z += amount;
			position.y += amount;
			get_entity()->get_transform()->set_position(position);
			position = get_entity()->get_transform()->get_position();
			if (!colliding(_other)) break;
			position.y -= amount;
			position.y -= amount;
			get_entity()->get_transform()->set_position(position);
			position = get_entity()->get_transform()->get_position();
			if (!colliding(_other)) break;
			position.y += amount;
			amount += step;
			get_entity()->get_transform()->set_position(position);
			position = get_entity()->get_transform()->get_position();

		}
		
		return position;
	}
}