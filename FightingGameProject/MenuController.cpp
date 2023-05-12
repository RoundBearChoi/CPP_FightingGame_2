#include "MenuController.h"

namespace RB::HBE::Menu
{
    void MenuController::Init()
	{

	}

	void MenuController::OnUpdate()
	{
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 320, 20 }, "HurtBoxEditor", olc::WHITE, 2);

		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 60 }, "[ , ] : prev/next sprite", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 80 }, "PgUp , PgDown : prev/next frame", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 100 }, "INS : create box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 120 }, "DEL : delete box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 140 }, "O , P : prev/next box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 160 }, "WASD : move box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 180 }, "Q : enlarge box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 200 }, "E : shrink box", olc::WHITE);
		olc::Renderer::ptrPGE->DrawString(olc::vi2d{ 10, 220 }, "ENTER : save data", olc::WHITE);
	}

	void MenuController::OnFixedUpdate()
	{
		example1();
		example2();
	}

	void MenuController::example1()
	{
		//'{"a" : true, "b" : [false, null, "foo", 123]}'

		const char json[] = "{\"a\" : true, \"b\" : [false, null, \"foo\", 123]}";
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
		assert(array->length == 4);

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

		struct json_array_element_s* b_4th = b_3rd->next;
		assert(b_4th->next == NULL);
		
		struct json_number_s* n = json_value_as_number(b_4th->value);
		assert(0 == strcmp(n->number, "123"));

		std::stringstream strValue;
		strValue << n->number;

		int intValue;
		strValue >> intValue;

		/* Don't forget to free the one allocation! */
		free(root);
	}

	void MenuController::example2()
	{
		const char json[] = "{\"foo\" : { \"bar\" : [123, false, null, true], \"haz\" : \"haha\" }}";
		struct json_value_s* root = json_parse(json, strlen(json));
		assert(root);

		struct json_value_s* foo = json_value_as_object(root)->start->value;
		assert(foo);

		struct json_value_s* extracted = json_extract_value(foo);

		/* We can free root now because we've got a new allocation for extracted! */
		free(root);

		assert(json_value_as_object(extracted));

		/* Don't forget to free the one allocation! */
		free(extracted);
	}
}