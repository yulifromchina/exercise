//question 1:完成赋值运算符函数
#include <iostream>

class CMyString
{
public:
	CMyString(char * pData = NULL) :m_pData(pData) {}
	CMyString(const CMyString &str) { m_pData = str.m_pData; }
	~CMyString(void) {}

	//注意：把返回类型声明为自身类型的引用
	//把传入的参数类型声明为常量，避免消耗复制构造函数
	CMyString& operator=(const CMyString str);
private:
	char * m_pData;
};

CMyString & CMyString::operator=(const CMyString str)
{
	//判断传入的参数和当前实例是否是同一个类型
	if (this == &str)
		return *this;

	//实例通过临时变量释放已有内存；临时变量在作用域外会自动调用析构函数释放内存
	//通过交换来保证异常安全
	CMyString strTemp(str);
	char * pTemp = strTemp.m_pData;
	strTemp.m_pData = m_pData;
	m_pData = pTemp;

	return *this;
}


int main()
{
	char * str = "hello world";
	CMyString c1(str);
	c1 = c1;

	CMyString c2 = c1;

	CMyString c3;
	c3 = c1 = c2;
	return 0;
}