#include <memory>
#include <glm/glm.hpp>
#include <vector>
#include "Component.h"
#include "Entity.h"
#include "renderer/Renderer.h"

namespace thegrill {

	struct BoxCollider;

	struct MeshCollider : Component
	{
		void on_initialize();
		void on_tick();

		bool colliding(const BoxCollider& _other);

		std::vector<renderer::Model::Face> m_faces;
	};
}