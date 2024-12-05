#include "Component.h"
#include <memory>


#include "SoundSystem.h"


namespace thegrill {

	struct SoundSource : public Component {
		SoundSource();


		void load_ogg(const std::string& _path, std::vector<unsigned char>& _buffer, ALenum& _format, ALsizei& _freq);


	private:

		ALenum format = 0;
		ALsizei freq = 0;
		std::vector<unsigned char> bufferData;
	};

}