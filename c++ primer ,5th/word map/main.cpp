#include "Filter.h"


int main()
{
	Filter obj_filter;
	obj_filter.AddBlackListFromFile("KeyWords.txt");//���C/C++�еĹؼ���
	obj_filter.AddRuleFromFile("Rule.txt");//��ȡ����
	obj_filter.TransFile("OriginText.txt");//����ԭ�ı�������result.txt

	return 0;
}