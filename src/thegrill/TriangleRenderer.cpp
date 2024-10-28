#include "Mesh.h"
#include "TriangleRenderer.h"


namespace thegrill {
	TriangleRenderer::TriangleRenderer(Mesh _mesh)
	{
		vboID = _mesh.vao_id();
	}
}