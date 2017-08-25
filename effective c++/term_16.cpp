//成对使用new 和 delete时要采取相同形式

#include <string>


std::string * stringArray = new std::string[100];
delete[] stringArray;

std::string * stringPtr = new std::string;
delete stringPtr;

//尽量不对数组使用typedef形式
typedef std::string AddressLines[4];
std::string * pa1 = new AddressLines;
delete[] pa1;//容易写成delete pal;