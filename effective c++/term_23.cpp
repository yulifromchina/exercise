//term 23:����non-friend && non-member���ǳ�Աͬʱ����Ԫ�������滻member��������ǿ��װ��

/******************************eg 1***************************/
class WebBrowser
{
public:
	void clearCache();
	void clearHistory();
	void removeCookies();

	//bad:Խ��ĺ������Է������ݣ���װ�Ծ�Խ��
	//void clearEverything()
	//{
	//	clearCache();
	//	clearHistory();
	//	removeCookies();
	//}
};



//better:�ǳ�Ա&&����Ԫ���ή�ͷ�װ��
void clearEverything(WebBrowser &wb)
{
	wb.clearCache();
	wb.clearHistory();
	wb.removeCookies();
}


//good����clearEverything��WebBrowser����ͬһ�������ռ�
namespace WebBrowserStuff
{
	class WebBroser{};
	void clearEverything(WebBrowser &wb);
}


//good:�����������--C++��׼��������֯��ʽ
//webBrowser.h��
namespace WebBrowserStuff
{
	class WebBroser {};
}

//webBrowserbookmark.h��
namespace WebBrowserStuff
{
	//����ǩ��صı�������
}

//webBrowsercookie.h��
namespace WebBrowserStuff
{
	//��cookie��صı�������
}