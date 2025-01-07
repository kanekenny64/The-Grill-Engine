#include "Resource.h"
#include "renderer/Renderer.h"

namespace thegrill {
	struct Model : Resource
	{
		std::shared_ptr<renderer::Model> get_model();
	private:
		void onLoad();
		std::shared_ptr<renderer::Model>  m_raw;
	};

	
}
