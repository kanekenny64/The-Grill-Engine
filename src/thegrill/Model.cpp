#include "Model.h"
#include <iostream>

namespace thegrill {
	std::shared_ptr<renderer::Model> Model::get_model()
	{
		return m_raw;
	}

    void Model::onLoad() {
		//Try to load model, if it fails, load default model
        try {
            m_raw = std::make_shared<renderer::Model>(getPath() + ".obj");
            if (!m_raw) {
                throw std::runtime_error("Failed to load model: " + getPath() + ".obj");
            }
        }
        catch (const std::exception& e) {
            std::cout << "Error loading model at:" << getPath() << std::endl;
            m_raw = std::make_shared<renderer::Model>("../assets/models/default.obj");
        }
    }

	void Model::onUnload() {
		m_raw->unload();
	}

}