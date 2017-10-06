//question 1:��ɸ�ֵ���������
#include <iostream>

class CMyString
{
public:
	CMyString(char * pData = NULL) :m_pData(pData) {}
	CMyString(const CMyString &str) { m_pData = str.m_pData; }
	~CMyString(void) {}

	//ע�⣺�ѷ�����������Ϊ�������͵�����
	//�Ѵ���Ĳ�����������Ϊ�������������ĸ��ƹ��캯��
	CMyString& operator=(const CMyString str);
private:
	char * m_pData;
};

CMyString & CMyString::operator=(const CMyString str)
{
	//�жϴ���Ĳ����͵�ǰʵ���Ƿ���ͬһ������
	if (this == &str)
		return *this;

	//ʵ��ͨ����ʱ�����ͷ������ڴ棻��ʱ����������������Զ��������������ͷ��ڴ�
	//ͨ����������֤�쳣��ȫ
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