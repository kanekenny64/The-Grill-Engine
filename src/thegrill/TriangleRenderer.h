#include "Component.h"
#include "NonCopyable.h"
#include "renderer/Renderer.h"
#include <memory>




namespace thegrill {

	struct Shader;
	struct Mesh;
	struct Model;
	

	struct TriangleRenderer :public Component {
	public:
		TriangleRenderer();
		void OnInit();

		void set_texture(std::shared_ptr<renderer::Texture> _tex);

	private:
		

		void on_render();

		renderer::Model m_model;
		renderer::Shader m_shader;
		std::shared_ptr<renderer::Texture> m_tex;
		
	};

}