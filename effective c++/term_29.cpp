//term 29: Ϊ���쳣��ȫ����Ŭ����ֵ�õ�


class PrettyMenu
{
public:
	void changeBackground(std::istream & imgSrc);
private:
	Mutex mutex;
	Image * bgImage;
	int imageChanges;
};

//bad
void PrettyMenu::changeBackground(std::istream & imgSrc)
{
	lock(&mutex);
	delete bgImage;
	++imageChanges;
	bgImage = new Image(imgSrc);//����쳣������ԭʼ���ݱ��ƻ�
	unlock(&mutex);//���ǰ���쳣�������޷��ͷ�
}



//better
void PrettyMenu::changeBackground(std::istream & imgSrc)
{
	using std::swap;
	Lock(&mutex);//ʹ��Lock class�����������������ͷ�
	std::sharepd_ptr<Image> pNew(new Image(bgImage));//���츱�����ڸ����޸�����
	pNew.reset(new Image(imgSrc));//��new��״̬�������Ƿ���һ������
	pNew->imageChanges++;
	swap(bgImage, pNew);//����������ԭʼֵ
}