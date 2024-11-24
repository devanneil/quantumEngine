#include <qOpenGL.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
const char* vertexShader = R"END(#version 330 core

layout (location=0) in vec3 vertexPos;
layout (location=1) in vec3 vertexColor;

out vec3 fragmentColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(vertexPos, 1.0);
    fragmentColor = vertexColor;
})END";
const char* fragmentShader = R"END(#version 330 core

in vec3 fragmentColor;

out vec4 screenColor;

void main()
{
    screenColor = vec4(fragmentColor, 1.0);
})END";

unsigned int make_module(const char* module, unsigned int module_type) {

	unsigned int shaderModule = glCreateShader(module_type);
	glShaderSource(shaderModule, 1, &module, NULL);
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

unsigned int make_shader() {

	//To store all the shader modules
	std::vector<unsigned int> modules;

	//Add a vertex shader module
	modules.push_back(make_module(vertexShader, GL_VERTEX_SHADER));

	//Add a fragment shader module
	modules.push_back(make_module(fragmentShader, GL_FRAGMENT_SHADER));

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
	glMesh mesh = glMesh("../src/app/models/square.obj");
	std::cout << mesh.faces << std::endl;
	unsigned int shader = make_shader();
	glUseProgram(shader);

	qMat<float> model = transformMatrix(0.5f, -0.2f, 0.0f, 0.0f, 0.0f, 0.0f);
	unsigned int model_location = glGetUniformLocation(shader, "model");
	glUniformMatrix4fv(model_location, 1, GL_FALSE, model.toArray());
	
	qVec<float> cameraPosition = {5.0, 5.0, 5.0};
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

		model = transformMatrix(0.0f, 0.0f, 0.0f, (float)(1.0*totalTime), (float)(10.0*totalTime), (float)(25.0*totalTime));
		unsigned int model_location = glGetUniformLocation(shader, "model");

		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shader);
		mesh.draw();
		glUniformMatrix4fv(model_location, 1, GL_FALSE, model.toArray());

		glfwSwapBuffers(window);
		double frameTime = glfwGetTime();
		totalTime += frameTime;
	}

	glDeleteProgram(shader);
	glfwTerminate();
	return 0;
}