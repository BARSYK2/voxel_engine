#include "Window.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include<iostream>


GLFWwindow* Window::window;
int Window::width = 0;
int Window::height = 0;


int Window::initialize(int width, int hieght, const char* title)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	window = glfwCreateWindow(width, hieght, title, nullptr, nullptr);

	if (window == nullptr) {
		std::cerr << "Failed to create GLFFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cerr << "Failed to initialize GLEW" << std::endl;
		return -1;
	}
	glViewport(0, 0, width, hieght);

	Window::width = width;
	Window::height = height;
	return 0;
}



void Window::terminate()
{
	return glfwTerminate();
}

void Window::setCursorMode(int mode)
{
	glfwSetInputMode(window, GLFW_CURSOR, mode);
}

bool Window::isShouldClose()
{
	return glfwWindowShouldClose(window);
}

void Window::setShouldClose(bool flag)
{
	glfwSetWindowShouldClose(window, flag);
}

void Window::swapBuffers()
{
	return glfwSwapBuffers(window);
}
