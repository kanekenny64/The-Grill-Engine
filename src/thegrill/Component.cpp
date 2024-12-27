#include "Component.h"
#include "Entity.h"
#include "Core.h"
#include "Input.h"


namespace thegrill {

	void Component::on_initialize() { }
	void Component::on_tick() { }
	void Component::on_render() { }

	void Component::tick() {
		on_tick();
	}

	void Component::render(){
		on_render();
	}

	std::shared_ptr<Entity> Component::get_entity() const
	{
		return m_entity.lock();
	}
	std::shared_ptr<Keyboard> Component::get_keyboard()
	{
		return get_entity()->get_core()->input()->keyboard();
	}

	std::shared_ptr<Core> Component::get_core()
	{
		return get_entity()->get_core();
	}

	std::shared_ptr<Transform> Component::get_transform()
	{
		return get_entity()->get_transform();
	}
}