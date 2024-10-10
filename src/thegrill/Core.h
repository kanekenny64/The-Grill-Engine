#include <iostream>
#include <memory>
#include <vector>

namespace thegrill
{
	struct Entity;

	struct Core
	{
		static std::shared_ptr<Core> initialize();

		void run();

		std::shared_ptr<Entity> add_entity();
	private:
		std::vector<std::shared_ptr<Entity> > m_entities;
		std::weak_ptr<Core> m_self;

	};
}