#include<iostream>

//会在PrintA处崩溃，因为并没有this指针

//class A
//{
//public:
//	void PrintA()
//	{
//		std::cout << _a<<std::endl;
//	}
//
//	void Show()
//	{
//		std::cout << "Show()"<<std::endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A *p = NULL;
//	p->PrintA();
//	p->Show();
//}

//运算符重载

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	int _year;
//	int _month;
//	int _day;
//};
//
//bool operator==(const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year&&d1._month
//		== d2._month&&d1._day == d2._day;
//}
//
//int main()
//{
//	Date d1(2018, 9, 26);
//	Date d2(2018, 9, 27);
//	std::cout << (d1 == d2) << std::endl;
//}

//赋值运算符重载

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	void operator=(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2018, 7, 2);
//	Date d2(d1);
//	Date d3(2018, 2, 3);
//	d2 = d3;
//}


//const对象函数

//class Date
//{
//public:
//	void Display()
//	{
//		std::cout << "Display()" << std::endl;
//		std::cout <<_year << std::endl;
//		std::cout <<_month<< std::endl;
//		std::cout <<_day<< std::endl;
//	}
//
//	void Display() const
//	{
//		std::cout << "Display()" << std::endl;
//		std::cout << _year << std::endl;
//		std::cout << _month << std::endl;
//		std::cout << _day << std::endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	d1.Display();
//
//	const Date d2;
//	d2.Display();
//	return 0;
//}

//C++初始化列表 explicit，初始化列表避免多次构造赋值

//class Array
//{
//public:
//	Array(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//explicit Date(int year)
//	:_year(year)
//{}

//class A
//{
//public:
//	A()
//	{
//		++_scount;
//	}
//	A(const A& t)
//	{
//		++_scount;
//	}
//	static int GetACount()
//	{
//		return _scount;
//	}
//private:
//	static int _scount;
//};
//int A::_scount = 0;
//
//int main()
//{
//	std::cout << A::GetACount() << std::endl;
//	A a1, a2;
//	A a3(a1);
//	std::cout << A::GetACount() << std::endl;
//}