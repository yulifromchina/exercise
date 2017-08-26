//term 41:�˽���ʽ�ӿںͱ����ڶ�̬



/***************************eg 1***********************************/
class Widget
{
public:
	Widget();
	virtual ~Widget();
	virtual std::size_t size() const;
	virtual void normalize();
	void swap(Widget & other);
};

//Widget�ӿ���һ����ʾ�ӿڣ���ΪWidget��Դ���пɼ�
//��ʾ�ӿ��ֺ�����ǩ��ʽ���ɣ��������ƣ��������ͣ���������
void doProcess(Widget & w)
{
	if (w.size() > 0 && w != someNastyWidget)
	{
		Widget temp(w);
		temp.normalize();
		temp.swap(w);
	}
}

/***************************eg 2***********************************/
//��ʽ�ӿ�
//���Կ���T����ʽ�ӿڵ�Լ���������ṩsize��Ա������֧��operator!=��
template <typename T>
void doProcess(T &w)
{
	if (w.size() > 0 && w != someNastyWidget)
	{
		Widget temp(w);
		temp.normalize();
		temp.swap(w);
	}
}
