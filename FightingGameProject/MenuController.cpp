#include "MenuController.h"

namespace RB::HBE::Menu
{
    void MenuController::Init()
	{
		const char json[] = "{\"a\" : true, \"b\" : [false, null, \"foo\"]}";
		struct json_value_s* root = json_parse(json, strlen(json));
		assert(root->type == json_type_object);

		struct json_object_s* object = (struct json_object_s*)root->payload;
		assert(object->length == 2);

		struct json_object_element_s* a = object->start;

		struct json_string_s* a_name = a->name;
		assert(0 == strcmp(a_name->string, "a"));
		assert(a_name->string_size == strlen("a"));

		struct json_value_s* a_value = a->value;
		assert(a_value->type == json_type_true);
		assert(a_value->payload == NULL);

		struct json_object_element_s* b = a->next;
		assert(b->next == NULL);

		struct json_string_s* b_name = b->name;
		assert(0 == strcmp(b_name->string, "b"));
		assert(b_name->string_size == strlen("b"));

		struct json_value_s* b_value = b->value;
		assert(b_value->type == json_type_array);

		struct json_array_s* array = (struct json_array_s*)b_value->payload;
		assert(array->length == 3);

		struct json_array_element_s* b_1st = array->start;

		struct json_value_s* b_1st_value = b_1st->value;
		assert(b_1st_value->type == json_type_false);
		assert(b_1st_value->payload == NULL);

		struct json_array_element_s* b_2nd = b_1st->next;

		struct json_value_s* b_2nd_value = b_2nd->value;
		assert(b_2nd_value->type == json_type_null);
		assert(b_2nd_value->payload == NULL);

		struct json_array_element_s* b_3rd = b_2nd->next;
		assert(b_3rd->next == NULL);

		struct json_value_s* b_3rd_value = b_3rd->value;
		assert(b_3rd_value->type == json_type_string);

		struct json_string_s* jstr = (struct json_string_s*)b_3rd_value->payload;
		std::string str = jstr->string;

		/* Don't forget to free the one allocation! */
		free(root);
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

	}
}