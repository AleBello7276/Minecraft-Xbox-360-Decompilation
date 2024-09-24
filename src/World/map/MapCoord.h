#pragma once

#include "MapData.h"

class MapCoord 
{
public:
	short field_28217_a;
	short field_28216_b;
	short field_28220_c;
	short field_28219_d;
	MapData field_28218_e;

	MapCoord(MapData* var1, byte var2, byte var3, byte var4, byte var5) 
	{
		this.field_28218_e = var1;
		this.field_28217_a = var2;
		this.field_28216_b = var3;
		this.field_28220_c = var4;
		this.field_28219_d = var5;
	}
};
