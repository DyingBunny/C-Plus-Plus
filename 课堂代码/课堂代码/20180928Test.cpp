//#include <iostream>
//using namespace std;

/*
// 作用域
// 普通命名空间
namespace N1
{
	int a = 10;
	int b;

	int Add(int left, int right)
	{
		return left + right;
	}
}

// 命名空间可以嵌套
namespace N2
{
	int a = 30;
	int b = 40;

	int Sub(int left, int right)
	{
		return left - right;
	}

	namespace N3
	{
		int a = 50;
		int b = 60;

		int Mul(int left, int right)
		{
			return left * right;
		}
	}
}

// 在同一个工程中可以定义多个相同名称的命名空间
namespace N1
{
	int c = 70;
	int d = 80;

	int Div(int left, int right)
	{
		return left / right;
	}
}

int a = 0;

int main()
{
	int a = 1;
	printf("%d\n", ::a);
	printf("%d\n", N1::a);
	printf("%d\n", N2::N3::a);
	return 0;
}
*/

/*
namespace N1
{
	int a = 10;
	int b;

	int Add(int left, int right)
	{
		return left + right;
	}
}

using N1::a;

int main()
{
	printf("%d\n", N1::a);
	printf("%d\n", a);
	return 0;
}
*/

/*
namespace N1
{
	int a = 10;
	int b;

	int Add(int left, int right)
	{
		return left + right;
	}
}

// 如果一个工程中定义多个相同的命名空间，编译器将来会将其合并成一个
namespace N1
{
	int c = 70;
	int d = 80;

	int Div(int left, int right)
	{
		return left / right;
	}
}

using namespace N1;
int main()
{
	printf("%d\n", a);
	Add(10, 20);
	return 0;
}
*/

/*
#include <iostream>
using namespace std;

int main()
{
	cout<<10<<" "<<12.34<<" "<<'A'<<endl;
	cout<<"hello world!!!"<<endl;

	int a;
	cin>>a;
	return 0;
}
*/

/*
// 缺省参数：在函数生命或者定义时，给参数带一个默认值
// 在函数调用时，如果传递了实参，参数就使用传递的实参，否则用默认值
#include <malloc.h>
void* GetMemory(int size = 100)
{
	cout<<size<<endl;
	return malloc(size);
}

int main()
{
	GetMemory();
	GetMemory(10);
	return 0;
}
*/

#if 0
// 缺省参数的分类：
// 全缺省参数：每个参数都带有缺省值
void TestFunc1(int a = 1, int b = 2, int c = 3)
{
	cout<<a<<" "<<b<<" "<<c<<endl;
}

// 半缺省参数：部分参数带有缺省值，注意：只能从右往左依次给出
void TestFunc2(int a, int b = 2, int c = 3)
{
	cout<<a<<" "<<b<<" "<<c<<endl;
}


int g_a = 10;
// 缺省参数不能再生命与定义的位置同时出现
void TestFunc3(int g_a = 10);

void TestFunc3(int a/* = 10*/)
{

}

int main()
{
	TestFunc1(10, 20, 30);
	TestFunc1(10, 20);
	TestFunc1(10);
	TestFunc1();

	TestFunc2(10);
	TestFunc2(10, 20);
	TestFunc2(10, 20, 30);
	return 0;
}
#endif

/*
// 函数重载：相同的作用域，函数名字必须相同，参数列表必须不同
int Add(int left, int right)
{
	return left + right;
}

double Add(double left, double right)
{
	return left + right;
}

char Add(char left, char right)
{
	return left + right;
}


int main()
{
	cout<<Add(1, 2)<<endl;
	cout<<Add(1.0, 2.0)<<endl;
	cout<<Add('1', '2')<<endl;
	return 0;
}
*/

#if 0
// 参数列表不同：参数的个数、类型、次序
// 1
void TestFunc(int a)
{}

// 2
// 参数的类型不一样
void TestFunc(char a)
{}

// 3
// 参数的个数不同
void TestFunc(int a, char b)
{}

// 4
// 参数类型次序
void TestFunc(char a, int b)
{}

/*
// 如果两个函数仅仅只是返回值类型不一样，不能形成重载
int TestFunc(int a)
{
	return 0;
}
*/

int main()
{
	return 0;
}
#endif

/*
// 无参 & 带有全缺省参数
void TestFunc()
{}

void TestFunc(int a = 10)
{}

int main()
{
	TestFunc();
	return 0;
}
*/

/*
// 为什么C++支持函数重载？C语言不行
int AddII(int left, int right)
{
	return left + right;
}

double AddDD(double left, double right)
{
	return left + right;
}

char AddCC(char left, char right)
{
	return left + right;
}
*/

/*
// 只给声明，不给定义--->链接阶段报错
// C语言中，编译器对函数名字的修饰规则：简单的在函数名字前加_
//int Add(int left, int right);
//{
//	return left + right;
//}

double Add(double left, double right);
//{
//	return left + right;
//}
//
//char Add(char left, char right)
//{
//	return left + right;
//}

int main()
{
	Add(1,2);
	Add(1.0, 2.0);
	return 0;
}
*/

/*
// 在C++中，编译器对函数名字的修饰规则：把参数的类型编译到函数的名字中
int Add(int left, int right);
double Add(double left, double right);
int Add(int left, double right);



int main()
{
	Add(1, 2);   // ?Add@@YAHHH@Z
	Add(1.0, 2.0);
	Add(1, 2.0);
	return 0;
}
*/

/*
extern "C" int Add(int left, int right);


int main()
{
	Add(1,2);
	return 0;
}
*/

int main()
{
	return 0;
}