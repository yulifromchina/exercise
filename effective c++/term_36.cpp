//term 36:�������¶���̳ж�����non-virtual����

//bad:
class B
{
public:
	void mf();
};
class D :public B
{
public:
	void mf();
};

B x;
B *pB = &x;//����ָ��ָ����������󣬵��õ���virutal�����Ļ���ȡ������ָ�����������(��̬��)
D *pD = &x;
pB->mf();//����non-virtual,��ȡ����ָ��---���õ���B::mf();
pD->mf();//���õ���D::mf();