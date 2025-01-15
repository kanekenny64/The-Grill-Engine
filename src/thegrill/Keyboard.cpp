#include "Keyboard.h"

namespace thegrill {

	void Keyboard::update()
	{
		pressedKeys.clear();
		releasedKeys.clear();
		
	}

	bool Keyboard::isKey(int key)
	{
		for (int i = 0; i < keys.size(); i++)
		{
			if (keys[i] == key)
			{
				return true;
			}
		}
		return false;
	}

	bool Keyboard::isKeyDown(int key)
	{
		
		for (int i = 0; i < pressedKeys.size(); i++)
		{
			if (pressedKeys[i] == key)
			{
				return true;
			}
	
		}
		return false;
	}

	bool Keyboard::isKeyReleased(int key)
	{
		for (int i = 0; i < releasedKeys.size(); i++)
		{
			if (releasedKeys[i] == key) {
				return true;
			}
		}
		return false;
	}
	void Keyboard::KeyRelease(int key)
	{
		for (int i = 0; i < keys.size(); i++)
		{
			if (keys[i] == key)
			{
				keys.erase(keys.begin() + i);
				break;
			}
		}
	}
}