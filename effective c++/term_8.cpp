//����8�������쳣������������

class DBConn;

//����������������׳��쳣����ô��
//way1:
DBConn:~DBConn
{
	try { db.close(); }
	 catch{
	   std::abort();//����׳��쳣��ǿ����ֹ����
	   }
}


//way2:
DBConn:~DBConn
{
	try { db.close(); }
catch{
	//������ת��¼����¼�¶�close�ĵ���ʧ��
}
}


//way3:���ͻ��ṩclose��������������׷�ٲ�����
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
			//������ת��¼����¼�¶�close�ĵ���ʧ��
		}
	}
}