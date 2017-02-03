
#include <iostream>
#include <string>
#include <map>
#include <utility>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "utility.hpp"
#include "camera.hpp"
#include "cube.hpp"

void keyCB(GLFWwindow * window, int key, int scancode, int action, int mods);
void mousePositionCB(GLFWwindow * window, double xPos, double yPos);
void mouseButtonCB(GLFWwindow * window, int button, int action, int mods);

int main() {
	GLFWwindow * window = Utility::initGLContext(
		keyCB, 
		mousePositionCB, 
		mouseButtonCB,
		{600, 600}
	);
	
	GLuint programID = Utility::loadShaders(
		"src/shaders/cube.vert",
		"src/shaders/cube.frag"
	);
	
	Camera camera (window);
	
	Cube c;
	
	c.setProgramID(programID);
	c.initGL();
		
	glm::mat4 cMat = c.getModelMatrix();
	cMat = glm::translate(cMat, glm::vec3(-1, 0, 0));
	c.setModelMatrix(cMat);
	
	do {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		camera.handleInput();
		
		c.render({0.1f, 0.1f, 0.1f}, camera.getViewMatrix(), camera.getPerspectiveMatrix());
		
		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	} while(
		glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS 
		&& glfwWindowShouldClose(window) == 0
	);
	
	return 0;
}

void keyCB(GLFWwindow * window, int key, int scancode, int action, int mods) {}

void mousePositionCB(GLFWwindow * window, double xPos, double yPos) {}

void mouseButtonCB(GLFWwindow * window, int button, int action, int mods) {}
