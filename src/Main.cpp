#include <iostream>
#include <SDL.h>
#include "Scan.hpp"
#include "Rendering.hpp"
#include "Shape.hpp"

using namespace std;

Rendering * rendering;
Shape * shape;
 
int main(int argc, char * argv[]){
	SDL_Init(SDL_INIT_EVERYTHING);

	//Scan * scan = new Scan();
	//scan->Load("http://google.com");

	#ifdef WIN32
		string assetPath = "../../assets/";
	#else
		string assetPath = "../assets/";
	#endif 

	shape = new Shape(assetPath + "shapes/states/s_16de14.shp");



	string initError;
	rendering = new Rendering();
	rendering->Initialize(initError, 100, 100, false, assetPath);

	return 0;
}
