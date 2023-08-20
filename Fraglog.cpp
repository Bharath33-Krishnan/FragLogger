#include "Fraglog.hpp" 
#include <algorithm>
#include <cstring>


FragLog::FragLog()
{
   try
   {
      file.open(logFile,std::ios::app);
      if(!file)
      {
         throw ErrorClass::DirectoryException; 
      } 
   }
   catch (ErrorClass error)
   {
      file.open("./Error.log",std::ios::out);
      switch (error) {
         case (ErrorClass::DirectoryException):
            file << logFile << " : directory does not exist" << std::endl;
            break;
         default:
            file << "Exception Occured" << std::endl;
      } 
      file.close();
   }
}


FragLog::~FragLog()
{
   file.close();
}
