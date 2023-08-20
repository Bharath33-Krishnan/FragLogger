#pragma once

#include <fstream>
#include <cstring>
class FragLog 
{
public:
   FragLog();
   inline void write(const char* log){ file<<log<<std::endl; }
   ~FragLog();


private:
   std::ofstream file;
   const char* logFile = "./logs/EngineLog.log";
};

enum class ErrorClass 
{
   DirectoryException = -1
};
