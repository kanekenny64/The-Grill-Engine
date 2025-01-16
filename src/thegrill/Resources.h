#include <memory>
#include <string>
#include <vector>
#include "Resource.h"

namespace thegrill {
	struct Core;
	struct Resources
	{

		Resources(std::shared_ptr<Core> _core);

		template <typename T>
		std::shared_ptr<T> load(const std::string& _path)
		{
			// Search for previously loaded resource
			for (size_t i = 0; i < m_resources.size(); ++i)
			{
				// Return it if found
				if (m_resources.at(i)->getPath() == "../assets/" + _path)
				{
					return std::dynamic_pointer_cast<T>(m_resources.at(i));
				}
			}
			// Create new instance, construct it and add to cache
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->m_path = "../assets/" + _path;
			rtn->load();
			m_resources.push_back(rtn);
			return rtn;
		}

		std::vector<std::shared_ptr<Resource> > getResources();
		

		void Update();

	private:
		std::vector<std::shared_ptr<Resource> > m_resources;
		std::weak_ptr<Core> m_core;
	};


}