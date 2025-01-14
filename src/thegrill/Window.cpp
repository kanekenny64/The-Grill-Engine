#include "Window.h"
#include <stdexcept>
#include <GL/glew.h>

namespace thegrill {
	Window::Window()
	{
		m_width = 800;
		m_height = 600;

		m_raw = SDL_CreateWindow("Triangle",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			m_width, m_height,
			SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);


		if (!m_raw) {
			throw std::runtime_error("Failed to create window");
		}

		m_context = SDL_GL_CreateContext(m_raw);

		if (glewInit() != GLEW_OK) {
			throw std::exception();
		}

		
	}

	Window::~Window()
	{
		SDL_GL_DeleteContext(m_context);
		SDL_DestroyWindow(m_raw);
		SDL_Quit;
	}

	void Window::Update()
	{
		
		glViewport(0, 0, m_width, m_height);
	}

	void Window::getDimensions(int& _w, int& _h)
	{
		SDL_GetWindowSize(m_raw, &m_width, &m_height);
		_w = m_width;
		_h = m_height;
	}

}
