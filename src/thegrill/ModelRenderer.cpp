#include <renderer/Shader.h>
#include <renderer/Mesh.h>
#include "ModelRenderer.h"
#include <iostream>
#include <glm/ext.hpp>

#include "Entity.h"
#include "Transform.h"
#include "Core.h"
#include "Camera.h"
#include "Window.h"

namespace thegrill {
	ModelRenderer::ModelRenderer():
		m_shader(renderer::Shader(false))
	{}
	void ModelRenderer::set_texture(std::shared_ptr<renderer::Texture> _tex)
	{
		m_tex = _tex;
	}
	void ModelRenderer::set_model(std::shared_ptr<renderer::Model> _model)
	{
		m_model = _model;
	}
	void ModelRenderer::on_render()
	{
		int height, width;
		get_entity()->get_core()->window()->getDimensions(width, height);
		//printf("Drawing\n");
		glm::mat4 projection = glm::perspective(glm::radians(45.0f), float(width) / float(height), 0.1f, 100.f);
		m_shader.setUniform("u_Projection", projection);

		
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