#pragma once
#include <iostream>
#include <stack>
#include <memory>

class JsonWriter
{
public:
	JsonWriter();
	~JsonWriter();

	//提供给用户的接口

	void start_array() { start_container(CONTAINER_TYPE_ARRAY); }
	void end_array() { end_container(CONTAINER_TYPE_ARRAY); }
	void start_object() { start_container(CONTAINER_TYPE_OBJECT); }
	void end_object() { end_container(CONTAINER_TYPE_OBJECT); }
	
	void key(const char * key);

	//value()参数的类型，是下面三种类型的，处理方式不同，需要单独定义；
	//是数字类型的，处理方式相同，通过#define重载
	void value(const char * value);
	void value(bool value);
	void value(std::string value);
	void value_null();

	//key_value()可由全部通过#define重载获得

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
	//用一个栈depth_存放JSON结构的深度，每嵌套一个“[]”或者“{}”，深度+1，深度可由depth_.size()得到；
	//需要存放嵌套的对象的：1）类型，2）子节点个数 
	//3）is_key_，对于CONTAINER_TYPE_OBJECT类型，上一个结点是否是key部分
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

		//构造函数
		container_type(CONTAINER_TYPE type):
			type_(type), child_count_(0)
		{ }
	};
	using container_type = struct container_type;
	std::stack<container_type *> depth_;

	//每一个start_xxx函数开始时调用，根据当前栈depth_和当前调用者的情况，来决定输出的格式
	//包括缩进、换行、逗号
	void start_child(bool is_key);

	//
	void start_container(CONTAINER_TYPE type);
	void end_container(CONTAINER_TYPE type);

	void indent();
	
};

