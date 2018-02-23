#include<iostream>
#include<string>
using namespace std;

class ProtoType
{
//protected类型对派生类是可访问的，对外是不可访问的
protected:
	int id;
	string name;
public:
	virtual ProtoType * Clone() { return NULL; }
	ProtoType() { }//调用拷贝构造函数时会调用父类的默认构造函数
	ProtoType(string s, int i) :name(s), id(i) {}
};

class ConcreteProtoType :public ProtoType
{
public:
	//合成默认函数
	//ConcreteProtoType() = default;
	ConcreteProtoType(string s, int i) :ProtoType(s, i) {}
	//拷贝构造函数
	ConcreteProtoType(const ConcreteProtoType & cpt)
	{
		this->id = cpt.id;
		++this->id;
		this->name = cpt.name + "_child";
		cout << "拷贝构造函数调用" << endl;
	}
	ConcreteProtoType * Clone()
	{
		return new ConcreteProtoType(*this);
	}
	void Show()
	{
		cout << "id:" << this->id << "  name:" << this->name << endl;
	}
};

int main()
{
	ConcreteProtoType * c1 = new ConcreteProtoType("Lillian",1);
	ConcreteProtoType * c2 = c1->Clone();
	ConcreteProtoType * c3 = c2->Clone();
	c1->Show();
	c2->Show();
	c3->Show();
	return 0;
}
