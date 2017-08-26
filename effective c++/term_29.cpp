//term 29: 为“异常安全”的努力是值得的


class PrettyMenu
{
public:
	void changeBackground(std::istream & imgSrc);
private:
	Mutex mutex;
	Image * bgImage;
	int imageChanges;
};

//bad
void PrettyMenu::changeBackground(std::istream & imgSrc)
{
	lock(&mutex);
	delete bgImage;
	++imageChanges;
	bgImage = new Image(imgSrc);//如果异常，导致原始数据被破坏
	unlock(&mutex);//如果前面异常，导致无法释放
}



//better
void PrettyMenu::changeBackground(std::istream & imgSrc)
{
	using std::swap;
	Lock(&mutex);//使用Lock class来管理，析构函数里释放
	std::sharepd_ptr<Image> pNew(new Image(bgImage));//构造副本，在副本修改数据
	pNew.reset(new Image(imgSrc));//以new的状态来决定是否下一步操作
	pNew->imageChanges++;
	swap(bgImage, pNew);//交换副本和原始值
}