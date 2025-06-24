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
		std::string ascii = R"(
▗▄▄▖  ▗▄▖ ▗▖ ▗▖▗▖  ▗▖▗▄▄▄ ▗▄▄▖ ▗▄▄▄▖ ▗▄▖ ▗▄▄▖  ▗▄▄▖ ▗▄▖ ▗▖  ▗▖▗▄▄▄▖ ▗▄▄▖
▐▌ ▐▌▐▌ ▐▌▐▌ ▐▌▐▛▚▖▐▌▐▌  █▐▌ ▐▌▐▌   ▐▌ ▐▌▐▌ ▐▌▐▌   ▐▌ ▐▌▐▛▚▞▜▌▐▌   ▐▌   
▐▛▀▚▖▐▌ ▐▌▐▌ ▐▌▐▌ ▝▜▌▐▌  █▐▛▀▚▖▐▛▀▀▘▐▛▀▜▌▐▛▀▚▖▐▌▝▜▌▐▛▀▜▌▐▌  ▐▌▐▛▀▀▘ ▝▀▚▖
▐▌ ▐▌▝▚▄▞▘▝▚▄▞▘▐▌  ▐▌▐▙▄▄▀▐▙▄▞▘▐▙▄▄▖▐▌ ▐▌▐▌ ▐▌▝▚▄▞▘▐▌ ▐▌▐▌  ▐▌▐▙▄▄▖▗▄▄▞▘

)";

		_writer.WriteToLogFile(_logFilePath, ascii, true);	
	}

	void LogController::OnUpdate()
	{

	}

	void LogController::OnFixedUpdate()
	{
		_skipper.DoFixedUpdate();
	}

	bool LogController::AddToStream(Players::PlayerID playerID, Log::LOG_TYPE logType, const std::string& str)
	{
		// get game frame and then concatenate with str
		// frame | player | type | actual string
		// 3 | p1 | input | weak punch down
		// 10 | p2 | attackCollider | pos 231 -1321 width 300 height 100
	
		std::string frame = RB::gFrame.toString();

		(*_pStringStream) << frame << " | " << playerID._to_string() << " | "  << logType._to_string() << " | " << str << std::endl;

		return true;
	}

	void LogController::_write()
	{
		if (_pStringStream && !_pStringStream->str().empty())
    	{		
			std::cout << "trying to write to log file.." << std::endl;

			_writer.WriteToLogFile(_logFilePath, _pStringStream->str(), false);

			_pStringStream->str("");
    	}
	}
}
