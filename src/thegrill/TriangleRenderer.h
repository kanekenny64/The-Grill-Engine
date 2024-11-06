#include "Component.h"
#include "NonCopyable.h"
#include "renderer/Renderer.h"




namespace thegrill {

	struct Shader;
	struct Mesh;
	struct Model;
	

	struct TriangleRenderer :public Component {
	public:
		TriangleRenderer();
		void OnInit();

	private:
		

		void on_render();

		renderer::Model m_model;
		renderer::Shader m_shader;
		renderer::Texture m_tex;
		
	};

}