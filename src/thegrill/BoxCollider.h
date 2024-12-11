#include "Component.h"
#include <glm/glm.hpp>


namespace thegrill {
	struct BoxCollider : Component
	{
		void on_initialize();
		bool colliding(const BoxCollider& _other);


	private:
		glm::vec3 m_size;
		glm::vec3 m_offset;
	};

}