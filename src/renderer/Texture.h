#ifndef TEXTURE_H
#define TEXTURE_H


#include <GL/glew.h>

#include <string>
#include <vector>

namespace renderer {
	struct Texture {
		Texture(const std::string& _path);
		Texture();
		~Texture();
		GLuint id();

	private:

		GLuint m_id;
		int m_width;
		std::vector<unsigned char> m_data;
		int m_height;
		bool m_dirty;
	};
}

 
#endif // !TEXTURE_H
