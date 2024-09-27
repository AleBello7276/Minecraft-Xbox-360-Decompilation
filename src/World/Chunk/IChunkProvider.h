#pragma once

#include <string>
#include "Chunk.h"
#include "../../Util/IProgressUpdate.h"

class IChunkProvider 
{
public:
	virtual bool chunkExists(int var1, int var2);
	virtual Chunk* provideChunk(int var1, int var2);
	virtual Chunk* func_538_d(int var1, int var2);
	virtual void populate(IChunkProvider* var1, int var2, int var3);
	virtual bool saveChunks(bool var1, IProgressUpdate* var2);
	virtual bool func_532_a();
	virtual bool func_536_b();
	virtual std::string makeString();
}
