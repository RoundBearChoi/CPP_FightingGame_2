#include "Writer.h"

namespace RB
{
	bool Writer::WriteToLogFile(const std::string& path, const std::string& str, bool startClean)
	{
		// Use truncate mode if startClean is true, append mode if false
    	std::ios::openmode mode = startClean ? std::ios::out : (std::ios::out | std::ios::app);
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
