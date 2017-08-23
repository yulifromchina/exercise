//����3������ʹ��const
#include <vector>


char greeting[] = "hello world";
char * greeting = "hello world"; //non-const pointer, non-const data
const char * p = greeting; //const data, non-const pointer
char * const p = greeting;//non-const data, const pointer
const char * const p = greeting;//const data, const pointer

std::vector<int>vec;
const std::vector<int>::iterator it= vec.begin();//error operation: it++
std::vector<int>::const_iterator it= vec.begin();//error operation:*it=5


//ʹ��mutable��const�������޸ĳ�Ա����
class TextBlock
{
public:
	std::size_t length() const;
private:
	char * pText;
	mutable std::size_t textLength;  //
	mutable bool lengthIsValid;  //
};

std::size_t TextBlock::length() const
{
	if (!lengthIsValid)
	{
		textLength = std::strlen(pText);
		lengthIsValid = true;
	}
	return textLength;
}


//��const��non-const�����б����ظ����
//bad
class TextBlock1
{
public:
	const char & operator[](std::size_t position) const
	{
		//�߽���
		//��ʶ���ݷ���
		//��������������
		//...
		return text[position];
	}
	char & operator[](std::size_t position) 
	{
		//�߽���
		//��ʶ���ݷ���
		//��������������
		//...
		return text[position];
	}
private:
	std::string text;
};

//better
class TextBlock2
{
public:
	const char & operator[](std::size_t position) const
	{
		//�߽���
		//��ʶ���ݷ���
		//��������������
		//...
		return text[position];
	}
	char & operator[](std::size_t position)
	{
		//static_cast��ȫת�ͣ����const
		//const_cast:�Ƴ�const û�и��õļ���
		return const_cast<char &>(static_cast<const TextBlock2&>(*this)[position]);
	}
private:
	std::string text;
};