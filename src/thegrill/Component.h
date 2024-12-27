#ifndef THEGRILL_COMPONENT_H
#define	THEGRILL_COMPONENT_H


#include <memory>


namespace thegrill {
	struct Entity;
	struct Keyboard;
	struct Core;
	struct Transform;

	struct Component
	{
	public:
		virtual void on_initialize();
		virtual void on_tick();
		virtual void on_render();

		void tick();
		void render();

		std::shared_ptr<Entity> get_entity() const;
		std::shared_ptr<Keyboard> get_keyboard();
		std::shared_ptr<Core> get_core();
		std::shared_ptr<Transform> get_transform();


	private:
		friend struct thegrill::Entity;

		std::weak_ptr<Entity> m_entity;
	};
}


#endif // !THEGRILL_COMPONENT_H