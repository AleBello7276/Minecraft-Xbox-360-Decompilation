#include "Material.h"


Material
    * Material::air,
    * Material::grassMaterial,
    * Material::ground,
    * Material::wood,
    * Material::rock,
    * Material::iron,
    * Material::water,
    * Material::lava,
    * Material::leaves,
    * Material::plants,
    * Material::sponge,
    * Material::cloth,
    * Material::fire,
    * Material::sand,
    * Material::circuits,
    * Material::glass,
    * Material::tnt,
    * Material::field_4262_q,
    * Material::ice,
    * Material::snow,
    * Material::builtSnow,
    * Material::cactus,
    * Material::clay,
    * Material::pumpkin,
    * Material::portal,
    * Material::cakeMaterial;


void Material::initMaterials()
{
	air             = new Material(MapColor::field_28212_b);
	grassMaterial   = new Material(MapColor::field_28211_c);
	ground          = new Material(MapColor::field_28202_l);
	wood            = new Material(MapColor::field_28199_o);
	rock            = new Material(MapColor::field_28201_m);
	iron            = new Material(MapColor::field_28206_h);
	water           = new Material(MapColor::field_28200_n);
	lava            = new Material(MapColor::field_28208_f);
	leaves          = new Material(MapColor::field_28205_i);
	plants          = new Material(MapColor::field_28205_i);
	sponge          = new Material(MapColor::field_28209_e);
	cloth           = new Material(MapColor::field_28209_e);
	fire            = new Material(MapColor::field_28212_b);
	sand            = new Material(MapColor::field_28210_d);
	circuits        = new Material(MapColor::field_28212_b);
	glass           = new Material(MapColor::field_28212_b);
	tnt             = new Material(MapColor::field_28208_f);
	field_4262_q    = new Material(MapColor::field_28205_i);
	ice             = new Material(MapColor::field_28207_g);
	snow            = new Material(MapColor::field_28204_j);
	builtSnow       = new Material(MapColor::field_28204_j);
	cactus          = new Material(MapColor::field_28205_i);
	clay            = new Material(MapColor::field_28203_k);
	pumpkin         = new Material(MapColor::field_28205_i);
	portal          = new Material(MapColor::field_28212_b);
    cakeMaterial    = new Material(MapColor::field_28212_b);
}

/*void Material::teardownMaterials()
{
	delete air;
    delete grassMaterial;
    delete ground;
    delete wood;
    delete rock;
    delete iron;
    delete water;
    delete lava;
    delete leaves;
    delete plants;
    delete sponge;
    delete cloth;
    delete fire;
    delete sand;
    delete circuits;
    delete glass;
    delete tnt;
    delete field_4262_q;
    delete ice;
    delete snow;
    delete builtSnow;
    delete cactus;
    delete clay;
    delete pumpkin;
    delete portal;
    delete cakeMaterial;
}*/

bool Material::getIsLiquid() const {
    return false;
}

bool Material::isSolid() const {
    return true;
}

bool Material::getCanBlockGrass() const {
    return true;
}

bool Material::getBurning() const {
    return canBurn;
}

bool Material::getIsSolid() const {
    return true;
}

Material* Material::func_27284_f() {
    field_27285_A = true;
    return this;
}

bool Material::func_27283_g() const {
    return field_27285_A;
}

bool Material::func_28126_h() const {
    return field_28128_D ? false : getIsSolid();
}


Material* Material::func_28127_i() {
    field_28128_D = true;
    return this;
}

Material* Material::setBurning() {
    canBurn = true;
    return this;
}