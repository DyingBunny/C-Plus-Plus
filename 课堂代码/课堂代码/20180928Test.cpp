//#include <iostream>
//using namespace std;

/*
// ������
// ��ͨ�����ռ�
namespace N1
{
	int a = 10;
	int b;

	int Add(int left, int right)
	{
		return left + right;
	}
}

// �����ռ����Ƕ��
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

// ��ͬһ�������п��Զ�������ͬ���Ƶ������ռ�
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

// ���һ�������ж�������ͬ�������ռ䣬�����������Ὣ��ϲ���һ��
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
// ȱʡ�������ں����������߶���ʱ����������һ��Ĭ��ֵ
// �ں�������ʱ�����������ʵ�Σ�������ʹ�ô��ݵ�ʵ�Σ�������Ĭ��ֵ
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
// ȱʡ�����ķ��ࣺ
// ȫȱʡ������ÿ������������ȱʡֵ
void TestFunc1(int a = 1, int b = 2, int c = 3)
{
	cout<<a<<" "<<b<<" "<<c<<endl;
}

// ��ȱʡ���������ֲ�������ȱʡֵ��ע�⣺ֻ�ܴ����������θ���
void TestFunc2(int a, int b = 2, int c = 3)
{
	cout<<a<<" "<<b<<" "<<c<<endl;
}


int g_a = 10;
// ȱʡ���������������붨���λ��ͬʱ����
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
// �������أ���ͬ�������򣬺������ֱ�����ͬ�������б���벻ͬ
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
// �����б�ͬ�������ĸ��������͡�����
// 1
void TestFunc(int a)
{}

// 2
// ���������Ͳ�һ��
void TestFunc(char a)
{}

// 3
// �����ĸ�����ͬ
void TestFunc(int a, char b)
{}

// 4
// �������ʹ���
void TestFunc(char a, int b)
{}

/*
// ���������������ֻ�Ƿ���ֵ���Ͳ�һ���������γ�����
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
// �޲� & ����ȫȱʡ����
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
// ΪʲôC++֧�ֺ������أ�C���Բ���
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
// ֻ����������������--->���ӽ׶α���
// C�����У��������Ժ������ֵ����ι��򣺼򵥵��ں�������ǰ��_
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
// ��C++�У��������Ժ������ֵ����ι��򣺰Ѳ��������ͱ��뵽������������
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