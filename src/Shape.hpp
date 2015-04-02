#pragma once
#include <shapelib/shapefil.h>
#include <string>
#include <iostream>

using namespace std;

struct Vertex2D{
	float x;
	float y;
};
struct Line2D{
	Vertex2D a;
	Vertex2D b;
};


class Shape
{
private:
public:
	Shape(string path);
};