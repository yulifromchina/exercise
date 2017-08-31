#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template<typename T>
void doSomething(const T*pInts, size_t num)
{
	for (int i = 0; i < num; i++)
		std::cout << pInts[i];
	std::cout << std::endl;
}

size_t fillArray(int * array, int num)
{
	for (int i = 0; i < num; i++)
		array[i] = i;
	return num;
}


size_t fillChar(char * cstr, int num)
{
	for (int i = 0; i < num; i++)
		cstr[i] = 'a';
	return num;
}

int main()
{
	//��vector���ݸ���������ĺ���
	std::vector<int> vi{1,2,3};
	if(!vi.empty())
		doSomething(&vi[0], vi.size());

	//��string���ݸ���������ĺ���
	std::string s1("hello");
	if(s1.length()!=0)
		doSomething(s1.c_str(), s1.length());

	//����c����API��ʼ��vector
	const size_t max_num = 256;
	std::vector<int> v1(max_num);
	v1.resize(fillArray(&v1[0], 10));
	//test:except:0123456789
	for_each(v1.begin(), v1.end(), [](int c) {std::cout << c ; });
	std::cout << std::endl;

	//��c����API��ʼ��string
	std::vector<char> v2(max_num);
	size_t num = fillChar(&v2[0], 10);
	std::string s2(v2.begin(), v2.begin()+num);
	//test:except:aaaaaaaaaa
	std::cout << s2 << std::endl;
	return 0;
}