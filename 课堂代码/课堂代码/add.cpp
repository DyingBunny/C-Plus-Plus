#include "add.h"

// int Add(int left, int right)
// {
// 	return left + right;
// }


template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}



void TestFunc()
{
	Add(1, 2); // ��������---���ɴ���int�Ĵ���
	Add(1.0, 2.0); // ��������---���ɴ���double�Ĵ���
	Add('1', '2');
}

