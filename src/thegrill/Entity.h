#pragma once

#include <memory>
#include <vector>
#include <glm/glm.hpp>


namespace thegrill {

	struct Core;
	struct Component;
	struct Transform;

	/**
	 * @brief The Entity class represents an object in the game world.
	 *
	 * Entities can have multiple components attached to them and are stored within core.
	 */
	struct Entity {

		/**
		 * @brief Adds a new component of type T to the entity.
		 * @tparam T Type of component to add.
		 * @return A shared pointer to the newly added component.
		 */
		template <typename T>
		std::shared_ptr<T> add_component() 
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();

			rtn->m_entity = m_self;

			m_components.push_back(rtn);

			rtn->on_initialize();

			

			return rtn;
		}

		/**
		 * @brief Gets a component of type T from the entity.
		 * @tparam T Type of component to get.
		 * @return A shared pointer to the component.
		 * @throws std::runtime_error if the component is not found.
		 */
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

		/**
		 * @brief Gets all components of type T from the entity.
		 * @tparam T The type of components to get.
		 * @param _components A vector to store the found components.
		 * @throws std::runtime_error if the component is not found.
		 */

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

			if (_components.empty())
			{
				throw std::runtime_error("Failed to find specified component");
			}
		}

		std::shared_ptr<Transform> get_transform() const;

		void set_position(glm::vec3 _position);

		std::shared_ptr<Core> get_core() const;

		void destroy();

		~Entity();
private:
	friend struct thegrill::Core;

		std::weak_ptr<Core> m_core; ///< Weak pointer to the core engine instance.
		std::weak_ptr<Entity> m_self; ///< Weak pointer to this entity.
		std::weak_ptr<Transform> m_transform; ///< Weak pointer to the transform component.

		std::vector<std::shared_ptr<Component> > m_components; ///< List of components attached to the entity.

		void OnTick();
		void OnRender();
		void OnGUI();

		bool alive = true; ///< Indicates whether the entity is alive.
	};

}