#include "Shape.hpp"


Shape::Shape(string path){
	SHPHandle handle = SHPOpen(path.c_str(), "rb");

	int numEntities = 0;
	int shapeType = SHPT_ARC;

	SHPGetInfo(handle, &numEntities, &shapeType, NULL, NULL);

	for (int i = 0; i < numEntities; i++){
		SHPObject * obj = SHPReadObject(handle, i);
		cout << "shape " << i << " parts: " << obj->nParts << " vertices: " << obj->nVertices << endl;


		int numPoints = 0;
		for (int j = 0; j < obj->nParts; j++) {
			if ((obj->nParts - 1) == j){
				// This is the last part, so we cant look at the start of the next part
				numPoints=	obj->nVertices - obj->panPartStart[j];
			}
			else {
				// Regular case
				numPoints = obj->panPartStart[j + 1] - obj->panPartStart[j];
			}

			int lastPoint = obj->panPartStart[j] + numPoints;

			for (int k = obj->panPartStart[j]; k < lastPoint; k++) {
				float x = obj->padfX[k];
				float y = obj->padfY[k];
		//		cout << "x : " << x << " y: " << y << endl;
			}
		}
			
	}

//	void SHPGetInfo(SHPHandle hSHP, int * pnEntities, int * pnShapeType, double * padfMinBound, double * padfMaxBound);

}

