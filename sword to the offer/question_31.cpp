//���������������
//����һ���������������������飬������һ����������������������飬������������͵����ֵ

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//��̬�滮
int MaxSub(vector<int> & data)
{
	if (data.empty())
		throw new exception("Invalid Parameter.");

	int len = data.size();
	if (len == 1)
		return data[0];

	int start = 0, end = 0;//��¼������������ʼ�ͽ����±�
	int max_sub = 0;//����������
	vector<int>dp; //��̬�滮����

	dp.push_back(data[0]);
	max_sub = data[0];

	int temp;
	for (int i = 1; i < len; ++i)
	{
		//���ǰ����������С�ڵ���0����ֱ�Ӷ���
		if (dp[i - 1] <= 0)
		{
			dp.push_back(data[i]);
			temp = i;//�����ʼλ��
		}
		else
			dp.push_back(data[i] + dp[i - 1]);

		if (dp[i] > max_sub)
		{
			max_sub = dp[i];
			start = temp;
			end = i;
		}
	}
	cout << "��������У���";
	for (int i = start; i <= end; ++i)
		cout << data[i] << ",";
	cout << ")" << endl;
	return max_sub;
}

int main()
{
	vector<int> data = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
	int result = MaxSub(data);
	cout << result << endl;
	return 0;
}