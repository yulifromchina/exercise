//term 23:宁以non-friend && non-member（非成员同时非友元）函数替换member函数来增强封装性

/******************************eg 1***************************/
class WebBrowser
{
public:
	void clearCache();
	void clearHistory();
	void removeCookies();

	//bad:越多的函数可以访问数据，封装性就越低
	//void clearEverything()
	//{
	//	clearCache();
	//	clearHistory();
	//	removeCookies();
	//}
};



//better:非成员&&非友元不会降低封装性
void clearEverything(WebBrowser &wb)
{
	wb.clearCache();
	wb.clearHistory();
	wb.removeCookies();
}


//good：让clearEverything和WebBrowser处于同一个命名空间
namespace WebBrowserStuff
{
	class WebBroser{};
	void clearEverything(WebBrowser &wb);
}


//good:分离便利函数--C++标准程序库的组织方式
//webBrowser.h：
namespace WebBrowserStuff
{
	class WebBroser {};
}

//webBrowserbookmark.h：
namespace WebBrowserStuff
{
	//与书签相关的便利函数
}

//webBrowsercookie.h：
namespace WebBrowserStuff
{
	//与cookie相关的便利函数
}