#include "Keyboard.h"
#include <iostream>

namespace thegrill {

	void Keyboard::update()
	{
		pressedKeys.clear();
		releasedKeys.clear();
		
	}

	bool Keyboard::isKeyPressed(int key)
	{
		return keys[key] && pressedKeys[key];
	}

	bool Keyboard::isKeyReleased(int key)
	{
		return keys[key] && releasedKeys[key];
	}

	bool Keyboard::isKeyHeld(int key)
	{
		return keys[key];
	}
	void Keyboard::KeyRelease(int key)
	{
		keys[key] = false;
		releasedKeys[key] = true;
	}
}