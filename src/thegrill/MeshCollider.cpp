#include "MeshCollider.h"
#include "Model.h"

namespace thegrill {
	void MeshCollider::on_initialize()
	{
		//This could cause an issue if an entity has no model or multiple models
		m_faces = get_entity()->get_component<Model>()->get_model()->getFaces();
	}
}