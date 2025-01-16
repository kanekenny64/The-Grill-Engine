#include "Texture.h"
#include <iostream>

namespace thegrill
{
	std::shared_ptr<renderer::Texture> Texture::get_texture()
	{
		m_timeout = 10;
		return m_texture;
	}

	void Texture::onLoad() {
		//Try to load the texture, if it fails, load the default texture
		try {
			m_texture = std::make_shared<renderer::Texture>(getPath() + ".png");
			if (!m_texture) {
				throw std::runtime_error("Failed to load texture: " + getPath() + ".png");
			}
		}
		catch (const std::exception& e) {
			std::cout << "Error loading texture at:" << getPath() << std::endl;
			m_texture = std::make_shared<renderer::Texture>("../assets/textures/default.png");
		}
	}

	void Texture::onUnload() {
		
		m_texture->unload();
	}
}