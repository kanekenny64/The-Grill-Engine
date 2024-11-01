#include <renderer/Shader.h>
#include <renderer/Mesh.h>
#include "TriangleRenderer.h"


namespace thegrill {
	TriangleRenderer::TriangleRenderer():
		m_shader(renderer::Shader(false)), m_mesh(renderer::Mesh())
	{}
}