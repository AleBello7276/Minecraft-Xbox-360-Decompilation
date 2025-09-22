#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
class NBTBase{

public:
	
	virtual void readTagContents(std::istream& input) = 0; // Assuming DataInput is similar to std::istream
	virtual void writeTagContents(std::ostream& output) = 0; // Assuming DataInput is similar to std::istream
	virtual short getType() = 0;

	std::string getKey() {
		return this->key == nullptr ? "" : this->key;
	}

	NBTBase* setKey(std::string var1) {
		this->key = var1;
		return this;
	}

	/*void java_writeUTF(std::ostream& output, const std::string& str) 
	{
		uint16_t length = (uint16_t)(str.size());
		output.write((const char*)(&length), sizeof(length));  
		// actually idk lol
		output.write(str.data(), length);  
	}*/

	static void writeTag(NBTBase* tag, std::ostream& output) 
	{
		/*short type = tag->getType();
   	 	output.write((const char*)(&type), sizeof(type));

		
		if(type != 0) {
			java_writeUTF(output, tag->getKey());
			tag->writeTagContents(output);
		}*/
	}

	static NBTBase* readTag(std::istream& input) 
	{
		/*short tagType;
		input.read((char*)(&tagType), sizeof(tagType));
		
		if (tagType == 0) {
			return new NBTTagEnd();
		} else 
		{
			NBTBase* tag = createTagOfType(tagType);
		
			uint16_t strLength;
			input.read((char*)(&strLength), sizeof(strLength));	
			std::string key(strLength, '\0');
			input.read(&key[0], strLength);  
			
			tag->key = key;
			tag->readTagContents(input);
			
			return tag;
		}*/
	}
	
	static std::string getTagName(short var0) {
		switch(var0) {
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

	static NBTBase createTagOfType(short var0) {
		switch(var0) {
		case 0:
			return new NBTTagEnd();
		case 1:
			return new NBTTagByte();
		case 2:
			return new NBTTagShort();
		case 3:
			return new NBTTagInt();
		case 4:
			return new NBTTagLong();
		case 5:
			return new NBTTagFloat();
		case 6:
			return new NBTTagDouble();
		case 7:
			return new NBTTagByteArray();
		case 8:
			return new NBTTagString();
		case 9:
			return new NBTTagList();
		case 10:
			return new NBTTagCompound();
		default:
			return null;
		}
	}


private:
	std::string key;

};