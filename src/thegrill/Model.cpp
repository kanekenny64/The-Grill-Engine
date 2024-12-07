#include "Model.h"

namespace thegrill {
	std::shared_ptr<renderer::Model> Model::getModel()
	{
		return m_raw;
	}

	void Model::onLoad() {
		m_raw = std::make_shared<renderer::Model>(getPath() + ".obj");
	}

}