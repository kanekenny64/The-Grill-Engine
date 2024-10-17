#include <memory>
#include <vector>

namespace thegrill {

	struct Core;
	struct Component;

	struct Entity {
		template <typename T>
		std::shared_ptr<T> add_component() 
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();

			rtn->on_initialize();

			m_components.push_back(rtn);

			return rtn;
		}

		~Entity();
private:
	friend struct thegrill::Core;

		std::weak_ptr<Core> m_core;

		std::vector<std::shared_ptr<Component> > m_components;

		void tick();
	};

}