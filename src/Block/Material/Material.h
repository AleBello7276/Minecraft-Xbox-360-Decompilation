#pragma once
#include "../../World/map/MapColor.h"



class Material {
private:
	bool canBurn;
	bool field_27285_A;
	bool field_28128_D;
public:
	MapColor* materialMapColor;
    Material(MapColor* color) : materialMapColor(color) {};

    static void initMaterials();
	//static void teardownMaterials();

    virtual bool getIsLiquid() const;
    virtual bool isSolid() const;
    virtual bool getCanBlockGrass() const;
    virtual bool getIsSolid() const;
    virtual bool getBurning() const;
    virtual bool func_27283_g() const;
    virtual bool func_28126_h() const;
    Material* func_27284_f();

    static Material
            *air,
            *grassMaterial,
            *ground,
            *wood,
            *rock,
            *iron,
            *water,
            *lava,
            *leaves,
            *plants,
            *sponge,
            *cloth,
            *fire,
            *sand,
            *circuits,
            *glass,
            *tnt,
            *field_4262_q,
            *ice,
            *snow,
            *builtSnow,
            *cactus,
            *clay,
            *pumpkin,
            *portal,
            *cakeMaterial;

private:
    Material* func_28127_i();
    Material* setBurning();
};

