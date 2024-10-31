#include <SDL2/SDL.h>

namespace thegrill {

	struct Core;

	struct Window
	{
		Window();
		~Window();

	private:
		friend struct thegrill::Core;
			SDL_Window* m_raw;
			SDL_GLContext m_context;
	};
}