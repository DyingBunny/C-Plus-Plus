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
//	man.SetStudentInfo("Jack", "��", 10);
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
//	//constʵ������thisָ�룬�����޸��κγ�Ա����
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

//const ��ͨ���ͱ����������������ڼ��滻
//const ���������Ա
//const ��Ա����
//const ���γ�Ա����

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



//thisָ��


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

//Point::Point(int a, int b)	//���캯������������ⲿ����
//{								//�����趨Ĭ�ϲ���
//	x = a;						//���캯�� �ɴ�����
//	y = b;
//}

int main()
{
	Point point1;
	point1.print();
	system("pause");
	return 0;
}


