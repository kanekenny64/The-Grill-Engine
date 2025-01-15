#include <vector>

namespace thegrill {
	struct Input;

	struct Keyboard {

	public:
		
		void update();
		
		bool isKey(int key);
		bool isKeyDown(int key);
		bool isKeyReleased(int key);

		void KeyRelease(int key);


	private:
		friend struct thegrill::Input;
		std::vector<int> keys;
		std::vector<int> pressedKeys;
		std::vector<int> releasedKeys;
	};
}