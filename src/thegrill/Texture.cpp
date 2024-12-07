#include "Texture.h"

namespace thegrill
{
	std::shared_ptr<renderer::Texture> Texture::getTexture()
	{
		return m_texture;
	}

	void Texture::onLoad() {
		m_texture = std::make_shared<renderer::Texture>(getPath() + ".png");
	}
}