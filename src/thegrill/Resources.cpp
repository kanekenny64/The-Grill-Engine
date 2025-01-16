#include "Resources.h"
#include "Core.h"

namespace thegrill {
	Resources::Resources(std::shared_ptr<Core> _core)
	{
		m_core = _core;
	}
	std::vector<std::shared_ptr<Resource> > Resources::getResources()
	{
		return m_resources;
	}
	void Resources::Update()
	{
		for (size_t i = 0; i < m_resources.size(); ++i)
		{
			//Check if resource is no longer in use
			//Check with timer if it isnt being used so it's not unloaded unnecessarily
			if (m_resources.at(i).use_count() == 1) {
				m_resources.at(i)->m_timeout -= m_core.lock()->DeltaTime();
				if (m_resources.at(i)->m_timeout <= 0)
				{
					m_resources.at(i)->unload();
				}
				
			}
			else
			{
				m_resources.at(i)->m_timeout = 0.00010;
			}
		}
	}
}