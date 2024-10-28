#include "Component.h"
#include "NonCopyable.h"
#include <GL/glew.h>


namespace thegrill {

	struct Mesh;
	struct Model;

	struct TriangleRenderer : Component, NonCopyable {
	public:
		TriangleRenderer(Mesh _mesh);
		TriangleRenderer(Model _model);
		void OnInit();

	private:
		TriangleRenderer(const TriangleRenderer&);
		TriangleRenderer& operator=(const TriangleRenderer&);
		GLuint programID;
		GLuint vboID;
		GLuint vbaID;

		void OnDisplay();

	};

}