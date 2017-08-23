//条款3：尽量使用const
#include <vector>


char greeting[] = "hello world";
char * greeting = "hello world"; //non-const pointer, non-const data
const char * p = greeting; //const data, non-const pointer
char * const p = greeting;//non-const data, const pointer
const char * const p = greeting;//const data, const pointer

std::vector<int>vec;
const std::vector<int>::iterator it= vec.begin();//error operation: it++
std::vector<int>::const_iterator it= vec.begin();//error operation:*it=5


//使用mutable在const函数中修改成员变量
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


//在const和non-const函数中避免重复检查
//bad
class TextBlock1
{
public:
	const char & operator[](std::size_t position) const
	{
		//边界检查
		//标识数据访问
		//检验数据完整性
		//...
		return text[position];
	}
	char & operator[](std::size_t position) 
	{
		//边界检查
		//标识数据访问
		//检验数据完整性
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
		//边界检查
		//标识数据访问
		//检验数据完整性
		//...
		return text[position];
	}
	char & operator[](std::size_t position)
	{
		//static_cast安全转型：添加const
		//const_cast:移除const 没有更好的技术
		return const_cast<char &>(static_cast<const TextBlock2&>(*this)[position]);
	}
private:
	std::string text;
};