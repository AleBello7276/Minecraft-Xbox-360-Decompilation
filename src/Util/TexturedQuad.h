#pragma once
#pragma once

#include "PositionTextureVertex.h"
#include <vector>

class TexturedQuad {

public:
    PositionTextureVertex vertexPositions[8];
	int nVertices;
	bool invertNormal;

    TexturedQuad(PositionTextureVertex* var1[]);
    TexturedQuad(PositionTextureVertex* var1[], int var2, int var3, int var4, int var5);

    void flipFace();
    // TODO

};