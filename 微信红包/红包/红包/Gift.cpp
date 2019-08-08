#include<iostream>
#include<vector>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

//class Gift 
//{
//public:
//	int getValue(vector<int> gifts, int n) 
//	{
//		int cout1 = 0;
//		int i = 0;//记录的第一个值
//		int j = 0;//记录的第二个值
//		for (i = 0; i <= n; i++)
//		{
//			for (j = 0; j <= n; j++)
//			{
//				if (gifts[i] == gifts[j])
//				{
//					cout1++;
//				}
//			}
//			if (cout1 > n / 2)
//			{
//				return gifts[i];
//			}
//			else
//			{
//				cout1 = 0;
//			}
//		}
//		return 0;
//	}
//};

int getValue(int gifts[], int n);
int main()
{
	int gifts[5] = { 1,2,3,2,2 };
	cout << getValue(gifts, 5);
	system("pause");
	return 0;
}


int getValue(int gifts[], int n)
{
	int cout1 = 0;
	int i = 0;//记录的第一个值
	int j = 0;//记录的第二个值
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (gifts[i] == gifts[j])
			{
				cout1++;
			}
		}
		if (cout1 > n / 2)
		{
			return gifts[i];
		}
		else
		{
			cout1 = 0;
		}
	}
	return 0;
}
