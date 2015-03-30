#include "Rendering.hpp"

Rendering::Rendering(){}

bool Rendering::Initialize(string & error, int windowHeight, int windowWidth, bool fullScreen, string assetPath){
	this->windowHeight = windowHeight;
	this->windowWidth = windowWidth;
	int opts = SDL_WINDOW_OPENGL;
	if (fullScreen){
		opts = opts | SDL_WINDOW_FULLSCREEN;
	}
	//SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	//SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 16);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
	this->window = SDL_CreateWindow("Test Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->windowWidth, this->windowHeight, opts);
	if (window == nullptr){
		error = string("Failed to start windowing subsystem");
		return false;
	}
	auto glcontext = SDL_GL_CreateContext(this->window);
	if (glcontext == nullptr){
		error = string("Failed to start graphics subsystem");
		return false;
	}
	glbinding::Binding::initialize();
	printf("OpenGL %s, GLSL %s\n", glGetString(GL_VERSION), glGetString(GL_SHADING_LANGUAGE_VERSION));

	//if (TTF_Init() == -1) {
	//	printf("TTF_Init: %s\n", TTF_GetError());
	//	exit(1);
	//}

	this->scanShader = new Shader();
	this->scanShader->SetupShader(assetPath + "shaders/scan.vert", assetPath + "shaders/scan.frag",
		list < string > {
		"in_Position",
	},
	list < string > {
			"projectionMatrix"
		});

	this->lineShader = new Shader();
	this->lineShader->SetupShader(assetPath + "shaders/lines.vert", assetPath + "shaders/lines.frag",
		list < string > {
		"in_Position"
	},
	list < string > {
			"projectionMatrix"
		});

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);


	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0.1, 0.1, 0.1, 1.0);


	return true;
}