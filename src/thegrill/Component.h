#ifndef THEGRILL_COMPONENT_H
#define	THEGRILL_COMPONENT_H


#include <memory>


namespace thegrill {
	struct Entity;
	struct Component
	{
	public:
		virtual void on_initialize();
		virtual void on_tick();
		virtual void on_render();

		void tick();
		void render();

		std::shared_ptr<Entity> get_entity();


	private:
		friend struct thegrill::Entity;

		std::weak_ptr<Entity> m_entity;
	};
}


#endif // !THEGRILL_COMPONENT_H