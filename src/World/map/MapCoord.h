#pragma once

#include "MapData.h"
class MapData;

class MapCoord
{
public:
    short field_28217_a;
    short field_28216_b;
    short field_28220_c;
    short field_28219_d;
    const MapData* field_28218_e;  

    MapCoord(const MapData* var1, short var2, short var3, short var4, short var5) 
	{
		this->field_28218_e = var1;
		this->field_28217_a = var2;
		this->field_28216_b = var3;
		this->field_28220_c = var4;
		this->field_28219_d = var5;
	}
};
