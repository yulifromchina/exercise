#include "Filter.h"

Filter::~Filter()
{
}


/*
** 函数名：AddRuleFromFile
** 功能：从rule_file_name 读取rule,添加到trans_map;非法的规则，生成到error.txt中
** 输入：rule_file_name (规则文件的名称)
** 输出：true(添加成功)  false(添加失败)
*/
bool Filter::AddRuleFromFile(const string & rule_file_name)
{
	ifstream in(rule_file_name);
	if (!in.is_open())
	{
		cerr << "Opening " << rule_file_name << " fail!" << endl;
		return false;
	}
	string key;  //要转换的单词
	string value; //转换后的内容
	size_t line_count = 0;//记录当前行数
	while (in >> key && getline(in, value))
	{
		//去掉value前的空格
		line_count++;
		size_t length = value.length();
		size_t begin = 0;
		while (begin < length && value[begin] == ' ')
		{
			begin++;
		}
		value = value.substr(begin);

		if (CheckRule(key) && CheckRule(value))//规则合法，记录到trans_map
		{

			trans_map[key] = value;
		}
		else//规则不合法，记录错误规则到error.txt
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
** 函数名：CheckRule
** 功能：检查line中是否包含了black_list的内容
** 输入：line (读取的一行文本)
** 输出：true(不包含black_list的内容)  false(包含black_list的内容)
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
** 函数名：AddBlackListFromFile
** 功能：从black_list_name 读取要过滤的关键字，添加到black_list中
** 输入：black_list_name(含有需要过滤的关键字的文件)
** 输出：true(添加成功)  false(添加失败)
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
** 函数名：transform
** 功能：找到trans_map中s对应的内容
** 输入：s(待转换的单词)
** 输出：原文本 或 转换后的文本
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
** 函数名：TransFile
** 功能：从file_name读取原文本，生成转化后的result.txt
** 输入参数：file_name(原文本文件)
** 输出：true(转换成功)  false(转换失败)
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
		bool firstword = true;//控制是否打印空格
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
