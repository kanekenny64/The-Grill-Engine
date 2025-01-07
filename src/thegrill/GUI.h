
#include "Renderer/Mesh.h"
#include "Renderer/Shader.h"


namespace thegrill {

	struct Core;
	struct Texture;

	struct GUI
	{
		GUI(std::shared_ptr<Core> _core);
		~GUI();

		void image(std::shared_ptr<renderer::Texture> _tex, float _x, float _y, float _w, float _h);
		int button(std::shared_ptr<renderer::Texture> _tex, float _x, float _y, float _w, float _h);

	private:
		friend struct thegrill::Core;

		std::shared_ptr<Core> m_core;
		std::shared_ptr<renderer::Shader> mShader;
		std::shared_ptr<renderer::Mesh> mRect;
	};

}