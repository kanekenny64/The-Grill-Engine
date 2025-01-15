#include <memory>


#define KEY_W SDLK_w
#define KEY_A SDLK_a
#define KEY_S SDLK_s
#define KEY_D SDLK_d

namespace thegrill {
	struct Keyboard;
	struct Mouse;

	struct Input
	{
		Input();

		bool Update();

		std::shared_ptr<Keyboard> keyboard() const;
		std::shared_ptr<Mouse> mouse() const;

	private:
		friend struct Core;
		std::shared_ptr<Keyboard> m_keyboard;
		std::shared_ptr<Mouse> m_mouse;
	};
}