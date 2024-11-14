#include "Resource.h"
#include "renderer/Renderer.h"

namespace thegrill {
	struct Texture : Resource
	{
		std::shared_ptr<renderer::Texture> getTexture();

	private:
		void onLoad();
		std::shared_ptr<renderer::Texture>  m_texture;
	};

	inline std::shared_ptr<renderer::Texture> Texture::getTexture()
	{
		return m_texture;
	}

	void Texture::onLoad() {
		m_texture = std::make_shared<renderer::Texture>(getPath());
	}

}
