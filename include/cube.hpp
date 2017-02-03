
#pragma once

#include <array>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "utility.hpp"

class Cube {
	public:
		Cube();
		
		void initGL();
		void render(Color color, glm::mat4 viewMatrix, glm::mat4 projectionMatrix);
		
		void setProgramID(GLuint programID);
		GLuint getProgramID();
		
		void setColor(Color color);
		Color getColor();
		
		void setModelMatrix(glm::mat4 modelMatrix);
		glm::mat4 getModelMatrix();
		
	private:	
		struct Buffers {
			GLuint vertex;
		};
		
		struct Handles {
			GLuint color;
			GLuint pvm;
		};
	
		Buffers buffers;
		Handles handles;
		
		glm::mat4 modelMatrix;		
		
		GLuint programID;
		GLuint vao;
		
		Color cubeColor;
		
};


