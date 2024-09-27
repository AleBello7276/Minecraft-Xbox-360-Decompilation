#pragma once

#include "MapData.h"

class EntityPlayer;

class MapInfo 
{
public:
	const EntityPlayer* field_28120_a;
	int* field_28119_b;
	int* field_28124_c;

	
private:
    int field_28122_e;
	int field_28121_f;
    const MapData* field_28123_d;

	MapInfo(MapData* var1, EntityPlayer* var2) {
		this->field_28123_d = var1;
		this->field_28119_b = new int[128];
		this->field_28124_c = new int[128];
		this->field_28122_e = 0;
		this->field_28121_f = 0;
		this->field_28120_a = var2;

		for(int var3 = 0; var3 < 128; ++var3) {
			this.field_28119_b[var3] = 0;
			this.field_28124_c[var3] = 127;
		}

	}
};
