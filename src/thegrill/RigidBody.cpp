#include "RigidBody.h"
#include "Collider.h"
#include "BoxCollider.h"
#include "MeshCollider.h"
#include "Core.h"
#include "Entity.h"
#include "Transform.h"
#include <vector>


namespace thegrill {
	void RigidBody::on_tick() {
		//get a list of all box colliders using Core::find
		//for each box collider, check if it is colliding with this rigid body
		//if it is, apply a force to the rigid body

		std::vector<std::shared_ptr<Collider> > colliders;
		get_entity()->get_core()->find<Collider>(colliders);

		std::vector<std::shared_ptr<BoxCollider> > worldBoxColliders;
		get_entity()->get_core()->find<BoxCollider>(worldBoxColliders);

		std::vector<std::shared_ptr<MeshCollider> > worldMeshColliders;
		get_entity()->get_core()->find<MeshCollider>(worldMeshColliders);

		std::vector<std::shared_ptr<BoxCollider> > thisBoxCollider;
		get_entity()->get_components<BoxCollider>(thisBoxCollider);

		std::vector<std::shared_ptr<MeshCollider> > thisMeshColliders;
		get_entity()->get_core()->find<MeshCollider>(thisMeshColliders);

		for (int i = 0; i < thisBoxCollider.size(); i++) {
			for (int j = 0; j < worldBoxColliders.size(); j++) {
				if (thisBoxCollider[i] == worldBoxColliders[j])
				{
					continue;
				}

				if (thisBoxCollider[i]->colliding(*worldBoxColliders[j])) {
					//output position of entity before collision
					std::cout << "Position before collision: " << get_entity()->get_transform()->get_position().x << ", " << get_entity()->get_transform()->get_position().y << ", " << get_entity()->get_transform()->get_position().z << std::endl;
					std::cout << "Colliding" << std::endl;
					get_entity()->get_transform()->set_position(thisBoxCollider[i]->get_collisionResponse(*worldBoxColliders[j]) - thisBoxCollider[i]->get_offset());
					//output position of entity after collision
					std::cout << "Position after collision: " << get_entity()->get_transform()->get_position().x << ", " << get_entity()->get_transform()->get_position().y << ", " << get_entity()->get_transform()->get_position().z << std::endl;
				
				}
				
			}
		}

		for (int i = 0; i < thisMeshColliders.size(); i++)
		{

			for (int j = 0; j < worldBoxColliders.size(); j++) {


				if ( thisMeshColliders[i]->colliding(*worldBoxColliders[j]))
				{
					std::cout << "Collision with mesh" << std::endl;
					worldBoxColliders[j]->get_entity()->get_transform()->set_position(worldBoxColliders[j]->get_collisionResponse(*thisMeshColliders[i]));
				}
			}
		}
	}
}