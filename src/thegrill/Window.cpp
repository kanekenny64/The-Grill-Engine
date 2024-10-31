#include "Window.h"
#include <stdexcept>
#include <GL/glew.h>

namespace thegrill {
	Window::Window()
	{
		int winW = 800;
		int winH = 600;

		m_raw = SDL_CreateWindow("Triangle",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			winW, winH,
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

}
