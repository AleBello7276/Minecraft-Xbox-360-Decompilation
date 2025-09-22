#include <string>

#include "../../World/nbt/NBTTagCompound.h"

class MapDataBase {
public:
    const std::string field_28168_a;

    
    MapDataBase(const std::string& var1) : field_28168_a(var1), dirty(false) { }

    
    virtual void readFromNBT(NBTTagCompound* var1) = 0;
    virtual void writeToNBT(NBTTagCompound* var1) = 0;

    void markDirty() 
    {
        setDirty(true);
    }
    void setDirty(bool var1) 
    {
        dirty = var1;
    }

   
    bool isDirty() const 
    {
        return dirty;
    }

private:
    bool dirty;
};
