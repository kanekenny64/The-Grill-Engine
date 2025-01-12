#include "Component.h"
#include <glm/glm.hpp>


namespace thegrill {
	struct BoxCollider : Component
	{
		void on_initialize();
		bool colliding(const BoxCollider& _other);

		glm::vec3 get_collisionResponse(const BoxCollider& _other);
		glm::vec3 get_offset() const { return m_offset; }
		glm::vec3 get_size() const { return m_size; }

		void set_offset(glm::vec3 _offset);
		void set_size(glm::vec3 _size);

	private:
		glm::vec3 m_size;
		glm::vec3 m_offset;
		
	};

}