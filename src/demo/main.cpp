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
	}

};

#undef main

int main()
{
	std::shared_ptr<Core> core = Core::initialize();
	std::shared_ptr<Resources> resources = core->get_resources();
	std::shared_ptr<Texture> tex = resources->load<Texture>("../textures/CookedChickenBreastAlbedo.png");
	std::shared_ptr<Model> model = resources->load<Model>("../models/CookedChickenBreast.obj");

	std::shared_ptr<Entity> entity = core->add_entity();
	entity->add_component<Player>();
	std::shared_ptr<TriangleRenderer> r =entity ->add_component<TriangleRenderer>();
	
	r->set_texture(tex->getTexture());
	r->set_model(model->getModel());

	entity->get_transform()-> m_position = glm::vec3(0, 0, -5);

	core->run();



return 0;
}	