#include <memory>
#include <string>
#include <vector>
#include "Resource.h"
#include <iostream>

namespace thegrill {
	struct Resources
	{
		template <typename T>
		std::shared_ptr<T> load(const std::string& _path)
		{
			// Search for previously loaded resource
			for (size_t i = 0; i < m_resources.size(); ++i)
			{
				// Return it if found
				if (m_resources.at(i)->getPath() == "../" + _path)
				{
					return std::dynamic_pointer_cast<T>(m_resources.at(i));
				}
			}
			// Create new instance, construct it and add to cache
			//std::cout << "Loading: " << _path << std::endl;
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->m_path = "../" + _path;
			rtn->load();
			m_resources.push_back(rtn);
			return rtn;
		}

		std::vector<std::shared_ptr<Resource> > getResources();

	private:
		std::vector<std::shared_ptr<Resource> > m_resources;
	};


}