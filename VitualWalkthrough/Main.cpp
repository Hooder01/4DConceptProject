#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>


int main() 
{
	glfwInit(); // creates window

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // GL needs to know which version it's using
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // GL needs to know which profile to use

	GLFWwindow* window = glfwCreateWindow(800, 800, "YoutubeOpenGL", NULL, NULL); // creates pop up window
	if (window == NULL) // fail safe net
	{
		std::cout << "Failed to create GL Window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwTerminate(); // closes window
	return 0;
}