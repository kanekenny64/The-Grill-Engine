#include "Core.h"
#include "Entity.h"
#include "Transform.h"
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include "Window.h"
#include "Resources.h"



namespace thegrill {


	std::shared_ptr<Core> Core::initialize()
	{
		

		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->m_window = std::make_shared<Window>();
		rtn->m_resources = std::make_shared<Resources>();
		 
		rtn->m_self = rtn;
		
		return rtn;
	}

	std::shared_ptr<Entity> Core::add_entity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
		rtn->m_core = m_self;
		//std::cout << rtn->m_core.lock().get() << std::endl;
		
		rtn->add_component<Transform>();

		m_entities.push_back(rtn);
		return rtn;
	}

	std::shared_ptr<Window> Core::window() const
	{
		return m_window;
	}

	std::shared_ptr<Resources> Core::get_resources()
	{
		return m_resources;
	}

	void Core::run()
	{
		bool quit = false;
		while (!quit) {

			SDL_Event event = { 0 };

			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					quit = true;
				}
			}

			for (size_t i = 0; i < m_entities.size(); i++)
			{
				m_entities.at(i)->OnTick();
			}

			//SDL_GL_ClearWindow(m_window->m_raw);

			glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glEnable(GL_DEPTH_TEST);
			glEnable(GL_CULL_FACE);
			
			for (size_t i = 0; i < m_entities.size(); i++)
			{
				m_entities.at(i)->OnRender();
			}

			SDL_GL_SwapWindow(m_window->m_raw);
		}
	}

}