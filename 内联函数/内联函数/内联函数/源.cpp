#include<iostream>

//inline int square(int a, int b)
//{
//	return a*b;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int square_result = square(a, b);
//	std::cout << square_result << std::endl;
//	return 0;
//}

class Student
{
public:
	Student(int num,int pum=1)
		:_num(num)
		,_pum(pum)
	{}

private:
	int _num;
	int _pum;
};

int main()
{
	Student(10);
	return 0;
}