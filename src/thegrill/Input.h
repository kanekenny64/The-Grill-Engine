#include <memory>
#include <SDL2/SDL.h>
#include <GL/glew.h>

#define KEY_W SDLK_w
#define KEY_A SDLK_a
#define KEY_S SDLK_s
#define KEY_D SDLK_d

namespace thegrill {
	struct Keyboard;
	struct Input
	{
		Input();

		bool Update();

		std::shared_ptr<Keyboard> keyboard() const;

	private:
		friend struct Core;
		std::shared_ptr<Keyboard> m_keyboard;
	};
}