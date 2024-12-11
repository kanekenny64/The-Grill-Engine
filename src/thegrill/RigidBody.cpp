#include "RigidBody.h"
#include "BoxCollider.h"
#include "Core.h"
#include "Entity.h"
#include <vector>


namespace thegrill {
	void RigidBody::on_tick() {
		//get a list of all box colliders using Core::find
		//for each box collider, check if it is colliding with this rigid body
//if it is, apply a force to the rigid body

		std::vector<std::shared_ptr<BoxCollider> > colliders;
		get_entity()->get_core()->find<BoxCollider>(colliders);

		std::vector<std::shared_ptr<BoxCollider> > thisCollider;
		std::vector<std::shared_ptr<BoxCollider> > otherColliders;



		//loop through all colliders and check if colliding with this rigid body, ignoring self
		for (auto& collider : colliders) {
			if (collider->get_entity() == get_entity()) {
				thisCollider.push_back(collider);
			}
			else {
				otherColliders.push_back(collider);
			}
		}

		for (int i = 0; i < thisCollider.size(); i++) {
			for (int j = 0; j < otherColliders.size(); j++) {
				if (thisCollider[i]->colliding(*otherColliders[j])) {
					std::cout << "Colliding" << std::endl;
				}
			}
		}
	}
}