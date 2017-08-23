#include "HfmTree.h"

int main()
{
	int weight[] = { 5,4,3,2,1 };
	Node * tree = HfmCreate(weight, sizeof(weight)/sizeof(int));
	std::cout << "»ô·òÂü±àÂë£º" << std::endl;
	GetHfmCode(tree, sizeof(weight) / sizeof(int));
	return 0;
}