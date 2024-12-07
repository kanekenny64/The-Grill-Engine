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

		for (auto& collider : colliders) {
			
		}
	}
}