#include "LogController.h"

namespace RB::Log
{
	LogController::LogController()
	{
		//std::cout << "log controller created" << std::endl;

		_pStringStream = new std::stringstream();

		std::function<void()> func = std::bind(&LogController::_WriteToFile, this);
		_skipper.SetFunction(func);
		_skipper.SetSkipFrames(60);
	}

	LogController::~LogController()
	{
		delete _pStringStream;
		_pStringStream = nullptr;
	}
	
	void LogController::Init()
	{
		// try to open file
		std::ofstream outFile(_file, std::ios::app);
		
		if (!outFile)
		{
			// if file doesn't exist, create
        	outFile.open(_file, std::ios::out);
        
			if (outFile.is_open())
			{
            	outFile.close();
        	}
    	}
		else
		{
        	// if file exists, close and reopen in truncate mode to clear it
        	outFile.close();

        	outFile.open(_file, std::ios::out | std::ios::trunc);
        
			if (outFile.is_open())
			{
            	outFile.close();
        	}
    	}
	}

	void LogController::OnUpdate()
	{

	}

	void LogController::OnFixedUpdate()
	{
		//std::cout << "logcontroller fixedupdate" << std::endl;

		_skipper.DoFixedUpdate();
	}
	bool LogController::AddToStream(const std::string& str)
	{
		// get game frame and then concatenate with str
		// frame | player | type | actual string
		// 3 | p1 | input | weak punch down
		// 10 | p2 | attackCollider | pos 231 -1321 width 300 height 100
	
		std::string strFrame = RB::gFrame.toString();

		(*_pStringStream) << strFrame << " | " << std::endl;

		return true;
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

	void LogController::_WriteToFile()
	{
		std::cout << "trying to write to log file.." << std::endl;

		_writer.WriteToLogFile();
	}
}
