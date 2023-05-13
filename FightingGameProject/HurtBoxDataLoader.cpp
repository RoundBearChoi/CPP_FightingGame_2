#include "HurtBoxDataLoader.h"

namespace RB::HurtBox
{
	void HurtBoxDataLoader::Init()
	{
		SaveSample();
	}

	void HurtBoxDataLoader::SaveSample()
	{
		std::string path = "HurtBoxData/";

		path += "Sample.HurtBoxData";

		std::ofstream file(path);

		if (file.is_open())
		{
			file << "{" << std::endl;
			file << "\"a\" : true," << std::endl;
			file << "\"b\" : [false, null, \"foo\", 123, 3.14]" << std::endl;
			file << "}" << std::endl;

			file.flush();
			file.close();
		}
	}
}