#include "JsonWriter.h"

int main()
{
	auto writer = new JsonWriter;
	writer->start_array();
		writer->start_object();
			writer->key_value("name","Lillian");
			writer->key_value("age", 24);
		writer->end_object();

		writer->start_object();
			writer->key_value("skills", "c++");
			writer->key_value("skills", "python");
			writer->key_value("skills", "php");
			writer->key_value("skills", "js");

			writer->key("path");
				writer->start_array();
				writer->value("web");
				writer->value("windows");
				writer->value("linux");
				writer->end_array();

			writer->key("num");
				writer->start_array();
				writer->value(1);
				writer->value(3.14);
				writer->value(0.9);
				writer->end_array();
		writer->end_object();

		writer->value(false);
		writer->value_null();

	writer->end_array();
	return 0;
}