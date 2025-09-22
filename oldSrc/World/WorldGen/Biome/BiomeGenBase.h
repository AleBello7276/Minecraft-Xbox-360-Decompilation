#pragma once

#include <string>

class BiomeGenBase 
{
public:
    //staticCtor
    static BiomeGenBase
            *rainforest,
            *swampland,
            *seasonalForest,
            *forest,
            *savanna,
            *shrubland,
            *taiga,
            *desert,
            *plains,
            *iceDesert,
            *tundra,
            *hell,
            *sky;


	/*BiomeGenBase rainforest = (new BiomeGenRainforest()).setColor(588342).setBiomeName("Rainforest").func_4124_a(2094168);
	BiomeGenBase swampland = (new BiomeGenSwamp()).setColor(522674).setBiomeName("Swampland").func_4124_a(9154376);
	BiomeGenBase seasonalForest = (new BiomeGenBase()).setColor(10215459).setBiomeName("Seasonal Forest");
	BiomeGenBase forest = (new BiomeGenForest()).setColor(353825).setBiomeName("Forest").func_4124_a(5159473);
	BiomeGenBase savanna = (new BiomeGenDesert()).setColor(14278691).setBiomeName("Savanna");
	BiomeGenBase shrubland = (new BiomeGenBase()).setColor(10595616).setBiomeName("Shrubland");
	BiomeGenBase taiga = (new BiomeGenTaiga()).setColor(3060051).setBiomeName("Taiga").setEnableSnow().func_4124_a(8107825);
	BiomeGenBase desert = (new BiomeGenDesert()).setColor(16421912).setBiomeName("Desert").setDisableRain();
	BiomeGenBase plains = (new BiomeGenDesert()).setColor(16767248).setBiomeName("Plains");
	BiomeGenBase iceDesert = (new BiomeGenDesert()).setColor(16772499).setBiomeName("Ice Desert").setEnableSnow().setDisableRain().func_4124_a(12899129);
	BiomeGenBase tundra = (new BiomeGenBase()).setColor(5762041).setBiomeName("Tundra").setEnableSnow().func_4124_a(12899129);
	BiomeGenBase hell = (new BiomeGenHell()).setColor(16711680).setBiomeName("Hell").setDisableRain();
	BiomeGenBase sky = (new BiomeGenSky()).setColor(8421631).setBiomeName("Sky").setDisableRain();*/

	std::string biomeName;
	int color;
	short topBlock = (byte)Block.grass.blockID;
	short fillerBlock = (byte)Block.dirt.blockID;
	int field_6502_q = 5169201;
	//protected List spawnableMonsterList = new ArrayList();
	//protected List spawnableCreatureList = new ArrayList();
	//protected List spawnableWaterCreatureList = new ArrayList();
	bool enableSnow;
	bool enableRain = true;
    
	static BiomeGenBase[] biomeLookupTable = new BiomeGenBase[4096];

	
};
