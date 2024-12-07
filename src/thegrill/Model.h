#include "Resource.h"
#include "renderer/Renderer.h"

namespace thegrill {
	struct Model : Resource
	{
		std::shared_ptr<renderer::Model> getModel();
	private:
		void onLoad();
		std::shared_ptr<renderer::Model>  m_raw;
	};

	
}
