#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

#if 0
// 
/*
1. ʶ������
2. ʶ�����еĳ�Ա����
3. ʶ�����еĳ�Ա����&���и�д
   ����ĳ�Ա��������һ��Ĭ�ϵĲ���----thisָ��
   �ڳ�Ա������ͨ��thisָ��ȥ����"��Ա����"
*/
class Date
{
public:
	/*
	void SetDate(Date* const this, int year, int month, int day)
	{
	    this->_year = year;
		this->_month = month;
		this->_day = day;
	}
	*/
	void SetDate(int year, int month, int day)
	{
		this->_year = year;
		_month = month;
		_day = day;
	}

	void TestFunc(...)
	{
		cout << this << endl;
	}

	/*
	void PrintDate(Data& d)
	void PrintDate(Date* cosnt this)
	{
	    cout << this->_year << "-" << this->_month << " " << this->_day << endl;
	}
	*/
	void PrintDate()
	{
		cout << _year << "-" << _month << " " << _day << endl;
	}

//private:
	int _year;
	int _month;
	int _day;
};


// this   ������*  const === ����
int main()
{
	Date d1,d2,d3;
	d1.SetDate(2018, 10, 21);
	Date* pd = &d1;
	pd->PrintDate();

	pd = nullptr;
	pd->TestFunc();  // Date::TestFunc(pd)
	pd->SetDate(2018, 10, 22);

	pd->_year = 2019;

	d1.TestFunc();

	
	cout << sizeof(d1) << endl;
	
	/*
	  Date::SetDate(&d1, 2018, 10, 21);
	*/
	d1.PrintDate();

	d2.SetDate(2018, 10, 21);
	return 0;
}
#endif


/*
class Date
{
public:
	// �����ж���ĳ�Ա���������������ܻὫ�䵱����������������
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}

	Date(int year);

	Date(int year, int month, int day)
	{
		cout << "Date::Date(int,int,int):" << this << endl;
		_year = year;
		_month = month;
		_day = day;
	}

	void SetDate(int year, int month, int day)
	{
		this->_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

Date::Date(int year)
{
	_year = year;
}




void TestFunc()
{
	Date d0;  // Date()
	Date d1(2018, 10, 24);   // call Date::Date()
	d1.PrintDate();
}

int main()
{
	TestFunc();
	return 0;
}
*/

#if 0
// 
class Date
{
public:
	/*
	// ����û�û����ʽ���壬�������ϳɵ�Ĭ�ϵĹ��캯��
	Date()
	{}
	*/

	// ȱʡ���캯��
	Date()
	{}

	// ��ʽ�����˹��캯��
	// ֻҪ�û���ʽ���壬Ĭ�ϵĹ��캯��������ϳ�
	// ����ȫȱʡ�Ĺ��캯��---ȱʡ�Ĺ��캯��
	// �޲εĺʹ���ȫȱʡ�Ĺ��캯��ֻ�ܴ���һ��
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void SetDate(int year, int month, int day)
	{
		this->_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};



int main()
{
	Date d;
	//Date d(2018, 10, 21);
	return 0;
}
#endif


/*
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		cout << "Date(int,int,int):" << this << endl;
		_year = year;
		_month = month;
		_day = day;
	}

	void SetDate(int year, int month, int day)
	{
		this->_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	~Date()
	{
		cout << "~Date():" << this << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

void TestFunc()
{
	Date d(2018, 10, 21);
}

int main()
{
	TestFunc();
	return 0;
}
*/

/*
#include <assert.h>

typedef int DataType;

class SeqList
{
public:
	SeqList(size_t capacity = 10)
	{
		_array = (DataType*)malloc(sizeof(DataType)*capacity);
		if (nullptr == _array)
		{
			assert(0);
		}

		_capacity = capacity;
		_size = 0;
	}

	void PushBack(const DataType& data)
	{
		// _CheckCapacity();
		_array[_size++] = data;
	}

	void PopBack()
	{
		--_size;
	}

	~SeqList()
	{
		if (_array)
		{
			free(_array);
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}
private:
	DataType* _array;
	size_t _capacity;
	size_t _size;
};

void TestFunc()
{
	SeqList s;
	s.PushBack(1);
	s.PushBack(2);
	s.PushBack(3);
	s.PushBack(4);

	s.PopBack();
}


int main()
{
	TestFunc();
	return 0;
}
*/

/*
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		cout << "Date(int,int,int):" << this << endl;
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		cout << "Date(Date& d):" << this << endl;
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	void SetDate(int year, int month, int day)
	{
		this->_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	~Date()
	{
		cout << "~Date():" << this << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2018, 10, 21);
	Date d2(d1);
	return 0;
}
*/

#if 0
#include <assert.h>

typedef int DataType;

class SeqList
{
public:
	SeqList(size_t capacity = 10)
	{
		_array = (DataType*)malloc(sizeof(DataType)*capacity);
		if (nullptr == _array)
		{
			assert(0);
		}

		_capacity = capacity;
		_size = 0;
	}

	void PushBack(const DataType& data)
	{
		// _CheckCapacity();
		_array[_size++] = data;
	}

	void PopBack()
	{
		--_size;
	}

	~SeqList()
	{
		if (_array)
		{
			free(_array);
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}
private:
	DataType* _array;
	size_t _capacity;
	size_t _size;
};

void TestFunc()
{
	SeqList s1;
	SeqList s2(s1);
}

int main()
{
	TestFunc();
	return 0;
}
#endif

int main()
{
	return 0;
}