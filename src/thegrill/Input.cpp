#include "Input.h"
#include "Keyboard.h"

namespace thegrill
{
	Input::Input()
	{
		m_keyboard = std::make_shared<Keyboard>();
	}
	bool Input::Update()
	{
		m_keyboard->update();

		SDL_Event event = { 0 };

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				return true;
			}

			else if (event.type == SDL_KEYDOWN) {
				m_keyboard->keys.push_back(event.key.keysym.sym);
				m_keyboard->pressedKeys.push_back(event.key.keysym.sym);
			}
			else if (event.type == SDL_KEYUP) {
				m_keyboard->releasedKeys.push_back(event.key.keysym.sym);
			}
		}

	}

	std::shared_ptr<Keyboard> Input::keyboard() const
	{
		return m_keyboard;
	}
}