//��Ʋ��ܱ��̳е���

//�ѹ��캯����������������Ϊ˽�к���

class SealedClass
{
public:
	static SealedClass * GetInstance()
	{
		return new SealedClass();
	}
	static void DeleteInstance(SealedClass * instance)
	{
		delete instance;
	}
private:
	SealedClass() {}
	~SealedClass() {}
};

int main()
{
	SealedClass * s = SealedClass::GetInstance();
	SealedClass::DeleteInstance(s);
	return 0;
}