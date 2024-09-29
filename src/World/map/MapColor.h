#pragma once

#include <vector>

class MapColor {
public:


    static MapColor
            *field_28212_b,
            *field_28211_c,
            *field_28210_d,
            *field_28209_e,
            *field_28208_f,
            *field_28207_g,
            *field_28206_h,
            *field_28205_i,
            *field_28204_j,
            *field_28203_k,
            *field_28202_l,
            *field_28201_m,
            *field_28200_n,
            *field_28199_o;
    
    static void statiCtor();
    

    static const std::vector<MapColor*> mapColorArray;

    int colorValue;
    int colorIndex;

    MapColor(int index, int value);
};

