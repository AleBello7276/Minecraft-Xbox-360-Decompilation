#pragma once

#include <string>

class IProgressUpdate 
{
public:
	virtual void func_594_b(std::string var1) const { }
	virtual void displayLoadingString(std::string var1) const { }
	virtual void setLoadingProgress(int var1) const { }
};
