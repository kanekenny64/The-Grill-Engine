#include "Model.h"


namespace thegrill {
	std::shared_ptr<renderer::Model> Model::get_model()
	{
		return m_raw;
	}

	void Model::onLoad() {
		m_raw = std::make_shared<renderer::Model>(getPath() + ".obj");
	}

	void Model::onUnload() {
		m_raw->unload();
	}

}