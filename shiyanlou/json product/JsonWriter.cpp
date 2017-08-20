#include "JsonWriter.h"



JsonWriter::JsonWriter()
{
}


JsonWriter::~JsonWriter()
{
}

void JsonWriter::key(const char * key)
{
	start_child(true);
	std::cout << "\"" << key << "\"";
	std::cout << " : ";
}

void JsonWriter::value(const char * value)
{
	start_child(false);
	std::cout << "\"" << value << "\"";
}

void JsonWriter::value(bool value)
{
	start_child(false);
	std::cout << ((value?"true":"false"));
}

void JsonWriter::value(std::string value)
{
	start_child(false);
	std::cout <<"\""<< value.c_str()<<"\"";
}

void JsonWriter::value_null()
{
	start_child(false);
	std::cout << "null";
}

void JsonWriter::start_child(bool is_key)
{
	if (depth_.empty())
	{
		return;
	}
	container_type * container = depth_.top();
	if (container->child_count_>0 )
	{
		//如果类型是数组，并且前面有结点了，那么要输出逗号
		if (container->type_ == CONTAINER_TYPE_ARRAY)
		{
			//输出逗号后换行，缩进
			std::cout << "," << std::endl;
			indent();
		}
		//如果类型是对象且是前面的结点是对象的value部分，那么要输出逗号
		else if (container->type_ == CONTAINER_TYPE_OBJECT && container->is_key_ ==false)
		{
			//输出逗号后换行缩进
			std::cout << "," << std::endl;
			indent();
		}
	}
	else if (container->child_count_ == 0)
	{
		std::cout << std::endl;
		indent();
	}
	

	container->child_count_++;
	container->is_key_ = is_key;
}

void JsonWriter::start_container(CONTAINER_TYPE type)
{
	//先输出当前的格式再入栈
	start_child(false);
	depth_.push(new container_type(type));
	std::cout << ((type == CONTAINER_TYPE_OBJECT) ? "{" : "[");
}

void JsonWriter::end_container(CONTAINER_TYPE type)
{
	container_type * container = depth_.top();
	depth_.pop();
	
	//如果父亲的孩子大于0，则先输出空行
	if (container->child_count_ > 0)
	{
		std::cout<<std::endl;
		indent();
	}

	std::cout << ((type == CONTAINER_TYPE_OBJECT) ? "}" : "]");

	delete container;
}

void JsonWriter::indent()
{
	for (int i = 0; i < depth_.size(); i++)
	{
		std::cout << " ";
	}
}
