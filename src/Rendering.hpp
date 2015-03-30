#pragma once
#define GLM_FORCE_RADIANS
#include "OpenGL33.hpp"
#include "Shader.hpp"
#include "Texture.hpp"

using namespace std;
using namespace gl33core;

class Rendering {

private:
	int windowWidth;
	int windowHeight;
	Shader * lineShader;
	Shader * scanShader;
public:
	Rendering();
	bool Initialize(string & error, int windowHeight, int windowWidth, bool fullScreen, string assetPath);
	void Render();
	SDL_Window * window;
	bool wireframe = false;
};