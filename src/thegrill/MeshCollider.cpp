#include "MeshCollider.h"
#include "Model.h"
#include "tribox3.h"
#include "BoxCollider.h"
#include "Transform.h"
#include "ModelRenderer.h"
#include "Component.h"
#include "Entity.h"


namespace thegrill {
	void MeshCollider::on_initialize()
	{
		//This could cause an issue if an entity has no model or multiple models
		m_faces = get_entity()->get_component<ModelRenderer>()->get_model()->getFaces();
		if (m_faces.empty())
		{
			throw std::runtime_error("MeshCollider Intialisation error: Failed to find mesh for meshrenderer to use");
		}
	}

	void MeshCollider::on_tick()
	{

	}
	bool MeshCollider::colliding(const BoxCollider& _other)
	{
		//loop thorugh faces in m_faces and check for collision with _other
		for (int i = 0; i < m_faces.size(); i++)
		{
			float boxCentre[3] = { _other.get_entity()->get_transform()->get_position().x, _other.get_entity()->get_transform()->get_position().y, _other.get_entity()->get_transform()->get_position().z };
			float boxHalfSize[3] = { _other.get_size().x / 2.0f, _other.get_size().y / 2.0f, _other.get_size().z / 2.0f };
			float triVerts[3][3] = { {m_faces[i].a.position.x, m_faces[i].a.position.y, m_faces[i].a.position.z},
												{m_faces[i].b.position.x, m_faces[i].b.position.y, m_faces[i].b.position.z},
												{m_faces[i].c.position.x, m_faces[i].c.position.y, m_faces[i].c.position.z} };
			if (triBoxOverlap(boxCentre, boxHalfSize, triVerts) == 1)
			{
				return true;
			}
		}
		return false;
	}
	
}