#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

/*
class SeqList
{
public:
SeqList(size_t capacity = 10)
{
_pData = (int*)malloc(sizeof(int)*capacity);
_capacity = 10;
_size = 0;
}

~SeqList()
{
if (_pData)
{
free(_pData);
_pData = nullptr;
_capacity = 0;
_size = 0;
}
}
private:
int* _pData;
size_t _capacity;
size_t _size;
};

*/

#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	bool IsSameDate(const Date& d)
	{
		return _year == d._year &&
			   _month == d._month &&
			   _day == d._day;
	}

	bool operator==(const Date& d)
	{
		return _year == d._year &&
			_month == d._month &&
			_day == d._day;
	}

	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	Date operator+(int days)
	{
		_day += 10;
		return *this;
	}

	~Date()
	{}

private:
	int _year;
	int _month;
	int _day;
};

/*
// ȫ�ֺ���
// ���������---->����
// �ñ������ܹ�֧���Զ������͵�һЩ��Ӧ������Ĳ���
bool operator==(const Date& left, const Date& right)
{
	return left._year == right._year &&
		   left._month == right._month &&
		   left._day == right._day;
}
*/


int main()
{
	Date d1(2018, 10, 25);
	Date d2(2018, 10, 26);

	d2 = d1;

	//if (d1.IsSameDate(d2))
    //if(d1 == d2)
	if (d1.operator==(d2)) // Date::operator==(&d1, &d2);
	{
		cout << "d1��d2��ͬһ��" << endl;
	}
	else
	{
		cout << "d1��d2����ͬһ��" << endl;
	}
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	// d1 = d2 = d3; ===> d1.operator=(d2);
	Date& operator=(const Date& d)
	{
		// ����Ƿ��Լ����Լ���ֵ
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this;
	}

	bool operator==(const Date& d)
	{
		return _year == d._year &&
			_month == d._month &&
			_day == d._day;
	}

	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	// d0 = ++d1;
	// d0 = d1++;
	// ǰ��++
	Date& operator++()
	{
		_day += 1;
		return *this;
	}

	// ����++
	Date operator++(int)
	{
		Date temp(*this);
		_day += 1;
		return temp;
	}

	Date& operator--()
	{
		_day -= 1;
		return *this;
	}

	Date operator--(int)
	{
		Date temp(*this);
		--*this;
		return temp;
	}


	~Date()
	{}

private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	int a = 1;
	int b = 2;
	int c = 3;

	a = b;
	a = b = c;  

	a = b++;
	a = ++b;
	Date d1(2018, 10, 31);
	Date d2;
	Date d3;

	d2 = d1;
	d3 = d2 = d1;  //  d3.operator=(d2.operator=(d1));
	
	d3 = d3;
	Date& d4 = d3;
	d3 = d1++; // 0
	d3 = ++d1;

	d1.operator++();
	d1.operator++(0);
	
	return 0;
}
#endif

/*
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	// d1 = d2 = d3; ===> d1.operator=(d2);
	Date& operator=(const Date& d)
	{
		// ����Ƿ��Լ����Լ���ֵ
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this;
	}

	bool operator==(const Date& d)
	{
		return _year == d._year &&
			_month == d._month &&
			_day == d._day;
	}

	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	// ǰ��++
	Date& operator++();

	// ����++
	Date operator++(int);
	Date& operator--();
	Date operator--(int);

	// ��һ�������ϼ���days����
	Date operator+(int days);
	Date operator-(int days);

	// �������ڼ�Ĳ������
	int operator-(const Date& d);

	bool operator>(const Date& d)
	{
		if (_year > d._year ||
			_year == d._year && _month > d._month ||
			_year == d._year && _month == d._month && _day > d._day)
		{
			return true;
		}

		return false;
	}

	bool operator<(const Date& d)
	{
		return !(*this > d || *this == d);
	}

	bool operator>=(const Date& d);
	bool operator<=(const Date& d);

	~Date()
	{}

private:
	int _year;
	int _month;
	int _day;
};


int main()
{

	Date d1(2018, 10, 100);
	Date d2;

	return 0;
}
*/

#if 0
// const ��Ա��
// const������ĳ�Ա����---const���͵ĳ�Ա����
// const������ĳ�Ա����---const���͵ĳ�Ա����
class Test
{
public:
	Test(int t)
	{
		_t = t;
	}

	// Test* const this:ָ���ܸı�
	void SetParam(const int t)
	{
		this->_t = t;
	}

	// const Test* const
	// ��const��Ա�����в����޸����"��Ա����"
	// ԭ����Ϊconst�ڴ˴����ε���thisָ��ָ��ռ��е����ݣ�
	int GetParam()const
	{
		// this
		// _t = 10;
		// _a = 20;
		_b = 30;
		return _t;
	}

//private:
	int _t;
	int _a;
	mutable int _b;
};



int main()
{
	Test t1(10);
	t1.SetParam(20);
	t1.GetParam();

	const Test t2(10);
	//t2.SetParam(20);  // Ϊʲô��
	cout << t2.GetParam() << endl;

	//t2._a = 10;
	t2._b = 20;

	return 0;
}
#endif

#if 0
class Test
{
public:
	Test(int t)
	{
		_t = t;
	}

	// Test* const this:ָ���ܸı�
	void SetParam(const int t)
	{
		this->_t = t;
	}

	// const Test* const
	// ��const��Ա�����в����޸����"��Ա����"
	// ԭ����Ϊconst�ڴ˴����ε���thisָ��ָ��ռ��е����ݣ�
	int GetParam()const
	{
		// this
		// _t = 10;
		// _a = 20;
		_b = 30;
		return _t;
	}

	void TestFunc1()
	{

	}

	void TestFunc2()const
	{

	}

	// const Test* const this
	void TestFuncWithConst()const
	{
		// this--> ֻ����
		//TestFunc1(this);   // Test* const this
		TestFunc2();  // const Test* const this
	}

	// Test* const this : �ɶ���д
	void TestFuncWithoutConst()
	{
		TestFunc1();  // Test* const
		TestFunc2();  // const Test* const��ֻ��
	}

	// Test* const
	Test* operator&()
	{
		cout << this << endl;
		return this;
	}

	// const Test* const
	const Test* operator&()const
	{
		return this;
	}

	//private:
	int _t;
	int _a;
	mutable int _b;
};

/*
��ͨ���󣺶�����ͨ��Ա������const���͵ĳ�Ա���������Ե���
cosnt����ֻ�ܵ���const���͵ĳ�Ա����

��ͨ���͵ĳ�Ա��������ͨ��Ա������const���͵ĳ�Ա���������Ե���
const��Ա������ֻ�ܵ���cosnt���͵ĳ�Ա����
*/

int main()
{
	// ��ͨ������ͨ��Ա������const���͵ĳ�Ա���������Ե���
	Test t1(10);   // �ȿ��Զ�ȡ���ݣ��޸�
	t1.SetParam(20);  // �ɶ�д
	t1.GetParam();    // ֻ�ܶ�ȡ��ǰ���������

	const Test t2(10);  // ֻ���Ķ���
	//t2.SetParam(20); // �ɶ�д�ĳ�Ա����  // Ϊʲô��
	cout << t2.GetParam() << endl;  // ֻ�ܶԵ�ǰ������ж�ȡ����

	//cout << &t1 << endl;
	//cout << &t2 << endl;

	Test* pt1 = &t1;

	const Test* pt = &t2;
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(_day)
		, _day(day)
		, r(_day)
		, a(10)
	{
		//this->_month = month;
		//_day = day;
		r = _day;
	}

private:
	int _year;
	int _month;
	int _day;

	int& r;
	const int a;
};



int main()
{
	int a;
	a = 20;
	a = 30;

	int b = 20;

	Date d1(2018, 10, 28);
	return 0;
}
#endif

#if 0
class Time
{
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}


	/*
	Time()
	{}
	*/

private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(_day)
		, _day(day)
		//, _t(11, 8, 30)
	{}

	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
		, _t(d._t)
	{}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

int main()
{
	Date d(2018, 10, 28);
	return 0;
}
#endif

#if 0
class Date
{
public:
	// ��ֹ���ι��캯������ת��������
	explicit Date(int year)
		: _year(year)
	{}

	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(_day)
		, _day(day)
	{}

	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	//Date d1(2018, 10, 28);
	Date d2;
	d2 = 2018;
	return 0;
}
#endif

/*
class Time
{
public:
	Time(int hour, int minute = 0, int second = 0)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}

private:
	int _hour;
	int _minute;
	int _second;
};


// û������Ĭ�ϵĹ��캯��
class Date
{
public:
// 	Date()
// 	{}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};


int main()
{
	Date d;   // call Date::Date()  // Time()
	return 0;
}
*/

#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	/*
	ostream& operator<<(ostream& _cout)
	{
		_cout << _year << "-" << _month << "-" << _day;
		return _cout;
	}
	*/

private:
	int _year;
	int _month;
	int _day;

	friend ostream& operator<<(ostream& _cout, const Date& d);
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}


int main()
{
	int a = 10;
	//int b = a; == = > b(a);
	
	Date d(2018, 10, 28);
	//cout << d << endl;
	//d.operator<<(cout);
	//d << cout;
	cout << d;
	cout << 10 << " " << 12.34 << endl;
	return 0;
}
#endif
