#include <thegrill/thegrill.h>
#include <iostream>

using namespace thegrill;

struct Player : Component {

	void on_initialize() {
		printf("Test::initialize\n");
	}

private:
	int m_dummy;

	void on_tick() {
		printf("Test::tick\n");
		
	}

};

int main()
{
	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> entity = core->add_entity();
	std::shared_ptr<Player> p = entity->add_component<Player>();
	//std::shared_ptr<TriangleRenderer> p = entity->add_component<TriangleRenderer>();
	

	core->run();

return 0;
}	