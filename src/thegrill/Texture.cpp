#include "Texture.h"
#include <iostream>

namespace thegrill
{
	std::shared_ptr<renderer::Texture> Texture::get_texture()
	{
		return m_texture;
	}

	void Texture::onLoad() {
		m_texture = std::make_shared<renderer::Texture>(getPath() + ".png");
	}

	void Texture::onUnload() {
		std::cout << "Texture::onUnload()" << std::endl;
		m_texture->unload();
	}
}