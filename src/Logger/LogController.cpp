#include "LogController.h"

namespace RB::Log
{
	LogController::LogController()
	{
		_pStringStream = new std::stringstream();

		std::function<void()> func = std::bind(&LogController::_write, this);
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
		_writer.WriteToLogFile(_logFilePath, "test", true);	
	}

	void LogController::OnUpdate()
	{

	}

	void LogController::OnFixedUpdate()
	{
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

	void LogController::_write()
	{
		std::cout << "trying to write to log file.." << std::endl;

		//_writer.WriteToLogFile();
	}
}
