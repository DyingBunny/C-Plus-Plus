#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

//class Person
//{
//public:
//	void ShowInfo()
//	{
//		cout << _name << "-" << _gender << "-" << _age << endl;
//	}
//public:
//	char _name[20];
//	char _gender[3];
//	int _age;
//
//	void SetStudentInfo(char *name, char *gender, int age)
//	{
//		strcpy_s(_name,20,name);
//		strcpy_s(_gender,3,gender);
//		_age = age;
//	}
//};
//
//void Test()
//{
//	Person man;
//	man.SetStudentInfo("Jack", "男", 10);
//	man.ShowInfo();
//}
//
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}

//class Date
//{
//public:
//	void Display()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	void SetDate(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void SetYear(int year)
//	{
//		_year = year;
//	}
//
//	int GetYear()
//	{ /
//		return _year;
//	}
//
//	void Test1()
//	{}
//
//	//const实际修饰this指针，不能修改任何成员变量
//	void Test2()const
//	{
//
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//const 普通类型变量：常量，编译期间替换
//const 来修饰类成员
//const 成员函数
//const 修饰成员变量

//int main()
//{
//	Date firstDate, secondDate;
//	firstDate.SetDate(2018, 10, 24);
//	secondDate.SetDate(2018,9,20);
//	firstDate.Display();
//	secondDate.Display();
//	system("pause");
//	return 0;
//}



//this指针


class Point
{
public:
	Point(int x=1, int y=2) 
	{						
		_x = x; 
		_y = y; 
	}
	//void MovePoint(int a, int b)
	//{ 
	//	_x += a; 
	//	_y += b; 
	//}
	void print()
	{
		cout << "x=" << _x << " "<<"y=" << _y << endl; 
	}
private:
	int _x;
	int _y;
};

//Point::Point(int a, int b)	//构造函数可以在类的外部定义
//{								//可以设定默认参数
//	x = a;						//构造函数 可带参数
//	y = b;
//}

int main()
{
	Point point1;
	point1.print();
	system("pause");
	return 0;
}


