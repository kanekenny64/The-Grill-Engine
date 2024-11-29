#include <vector>

namespace thegrill {

	struct Core;

	struct Keyboard {

	public:
		


		void update();
		
		bool isKeyPressed(int key);
		bool isKeyReleased(int key);
		bool isKeyHeld(int key);


	private:
		friend struct thegrill::Core;
		std::vector<int> keys;
		std::vector<int> pressedKeys;
		std::vector<int> releasedKeys;
	};
}