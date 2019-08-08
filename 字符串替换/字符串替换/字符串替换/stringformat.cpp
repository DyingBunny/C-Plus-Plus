#include<string>
#include<iostream>
#include<vector>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

class StringFormat 
{
public:
	string formatString(string A, int n, vector<char> arg, int m) 
	{
		string strRet;
		int index = 0;
		for (size_t i = 0; i < A.size(); ++i)
		{
			if (A[i] == '%'&&A[i + 1] == 's')
			{
				strRet[i] += arg[index];
			}
			else
			{
				strRet[i] = A[i];
			}
		}
		for (; index < m; ++index)
		{
			strRet += arg[index];
		}
	} 
};