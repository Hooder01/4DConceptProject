#include<iostream> // This includes the Input/Output Stream library
#include<glad/glad.h> // This includes the GLAD (OpenGL Loader) library
#include<GLFW/glfw3.h> // This includes the GLFW library, which is used for creating windows


int main() // Creates and sets as main function
{
	glfwInit(); // creates window

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // This ensures that the window will use OpenGL version 3.x (major version 3).
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // This ensures that the window will use OpenGL version 3.3 (minor version 3).
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // GL needs to know which profile to use

	GLFWwindow* window = glfwCreateWindow(800, 800, "Vitual4DSpace"/*is name of window!*/, NULL, NULL); // creates the pop up window
	if (window == NULL) // fail safe net
	{
		std::cout << "Failed to create GL Window" << std::endl;
		glfwTerminate(); // closes/terminates window
		return -1;
	}
	glfwMakeContextCurrent(window); // takes the "window" we made with GLFWwindow and sets its OpenGL context as the current one for the calling thread


	gladLoadGL(); // This loads all the OpenGL function pointers using the GLAD loader

	glViewport(0, 0, 800, 800); // Area of which part of the window will render! (this should be the same as "createwindow")

	glClearColor(0.224f, 0.224f, 0.224f, 0.0f); // Color RGB values
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window); // This swaps the front and back buffers of the specified window


	while (!glfwWindowShouldClose(window)) // This loop continues running as long as the window should remain open
	{
		glfwPollEvents(); // This processes all pending events, It ensures the application stays responsive to user input
	}



	glfwDestroyWindow(window); // This destroys the specified window and its context, freeing up the resources used by the window.
	glfwTerminate(); 
	return 0;
}