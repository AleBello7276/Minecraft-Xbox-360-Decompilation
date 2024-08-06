#pragma once
#include "MapColor.h"

class Material {
private:
	bool canBurn = false;
	bool field_27285_A = false;
	bool field_28128_D = false;
public:
	const MapColor& materialMapColor;
    Material(const MapColor& color) : materialMapColor(color) {};

    bool getIsLiquid() const;
    bool isSolid() const;
    bool getCanBlockGrass() const;
    bool getIsSolid() const;
    bool getBurning() const;
    Material* func_27284_f();
    bool func_27283_g() const;
    bool func_28126_h() const;

    static const Material air;
    static const Material grassMaterial;
    static const Material ground;
    static const Material wood;
    static const Material rock;
    static const Material iron;
    static const Material water;
    static const Material lava;
    static const Material leaves;
    static const Material plants;
    static const Material sponge;
    static const Material cloth;
    static const Material fire;
    static const Material sand;
    static const Material circuits;
    static const Material glass;
    static const Material tnt;
    static const Material field_4262_q;
    static const Material ice;
    static const Material snow;
    static const Material builtSnow;
    static const Material cactus;
    static const Material clay;
    static const Material pumpkin;
    static const Material portal;
    static const Material cakeMaterial;

private:
    Material* func_28127_i();
    Material* setBurning();
};

// Still needed to implement extended Material classes such as MaterialTransparent
const Material Material::air(MapColor::field_28212_b);
const Material Material::grassMaterial(MapColor::field_28211_c);
const Material Material::ground(MapColor::field_28202_l);
const Material Material::wood(MapColor::field_28199_o);
const Material Material::rock(MapColor::field_28201_m);
const Material Material::iron(MapColor::field_28206_h);
const Material Material::water(MapColor::field_28200_n);
const Material Material::lava(MapColor::field_28208_f);
const Material Material::leaves(MapColor::field_28205_i);
const Material Material::plants(MapColor::field_28205_i);
const Material Material::sponge(MapColor::field_28209_e);
const Material Material::cloth(MapColor::field_28209_e);
const Material Material::fire(MapColor::field_28212_b);
const Material Material::sand(MapColor::field_28210_d);
const Material Material::circuits(MapColor::field_28212_b);
const Material Material::glass(MapColor::field_28212_b);
const Material Material::tnt(MapColor::field_28208_f);
const Material Material::field_4262_q(MapColor::field_28205_i);
const Material Material::ice(MapColor::field_28207_g);
const Material Material::snow(MapColor::field_28204_j);
const Material Material::builtSnow(MapColor::field_28204_j);
const Material Material::cactus(MapColor::field_28205_i);
const Material Material::clay(MapColor::field_28203_k);
const Material Material::pumpkin(MapColor::field_28205_i);
const Material Material::portal(MapColor::field_28212_b);
const Material Material::cakeMaterial(MapColor::field_28212_b);