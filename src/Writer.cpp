#include "Writer.h"

namespace RB
{
	bool Writer::WriteToLogFile(const std::string& path, const std::string& str, bool startClean)
	{
		// use truncate mode if startClean is true, append mode if false
    	std::ios::openmode mode = startClean ? std::ios::out : (std::ios::out | std::ios::app);
    	
		// try to open file
		std::ofstream outFile(path, mode);

    	if (!outFile.is_open())
		{
			return false;
    	}

    	outFile << str << std::endl;

    	if (outFile.fail())
		{
			return false;
    	}

    	// No explicit close() needed; destructor handles it
    	return true;
	}
}
