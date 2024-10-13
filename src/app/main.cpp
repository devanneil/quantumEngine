#include <qOpenGL.h>
#include "triangle_mesh.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
#include <vector>
unsigned int make_module(const std::string& filepath, unsigned int module_type);

unsigned int make_shader(const std::string& vertex_filepath, const std::string& fragment_filepath) {

	//To store all the shader modules
	std::vector<unsigned int> modules;

	//Add a vertex shader module
	modules.push_back(make_module(vertex_filepath, GL_VERTEX_SHADER));

	//Add a fragment shader module
	modules.push_back(make_module(fragment_filepath, GL_FRAGMENT_SHADER));

	//Attach all the modules then link the program
	unsigned int shader = glCreateProgram();
	for (unsigned int shaderModule : modules) {
		glAttachShader(shader, shaderModule);
	}
	glLinkProgram(shader);

	//Check the linking worked
	int success;
	glGetProgramiv(shader, GL_LINK_STATUS, &success);
	if (!success) {
		char errorLog[1024];
		glGetProgramInfoLog(shader, 1024, NULL, errorLog);
		std::cout << "Shader linking error:\n" << errorLog << '\n';
	}

	//Modules are now unneeded and can be freed
	for (unsigned int shaderModule : modules) {
		glDeleteShader(shaderModule);
	}

	return shader;

}

unsigned int make_module(const std::string& filepath, unsigned int module_type) {
	std::ifstream file;
	std::stringstream bufferedLines;
	std::string line;

	file.open(filepath);
	while (std::getline(file, line)) {
		//std::cout << line << std::endl;
		bufferedLines << line << '\n';
	}
	std::string shaderSource = bufferedLines.str();
	const char* shaderSrc = shaderSource.c_str();
	bufferedLines.str("");
	file.close();

	unsigned int shaderModule = glCreateShader(module_type);
	glShaderSource(shaderModule, 1, &shaderSrc, NULL);
	glCompileShader(shaderModule);

	int success;
	glGetShaderiv(shaderModule, GL_COMPILE_STATUS, &success);
	if (!success) {
		char errorLog[1024];
		glGetShaderInfoLog(shaderModule, 1024, NULL, errorLog);
		std::cout << "Shader Module compilation error:\n" << errorLog << std::endl;
	}

	return shaderModule;
}

int main() {
		
	GLFWwindow* window;

	if (!glfwInit()) {
		return -1;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
	
	window = glfwCreateWindow(640, 480, "Hello Window!", NULL, NULL);
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Couldn't load opengl" << std::endl;
		glfwTerminate();
		return -1;
	}

	glClearColor(0.25f, 0.5f, 0.75f, 1.0f);

	TriangleMesh* triangle = new TriangleMesh();

	unsigned int shader = make_shader(
		"../src/app/shaders/vertex.txt", 
		"../src/app/shaders/fragment.txt"
	);
	glUseProgram(shader);

	qMat<float> model = transformMatrix(0.5f, -0.2f, 0.0f, 0.0f, 0.0f, 0.0f);
	unsigned int model_location = glGetUniformLocation(shader, "model");
	glUniformMatrix4fv(model_location, 1, GL_FALSE, model.toArray());
	
	qVec<float> cameraPosition = {1.0, 1.0, 1.0};
	qVec<float> cameraTarget = {0, 0, 0};
	qVec<float> globalUp = {0, 0, 1};
	qMat<float> view = viewMatrix(cameraPosition, cameraTarget);
	unsigned int view_location = glGetUniformLocation(shader, "view");
	glUniformMatrix4fv(view_location, 1, GL_FALSE, view.toArray());

	qMat<float> projection = projectionMatrix(45.0f, 480.0f/640.0f, 0.5f, 10.0f);
	unsigned int projection_location = glGetUniformLocation(shader, "projection");
	glUniformMatrix4fv(projection_location, 1, GL_FALSE, projection.toArray());
	
	double totalTime = glfwGetTime();
	while (!glfwWindowShouldClose(window)) {
		glfwSetTime(0);

		glfwPollEvents();

		model = rotationMatrix(0.0f, 0.0f, 10.0f * (float)totalTime);
		unsigned int model_location = glGetUniformLocation(shader, "model");

		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shader);
		triangle->draw();

		glUniformMatrix4fv(model_location, 1, GL_FALSE, model.toArray());

		glfwSwapBuffers(window);
		double frameTime = glfwGetTime();
		totalTime += frameTime;
	}

	glDeleteProgram(shader);
	delete triangle;
	glfwTerminate();
	return 0;
}