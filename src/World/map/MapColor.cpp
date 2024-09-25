#include "MapColor.h"

MapColor
    *MapColor::field_28212_b,
    *MapColor::field_28211_c,
    *MapColor::field_28210_d,
    *MapColor::field_28209_e,
    *MapColor::field_28208_f,
    *MapColor::field_28207_g,
    *MapColor::field_28206_h,
    *MapColor::field_28205_i,
    *MapColor::field_28204_j,
    *MapColor::field_28203_k,
    *MapColor::field_28202_l,
    *MapColor::field_28201_m,
    *MapColor::field_28200_n,
    *MapColor::field_28199_o;

MapColor::MapColor(int index, int value) {
    this->colorValue = value;
    this->colorIndex = index;
    //TODO
    //MapColor* mo = this;
    //mapColorArray.push_back(mo);
}


void MapColor::initMapColors()
{
    field_28212_b   = new MapColor(0, 0);
    field_28211_c   = new MapColor(1, 8368696);
    field_28210_d   = new MapColor(2, 16247203);
    field_28209_e   = new MapColor(3, 10987431);
    field_28208_f   = new MapColor(4, 16711680);
    field_28207_g   = new MapColor(5, 10526975);
    field_28206_h   = new MapColor(6, 10987431);
    field_28205_i   = new MapColor(7, 31744);
    field_28204_j   = new MapColor(8, 16777215);
    field_28203_k   = new MapColor(9, 10791096);
    field_28202_l   = new MapColor(10, 12020271);
    field_28201_m   = new MapColor(11, 7368816);
    field_28200_n   = new MapColor(12, 4210943);
    field_28199_o   = new MapColor(13, 6837042);
}