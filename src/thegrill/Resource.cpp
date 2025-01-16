#include "Resource.h"

namespace thegrill {
	std::string Resource::getPath() const {
		return m_path;
	}

	void Resource::load() {
		m_timeout = 0;
		onLoad();
	}

	void Resource::unload() {
		onUnload();
	}
}