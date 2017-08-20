#pragma once
#include <iostream>
#include <stack>
#include <memory>

class JsonWriter
{
public:
	JsonWriter();
	~JsonWriter();

	//�ṩ���û��Ľӿ�

	void start_array() { start_container(CONTAINER_TYPE_ARRAY); }
	void end_array() { end_container(CONTAINER_TYPE_ARRAY); }
	void start_object() { start_container(CONTAINER_TYPE_OBJECT); }
	void end_object() { end_container(CONTAINER_TYPE_OBJECT); }
	
	void key(const char * key);

	//value()���������ͣ��������������͵ģ�����ʽ��ͬ����Ҫ�������壻
	//���������͵ģ�����ʽ��ͬ��ͨ��#define����
	void value(const char * value);
	void value(bool value);
	void value(std::string value);
	void value_null();

	//key_value()����ȫ��ͨ��#define���ػ��

#define VALUE_DEF(t) void value(t value){start_child(false);std::cout<<value;}

	VALUE_DEF(int)
	VALUE_DEF(float)
	VALUE_DEF(double)

#define KEY_VALUE_DEF(t) void key_value(const char * key_, t value_){key(key_);value(value_); }
	KEY_VALUE_DEF(int)
	KEY_VALUE_DEF(float)
	KEY_VALUE_DEF(double)
	KEY_VALUE_DEF(std::string)
	KEY_VALUE_DEF(const char *)
	KEY_VALUE_DEF(bool)
	
private:
	//��һ��ջdepth_���JSON�ṹ����ȣ�ÿǶ��һ����[]�����ߡ�{}�������+1����ȿ���depth_.size()�õ���
	//��Ҫ���Ƕ�׵Ķ���ģ�1�����ͣ�2���ӽڵ���� 
	//3��is_key_������CONTAINER_TYPE_OBJECT���ͣ���һ������Ƿ���key����
	enum CONTAINER_TYPE
	{
		CONTAINER_TYPE_ARRAY,
		CONTAINER_TYPE_OBJECT
	};
	struct container_type
	{
		CONTAINER_TYPE type_;
		int child_count_;
		bool is_key_;

		//���캯��
		container_type(CONTAINER_TYPE type):
			type_(type), child_count_(0)
		{ }
	};
	using container_type = struct container_type;
	std::stack<container_type *> depth_;

	//ÿһ��start_xxx������ʼʱ���ã����ݵ�ǰջdepth_�͵�ǰ�����ߵ����������������ĸ�ʽ
	//�������������С�����
	void start_child(bool is_key);

	//
	void start_container(CONTAINER_TYPE type);
	void end_container(CONTAINER_TYPE type);

	void indent();
	
};

