//�ɶ�ʹ��new �� deleteʱҪ��ȡ��ͬ��ʽ

#include <string>


std::string * stringArray = new std::string[100];
delete[] stringArray;

std::string * stringPtr = new std::string;
delete stringPtr;

//������������ʹ��typedef��ʽ
typedef std::string AddressLines[4];
std::string * pa1 = new AddressLines;
delete[] pa1;//����д��delete pal;