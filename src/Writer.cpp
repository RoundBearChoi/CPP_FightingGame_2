#include "Writer.h"

namespace RB
{
	bool Writer::WriteToLogFile(const std::string& path, const std::string& str, bool startClean)
	{
		// Set mode: truncate if startClean is true, append if false
    	std::ios::openmode mode = startClean ? std::ios::out : (std::ios::out | std::ios::app);
    
    	// Open file (creates file if it doesn't exist)
    	std::ofstream outFile(path, mode);

    	if (!outFile.is_open())
		{
        	return false; // Failed to open or create file
    	}

    	// Write string and newline
    	outFile << str << std::endl;

    	if (outFile.fail())
		{
        	return false; // Write operation failed
    	}

    	// No explicit close needed; destructor handles it
    	return true;
	}
}
