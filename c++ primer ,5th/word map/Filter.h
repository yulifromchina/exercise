#pragma once
#include "head.h"
class Filter
{
public:
	Filter() = default;
	~Filter();

	bool AddRuleFromFile(const string & rule_file_name);//��rule_file_name ��ȡrule,��ӵ�trans_map
	bool AddBlackListFromFile(const string &black_list_name);//��black_list_name ��ȡҪ���˵Ĺؼ��֣���ӵ�black_list��
	bool TransFile(const string & file_name);//��file_name��ȡԭ�ı�������ת�����result.txt

private:
	bool CheckRule(const string & line);//���line���Ƿ������black_list������
	const string & transform(const string &s);//�ҵ�trans_map��s��Ӧ������
	map<string, string> trans_map;//����ӳ���
	set<string> black_list;//��Ҫ���˵Ĺؼ�������
};

