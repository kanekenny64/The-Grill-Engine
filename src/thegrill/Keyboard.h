#include <vector>

namespace thegrill {


	struct Input;

	struct Keyboard {

	public:
		


		void update();
		
		bool isKeyPressed(int key);
		bool isKeyReleased(int key);
		bool isKeyHeld(int key);

		void KeyRelease(int key);


	private:
		friend struct thegrill::Input;
		std::vector<int> keys;
		std::vector<int> pressedKeys;
		std::vector<int> releasedKeys;
	};
}