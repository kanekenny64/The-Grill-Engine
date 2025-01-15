#include <iostream>
#include <memory>
#include <vector>

namespace thegrill
{
	struct Entity;
	struct Window;
	struct Resources;
	struct Input;
	struct SoundSystem;
	struct Camera;
	struct GUI;

	/**
	 * @brief The Core class is the main engine class that manages the game loop and core systems.
	 */
	struct Core
	{
		/**
		 * @brief Initializes the core engine instance.
		 * @return A shared pointer to the initialized core engine instance.
		 */
		static std::shared_ptr<Core> initialize();
		
		/**
		 * @brief Runs the main game loop.
		 */
		void run();

		
		std::shared_ptr<Entity> add_entity();
		std::shared_ptr<Window> window() const;
		std::shared_ptr<SoundSystem> sound_system();
		std::shared_ptr<Resources> get_resources();
		std::shared_ptr<Input> input();
		std::shared_ptr<Camera> current_camera();
		std::shared_ptr<GUI> gui();

		void set_current_cam(std::shared_ptr<Camera> _cam);

		float DeltaTime();

		/**
		 * @brief Finds all components of a given type.
		 * @tparam T The type of component to find.
		 * @param _out A vector to store found components.
		 */
		template <typename T>
		void find(std::vector<std::shared_ptr<T> >& _out)
		{
			_out.clear();

			// Go through each Entity in Core.
			for (size_t ei = 0; ei < m_entities.size(); ++ei)
			{
				std::shared_ptr<Entity> e = m_entities.at(ei);
				// Go through each Component in Entity.
				for (size_t ci = 0; ci < e->m_components.size(); ++ci)
				{
					std::shared_ptr<Component> c = e->m_components.at(ci);
					// Try to dynamic cast the Component to a T.
					std::shared_ptr<T> t = std::dynamic_pointer_cast<T>(c);
					// If succeeds then add it to the output array.
					if (t)
					{
						_out.push_back(t);
					}
				}
			}
		}

		 
	private:
		std::shared_ptr<Window> m_window;
		std::shared_ptr<SoundSystem> m_sound_system;
		std::shared_ptr<Input> m_input;
		std::shared_ptr<Resources> m_resources;
		std::vector<std::shared_ptr<Entity> > m_entities;
		std::vector<std::shared_ptr<Camera> > m_cameras;
		std::shared_ptr<GUI> m_gui;
		std::weak_ptr<Camera> m_current_cam;
		std::weak_ptr<Core> m_self;
		
		float deltaTime = 0.0f;
	};
}