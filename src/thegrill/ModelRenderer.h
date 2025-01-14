#include "Component.h"
#include "NonCopyable.h"
#include "renderer/Renderer.h"
#include <memory>




namespace thegrill {

	struct Shader;
	struct Mesh;
	struct Model;
	struct Texture;

	

	struct ModelRenderer :public Component {
	public:
		ModelRenderer();
		void OnInit();

		void set_texture(std::shared_ptr<Texture> _tex);
		void set_model(std::shared_ptr<Model> _model);

		std::shared_ptr<renderer::Model> get_model() { return m_model; }
	private:
		

		void on_render();

		
		renderer::Shader m_shader;
		std::shared_ptr<renderer::Texture> m_tex;
		std::shared_ptr<renderer::Model> m_model;
		
	};

}