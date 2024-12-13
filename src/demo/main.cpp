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
		//check if button is pressed
		if (get_keyboard()->isKeyDown(KEY_W)) {
			//move forward
			std::cout << "W is pressed" << std::endl;
			glm::vec3 pos = get_entity()->get_transform()->get_position();
			pos.z += 0.1f;
			get_entity()->set_position(pos);
			
		}
		if (get_keyboard()->isKeyDown(KEY_S)) {
			//move back
			std::cout << "S is pressed" << std::endl;
			glm::vec3 pos = get_entity()->get_transform()->get_position();
			pos.z -= 0.1f;
			get_entity()->set_position(pos);
		}

		if (get_keyboard()->isKeyDown(KEY_D)) {
			//move back
			std::cout << "S is pressed" << std::endl;
			glm::vec3 pos = get_entity()->get_transform()->get_position();
			pos.x += 0.1f;
			get_entity()->set_position(pos);
		}

		if (get_keyboard()->isKeyDown(KEY_A)) {
			//move left
			std::cout << "A is pressed" << std::endl;
			glm::vec3 pos = get_entity()->get_transform()->get_position();
			pos.x -= 0.1f;
			get_entity()->set_position(pos);
		}
	}

};



#undef main

int main()
{
	std::shared_ptr<Core> core = Core::initialize();
	std::shared_ptr<Resources> resources = core->get_resources();
	std::shared_ptr<Texture> tex = resources->load<Texture>("textures/CookedChickenBreastAlbedo");
	std::shared_ptr<Model> model = resources->load<Model>("models/CookedChickenBreast");
	std::shared_ptr<Audio> sound = resources->load<Audio>("audio/blue-blood-ogg-67848");

	std::shared_ptr<Entity> entity = core->add_entity();
	entity->add_component<Player>();
	std::shared_ptr<TriangleRenderer> r =entity ->add_component<TriangleRenderer>();
	std::shared_ptr<SoundSource> Ssource = entity->add_component<SoundSource>();
	std::shared_ptr<BoxCollider> collider = entity->add_component<BoxCollider>();
	std::shared_ptr<RigidBody> rigidBody = entity->add_component<RigidBody>();

	Ssource->setAudio(sound);
	Ssource->play();
	
	
	r->set_texture(tex->getTexture());
	r->set_model(model->getModel());

	entity->set_position(glm::vec3(0, 0, -15));

	//second player
	std::shared_ptr<Entity> entity2 = core->add_entity();
	std::shared_ptr<TriangleRenderer> r2 = entity2->add_component<TriangleRenderer>();
	std::shared_ptr<BoxCollider> collider2 = entity2->add_component<BoxCollider>();
	std::shared_ptr<RigidBody> rigidBody2 = entity2->add_component<RigidBody>();
	r2->set_texture(tex->getTexture());
	r2->set_model(model->getModel());

	entity2->set_position(glm::vec3(5, 0, -15));;


	core->run();



return 0;
}	