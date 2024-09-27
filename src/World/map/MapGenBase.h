#pragma once

#include "../../Java/Math/Random.h"
#include "../World.h"
#include "../Chunk/IChunkProvider.h"

class MapGenBase 
{
protected:
	int field_1306_a = 8;
	Random* rand = new Random();
    void func_868_a(World var1, int var2, int var3, int var4, int var5, byte[] var6) 
    {
	}
public:
    void func_867_a(IChunkProvider* var1, World* var2, int var3, int var4, byte* var5[]) 
    {
		int var6 = this->field_1306_a;
		this->rand->setSeed(var2->getRandomSeed());
		long var7 = this.rand->nextLong() / 2L * 2L + 1L;
		long var9 = this.rand->nextLong() / 2L * 2L + 1L;

		for(int var11 = var3 - var6; var11 <= var3 + var6; ++var11) {
			for(int var12 = var4 - var6; var12 <= var4 + var6; ++var12) {
				this->rand->setSeed((long)var11 * var7 + (long)var12 * var9 ^ var2.getRandomSeed());
				this.func_868_a(var2, var11, var12, var3, var4, var5);
			}
		}

	}

	
};
