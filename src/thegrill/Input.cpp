#include "Input.h"
#include "Keyboard.h"
#include "Mouse.h"
#include <iostream>

namespace thegrill
{
	Input::Input()
	{
		m_keyboard = std::make_shared<Keyboard>();
		m_mouse = std::make_shared<Mouse>();
	}
	bool Input::Update()
	{
		m_keyboard->update();
		m_mouse->update();

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

			else if (event.type == SDL_MOUSEMOTION)
			{
				m_mouse->mouseX = event.motion.x;
				m_mouse->mouseY = event.motion.y;
			}
						
			else if (event.type == SDL_MOUSEBUTTONDOWN) {
				
				m_mouse->buttons.push_back(event.button.button);
				m_mouse->pressedButtons.push_back(event.button.button);
			}
			else if (event.type == SDL_MOUSEBUTTONUP) {
				m_mouse->releasedButtons.push_back(event.button.button);
			}
		}

	}

	std::shared_ptr<Keyboard> Input::keyboard() const
	{
		return m_keyboard;
	}

	std::shared_ptr<Mouse> Input::mouse() const
	{
		return m_mouse;
	}
}