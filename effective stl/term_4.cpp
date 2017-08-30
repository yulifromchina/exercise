//#include <list>
//#include <algorithm>
//#include <iostream>
//
//int main()
//{
//	std::list<int> list1{1};
//	std::list<int> list2{1,2,10,3,5,5,6,10,3,2};
//
//	typedef std::list<int> Container;
//	typedef Container::iterator CIterator;
//
//	list1.splice(list1.end(), list2, std::find(list2.begin(),list2.end(),5), std::find(list2.rbegin(), list2.rend(), 10).base());
//	for_each(list1.begin(), list1.end(), [](int c) {std::cout << c << " "; });
//	return 0;
//}