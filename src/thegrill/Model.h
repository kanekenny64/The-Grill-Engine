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

	inline std::shared_ptr<renderer::Model> Model::getModel()
	{
		return m_raw;
	}

	void Model::onLoad() {
		m_raw = std::make_shared<renderer::Model>(getPath());
	}

}
