//term 28:���ⷵ��handlesָ������ڲ��ɷ�


//bad
class Rectangle
{
public:
	Point& upperleft() const { return PData->ulhc; }
	//����һ���ڲ����ݵ����ã������ݿ��ܱ���ȡ���޸�
};


//better
class Rectangle
{
public:
	const Point& upperleft() const { return PData->ulhc; }
	//���ܱ��ⲿ�޸��ˣ��������������������ˣ����ܵ����ⲿָ������
};