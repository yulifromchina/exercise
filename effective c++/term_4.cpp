//ȷ��������ʹ��ǰ�Ѿ���ʼ��
#include <string>


//ʹ�ó�Ա��ʼ���б�����Ǹ�ֵ
//bad
class ABEntry
{
public:
	ABEntry(const std::string &name);
private:
	std::string theName;
};

ABEntry::ABEntry(const std::string & name)
{
	theName = name; //��ֵ
}

//better
class ABEntry
{
public:
	ABEntry(const std::string &name);
private:
	std::string theName;
};

ABEntry::ABEntry(const std::string & name):theName(name){}//ʹ�ó�Ա��ʼ���б�


//����뵥Ԫ��ʼ������:��local-static�����滻non-local-static����
//bad
//���뵥ԪA
class FileSystem
{
public:
	std::size_t  numsDisk() const;
};
extern FileSystem fs;
//���뵥ԪB
class Directory
{
public:
	Directory(params)
	{
		std::size_t disks = fs.numsDisk();//���ܻ�ʹ��δ��ʼ����fs����
	}
};


//better
//���뵥ԪA
class FileSystem
{
public:
	std::size_t  numsDisk() const;
	FileSystem & fs() 
	{
		static FileSystem fs;
		return fs;
	}
};
extern FileSystem fs;
//���뵥ԪB
class Directory
{
public:
	Directory(params)
	{
		std::size_t disks = fs().numsDisk();//��local-static�滻non-local-static������ȷ��ʹ��ʱ�Ѿ���ʼ��
	}
};