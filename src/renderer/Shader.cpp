#include "shader.h"
#include <glm/ext.hpp>
#include <iostream>
namespace renderer {
	Shader::Shader(bool ortho) {
		if (ortho)
		{
			GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vertexShaderId, 1, &orthoVertexShaderSrc, NULL);
			glCompileShader(vertexShaderId);
			GLint success = 0;
			glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);

			if (!success)
			{
				throw std::exception();
			}


			// Create a new fragment shader, attach source code, compile it and
			// check for errors.
			GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(fragmentShaderId, 1, &orthoFragmentShaderSrc, NULL);
			glCompileShader(fragmentShaderId);
			glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);

			if (!success)
			{
				throw std::exception();
			}
			/************ Program ***************/

			// Create new shader program and attach our shader objects
			programId = glCreateProgram();
			glAttachShader(programId, vertexShaderId);
			glAttachShader(programId, fragmentShaderId);

			// Ensure the VAO "position" attribute stream gets set as the first position
			// during the link.
			glBindAttribLocation(programId, 0, "a_Position");
			glBindAttribLocation(programId, 1, "a_TexCoord");
			glBindAttribLocation(programId, 2, "a_Normal");

			// Perform the link and check for failure
			glLinkProgram(programId);
			glGetProgramiv(programId, GL_LINK_STATUS, &success);


			// Find uniform locations
			modelLoc = glGetUniformLocation(programId, "u_Model");
			projectionLoc = glGetUniformLocation(programId, "u_Projection");


			if (!success)
			{
				throw std::exception();
			}


			// Detach and destroy the shader objects. These are no longer needed
			// because we now have a complete shader program.
			glDetachShader(programId, vertexShaderId);
			glDeleteShader(vertexShaderId);
			glDetachShader(programId, fragmentShaderId);
			glDeleteShader(fragmentShaderId);
		}
		else
		{
			// Create a new vertex shader, attach source code, compile it and
		// check for errors.
			GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vertexShaderId, 1, &vertexShaderSrc, NULL);
			glCompileShader(vertexShaderId);
			GLint success = 0;
			glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);

			if (!success)
			{
				throw std::exception();
			}


			// Create a new fragment shader, attach source code, compile it and
			// check for errors.
			GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(fragmentShaderId, 1, &fragmentShaderSrc, NULL);
			glCompileShader(fragmentShaderId);
			glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);

			if (!success)
			{
				throw std::exception();
			}
			/************ Program ***************/

			// Create new shader program and attach our shader objects
			programId = glCreateProgram();
			glAttachShader(programId, vertexShaderId);
			glAttachShader(programId, fragmentShaderId);

			// Ensure the VAO "position" attribute stream gets set as the first position
			// during the link.
			glBindAttribLocation(programId, 0, "a_Position");
			glBindAttribLocation(programId, 1, "a_TexCoord");
			glBindAttribLocation(programId, 2, "a_Normal");

			// Perform the link and check for failure
			glLinkProgram(programId);
			glGetProgramiv(programId, GL_LINK_STATUS, &success);


			// Find uniform locations
			modelLoc = glGetUniformLocation(programId, "u_Model");
			viewLoc = glGetUniformLocation(programId, "u_View");
			projectionLoc = glGetUniformLocation(programId, "u_Projection");


			if (!success)
			{
				throw std::exception();
			}


			// Detach and destroy the shader objects. These are no longer needed
			// because we now have a complete shader program.
			glDetachShader(programId, vertexShaderId);
			glDeleteShader(vertexShaderId);
			glDetachShader(programId, fragmentShaderId);
			glDeleteShader(fragmentShaderId);

		
		}

	}

	Shader::~Shader() {

	}

	void Shader::setUniform(std::string variable, glm::mat4 value) {
		glUseProgram(programId);
		glUniformMatrix4fv(glGetUniformLocation(programId, variable.c_str()), 1, GL_FALSE, glm::value_ptr(value));
		glUseProgram(0);
	}



	void Shader::setUniform(std::string variable, glm::vec3 value) {
		glUseProgram(programId);
		glUniformMatrix4fv(glGetUniformLocation(programId, variable.c_str()), 1, GL_FALSE, glm::value_ptr(value));
		glUseProgram(0);
	}

	void Shader::setUniform(std::string variable, std::shared_ptr<renderer::Texture> value, int unit)
	{
		glActiveTexture(GL_TEXTURE0 + unit);
		glBindTexture(GL_TEXTURE_2D, value->id());
		glUseProgram(programId);
		glUniform1i(glGetUniformLocation(programId, variable.c_str()), unit);
		glUseProgram(0);
		glActiveTexture(GL_TEXTURE0);
	}

	void Shader::setUniform(std::string variable, GLuint value, int unit)
	{
		glActiveTexture(GL_TEXTURE0 + unit);
		glBindTexture(GL_TEXTURE_2D, value);
		glUseProgram(programId);
		glUniform1i(glGetUniformLocation(programId, variable.c_str()), unit);
		glUseProgram(0);
		glActiveTexture(GL_TEXTURE0);
	}



	void Shader::draw(GLuint _VAOID, GLuint _VBOID, GLsizei _vCount, bool depth_testing)
	{
		//std::cout << "Drawing" << std::endl;
		// Instruct OpenGL to use our shader program and our VAO
		glUseProgram(programId);
		glBindVertexArray(_VBOID);
		//	std::cout << programId << " " << ortho << std::endl;
			// Draw 3 vertices (a triangle)
		glDrawArrays(GL_TRIANGLES, 0, _vCount);

		//disable depth testing for 2d
		if (!depth_testing) {
			glDisable(GL_DEPTH_TEST);
		}
		else
		{
			glEnable(GL_DEPTH_TEST);
		}
		glBindVertexArray(0);
		glUseProgram(0);
		//print vertex shader
	//	std::cout << "Fram Shader: " << fragmentShaderSrc << std::endl;
	}




}
