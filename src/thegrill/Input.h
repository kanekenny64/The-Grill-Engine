#include <memory>


namespace thegrill {
	struct Keyboard;
	struct Input
	{
		Input();

		void Update();

		std::shared_ptr<Keyboard> keyboard() const;

	private:
		friend struct Core;
		std::shared_ptr<Keyboard> m_keyboard;
	};
}