#include <vector>

namespace thegrill
{
	struct Input;

	struct Mouse {

		public:
		void update();

		bool isButton(int button);
		bool isButtonDown(int button);
		bool isButtonReleased(int button);

		void ButtonRelease(int button);

		int getXPos() { return mouseX; }
		int getYPos() { return mouseY; }

		private:
			friend struct thegrill::Input;
			std::vector<int> buttons;
			std::vector<int> pressedButtons;
			std::vector<int> releasedButtons;

			int mouseX;
			int mouseY;
	};
}