#include "Entity.h"
#include "Component.h"
#include "Transform.h"

#include <iostream>

namespace thegrill {
	std::shared_ptr<Transform> Entity::get_transform() const
	{
		return m_transform.lock();
	}
	void Entity::set_position(glm::vec3 _position)
	{
		get_transform()->set_position(_position);
	}
	std::shared_ptr<Core> Entity::get_core() const
	{
		return m_core.lock();
	}

	//When destroy is called, first check if its already destroyed
	//If it is not destroyed, set alive to false and call on_destroy for all components
	void Entity::destroy()
	{
		if (alive)
		{
			alive = false;

			for (size_t ci = 0; ci < m_components.size(); ci++)
			{
				m_components.at(ci)->on_destroy();
			}
		}
	}
	Entity::~Entity() {
		std::cout << "Entity Destroyed" << std::endl;
	}

	void Entity::OnTick() {
		for (size_t ci = 0; ci < m_components.size(); ci++)
		{
			m_components.at(ci)->tick();
		}
	}

	void Entity::OnRender() {
		for (size_t ci = 0; ci < m_components.size(); ci++)
		{
			m_components.at(ci)->render();
		}
	}
	void Entity::OnGUI()
	{
		for (size_t ci = 0; ci < m_components.size(); ci++)
		{
			m_components.at(ci)->gui();
		}
	}
}