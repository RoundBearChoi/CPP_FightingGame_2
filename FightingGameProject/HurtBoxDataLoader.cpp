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

		std::string loadedStr((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

		loadedStr.erase(std::remove(loadedStr.begin(), loadedStr.end(), '\n'), loadedStr.cend());

		std::cout << loadedStr << std::endl;

		const char* json = loadedStr.c_str();

		struct json_value_s* root = json_parse(json, strlen(json));

		struct json_object_s* object = json_value_as_object(root);
		assert(object != NULL);
		assert(object->length == 2);

		struct json_object_element_s* a = object->start;

		struct json_string_s* a_name = a->name;
		assert(0 == strcmp(a_name->string, "a"));
		assert(a_name->string_size == strlen("a"));

		struct json_value_s* a_value = a->value;
		assert(json_value_is_true(a_value));

		struct json_object_element_s* b = a->next;
		assert(b->next == NULL);

		struct json_string_s* b_name = b->name;
		assert(0 == strcmp(b_name->string, "b"));
		assert(b_name->string_size == strlen("b"));

		struct json_array_s* array = json_value_as_array(b->value);
		assert(array->length == 5);

		struct json_array_element_s* b_1st = array->start;

		struct json_value_s* b_1st_value = b_1st->value;
		assert(json_value_is_false(b_1st_value));

		struct json_array_element_s* b_2nd = b_1st->next;

		struct json_value_s* b_2nd_value = b_2nd->value;
		assert(json_value_is_null(b_2nd_value));

		struct json_array_element_s* b_3rd = b_2nd->next;
		assert(b_3rd->next != NULL);

		struct json_string_s* string = json_value_as_string(b_3rd->value);
		assert(string != NULL);
		assert(0 == strcmp(string->string, "foo"));
		assert(string->string_size == strlen("foo"));

		std::string s(string->string);

		struct json_array_element_s* b_4th = b_3rd->next;
		assert(b_4th->next != NULL);

		struct json_number_s* n4 = json_value_as_number(b_4th->value);
		assert(0 == strcmp(n4->number, "123"));

		std::stringstream str4;
		str4 << n4->number;

		int intValue;
		str4 >> intValue;

		assert(b_4th->next != NULL);

		struct json_array_element_s* b_5th = b_4th->next;
		struct json_number_s* n5 = json_value_as_number(b_5th->value);

		assert(b_5th->next == NULL);

		std::stringstream str5;
		str5 << n5->number;

		float floatValue;
		str5 >> floatValue;

		/* Don't forget to free the one allocation! */
		free(root);
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