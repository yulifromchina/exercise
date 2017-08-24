//条款8：别让异常逃离析构函数

class DBConn;

//如果析构函数必须抛出异常，那么：
//way1:
DBConn:~DBConn
{
	try { db.close(); }
	 catch{
	   std::abort();//如果抛出异常就强行终止程序
	   }
}


//way2:
DBConn:~DBConn
{
	try { db.close(); }
catch{
	//制作运转记录，记录下对close的调用失败
}
}


//way3:给客户提供close函数，析构函数追踪并管理
void DBConn::close()
{
	db.close();
	closed = true;
}
DBConn:~DBConn
{
	if (!closed)
	{
		try
		{	
			db.close();
		}
		catch ()
		{
			//制作运转记录，记录下对close的调用失败
		}
	}
}