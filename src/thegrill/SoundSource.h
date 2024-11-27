#include "Component.h"
#include <memory>


#include <AL/al.h>
#include <AL/alc.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include <stdexcept>
#include <vector>
#include <string>

#include "stb_vorbis.c"



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