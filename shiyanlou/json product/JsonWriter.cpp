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
		//������������飬����ǰ���н���ˣ���ôҪ�������
		if (container->type_ == CONTAINER_TYPE_ARRAY)
		{
			//������ź��У�����
			std::cout << "," << std::endl;
			indent();
		}
		//��������Ƕ�������ǰ��Ľ���Ƕ����value���֣���ôҪ�������
		else if (container->type_ == CONTAINER_TYPE_OBJECT && container->is_key_ ==false)
		{
			//������ź�������
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
	//�������ǰ�ĸ�ʽ����ջ
	start_child(false);
	depth_.push(new container_type(type));
	std::cout << ((type == CONTAINER_TYPE_OBJECT) ? "{" : "[");
}

void JsonWriter::end_container(CONTAINER_TYPE type)
{
	container_type * container = depth_.top();
	depth_.pop();
	
	//������׵ĺ��Ӵ���0�������������
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
