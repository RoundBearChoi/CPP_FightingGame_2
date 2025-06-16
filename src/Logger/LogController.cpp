#include "LogController.h"

namespace RB::Log
{
	LogController::LogController()
	{
		_pStringStream = new std::stringstream();
	}

	LogController::~LogController()
	{
		delete _pStringStream;
		_pStringStream = nullptr;
	}
	
	void LogController::Init()
	{
		//std::cout << "ini test log controller" << std::endl;
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
