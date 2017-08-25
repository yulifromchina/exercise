//term13:以RAII对象管理资源

#include <memory>

//bad
class Investment {};
Investment * createInvestment();//假设返回指针，指向一个动态分配的Investment对象
void f()
{
	Investment * pInv = createInvestment();
	//... 假设在这里有return行为，会导致资源泄露
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