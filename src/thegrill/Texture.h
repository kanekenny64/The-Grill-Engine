#include "Resource.h"
#include "renderer/Renderer.h"

namespace thegrill {
	struct Texture : Resource
	{
		std::shared_ptr<renderer::Texture> get_texture();

	private:
		void onLoad();
		void onUnload();
		std::shared_ptr<renderer::Texture>  m_texture;
	};

}
