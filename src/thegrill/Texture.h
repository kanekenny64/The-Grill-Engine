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

}
