#include <memory>
#include <glm/glm.hpp>
#include <vector>
#include "Component.h"
#include "Entity.h"
#include "renderer/Renderer.h"

namespace thegrill {

	struct MeshCollider : Component
	{
		void on_initialize();

		std::vector<renderer::Model::Face> m_faces;
	};
}