//term13:��RAII���������Դ

#include <memory>

//bad
class Investment {};
Investment * createInvestment();//���践��ָ�룬ָ��һ����̬�����Investment����
void f()
{
	Investment * pInv = createInvestment();
	//... ������������return��Ϊ���ᵼ����Դй¶
	delete pInv;
}


//better
//way1:
void f()
{
	std::auto_ptr<Investment> p1(createInvestment());
}

//way2:
void f()
{
	std::shared_ptr<Investment> p1(createInvestment());
}