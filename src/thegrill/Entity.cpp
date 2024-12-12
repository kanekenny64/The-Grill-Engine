#include "Entity.h"
#include "Component.h"
#include "Transform.h"

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
	Entity::~Entity() {

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
}