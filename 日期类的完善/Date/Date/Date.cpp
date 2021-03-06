#include<iostream>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		if (!IsInvalidDate(_year, _month, _day))//时间出现问题后，重置为默认的1900-1-1
		{
			_year = 1900;
			_month = 1;
			_day = 1;
		}
	}

	Date operator+(int days)//判断相差天数
	{
		Date tmp(*this);
		while (days != 0)
		{
			if (tmp._day + days <= tmp._GetDaysOfMonth(tmp._year, tmp._month))
			{
				tmp._day = tmp._day + days;
				days = 0;
			}
			else
			{
				if (tmp._month == 12)
				{
					tmp._year = tmp._year + 1;
					tmp._month = 1;
					tmp._day = 1;
					days=days - (tmp._GetDaysOfMonth(tmp._year, tmp._month) - tmp._day);
				}
				else
				{
					tmp._month = tmp._month + 1;
					days=days - (tmp._GetDaysOfMonth(tmp._year, tmp._month) - tmp._day);
					tmp._day = 1;
				}
			}
		}
		return tmp;
	}

	Date operator-(int days)//判断相差天数
	{
		Date tmp(*this);
		while (days != 0)
		{
			if (days < tmp._day)
			{
				tmp._day = tmp._day - days;
				days = 0;
			}
			else
			{
				if (tmp._month == 1)
				{
					tmp._year = tmp._year - 1;
					tmp._month = 12;
					days = days - tmp._day;
					tmp._day = tmp._GetDaysOfMonth(tmp._year, tmp._month);
				}
				else
				{
					tmp._month = tmp._month - 1;
					days = days - tmp._day;
					tmp._day = tmp._GetDaysOfMonth(tmp._year, tmp._month);
				}
			}
		}
		return tmp;
	}

	Date& operator++()//前置++
	{
		/*if (_day < _GetDaysOfMonth(_year, _month))	//直接写法
		{
			_day = _day + 1;
		}
		else
		{
			if (_month == 12)
			{
				_year += 1;
				_month = 1;
				_day = 1;
			}
			else
			{
				_month += 1;
				_day = 1;
			}
		}*/
		*this = *this + 1;
		return *this;
	}
	Date operator++(int)//后置++
	{
		Date tmp(*this);
		*this=*this + 1;
		return tmp;
	}
	Date& operator--()
	{
		*this = *this - 1;
		return *this;
	}

	Date operator--(int)
	{
		Date tmp(*this);
		*this = *this - 1;
		return tmp;
	}

	int operator-(const Date& d)
	{
		Date minDate(*this);
		Date maxDate(d);

		if (*this > d)
		{
			minDate = d;
			maxDate = *this;
		}

		int count = 0;
		while (minDate != maxDate)
		{
			++count;
			++minDate;
		}

		return count;
	}

	bool operator==(const Date& d)const//判断是否相等
	{
		if (_year && d._year || _month && d._month || _day && d._day)
		{
			return true;
		}
	}
	bool operator!=(const Date& d)const//判断是否不等
	{
		if (_year != d._year || _month != d._month || _day != d._day)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	bool operator>(const Date& d)const//判断日期前后
	{
		if (_year > d._year)
		{
			return true;
		}
		else if (_year == d._year&&_month > d._month)
		{
			return true;
		}
		else if (_year == d._year&&_month == d._month&&_day > d._day)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void PrintDaysOfMonth()//打印一个月的天数
	{
		cout << _GetDaysOfMonth(_year, _month);
	}

private:

	bool IsInvalidDate(int year,int month,int day)//防止日期非法
	{
		if (year < 1 || month < 0 || month>12 || day<0 || day>_GetDaysOfMonth(year, month))
		{
			return false;
		}
		else
		{
			return true;
		}

	}


	int _GetDaysOfMonth(int year, int month)//获取一个月有几天
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			return 31;
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			return 30;
		}
		else if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month == 2)
		{
			return 29;
		}
		else 
		{
			return 28;
		}
	}

	friend ostream& operator<<(ostream& _cout, const Date& d)//重载<<，打印时间
	{
		_cout << d._year << '-'<< d._month << '-'<< d._day;
		return _cout;
	}



private:
	int _year;
	int _month;
	int _day;
};

void TestDate(Date d)
{
	Date d1(2004, 3, 4);
	cout<<d1.operator-(d);
}

int main()
{
	Date d(2004, 3, 2);
	TestDate(d);
	system("pause");
	return 0;
}