#include <thegrill/thegrill.h>

#include <iostream>

using namespace thegrill;

void initialiseMenu(std::shared_ptr<Core> core);
void initialiseGame(std::shared_ptr<Core> core);


#undef main

int main()
{
	std::shared_ptr<Core> core = Core::initialize();

	initialiseMenu(core);
	core->run();

	return 0;
}

struct Menu : Component {
	void on_gui() {
		get_gui()->image(get_core()->get_resources()->load<thegrill::Texture>("textures/Background"), 0, 0, 980, 720);
		int play = get_gui()->button(get_core()->get_resources()->load<thegrill::Texture>("textures/PlayButton"), 290, 460, 300, 200);
		int quit = get_gui()->button(get_core()->get_resources()->load<thegrill::Texture>("textures/QuitButton"), 290, 200, 300, 200);
		
		if (play == 2) {
			get_core()->DestroyAllEntities();
			initialiseGame(get_core());
		}

		if (quit == 2) {
			get_core()->Quit();
		}
	}
};


void initialiseMenu(std::shared_ptr<Core> core) {
	std::shared_ptr<Entity> menu = core->add_entity();
	menu->add_component<Menu>();
}

struct Player : Component {


private:

	void on_tick() {

		//check if button is pressed
		if (get_keyboard()->isKeyDown(KEY_W)) {
			//move forward

			vec3 pos = get_entity()->get_transform()->get_position();
			pos.z -= 0.5f;
			get_entity()->set_position(pos);

		}
		if (get_keyboard()->isKeyDown(KEY_S)) {
			//move back
			vec3 pos = get_entity()->get_transform()->get_position();
			pos.z += 0.5f;
			get_entity()->set_position(pos);
		}

		// Check if the 'D' key is pressed to move right
		if (get_keyboard()->isKeyDown(KEY_D)) {
			vec3 pos = get_entity()->get_transform()->get_position();
			pos.x += 0.5f;
			get_entity()->get_transform()->set_position(pos);
		}

		// Check if the 'A' key is pressed to move left
		if (get_keyboard()->isKeyDown(KEY_A)) {
			vec3 pos = get_entity()->get_transform()->get_position();
			pos.x -= 0.5f;
			get_entity()->get_transform()->set_position(pos);
		}

		//Check if Space is pressed to change the camera
		if (get_keyboard()->isKeyDown(KEY_LEFT)) {
				
			get_core()->set_current_cam(get_entity()->get_component<Camera>());
		}

	}

};

struct secondCamera : Component {
private:
	void on_tick() {
		if (get_keyboard()->isKeyDown(KEY_RIGHT)) {
			get_core()->set_current_cam(get_entity()->get_component<Camera>());
		}
	}
};

struct Child : Component {

	void on_initialize() {
		printf("Child::initialize\n");
	}

	void on_destroy() {
		printf("Child::destroy\n");
	}

private:


	void on_tick() {
		
	}

};


struct collectable : Component
{
	void on_initialize() {
		get_entity()->get_component<BoxCollider>()->set_trigger(true);
			std::cout << "collectable initialized" << std::endl;
	}
	void on_tick() {
		bool pickup = get_entity()->get_component<BoxCollider>()->get_isColliding();
		if (pickup)
		{
			get_entity()->destroy();
		}
	}
};

struct itemSpawner : Component
{
	void on_initialize() {
		std::cout << "itemSpawner initialized" << std::endl;
	}

	void on_tick() {
		spawnTime -= get_core()->DeltaTime();
		//std::cout << spawnTime << std::endl;
		if (spawnTime <= 0)
		{
			std::cout << "Spawning item" << std::endl;
			spawnTime = 0.00002f;
			std::shared_ptr<Entity> item = get_core()->add_entity();
			std::shared_ptr<ModelRenderer> r = item->add_component<ModelRenderer>();
			std::shared_ptr<BoxCollider> collider = item->add_component<BoxCollider>();
			collider->set_trigger(true);
			std::shared_ptr<RigidBody> rigidBody = item->add_component<RigidBody>();
			std::shared_ptr<collectable> itemComponent = item->add_component<collectable>();
			std::shared_ptr<Texture> t = get_core()->get_resources()->load<Texture>("textures/CookedChickenBreastAlbedo");
			std::shared_ptr<Model> m = get_core()->get_resources()->load<Model>("models/CookedChickenBreast");
			r->set_texture(t);
			r->set_model(m);
			item->set_position(vec3(0, 0, -20));
		}
	}

private:
	float spawnTime = 0.00002f;
};

void initialiseGame(std::shared_ptr <Core> core) {

	std::shared_ptr<Resources> resources = core->get_resources();
	std::shared_ptr<Texture> tex = resources->load<Texture>("textures/CookedChickenBreastAlbedo");
	std::shared_ptr<Audio> sound = resources->load<Audio>("audio/blue-blood-ogg-67848");
	std::shared_ptr<Model> map = resources->load<Model>("models/re_hall_baked");
	std::shared_ptr<Texture> maptex = resources->load<Texture>("textures/re_hall_diffuse");

	std::shared_ptr<Entity> entity = core->add_entity();
	entity->add_component<Player>();
	std::shared_ptr<SoundSource> Ssource = entity->add_component<SoundSource>();
	std::shared_ptr<BoxCollider> collider = entity->add_component<BoxCollider>();
	std::shared_ptr<RigidBody> rigidBody = entity->add_component<RigidBody>();
	std::shared_ptr<Camera> camera = entity->add_component<Camera>();

	

	Ssource->set_audio(sound);
	Ssource->set_looping(true);	

	

	entity->set_position(vec3(0, 0, 5));

	std::shared_ptr<Entity> itemSpawnerEntity = core->add_entity();
	itemSpawnerEntity->add_component<itemSpawner>();


	//second player
	std::shared_ptr<Entity> entity2 = core->add_entity();
	std::shared_ptr<ModelRenderer> r2 = entity2->add_component<ModelRenderer>();
	std::shared_ptr<AnimationTrack> AnimTrack1 = entity2->add_component<AnimationTrack>();
	std::shared_ptr<AnimationController> AnimController1 = entity2->add_component<AnimationController>();
	
	AnimTrack1->create("models/guppy40001", 6);
	AnimController1->set_track(AnimTrack1);
	AnimController1->set_duration(2.5f);
	r2->set_texture(tex);
	r2->set_model(resources->load<Model>("models/guppy40001"));

	entity2->add_component<Child>();
	

	entity2->set_position(vec3(2, -2.8, -10));;

	entity2->get_transform()->set_parent(entity);

	std::shared_ptr<Entity> entity3 = core->add_entity();
	std::shared_ptr<Camera> camera2 = entity3->add_component<Camera>();
	entity3->set_position(vec3(10, 0, -10));
	entity3->get_transform()->set_rotation(vec3(0, 90, 0));
	entity3->add_component<secondCamera>();

	std::shared_ptr<Entity> map1 = core->add_entity();
	std::shared_ptr<ModelRenderer> r3 = map1->add_component<ModelRenderer>();
	r3->set_texture(maptex);
	r3->set_model(map);
	std::shared_ptr<MeshCollider> mapcollider = map1->add_component<MeshCollider>();
}






