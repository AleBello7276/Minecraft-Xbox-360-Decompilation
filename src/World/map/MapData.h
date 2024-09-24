#pragma once 

#include <string>
#include <vector>
#include <unordered_map>
#include "MapDataBase.h" 
#include "MapCoord.h" 
#include "../nbt/NBTTagCompound.h"

class EntityPlayer;    // Forward declaration
class ItemStack;       // Forward declaration
class MapInfo;         // Forward declaration

class MapData : public MapDataBase {
public:
    int field_28180_b;
    int field_28179_c;
    short field_28178_d;
    short field_28177_e;
    short field_28176_f[16384]; 
    int field_28175_g;
    std::vector<MapInfo*> field_28174_h; 
    std::unordered_map<EntityPlayer*, MapInfo*> field_28172_j; 
    std::vector<MapCoord*> field_28173_i; 

    MapData(const std::string& var1);

    
    void readFromNBT(NBTTagCompound* var1) override;
    void writeToNBT(NBTTagCompound* var1) override;
    void func_28169_a(EntityPlayer* var1, ItemStack* var2);
    void func_28170_a(int var1, int var2, int var3);
    void func_28171_a(short* var1);
};