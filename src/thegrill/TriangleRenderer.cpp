#include <renderer/Shader.h>
#include <renderer/Mesh.h>
#include "TriangleRenderer.h"
#include <iostream>
#include <glm/ext.hpp>


namespace thegrill {
	TriangleRenderer::TriangleRenderer():
		m_shader(renderer::Shader(false)), m_model(renderer::Model("../models/CookedChickenBreast.obj"))
	{}
	void TriangleRenderer::on_render()
	{
		//std::cout << "Drawing" << std::endl;
		glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 10.f);
		m_shader.setUniform("u_Projection", projection);

		glm::mat4 model;
		model = glm::translate(model, glm::vec3(0, 0, -5));
		m_shader.setUniform("u_Model", model);

		glm::mat4 view(0);
		m_shader.setUniform("u_View", view);
		m_shader.draw(m_shader.programId, m_model.vao_id(), m_model.vertex_count(), true);
	}
}