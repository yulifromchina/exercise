//term 17:以独立语句将newed对象置于智能指针
//解决函数参数的执行顺序是不确定的问题

int Priority();//揭示处理程序优先权的函数
void ProcessWidget(std::shared_ptr<Widget>pw, int Priority());//对动态分配的对象pw带有优先权的处理


//bad
//调用时：
ProcessWidget(std::shared_ptr<Widget>(new Widget), Priority());
//在调用函数前，编译器会做3件事情
//1、调用Priority
//2、执行new Widget
//3、调用shared_ptr构造函数

//如果执行顺序为213，且在1中发生异常，可能会引发资源泄露


//better--编译器对跨域语句的各项操作，没有重新排列的自由
std::shared_ptr<Widget> pw(new Widget);
ProcessWidget(pw, Priority());