//确定对象在使用前已经初始化
#include <string>


//使用成员初始化列表而不是赋值
//bad
class ABEntry
{
public:
	ABEntry(const std::string &name);
private:
	std::string theName;
};

ABEntry::ABEntry(const std::string & name)
{
	theName = name; //赋值
}

//better
class ABEntry
{
public:
	ABEntry(const std::string &name);
private:
	std::string theName;
};

ABEntry::ABEntry(const std::string & name):theName(name){}//使用成员初始化列表


//跨编译单元初始化问题:用local-static对象替换non-local-static对象
//bad
//编译单元A
class FileSystem
{
public:
	std::size_t  numsDisk() const;
};
extern FileSystem fs;
//编译单元B
class Directory
{
public:
	Directory(params)
	{
		std::size_t disks = fs.numsDisk();//可能会使用未初始化的fs对象
	}
};


//better
//编译单元A
class FileSystem
{
public:
	std::size_t  numsDisk() const;
	FileSystem & fs() 
	{
		static FileSystem fs;
		return fs;
	}
};
extern FileSystem fs;
//编译单元B
class Directory
{
public:
	Directory(params)
	{
		std::size_t disks = fs().numsDisk();//用local-static替换non-local-static，可以确保使用时已经初始化
	}
};