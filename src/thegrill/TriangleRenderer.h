#include "Component.h"
#include "NonCopyable.h"




namespace thegrill {

	struct Shader;
	struct Mesh;
	struct Model;
	

	struct TriangleRenderer : Component, NonCopyable {
	public:
		TriangleRenderer();
		void OnInit();

	private:
		TriangleRenderer(const TriangleRenderer&);
		TriangleRenderer& operator=(const TriangleRenderer&);
		

		void OnDisplay();

		renderer::Mesh m_mesh;
		renderer::Shader m_shader;
		
	};

}