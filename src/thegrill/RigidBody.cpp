#include "RigidBody.h"
#include "BoxCollider.h"
#include "Core.h"
#include "Entity.h"
#include "Transform.h"
#include <vector>


namespace thegrill {
	void RigidBody::on_tick() {
		//get a list of all box colliders using Core::find
		//for each box collider, check if it is colliding with this rigid body
		//if it is, apply a force to the rigid body

		std::vector<std::shared_ptr<BoxCollider> > colliders;
		get_entity()->get_core()->find<BoxCollider>(colliders);

		std::vector<std::shared_ptr<BoxCollider> > thisCollider;

		get_entity()->get_components<BoxCollider>(thisCollider);



		for (int i = 0; i < thisCollider.size(); i++) {
			for (int j = 0; j < colliders.size(); j++) {
				if (thisCollider[i] == colliders[j])
				{
					continue;
				}
				if (thisCollider[i]->colliding(*colliders[j])) {
					//output position of entity before collision
					std::cout << "Position before collision: " << get_entity()->get_transform()->get_position().x << ", " << get_entity()->get_transform()->get_position().y << ", " << get_entity()->get_transform()->get_position().z << std::endl;
					std::cout << "Colliding" << std::endl;
					get_entity()->get_transform()->set_position(thisCollider[i]->get_collisionResponse(*colliders[j]) - thisCollider[i]->get_offset());
					//output position of entity after collision
					std::cout << "Position after collision: " << get_entity()->get_transform()->get_position().x << ", " << get_entity()->get_transform()->get_position().y << ", " << get_entity()->get_transform()->get_position().z << std::endl;
				
				}

				
			}
		}
	}
}