#include "Core.h"
#include "Entity.h"
#include "Transform.h"

#include "Timer.h"

#include "Window.h"
#include "Resources.h"
#include "Input.h"
#include "SoundSystem.h"
#include "GUI.h"

#include "Camera.h"


namespace thegrill {

	/**
	 * @brief Initializes the core engine instance.
	 * @return Shared pointer to the initialised instance of core.
	 */

	std::shared_ptr<Core> Core::initialize()
	{
		
		//Instantiate core systems
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->m_window = std::make_shared<Window>();
		rtn->m_resources = std::make_shared<Resources>(rtn);
		rtn->m_input = std::make_shared<Input>();
		rtn->m_sound_system = std::make_shared<SoundSystem>();
		rtn->m_gui = std::make_shared<GUI>(rtn);
		 
		rtn->m_self = rtn;
		
		return rtn;
	}

	std::shared_ptr<Entity> Core::add_entity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
		rtn->m_core = m_self;
		rtn->m_self = rtn;
		
		
		//Transform component is added to all entities by default
		rtn->m_transform = rtn->add_component<Transform>();

		m_entities.push_back(rtn);
		return rtn;
	}

	std::shared_ptr<Window> Core::window() const
	{
		return m_window;
	}

	std::shared_ptr<SoundSystem> Core::sound_system()
	{
		return m_sound_system;
	}

	std::shared_ptr<Resources> Core::get_resources()
	{
		return m_resources;
	}

	std::shared_ptr<Input> Core::input()
	{
		return m_input;
	}

	std::shared_ptr<Camera> Core::current_camera()
	{
		return m_current_cam;
	}

	std::vector<std::shared_ptr<Camera>> Core::cameras()
	{
		return m_cameras;
	}

	std::shared_ptr<GUI> Core::gui()
	{
		return m_gui;
	}

	/**
	* @brief Sets the current active camera.
	* @param _cam A shared pointer to the camera to set as the current active camera.
	*/
	void Core::set_current_cam(std::shared_ptr<Camera> _cam)
	{
		if (!_cam)
		{
			throw std::runtime_error("No camera found");
		}
		m_current_cam = _cam;
	}

	void Core::add_camera(std::shared_ptr<Camera> _cam)
	{
		m_cameras.push_back(_cam);
		validCam = true;
	}

	void Core::remove_camera(std::shared_ptr<Camera> _cam)
	{
		for (size_t i = 0; i < m_cameras.size(); i++)
		{
			if (m_cameras.at(i) == _cam)
			{
				m_cameras.erase(m_cameras.begin() + i);
				if (m_cameras.empty())
				{
					m_current_cam.reset();
				}
				break;
			}
		}
	}

	
	float Core::DeltaTime()
	{
		return deltaTime;
	}

	void Core::DestroyAllEntities()
	{
		for (int i = 0; i < m_entities.size(); i++)
		{
			m_entities.at(i)->destroy();
		}

	}

	void Core::Quit()
	{
		quit = true;
	}

	void Core::run()
	{
		
		Timer timer;

		while (!quit) {

			//calculate delta time
			deltaTime = timer.elapsed();

			//update all entities
			for (size_t i = 0; i < m_entities.size(); i++)
			{
				m_entities.at(i)->OnTick();
			}

			//remove dead entities
			for (size_t i = 0; i < m_entities.size(); i++)
			{
				if (m_entities.at(i)->alive == false)
				{
					m_entities.erase(m_entities.begin() + i);
					i--;
				}
			}

			

			//clear keyboard vectors
			quit = m_input->Update();

			//update window
			window()->Update();


			//Before rendering, check for a valid camera component
			if (m_cameras.empty())
			{
				std::shared_ptr<Entity> entity = add_entity();
				std::shared_ptr<Camera> camera = entity->add_component<Camera>();
				m_current_cam = camera;
			}
			else
			{
				if (!m_current_cam)
				{
					for (int i = 0; i < m_cameras.size(); i++)
					{
						
						m_current_cam = m_cameras.at(i);
						break;
					}
				}
				
			}


			glClearColor(0.1f, 0.1f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glEnable(GL_DEPTH_TEST);
			glEnable(GL_CULL_FACE);
			

			//Call render functions for all entities
			for (size_t i = 0; i < m_entities.size(); i++)
			{
				m_entities.at(i)->OnRender();
			}

			//Gui functions called after to ensure they are rendered on top
			for (size_t i = 0; i < m_entities.size(); i++)
			{
				m_entities.at(i)->OnGUI();
			}

			m_resources->Update();

			SDL_GL_SwapWindow(m_window->m_raw);

			timer.reset();
		}
	}

}