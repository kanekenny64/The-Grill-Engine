#include "Input.h"
#include "Keyboard.h"

namespace thegrill
{
	Input::Input()
	{
		m_keyboard = std::make_shared<Keyboard>();
	}
	void Input::Update()
	{
		m_keyboard->update();
	}
	std::shared_ptr<Keyboard> Input::keyboard() const
	{
		return m_keyboard;
	}
}
