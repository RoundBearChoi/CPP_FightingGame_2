#include "HurtBoxDataLoader.h"

namespace RB::HurtBox
{
	void HurtBoxDataLoader::Init()
	{
		LoadSample();
		SaveSample();
	}

	void HurtBoxDataLoader::LoadSample()
	{
		std::cout << std::endl;
		std::cout << "loading sample HurtBoxData.." << std::endl;

		std::ifstream ifs("HurtBoxData/Sample.HurtBoxData");

		std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

		std::cout << content << std::endl;
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