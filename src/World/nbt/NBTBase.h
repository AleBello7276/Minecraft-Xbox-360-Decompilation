#pragma once
#include <iostream>

class NBTBase{

public:
	
	virtual void readTagContents(std::istream& input) = 0; // Assuming DataInput is similar to std::istream
	virtual void writeTagContents(std::ostream& output) = 0; // Assuming DataInput is similar to std::istream
	virtual short getType() = 0;


	static char * getTagName(short NBTTag__EG);

	char * getKey() {
		return key == 0 ? "" : key;
	}

	NBTBase * setKey(char * newKey) {
		key = newKey;
		return this;
	}


	static NBTBase* readTag(std::istream& input){
		short var1 = input.read();
		if(var1 == 0) {
			return new NBTTagEnd();
		} else {
			NBTBase var2 = createTagOfType(var1);
			var2.key = var0.readUTF();
			var2.readTagContents(var0);
			return var2;
		}
	}

private:
	char * key;

}