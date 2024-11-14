#include "Resource.h"
#include "renderer/Renderer.h"

namespace thegrill {
	struct Texture : Resource
	{

		void onLoad(const std::string& _path);
	private:
		std::shared_ptr<renderer::Texture>  m_raw;
	};

	void Texture::onLoad(const std::string& _path) {
		m_raw = std::make_shared<renderer::Texture>(_path);
	}

}
