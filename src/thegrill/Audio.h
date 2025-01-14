#include "Resource.h"
#include "SoundSystem.h"

namespace thegrill {

	/**
	 * @brief The Audio class represents an audio resource that can be loaded and managed within the sound system.
	 */

	struct Audio : Resource {

		~Audio();

		/**
		 * @brief Loads an OGG audio file into a buffer.
		 *
		 * This function reads the audio data from the specified file path and creates the buffer,
		 * format, and frequency variables.
		 *
		 * @param _path The path to the OGG audio file.
		 * @param _buffer A reference to a vector that will hold the audio data.
		 * @param _format A reference to an ALenum variable that stores the audio format.
		 * @param _freq A reference to an ALsizei variable that stores the audio frequency.
		 */

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