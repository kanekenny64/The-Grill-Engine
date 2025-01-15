#include "Resources.h"

namespace thegrill {
	std::vector<std::shared_ptr<Resource> > Resources::getResources()
	{
		return m_resources;
	}
	void Resources::Update()
	{
		/*for (size_t i = 0; i < m_resources.size(); ++i)
		{
			if (m_resources.at(i).use_count() == 1) {
				
				m_resources.at(i)->unload();
			}
		}*/
	}
}