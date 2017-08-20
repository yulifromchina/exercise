#include "Filter.h"


int main()
{
	Filter obj_filter;
	obj_filter.AddBlackListFromFile("KeyWords.txt");//添加C/C++中的关键字
	obj_filter.AddRuleFromFile("Rule.txt");//读取规则
	obj_filter.TransFile("OriginText.txt");//翻译原文本，生成result.txt

	return 0;
}