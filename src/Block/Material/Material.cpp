#include "Material.h"

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