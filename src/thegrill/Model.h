#include "Resource.h"
#include "renderer/Renderer.h"

namespace thegrill {
	struct Model : Resource
	{


	private:
		std::shared_ptr<renderer::Model>  m_raw;
	};
}
