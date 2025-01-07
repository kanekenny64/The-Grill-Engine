#include "Mouse.h"

namespace thegrill {

	void Mouse::update()
	{
		pressedButtons.clear();
		releasedButtons.clear();
	}

	bool Mouse::isButton(int button)
	{
		for (int i = 0; i < buttons.size(); i++)
		{
			if (buttons[i] == button)
			{
				return true;
			}
		}
		return false;
	}

	bool Mouse::isButtonDown(int button)
	{
		for (int i = 0; i < pressedButtons.size(); i++)
		{
			if (pressedButtons[i] == button)
			{
				return true;
			}
		}
		return false;
	}

	bool Mouse::isButtonReleased(int button)
	{
		for (int i = 0; i < releasedButtons.size(); i++)
		{
			if (releasedButtons[i] == button)
			{
				return true;
			}
		}
		return false;
	}

	void Mouse::ButtonRelease(int button)
	{
		for (int i = 0; i < buttons.size(); i++)
		{
			if (buttons[i] == button)
			{
				buttons.erase(buttons.begin() + i);
				break;
			}
		}
	}
}