#pragma once 


class Logger
{
public:

    

    //Print string with args using OutputDebugStringA so i can see it in xenia console :}
    static void LogPrintf(const char* format, ...) {
        char buffer[256]; 

        va_list args;
        va_start(args, format);
        vsnprintf(buffer, sizeof(buffer), format, args);
        va_end(args);

        OutputDebugStringA(buffer);
    }

private:
    
};



