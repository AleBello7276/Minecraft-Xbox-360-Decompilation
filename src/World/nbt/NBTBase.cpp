#include "NBTBase.h"
#include <iostream>



static char * NBTBase::getTagName(short NBTTag__EG){
  switch(NBTTag__EG) {
  case 0:
    return "TAG_End";
  case 1:
    return "TAG_Byte";
  case 2:
    return "TAG_Short";
  case 3:
    return "TAG_Int";
  case 4:
    return "TAG_Long";
  case 5:
    return "TAG_Float";
  case 6:
    return "TAG_Double";
  case 7:
    return "TAG_Byte_Array";
  case 8:
    return "TAG_String";
  case 9:
    return "TAG_List";
  case 10:
    return "TAG_Compound";
  default:
    return "UNKNOWN";
  }
}

