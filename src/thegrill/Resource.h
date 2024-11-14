#include <string>

namespace thegrill {
	struct Resource	
	{
		virtual void onLoad() = 0;
		std::string getPath() const;
	private:
		std::string m_path;
		void load();
	};


	std::string Resource::getPath() const {
		return m_path;
	}
}

