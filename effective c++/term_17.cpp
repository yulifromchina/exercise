//term 17:�Զ�����佫newed������������ָ��
//�������������ִ��˳���ǲ�ȷ��������

int Priority();//��ʾ�����������Ȩ�ĺ���
void ProcessWidget(std::shared_ptr<Widget>pw, int Priority());//�Զ�̬����Ķ���pw��������Ȩ�Ĵ���


//bad
//����ʱ��
ProcessWidget(std::shared_ptr<Widget>(new Widget), Priority());
//�ڵ��ú���ǰ������������3������
//1������Priority
//2��ִ��new Widget
//3������shared_ptr���캯��

//���ִ��˳��Ϊ213������1�з����쳣�����ܻ�������Դй¶


//better--�������Կ������ĸ��������û���������е�����
std::shared_ptr<Widget> pw(new Widget);
ProcessWidget(pw, Priority());