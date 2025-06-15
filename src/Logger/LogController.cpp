#include "LogController.h"

namespace RB::Log
{
	LogController::~LogController()
	{

	}
	
	void LogController::Init()
	{

	}

	void LogController::OnUpdate()
	{

	}

	void LogController::OnFixedUpdate()
	{

	}

	bool LogController::WriteToFile(const std::string& path, const std::stringstream& stream)
	{
    	std::ofstream outFile(path, std::ios::out | std::ios::binary);

    	if (!outFile.is_open())
		{
        	return false;
		}

    	outFile << stream.str();
    	outFile.close();

		return true;
	}
}
