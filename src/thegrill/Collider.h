#pragma once

#include "Component.h"
#include <glm/glm.hpp>

/**
* @brief The Collider class acts as a parent for other colliders to inherit from.
* 
* It does not contain any data or functions, but can be used to identify colliders in the engine.
*/

namespace thegrill {
	struct Collider : Component
	{ };
}
