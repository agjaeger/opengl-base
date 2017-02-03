
#include "cube.hpp"

static const GLfloat vertex_buffer_data[] = {
	-1.0f, -1.0f, -1.0f,
	 1.0f, -1.0f, -1.0f,
	 1.0f,  1.0f, -1.0f,
	 1.0f,  1.0f, -1.0f,
	-1.0f,  1.0f, -1.0f,
	-1.0f, -1.0f, -1.0f,

	-1.0f, -1.0f,  1.0f,
	 1.0f, -1.0f,  1.0f,
	 1.0f,  1.0f,  1.0f,
	 1.0f,  1.0f,  1.0f,
	-1.0f,  1.0f,  1.0f,
	-1.0f, -1.0f,  1.0f,

	-1.0f,  1.0f,  1.0f,
	-1.0f,  1.0f, -1.0f,
	-1.0f, -1.0f, -1.0f,
	-1.0f, -1.0f, -1.0f,
	-1.0f, -1.0f,  1.0f,
	-1.0f,  1.0f,  1.0f,

	 1.0f,  1.0f,  1.0f,
	 1.0f,  1.0f, -1.0f,
	 1.0f, -1.0f, -1.0f,
	 1.0f, -1.0f, -1.0f,
	 1.0f, -1.0f,  1.0f,
	 1.0f,  1.0f,  1.0f,

	-1.0f, -1.0f, -1.0f,
	 1.0f, -1.0f, -1.0f,
	 1.0f, -1.0f,  1.0f,
	 1.0f, -1.0f,  1.0f,
	-1.0f, -1.0f,  1.0f,
	-1.0f, -1.0f, -1.0f,

	-1.0f,  1.0f, -1.0f,
	 1.0f,  1.0f, -1.0f,
	 1.0f,  1.0f,  1.0f,
	 1.0f,  1.0f,  1.0f,
	-1.0f,  1.0f,  1.0f,
	-1.0f,  1.0f, -1.0f
};

Cube::Cube() {}

void Cube::initGL() {
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	
	glGenBuffers(1, &buffers.vertex);
	glBindBuffer(GL_ARRAY_BUFFER, buffers.vertex);
	
	glBufferData(
		GL_ARRAY_BUFFER, 
		sizeof(vertex_buffer_data), 
		vertex_buffer_data, GL_STATIC_DRAW
	);

	handles.color = glGetUniformLocation(programID, "vertColor");
	handles.pvm = glGetUniformLocation(programID, "pvm");

}

void Cube::render(Color color, glm::mat4 viewMatrix, glm::mat4 projectionMatrix) {
	glUseProgram(programID);
	
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, buffers.vertex);
	
	glUniform3f(handles.color, color[0], color[1], color[2]);
	
	glm::mat4 pvm = projectionMatrix * viewMatrix * modelMatrix;
	
	glUniformMatrix4fv(handles.pvm, 1, GL_FALSE, &pvm[0][0]);
	
	glVertexAttribPointer(
		0,			// first index
		3,			// length
		GL_FLOAT,	// type
		GL_FALSE,	// normalized
		0,			// stride
		(void *) 0	// data
	);
	
	glDrawArrays(GL_TRIANGLES, 0, 36);
	
	glDisableVertexAttribArray(0);
	glUseProgram(0);
}

void Cube::setProgramID(GLuint programID) {
	this->programID = programID;
}

GLuint Cube::getProgramID() {
	return programID;
}

void Cube::setColor(Color color) {
	cubeColor = color;
}

Color Cube::getColor() {
	return cubeColor;
}

void Cube::setModelMatrix(glm::mat4 modelMatrix) {
	this->modelMatrix = modelMatrix;
}

glm::mat4 Cube::getModelMatrix() {
	return modelMatrix;
}
