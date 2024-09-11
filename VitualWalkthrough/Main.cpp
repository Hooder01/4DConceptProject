#include<iostream> // This includes the Input/Output Stream library
#include<glad/glad.h> // This includes the GLAD (OpenGL Loader) library
#include<GLFW/glfw3.h> // This includes the GLFW library, which is used for creating windows


// copied source code (TEMP)
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";



int main() // Creates and sets as main function
{
	glfwInit(); // creates window

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // This ensures that the window will use OpenGL version 3.x (major version 3).
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // This ensures that the window will use OpenGL version 3.3 (minor version 3).
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // GL needs to know which profile to use


	GLfloat vertices[] = // An array that will concist of the vertex position points, GLfloat like any float is flaoting point numbers (aka perfect for position points)
	{
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.5f, -0.5 * float(sqrt(3)) / 3, 0.0f,
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f
	};


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


	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER); // creates a new "Shader Vertex" object then stores it within an ID (this is part of the pipeline) FIX THIS COMMENT!
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); // using vertexShader from before is now assinged the source code (we didn't have that before I guess) "1" is just the first set of an array in said source code, then the vertex shadersource is being pointed to the actaul source code (hence the name)
	glCompileShader(vertexShader); // Compiles the shader I made (cooking it for the PC if you will)




	glClearColor(0.224f, 0.224f, 0.224f, 0.0f); // Color RGB values (aka this sets the color)
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