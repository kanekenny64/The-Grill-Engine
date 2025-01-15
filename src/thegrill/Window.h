#include <SDL2/SDL.h>

namespace thegrill {

	struct Core;

	struct Window
	{
		Window();
		~Window();

		void Update();

		void get_dimensions(int& _w, int& _h);

	private:
		friend struct thegrill::Core;
			SDL_Window* m_raw;
			SDL_GLContext m_context;

			int m_width;
			int m_height;
	};
}