#include "Entity.h"
#include "Component.h"

namespace thegrill {

	Entity::~Entity() {

	}

	void Entity::tick() {
		for (size_t ci = 0; ci < m_components.size(); ci++)
		{
			m_components.at(ci)->tick();
		}
	}
}