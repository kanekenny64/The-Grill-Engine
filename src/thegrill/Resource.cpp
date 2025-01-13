#include "Resource.h"

namespace thegrill {
	std::string Resource::getPath() const {
		return m_path;
	}

	void Resource::load() {
		onLoad();
	}

	void Resource::unload() {
		onUnload();
	}
}