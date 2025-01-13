#include "Resource.h"
#include "SoundSystem.h"

namespace thegrill {
	struct Audio : Resource {

		~Audio();

		void load_ogg(const std::string& _path, std::vector<unsigned char>& _buffer, ALenum& _format, ALsizei& _freq);
		void onLoad();
		void onUnload();

		ALuint m_Id;
	private:

		ALenum format = 0;
		
		ALsizei freq = 0;
		std::vector<unsigned char> bufferData;
	};
}