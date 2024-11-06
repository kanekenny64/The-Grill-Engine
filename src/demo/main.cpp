#include <thegrill/thegrill.h>

#include <iostream>

using namespace thegrill;

struct Player : Component {

	void on_initialize() {
		printf("Test::initialize\n");
	}

private:
	int m_dummy = 1;

	void on_tick() {
		//printf("Test::Tick\n");
	}

};

#undef main

int main()
{
	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> entity = core->add_entity();
	entity->add_component<Player>();
	entity ->add_component<TriangleRenderer>();
	

	core->run();

return 0;
}	