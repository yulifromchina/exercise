#include "Filter.h"

Filter::~Filter()
{
}


/*
** ��������AddRuleFromFile
** ���ܣ���rule_file_name ��ȡrule,��ӵ�trans_map;�Ƿ��Ĺ������ɵ�error.txt��
** ���룺rule_file_name (�����ļ�������)
** �����true(��ӳɹ�)  false(���ʧ��)
*/
bool Filter::AddRuleFromFile(const string & rule_file_name)
{
	ifstream in(rule_file_name);
	if (!in.is_open())
	{
		cerr << "Opening " << rule_file_name << " fail!" << endl;
		return false;
	}
	string key;  //Ҫת���ĵ���
	string value; //ת���������
	size_t line_count = 0;//��¼��ǰ����
	while (in >> key && getline(in, value))
	{
		//ȥ��valueǰ�Ŀո�
		line_count++;
		size_t length = value.length();
		size_t begin = 0;
		while (begin < length && value[begin] == ' ')
		{
			begin++;
		}
		value = value.substr(begin);

		if (CheckRule(key) && CheckRule(value))//����Ϸ�����¼��trans_map
		{

			trans_map[key] = value;
		}
		else//���򲻺Ϸ�����¼�������error.txt
		{
			ofstream out("error.txt", ios::app);
			if (!out.is_open())
			{
				cerr << "Create error.txt fail!" << endl;
				return false;
			}
			out << rule_file_name << " line:" << line_count << " " << key << " " << value << endl;
			out.close();
		}
	}
#ifdef DEBUG
	cout << "Rules:" << endl;
	for (const auto & it : trans_map)
	{
		cout << it.first << " " << it.second << endl;
	}
#endif // DEBUG
	in.close();
	return true;
}


/*
** ��������CheckRule
** ���ܣ����line���Ƿ������black_list������
** ���룺line (��ȡ��һ���ı�)
** �����true(������black_list������)  false(����black_list������)
*/
bool Filter::CheckRule(const string & line)
{
	if (black_list.find(line)!=black_list.end())
	{
		return false;
	}
	return true;
}


/*
** ��������AddBlackListFromFile
** ���ܣ���black_list_name ��ȡҪ���˵Ĺؼ��֣���ӵ�black_list��
** ���룺black_list_name(������Ҫ���˵Ĺؼ��ֵ��ļ�)
** �����true(��ӳɹ�)  false(���ʧ��)
*/
bool Filter::AddBlackListFromFile(const string &black_list_name)
{
	ifstream in(black_list_name);
	if (!in.is_open())
	{
		cerr << "Opening " << black_list_name << " fail!" << endl;
		return false;
	}
	string line;
	while (getline(in, line))
	{
		black_list.insert(line);
	}	
#ifdef DEBUG
	cout << "black_list:" << endl;
	for (const auto & it : black_list)
	{
		cout << it<< " ";
	}
	cout << endl;
#endif // DEBUG
	in.close();
	return true;
}

/*
** ��������transform
** ���ܣ��ҵ�trans_map��s��Ӧ������
** ���룺s(��ת���ĵ���)
** �����ԭ�ı� �� ת������ı�
*/
const string & Filter::transform(const string &s)
{
	auto map_it = trans_map.find(s);
	if (map_it != trans_map.cend())
	{
		return map_it->second;
	}
	else {
		return s;
	}
}

/*
** ��������TransFile
** ���ܣ���file_name��ȡԭ�ı�������ת�����result.txt
** ���������file_name(ԭ�ı��ļ�)
** �����true(ת���ɹ�)  false(ת��ʧ��)
*/
bool Filter::TransFile(const string & file_name)
{
	ifstream in(file_name);
	ofstream out("result.txt");
	if (!in.is_open())
	{
		cerr << "Opening " << file_name << " fail!" << endl;
		return false;
	}
	if (!out.is_open())
	{
		cerr << "Creating result.txt fail!" << endl;
		return false;
	}
	string text;
	while (getline(in, text))
	{
		istringstream stream(text);
		string word;
		bool firstword = true;//�����Ƿ��ӡ�ո�
		while (stream >> word)
		{
			if (firstword)
			{
				firstword = false;
			}
			else
			{
				out << " ";
			}
			out << transform(word);
		}
		out << endl;
	}
	in.close();
	out.close();
	return true;
}
