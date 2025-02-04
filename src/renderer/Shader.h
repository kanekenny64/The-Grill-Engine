#ifndef SHADER_H
#define SHADER_H
#include <memory>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>

#include <string>
#include <vector>
#include "texture.h"

namespace renderer {
	struct Shader
	{


	public:
		Shader(bool ortho);
		~Shader();

		void setUniform(std::string variable, glm::mat4 value);
		void setUniform(std::string variable, glm::vec3 value);
		void setUniform(std::string variable, std::shared_ptr<renderer::Texture> value, int unit);
		void setUniform(std::string variable, GLuint value, int unit);

		void draw(GLuint _VAOID, GLuint _VBOID, GLsizei _size, bool depth_testing);

		void clean_up();


		GLuint programId;
		GLint modelLoc;
		GLint viewLoc;
		GLint projectionLoc;

		bool ortho = false;

	private:


		const GLchar* vertexShaderSrc =
			"attribute vec3 a_Position;            " \
			"attribute vec3 a_Normal;"\
			"attribute vec2 a_TexCoord;               " \
			"uniform mat4 u_Projection;"\
			"uniform mat4 u_View; "	\
			"uniform mat4 u_Model;"
			"varying vec2 ex_TexCoord;               " \
			"varying vec3 ex_Normal;"\
			"varying vec3 ex_FragPos;"\
			"void main()                            " \
			"{                                      " \
			" gl_Position = u_Projection * u_View * u_Model * vec4(a_Position, 1.0);"\
			" ex_TexCoord = a_TexCoord;"\
			" ex_Normal = mat3(u_Model) * a_Normal;"\
			" ex_FragPos = vec3(u_Model * vec4(a_Position, 1.0));"\
			"}                                      " \
			"                                       ";
		//Using diffuse
		const GLchar* fragmentShaderSrc =
			"uniform sampler2D u_Texture;    " \
			"varying vec2 ex_TexCoord;" \
			"varying vec3 ex_Normal;"\
			"varying vec3 ex_FragPos;"\
			"void main()               " \
			"{                         " \
			"vec4 tex = texture2D(u_Texture, ex_TexCoord); " \
			"vec3 lightPos = vec3(-10, 0, -10);                         " \
			"vec3 diffuseColor = vec3(1, 1, 1);                         " \
			"                         " \
			"vec3 N = normalize(ex_Normal);                         " \
			"vec3 lightDir = normalize(lightPos - ex_FragPos);                         " \
			"float diff = max(dot(N, lightDir), 0.0);                         " \
			"vec3 diffuse = diffuseColor * diff;                         " \
			"vec3 lighting = diffuse;                         " \
			" gl_FragColor =  tex; " \
			"                         " \
			"                         " \
			"                         " \
			"}                         " \
			"                          ";

		

		const GLchar* orthoVertexShaderSrc =
			"attribute vec3 a_Position;            " \
			"attribute vec3 a_Normal;"\
			"attribute vec2 a_TexCoord;               " \
			"               " \
			"uniform mat4 u_Projection;"\
			"uniform mat4 u_Model;"
			"varying vec2 ex_TexCoord;               " \
			"varying vec3 ex_Normal;"\
			"varying vec3 ex_FragPos;"\
			"void main()                            " \
			"{                                      " \
			"  " \
			"    " \
			" gl_Position =  u_Projection * u_Model * vec4(a_Position, 1.0);"\
			" ex_TexCoord = a_TexCoord;"\
			" ex_Normal = mat3(u_Model) * a_Normal;"\
			" ex_FragPos = vec3(u_Model * vec4(a_Position, 1.0));"\
			"}                                      " \
			"                                       ";

		const GLchar* orthoFragmentShaderSrc =
			"uniform sampler2D in_Texture;"\
			"uniform vec3 in_LightPos;"\
			"uniform mat4 in_View; "\

			"varying vec2 ex_TexCoord; "\
			"varying vec3 ex_Normal;"\
			"varying vec3 ex_FragPos;"\

			"void main()"\
			"{"\
			"vec4 tex = texture2D(in_Texture, ex_TexCoord); "\

			"vec3 norm = normalize(ex_Normal); "\
			"vec3 lightDir = normalize(in_LightPos - ex_FragPos);"\

			"float diff = max(dot(norm, lightDir), 0.0); "\
			"vec3 diffuse = diff * vec3(1, 1, 1);"\

			"vec4 viewPos = inverse(in_View) * vec4(0, 0, 0, 1); "\
			"vec3 viewDir = normalize(viewPos - ex_FragPos);"\
			"vec3 reflectDir = reflect(-lightDir, norm); "\
			"float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);"\
			"vec3 specular = spec * vec3(1, 1, 1); "\

			"vec3 lighting = diffuse + specular; "\

			"gl_FragColor = tex; "\
			"}                                      "\
			;

	};

}
#endif // !SHADER_H

