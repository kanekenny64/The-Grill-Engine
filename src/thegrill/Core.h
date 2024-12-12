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


	struct Core
	{
		static std::shared_ptr<Core> initialize();
		
		void run();

		
		std::shared_ptr<Entity> add_entity();
		std::shared_ptr<Window> window() const;
		std::shared_ptr<SoundSystem> sound_system();
		std::shared_ptr<Resources> get_resources();
		std::shared_ptr<Input> input();


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
		std::weak_ptr<Core> m_self;

	};
}