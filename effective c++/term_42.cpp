//term 42:�˽�typename��˫������


/*****************  eg  1************************/
//bad
template <typename C>
void print2nd(const C & container)
{
	if (container.size() >= 2)
	{
		//�������ڽ���templateʱ������Ƕ�״������ƣ���ٶ���������
		C::const_iterator iter(container.begin());

	}
}


//current
template <typename C>
void print2nd(const C & container)
{
	if (container.size() >= 2)
	{
		//typename������ΪǶ�״������Ƶ�ǰ׺�ʣ��������������
		typename C::const_iterator iter(container.begin());

	}
}