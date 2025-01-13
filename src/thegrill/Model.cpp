#include "Model.h"
#include <iostream>

namespace thegrill {
	std::shared_ptr<renderer::Model> Model::get_model()
	{
		return m_raw;
	}

	void Model::onLoad() {
		m_raw = std::make_shared<renderer::Model>(getPath() + ".obj");
	}

	void Model::onUnload() {
		std::cout << "Model::onUnload()" << std::endl;
		m_raw->unload();
	}

}