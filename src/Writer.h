#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

namespace RB
{
	class Writer
	{
	public:
		Writer() = default;
		~Writer() = default;

	public:
		bool WriteToLogFile(const std::string& path, const std::string& str, bool startClean);
	};
}

