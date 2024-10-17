#include "Core.h"
#include "Entity.h"
#include "Transform.h"
#include <iostream>

namespace thegrill {


	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->m_self = rtn;

		return rtn;
	}

	std::shared_ptr<Entity> Core::add_entity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
		rtn->m_core = m_self;
		//std::cout << rtn->m_core.lock().get() << std::endl;
		
		rtn->add_component<Transform>();

		m_entities.push_back(rtn);
		return rtn;
	}

	void Core::run()
	{
		for (size_t i = 0; i < 25; i++)
		{
			for (size_t i = 0; i < m_entities.size(); i++)
			{
				m_entities.at(i)->tick();
			}
		}
	}

}