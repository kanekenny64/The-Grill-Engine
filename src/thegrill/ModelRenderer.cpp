#include <renderer/Shader.h>
#include <renderer/Mesh.h>
#include "ModelRenderer.h"
#include <glm/ext.hpp>
#include "Texture.h"
#include "Model.h"
#include "Entity.h"
#include "Transform.h"
#include "Core.h"
#include "Camera.h"
#include "Window.h"

namespace thegrill {
	ModelRenderer::ModelRenderer():
		m_shader(renderer::Shader(false))
	{}

	void ModelRenderer::set_texture(std::shared_ptr<Texture> _tex)
	{
		m_tex = _tex->get_texture();
	}
	void ModelRenderer::set_model(std::shared_ptr<Model> _model)
	{
		m_model = _model->get_model();
	}
	void ModelRenderer::on_render()
	{

		// Check if m_tex and m_model are valid
		if (!m_tex || !m_model)
		{
			throw std::runtime_error("ModelRenderer Error: Failed to find valid Texture or Model");
			return;
		}

		//Set uniforms for the shader
		int height, width;
		get_entity()->get_core()->window()->get_dimensions(width, height);
		glm::mat4 projection = glm::perspective(glm::radians(45.0f), float(width) / float(height), 0.1f, 100.f);
		m_shader.setUniform("u_Projection", projection);

		
		m_shader.setUniform("u_Model", get_entity()->get_transform()->get_model());

		glm::vec3 camRot = get_core()->current_camera()->get_transform()->get_rotation();

		glm::mat4 view(1);
		view = glm::translate(view, get_core()->current_camera()->get_transform()->get_position());
		view = glm::rotate(view, camRot.x, glm::vec3(1, 0, 0));
		view = glm::rotate(view, camRot.y, glm::vec3(0, 1, 0));
		view = glm::rotate(view, camRot.z, glm::vec3(0, 0, 1));
		m_shader.setUniform("u_View", glm::inverse(view));

		m_shader.setUniform("u_Texture", m_tex, 1);

		m_shader.draw(m_shader.programId, m_model->vao_id(), m_model->vertex_count(), true);
	}
}