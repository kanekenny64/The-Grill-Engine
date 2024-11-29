#include <iostream>
#include <memory>
#include <vector>

namespace thegrill
{
	struct Entity;
	struct Window;
	struct Resources;
	struct Input;


	struct Core
	{
		static std::shared_ptr<Core> initialize();
		
		void run();

		
		std::shared_ptr<Entity> add_entity();
		std::shared_ptr<Window> window() const;
		std::shared_ptr<Resources> get_resources();
		std::shared_ptr<Input> input();
		 
	private:
		std::shared_ptr<Window> m_window;
		std::shared_ptr<Input> m_input;
		std::shared_ptr<Resources> m_resources;
		std::vector<std::shared_ptr<Entity> > m_entities;
		std::weak_ptr<Core> m_self;

	};
}