#pragma once
#include "head.h"
class Filter
{
public:
	Filter() = default;
	~Filter();

	bool AddRuleFromFile(const string & rule_file_name);//从rule_file_name 读取rule,添加到trans_map
	bool AddBlackListFromFile(const string &black_list_name);//从black_list_name 读取要过滤的关键字，添加到black_list中
	bool TransFile(const string & file_name);//从file_name读取原文本，生成转化后的result.txt

private:
	bool CheckRule(const string & line);//检查line中是否包含了black_list的内容
	const string & transform(const string &s);//找到trans_map中s对应的内容
	map<string, string> trans_map;//规则映射表
	set<string> black_list;//需要过滤的关键字名单
};

