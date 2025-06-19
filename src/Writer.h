#pragma once

namespace RB
{
	class Writer
	{
	public:
		Writer() = default;
		~Writer() = default;

	public:
		bool WriteToLogFile();
	};
}

