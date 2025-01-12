#include <thegrill/thegrill.h>

#include <iostream>



using namespace thegrill;

struct Player : Component {

	void on_initialize() {
		printf("Test::initialize\n");
	}

	void on_gui() {

		get_gui()->button(get_core()->get_resources()->load<thegrill::Texture>("textures/CookedChickenBreastAlbedo")->get_texture(), 20, 20, 400, 400);
	}

	void on_destroy() {
		printf("Test::destroy\n");
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

		std::cout << "Position: " << get_entity()->get_transform()->get_position().x << ", " << get_entity()->get_transform()->get_position().y << ", " << get_entity()->get_transform()->get_position().z << std::endl;
	}

};



#undef main

int main()
{
	std::shared_ptr<Core> core = Core::initialize();

	{
		std::shared_ptr<Resources> resources = core->get_resources();
		std::shared_ptr<Texture> tex = resources->load<Texture>("textures/CookedChickenBreastAlbedo");
		std::shared_ptr<Model> model = resources->load<Model>("models/CookedChickenBreast");
		std::shared_ptr<Audio> sound = resources->load<Audio>("audio/blue-blood-ogg-67848");

		std::shared_ptr<Entity> entity = core->add_entity();
		entity->add_component<Player>();
		std::shared_ptr<ModelRenderer> r = entity->add_component<ModelRenderer>();
		std::shared_ptr<SoundSource> Ssource = entity->add_component<SoundSource>();
		std::shared_ptr<BoxCollider> collider = entity->add_component<BoxCollider>();
		std::shared_ptr<RigidBody> rigidBody = entity->add_component<RigidBody>();
		std::shared_ptr<Camera> camera = entity->add_component<Camera>();

		Ssource->setAudio(sound);
		//Ssource->play();


		r->set_texture(tex->get_texture());
		r->set_model(model->get_model());

		entity->set_position(glm::vec3(0, 0, 5));

		//second player
		std::shared_ptr<Entity> entity2 = core->add_entity();
		std::shared_ptr<ModelRenderer> r2 = entity2->add_component<ModelRenderer>();
		std::shared_ptr<BoxCollider> collider2 = entity2->add_component<BoxCollider>();
		std::shared_ptr<RigidBody> rigidBody2 = entity2->add_component<RigidBody>();
		std::shared_ptr<AnimationTrack> AnimTrack1 = entity2->add_component<AnimationTrack>();
		std::shared_ptr<AnimationController> AnimController1 = entity2->add_component<AnimationController>();
		AnimTrack1->create("models/guppy40001", 4);
		AnimController1->set_track(AnimTrack1);
		AnimController1->set_duration(10.5f);
		r2->set_texture(tex->get_texture());
		r2->set_model(model->get_model());

		

		entity2->set_position(glm::vec3(5, 0, -15));;

		entity2->get_transform()->set_parent(entity);
	}
	core->run();



return 0;
}	