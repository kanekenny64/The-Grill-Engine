#include <memory>
#include <SDL2/SDL.h>
#include <GL/glew.h>


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