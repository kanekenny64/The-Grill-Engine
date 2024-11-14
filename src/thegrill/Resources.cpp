#include "Resources.h"

namespace thegrill {
	std::vector<std::shared_ptr<Resource> > Resources::getResources()
	{
		return m_resources;
	}
}