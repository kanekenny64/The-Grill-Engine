#include "GUI.h"
#include <glm/ext.hpp>
#include "renderer/Texture.h"
#include "Core.h"
#include "Input.h"
#include "Mouse.h"
#include "Window.h"
#include "Texture.h"

namespace thegrill {

	GUI::GUI(std::shared_ptr<Core> _core) : m_core(_core)
	{
		mShader = std::make_shared<renderer::Shader>(true);
		mRect = std::make_shared<renderer::Mesh>();
		
		//Populate the mesh with a rectangle
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

	void GUI::image(std::shared_ptr<Texture> _tex, float _x, float _y, float _w, float _h)
	{
		int height, width;
		m_core.lock()->window()->get_dimensions(width, height);

		glm::mat4 projection = glm::ortho(0.0f, float(width), 0.0f, float(height), 0.0f, 1.0f);
		mShader->setUniform("u_Projection", projection);

		glm::mat4 model(1.0f);
		model = glm::translate(model, glm::vec3(_x, _y, 0));
		model = glm::scale(model, glm::vec3(_w, _h, 1));
		mShader->setUniform("u_Model", model);

		glm::mat4 view(1);

		mShader->setUniform("in_View", view);

		mShader->setUniform("in_Texture", _tex->get_texture(), 1);

		mShader->draw(mShader->programId, mRect->vao_id(), mRect->vertex_count(), false);

	}

	//Return 0 for no click, 1 for hover, 2 for click
	int GUI::button(std::shared_ptr<Texture> _tex, float _x, float _y, float _w, float _h)
	{
		//Get mouse position
		glm::vec2 mp = glm::vec2(m_core.lock()->input()->mouse()->getXPos(), m_core.lock()->input()->mouse()->getYPos());


		//Draw the button
		int height, width;
		m_core.lock()->window()->get_dimensions(width, height);

		glm::mat4 projection = glm::ortho(0.0f, float(width), 0.0f, float(height), 0.0f, 1.0f);
		mShader->setUniform("u_Projection", projection);

		glm::mat4 model(1.0f);
		model = glm::translate(model, glm::vec3(_x, _y, 0));
		model = glm::scale(model, glm::vec3(_w, _h, 1));
		mShader->setUniform("u_Model", model);

		glm::mat4 view(1);

		mShader->setUniform("in_View", view);

		mShader->setUniform("in_Texture", _tex->get_texture(), 1);

		mShader->draw(mShader->programId, mRect->vao_id(), mRect->vertex_count(), false);

		//Test for button click or hover

		//invert y axis
		mp.y = height - mp.y;

		if (mp.x > _x && mp.x < _x + _w &&
			mp.y > _y && mp.y < _y + _h)
		{
			
			if (m_core.lock()->input()->mouse()->isButtonDown(SDL_BUTTON_LEFT))
			{
				return 2;
			}
			else
			{
				return 1;
			}
		}
		
		return 0;
	}

} 