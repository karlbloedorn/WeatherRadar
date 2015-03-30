#include <iostream>
#include <SDL.h>
#include "Scan.hpp"

using namespace std;

int main(int argc, char * argv[]){
	SDL_Init(SDL_INIT_EVERYTHING);

	Scan * scan = new Scan();
	scan->Load("http://google.com");


	return 0;
}