#include "Component.h"
#include <GL/glew.h>
#include <GL/glew.h>

namespace thegrill {

	struct Mesh{};
	struct Model{};

	struct triangleRenderer : Component {

	protected:
		triangleRenderer(Mesh _mesh);
		triangleRenderer(Model _model);

	public:
		triangleRenderer(const triangleRenderer&) = delete;
		triangleRenderer& operator=(const triangleRenderer&) = delete;
		void OnInit();

	private:
		GLuint programID;
		GLuint vboID;
		GLuint vbaID;

		void OnDisplay();

	};

}