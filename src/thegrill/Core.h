#include <iostream>
#include <memory>
#include <vector>

namespace thegrill
{
	struct Entity;
	struct Window;
	struct Resources;


	struct Core
	{
		static std::shared_ptr<Core> initialize();
		
		void run();

		
		std::shared_ptr<Entity> add_entity();
		std::shared_ptr<Window> window() const;
		std::shared_ptr<Resources> get_resources();
		 
	private:
		std::shared_ptr<Window> m_window;
		std::shared_ptr<Resources> m_resources;
		std::vector<std::shared_ptr<Entity> > m_entities;
		std::weak_ptr<Core> m_self;

	};
}