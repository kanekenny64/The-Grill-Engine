 #include <memory>
#include <vector>
#include <glm/glm.hpp>


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

			m_components.push_back(rtn);

			rtn->on_initialize();

			

			return rtn;
		}

		template <typename T>
		std::shared_ptr<T> get_component() const
		{
			for (auto& comp : m_components)
			{
				std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(comp);

				if (rtn)
				{
					return rtn;
				}
			}

			throw std::runtime_error("Failed to find specified component");
		}

		template <typename T>
		void get_components(std::vector<std::shared_ptr<T> >& _components) const
		{
			_components.clear();

			for (auto& comp : m_components)
			{
				std::shared_ptr<T> cast = std::dynamic_pointer_cast<T>(comp);

				if (cast)
				{
					_components.push_back(cast);
				}
			}
		}

		std::shared_ptr<Transform> get_transform() const;

		void set_position(glm::vec3 _position);

		std::shared_ptr<Core> get_core() const;

		void destroy();

		~Entity();
private:
	friend struct thegrill::Core;

		std::weak_ptr<Core> m_core;
		std::weak_ptr<Entity> m_self;
		std::weak_ptr<Transform> m_transform;

		std::vector<std::shared_ptr<Component> > m_components;

		void OnTick();
		void OnRender();
		void OnGUI();

		bool alive = true;
	};

}