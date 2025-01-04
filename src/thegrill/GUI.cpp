#include "GUI.h"
#include <glm/ext.hpp>

namespace thegrill {

	GUI::GUI(std::shared_ptr<Core> _core)
	{
		m_core = _core;
		
		renderer::Face face;
		face.a.position = glm::vec3(1.0f, 0.0f, 0.0f);
		face.b.position = glm::vec3(0.0f, 1.0f, 0.0f);
		face.c.position = glm::vec3(0.0f, 0.0f, 0.0f);
		face.a.texcoord = glm::vec2(1.0f, 0.0f);
		face.b.texcoord = glm::vec2(0.0f, 1.0f);
		face.c.texcoord = glm::vec2(0.0f, 0.0f);
		mRect->add(face);

		renderer::Face face2;
		face2.a.position = glm::vec3(1.0f, 0.0f, 0.0f);
		face2.b.position = glm::vec3(1.0f, 1.0f, 0.0f);
		face2.c.position = glm::vec3(0.0f, 1.0f, 0.0f);
		face2.a.texcoord = glm::vec2(1.0f, 0.0f);
		face2.b.texcoord = glm::vec2(1.0f, 1.0f);
		face2.c.texcoord = glm::vec2(0.0f, 1.0f);
		mRect->add(face2);
	}

	GUI::~GUI()
	{
	}

	void GUI::image(std::shared_ptr<renderer::Texture> _tex, float _x, float _y, float _w, float _h)
	{
		glm::mat4 projection = glm::ortho(0.0f, 800.0f, 0.0f, 800.0f, 0.0f, 1.0f);
		mShader->setUniform("u_Projection", projection);

		glm::mat4 model(1.0f);
		model = glm::translate(model, glm::vec3(_x, _y, 0));
		model = glm::scale(model, glm::vec3(_w, _h, 1));
		mShader->setUniform("u_Model", model);

		mShader->setUniform("u_Texture", _tex, 1);

		mShader->draw(mShader->programId, mRect->vao_id(), mRect->vertex_count(), false);

	}

	bool GUI::button(std::shared_ptr<renderer::Texture> _tex, float _x, float _y, float _w, float _h)
	{
		return false;
	}

} 