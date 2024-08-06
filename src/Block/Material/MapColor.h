#pragma once

#include <array>

class MapColor {
public:
    static const MapColor field_28212_b;
    static const MapColor field_28211_c;
    static const MapColor field_28210_d;
    static const MapColor field_28209_e;
    static const MapColor field_28208_f;
    static const MapColor field_28207_g;
    static const MapColor field_28206_h;
    static const MapColor field_28205_i;
    static const MapColor field_28204_j;
    static const MapColor field_28203_k;
    static const MapColor field_28202_l;
    static const MapColor field_28201_m;
    static const MapColor field_28200_n;
    static const MapColor field_28199_o;
    static std::array<MapColor, 14> mapColorArray;

    int colorValue;
    int colorIndex;

private:
    MapColor(int index, int value) {
        this->colorValue = value;
        this->colorIndex = index;
    }
};

const MapColor MapColor::field_28212_b(0, 0);
const MapColor MapColor::field_28211_c(1, 8368696);
const MapColor MapColor::field_28210_d(2, 16247203);
const MapColor MapColor::field_28209_e(3, 10987431);
const MapColor MapColor::field_28208_f(4, 16711680);
const MapColor MapColor::field_28207_g(5, 10526975);
const MapColor MapColor::field_28206_h(6, 10987431);
const MapColor MapColor::field_28205_i(7, 31744);
const MapColor MapColor::field_28204_j(8, 16777215);
const MapColor MapColor::field_28203_k(9, 10791096);
const MapColor MapColor::field_28202_l(10, 12020271);
const MapColor MapColor::field_28201_m(11, 7368816);
const MapColor MapColor::field_28200_n(12, 4210943);
const MapColor MapColor::field_28199_o(13, 6837042);

std::array<MapColor, 14> MapColor::mapColorArray = {
    MapColor::field_28212_b, MapColor::field_28211_c, MapColor::field_28210_d, MapColor::field_28209_e,
    MapColor::field_28208_f, MapColor::field_28207_g, MapColor::field_28206_h, MapColor::field_28205_i,
    MapColor::field_28204_j, MapColor::field_28203_k, MapColor::field_28202_l, MapColor::field_28201_m,
    MapColor::field_28200_n, MapColor::field_28199_o
};