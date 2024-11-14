#include <string>
#pragma once

namespace thegrill {
	struct Resources;
	struct Resource	
	{
		
		std::string getPath() const;
	private:
		friend struct thegrill::Resources;
		virtual void onLoad() = 0;
		std::string m_path;
		void load();
	};


	
}

