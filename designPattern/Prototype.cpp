//#include<iostream>
//#include<string>
//using namespace std;
//
//class ProtoType
//{
////protected���Ͷ��������ǿɷ��ʵģ������ǲ��ɷ��ʵ�
//protected:
//	int id;
//	string name;
//public:
//	virtual ProtoType * Clone() { return NULL; }
//	ProtoType() { }//���ÿ������캯��ʱ����ø����Ĭ�Ϲ��캯��
//	ProtoType(string s, int i) :name(s), id(i) {}
//};
//
//class ConcreteProtoType :public ProtoType
//{
//public:
//	//�ϳ�Ĭ�Ϻ���
//	//ConcreteProtoType() = default;
//	ConcreteProtoType(string s, int i) :ProtoType(s, i) {}
//	//�������캯��
//	ConcreteProtoType(const ConcreteProtoType & cpt)
//	{
//		this->id = cpt.id;
//		++this->id;
//		this->name = cpt.name + "_child";
//		cout << "�������캯������" << endl;
//	}
//	ConcreteProtoType * Clone()
//	{
//		return new ConcreteProtoType(*this);
//	}
//	void Show()
//	{
//		cout << "id:" << this->id << "  name:" << this->name << endl;
//	}
//};
//
//int main()
//{
//	ConcreteProtoType * c1 = new ConcreteProtoType("Lillian",1);
//	ConcreteProtoType * c2 = c1->Clone();
//	ConcreteProtoType * c3 = c2->Clone();
//	c1->Show();
//	c2->Show();
//	c3->Show();
//	return 0;
//}