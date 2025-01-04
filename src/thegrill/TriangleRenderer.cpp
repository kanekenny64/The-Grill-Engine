#include <renderer/Shader.h>
#include <renderer/Mesh.h>
#include "TriangleRenderer.h"
#include <iostream>
#include <glm/ext.hpp>

#include "Entity.h"
#include "Transform.h"
#include "Core.h"
#include "Camera.h"

namespace thegrill {
	TriangleRenderer::TriangleRenderer():
		m_shader(renderer::Shader(false))
	{}
	void TriangleRenderer::set_texture(std::shared_ptr<renderer::Texture> _tex)
	{
		m_tex = _tex;
	}
	void TriangleRenderer::set_model(std::shared_ptr<renderer::Model> _model)
	{
		m_model = _model;
	}
	void TriangleRenderer::on_render()
	{
		//glViewport(0, 0, 800.0f, 600.0f);
		//glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//printf("Drawing\n");
		glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.f);
		m_shader.setUniform("u_Projection", projection);

		//glm::mat4 model(1.0f);
		//model = glm::translate(model, glm::vec3(0, 0, -15));
		//model = glm::scale(model, glm::vec3(1.5, 1.5, 1.5) );
		//m_shader.setUniform("u_Model", model);
		m_shader.setUniform("u_Model", get_entity()->get_transform()->get_model());

		glm::mat4 view(1);
		view = glm::translate(view, get_core()->current_camera()->get_transform()->get_position());
		//view = glm::rotate(view, -40.0f, glm::vec3(1, 0, 0));
		m_shader.setUniform("u_View", glm::inverse(view));

		m_shader.setUniform("u_Texture", m_tex, 1);

		//m_shader.setUniform("in_LightPos", glm::vec3(-20, 10, -20));
		m_shader.draw(m_shader.programId, m_model->vao_id(), m_model->vertex_count(), true);


		
	}
}