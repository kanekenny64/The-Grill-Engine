 #include <memory>
#include <vector>


namespace thegrill {

	struct Core;
	struct Component;
	struct Transform;

	struct Entity {

		template <typename T>
		std::shared_ptr<T> add_component() 
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();

			rtn->m_entity = m_self;

			rtn->on_initialize();

			m_components.push_back(rtn);

			return rtn;
		}

		std::shared_ptr<Transform> get_transform() const;

		~Entity();
private:
	friend struct thegrill::Core;

		std::weak_ptr<Core> m_core;
		std::weak_ptr<Entity> m_self;
		std::weak_ptr<Transform> m_transform;

		std::vector<std::shared_ptr<Component> > m_components;

		void OnTick();
		void OnRender();
	};

}