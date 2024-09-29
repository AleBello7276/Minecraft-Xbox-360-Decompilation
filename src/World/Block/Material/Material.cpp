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


void Material::statiCtor()
{
	air             = (new MaterialTransparent(MapColor::field_28212_b));
	grassMaterial   = (new Material(MapColor::field_28211_c));
	ground          = (new Material(MapColor::field_28202_l));
	wood            = (new Material(MapColor::field_28199_o))->setBurning();
	rock            = (new Material(MapColor::field_28201_m));
	iron            = (new Material(MapColor::field_28206_h));
	water           = (new MaterialLiquid(MapColor::field_28200_n));
	lava            = (new MaterialLiquid(MapColor::field_28208_f));
	leaves          = (new Material(MapColor::field_28205_i))->setBurning()->func_28127_i();
	plants          = (new MaterialLogic(MapColor::field_28205_i));
	sponge          = (new Material(MapColor::field_28209_e));
	cloth           = (new Material(MapColor::field_28209_e))->setBurning();
	fire            = (new MaterialTransparent(MapColor::field_28212_b));
	sand            = (new Material(MapColor::field_28210_d));
	circuits        = (new MaterialLogic(MapColor::field_28212_b));
	glass           = (new Material(MapColor::field_28212_b))->func_28127_i();
	tnt             = (new Material(MapColor::field_28208_f))->setBurning()->func_28127_i();
	field_4262_q    = (new Material(MapColor::field_28205_i));
	ice             = (new Material(MapColor::field_28207_g))->func_28127_i();
	snow            = (new MaterialLogic(MapColor::field_28204_j))->func_27284_f()->func_28127_i();
	builtSnow       = (new Material(MapColor::field_28204_j));
	cactus          = (new Material(MapColor::field_28205_i))->func_28127_i();
	clay            = (new Material(MapColor::field_28203_k));
	pumpkin         = (new Material(MapColor::field_28205_i));
	portal          = (new MaterialPortal(MapColor::field_28212_b));
    cakeMaterial    = (new Material(MapColor::field_28212_b));
}


// Material

bool Material::getIsLiquid() const 
{
    return false;
}

bool Material::isSolid() const 
{
    return true;
}

bool Material::getCanBlockGrass() const 
{
    return true;
}

bool Material::getBurning() const 
{
    return this->canBurn;
}

bool Material::getIsSolid() const {
    return true;
}

Material* Material::func_27284_f() {
    this->field_27285_A = true;
    return this;
}

bool Material::func_27283_g() const {
    return this->field_27285_A;
}

bool Material::func_28126_h() const {
    return this->field_28128_D ? false : this->getIsSolid();
}


Material* Material::func_28127_i() {
    this->field_28128_D = true;
    return this;
}

Material* Material::setBurning() {
    this->canBurn = true;
    return this;
}

// MaterialTransparent

bool MaterialTransparent::isSolid() const
{
    return false;
}
bool MaterialTransparent::getCanBlockGrass() const
{
    return false;
}
bool MaterialTransparent::getIsSolid() const
{
    return false;
}

// MaterialPortal

bool MaterialPortal::isSolid() const
{
    return false;
}
bool MaterialPortal::getCanBlockGrass() const
{
    return false;
}
bool MaterialPortal::getIsSolid() const
{
    return false;
}

// MaterialLogic

bool MaterialLogic::isSolid() const
{
    return false;
}
bool MaterialLogic::getCanBlockGrass() const
{
    return false;
}
bool MaterialLogic::getIsSolid() const
{
    return false;
}

// MaterialLiquid

bool MaterialLiquid::isSolid() const
{
    return false;
}
bool MaterialLiquid::getIsLiquid() const
{
    return true;
}
bool MaterialLiquid::getIsSolid() const
{
    return false;
}