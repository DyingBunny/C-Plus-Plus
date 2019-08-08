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
	Add(1, 2); // 参数推演---生成处理int的代码
	Add(1.0, 2.0); // 参数推演---生成处理double的代码
	Add('1', '2');
}

