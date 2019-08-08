#include "hehe.h"

////测试栈内存
//int main()
//{
//	using namespace std;
//	int i = 10; //变量i储存在栈区中
//	const int i2 = 20;
//	int i3 = 30;
//	cout << &i << " " << &i2 << " " << &i3 << endl;
//	system("pause");
//	return 0;
//}




//测试堆内存和栈内存的区别
//int main()
//{
//	using namespace std;
//	int i = 10; //变量i储存在栈区中
//	char pc[] = "hello!"; //储存在栈区
//	const double cd = 99.2; //储存在栈区
//	static long si = 99; //si储存在可读写区，专门用来储存全局变量和静态变量的内存
//	int* pi = new int(100); //指针pi指向的内存是在 堆区，专门储存程序运行时分配的内存
//	cout << &i << " " << &pc << " " << &cd << " " << &si << " " << pi << endl;
//	delete pi; //需程序员自己释放
//	return 0;
//}



//传值不改变例子
//void Swap(int right, int left);
//int main()
//{
//	using namespace std;
//	int left = 100;
//	int right = 200;
//	cout << left << " " << right << endl;
//	Swap(right, left);
//	cout << left << " " << right << endl;
//	return 0;
//}
//
//void Swap(int right, int left)
//{
//	int tmp;
//	tmp = right;
//	right = left;
//	left = tmp;
//}



//传址
//void Swap(int *right, int *left);
//int main()
//{
//	using namespace std;
//	int left = 100;
//	int right = 200;
//	cout << left << " " << right << endl;
//	Swap(&right, &left);
//	cout << left << " " << right << endl;
//	system("pause");
//	return 0;
//}
//
//void Swap(int *right, int *left)
//{
//	int tmp;
//	tmp = *right;
//	*right = *left;
//	*left = tmp;
//}



//引用来实现交换j
//void Swap(int &right, int &left);
//int main()
//{
//	using namespace std;
//	int left = 100;
//	int right = 200;
//	cout << left << " " << right << endl;
//	Swap(right,left);
//	cout << left << " " << right << endl;
//	system("pause");
//	return 0;
//}
//
//void Swap(int &right, int &left)
//{
//	int tmp;
//	tmp = left;
//	left = right;
//	right = left;
//}

//void Test()
//{
//	const int a = 10;
//	float b = 0.31;
//	const int& ra = a;
//	int& rb = b;
//	printf("%d", b);
//}
//
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}

//int &Change();
//int main()
//{
//	int &b = Change();
//	//Change();
//	cout << b<<endl;
//	cout << b << endl;
//	system("pause");
//	return 0;
//}
//
//int &Change()
//{
//	int a = 10;
//	return a;
//}

//-----------------------------------------引用作为返回值--------------------------
//int& Test(int& a)
//{
//	a += 10;
//	return a;
//}

//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//int main()
//{
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	cout << ret << endl;
//	system("pause");
//	return 0;
//}

//int &test_str();
//
//int &test_str()
//{
//	int b = 5;
//	return b;
//}
//
//int main()
//{
//	int& a = test_str();
//	cout<<a<< endl;
//	system("pause");
//	return 0;
//}


//class Pp1
//{
//	int Add_Double(int a,int b)
//	{
//		return a + b;
//	}
//
//	int Add_Third(int a,int b,int c)
//	{
//		return a + b + c;
//	}
//};
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int sum = 0;
//	sum = Pp1.Add_Double(a, b);
//}

//int main()
//{
//	float a = 2.0;
//	float b = 3.14;
//	printf("%f", a*a*b);
//	system("pause");
//	return 0;
//}

//-------------------------------------析构函数------------------------------
//typedef int Datatype;
//
//class Seqlist
//{
//public:
//	Seqlist(int capacity = 10)
//	{
//		_pData = (Datatype*)malloc(capacity*sizeof(Datatype));
//		assert(_pData);
//		_size = 0;
//		_capacity = capacity;
//	}
//
//	void PushBack(Datatype data)
//	{
//		_pData[_size++] = data;
//	}
//
//	~Seqlist()
//	{
//		if (_pData)
//		{
//			free(_pData);
//			_pData = NULL;
//			_size = 0;
//			_capacity = 0;
//		}
//	}
//
//private:
//	int* _pData;
//	size_t _size;
//	size_t _capacity;
//};
//
//void TestFunc()
//{
//	Seqlist s;
//	s.PushBack(1);
//	s.PushBack(2);
//	s.PushBack(3);
//	s.PushBack(4);
//}
//
//int main()
//{
//	TestFunc();
//	system("pause");
//	return 0;
//}

//----------------------------------------------
//class String
//{
//public:
//	String(const char* str = "jack")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//	~String()
//	{
//		cout << "~String()" << endl;
//		free(_str);
//	}
//private:
//	char* _str;
//};
//
//class Person
//{
//private:
//	String _name;
//	int _age;
//};
//
//int main()
//{
//	Person p;
//	system("pause");
//	return 0;
//}

//------------------------------------拷贝构造函数-----------------------------

//class data
//{
//private:
//	int _year;
//	int _month;
//	int _day;
//
//public:
//	data(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//拷贝构造函数
//	data(const data &d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	void print(const data& data)
//	{
//		cout << _year << "--" << _month << "--" << _day;
//		cout << "\n";
//	}
//};
//
//int main()
//{
//	data d1(2018,11,10);
//	data d2(d1);
//	d1.print(d1);
//	d2.print(d2);
//	system("pause");
//	return 0;
//}

//---------------------------------------this指针--------------------------

//typedef int Datetype;
//class Data
//{
//private:
//	Datetype _year;
//	Datetype _month;
//	Datetype _day;
//
//public:
//	void SetData(Datetype year, Datetype month, Datetype day)
//	{
//		_year = year;
//		this->_month = month;                           //三句话是等价的
//		(*this)._day = day;
//	}
//
//	void Display()
//	{
//		cout << _year << "--" << _month << "--" << _day;
//		cout << "\n";
//	}
//};
//
//int main()
//{
//	Data first;
//	first.SetData(2018, 11, 10);
//	Data second;
//	second.SetData(2018, 11, 10);
//	first.Display();
//	second.Display();
//	system("pause");
//	return 0;
//}

//----------------------------------------------错误事例--------------------------------------
//class A
//{
//private:
//	int _a;
//
//public:
//	void PrintA()
//{
//	cout << _a << endl;
//}
//	void Show()
//	{
//		cout << "Show()" << endl;
//	}
//};
//
//int main()
//{
//	A* p = NULL;
//	p->PrintA();
//	p->Show();
//	system("pause");
//	return 0;
//}

//------------this的实际运用--------

//class A
//{
//public:
//	int get() const
//	{ 
//		return i; 
//	}
//	void set(int x)
//	{ 
//		this->i = x; 
//		cout << "this指针保存的内存地址为:" << this << endl; 
//	}
//
//private:
//	int i;
//};
//
//int main()
//{
//	A a;
//	a.set(9);
//	cout << "对象a所在的内存地址为:" << &a << endl;
//	cout << "对象a所保存的值为:" << a.get() << endl;//对象的地址和this指针的地址是一样的
//	cout << endl;
//	A b;
//	b.set(999);
//	cout << "对象b所在的内存地址为:" << &b << endl;
//	cout << "对象b所保存的值为:" << b.get() << endl;
//	system("pause");
//	return 0;
//}

//--------------------------operator运算符重载-----------------------

//class Date
//{
//public:
//	Date(int year = 2018, int month = 11, int day = 23)
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
//	return d1._year == d2._year
//		&&d1._month == d2._month
//		&&d1._day == d2._day;
//}
//
//void Test()
//{
//	Date d1(2018, 11, 26);
//	Date d2(2018, 11, 24);
//	//cout << (d1._year == d2._year) << endl;
//	cout << (d1 == d2) << endl;
//}
//
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}

//-------------------------另一个例子---------------------
//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	bool operator==(const Date& d1)
//	{
//		return _year == d1._year
//			&&_month == d1._month
//			&&_day == d1._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void Test()
//{
//	Date d1(2018, 11, 23);
//	Date d3(2018, 11, 24);
//	cout << (d1 == d3) << endl;
//}
//
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}

//---------------初始化列表---------------   
//class data                                  //初始化只能有一次
//{
//private:
//	int _year;
//	int _month;
//	int _day;
//
//public:
//	data(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	void print(const data& data)
//	{
//		cout << _year << "--" << _month << "--" << _day;
//		cout << "\n";
//	}
//};
//
//int main()
//{
//	data d1(2018,11,10);
//	d1.print(d1);
//	data d1(2017, 3, 10);
//	d1.print(d1);
//	system("pause");
//	return 0;
//}

//------------------------------static的运用--------------------
//class B
//{
//public:
//	int _b;
//	B(int b = 0)
//		:_b(b)
//	{}
//};
//
//class A
//{
//public:
//	void Print()
//	{
//		cout << a << endl;
//		cout << x._b << endl;
//		cout << p << endl;
//	}
//
//private:
//	//非静态成员变量，可以在声明变量时，直接初始化
//	int a = 10;
//	B x = 20;
//	int *p = (int*)malloc(4);
//	static int n;
//};
//
//int A::n = 10;
//
//int main()
//{
//	A a;
//	a.Print();
//	system("pause");
//	return 0;
//}

//----------------------友元函数---------------------
//错误事例，如果operator重载符定义在类内，会抢占第一个参数，而如果定义在类外，便会无法访问类中的对象
//class Date
//{
//public:
//	Date(int year, int month, int day)
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
//
//ostream& operator<<(ostream& _cout, const date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day;
//	return _cout;
//}
//int main()
//{
//	date d(2018, 11, 8);
//	d << cout;
//	system("pause");
//	return 0;
//}

//--------------------------------正确事例-------------------------
//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	friend ostream& operator<<(ostream& _cout, const Date& d)
//	{
//		_cout << d._year << '-' << d._month << '-' << d._day;
//		return _cout;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//};
//
//
//void Test(Date d)
//{
//	cout << d;
//}
//int main()
//{
//	Date d(2018, 11, 28);
//	Test(d);
//	system("pause");
//	return 0;
//}


//----------------------String类------------------

//void TestString(string s)
//{
//	
//	cout << s.size() << endl;
//	cout << s.length() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//}
//
//void ClearString(string s)
//{
//	s.clear();
//	cout << s.length() << endl;
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//}
//
//void AddString(string s)
//{
//	s.resize(13, 'a');
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//}
//
//void MinerString(string s)
//{
//	s.resize(5);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//}
//
//class Solution
//{
//public:
//	Solution(string s)
//	{
//		_s = s;
//	}
//
//	string ReverseString()
//	{
//		if (_s.empty())
//		{
//			return _s;
//		}
//		size_t start = 0;
//		size_t end = _s.size() - 1;
//		while (start < end)
//		{
//			swap(_s[start], _s[end]);
//			start++;
//			end--;
//
//		}
//		return _s;
//	}
//
//	void TestString()
//	{
//
//		cout << _s.size() << endl;
//		cout << _s.length() << endl;
//		cout << _s.capacity() << endl;
//		cout << _s << endl;
//	}
//
//private:
//	string _s;
//};
//
//int main()
//{
//	Solution s("hello world");
//	cout << s.ReverseString() << endl;
//	s.TestString();
//	/*TestString(s);*/                                        //类中的构造函数创建的对象如何作为外部函数的参数？
//	system("pause");
//	return 0;
//}

//-------------------------------String接口的使用-----------------------------

//void TestString()
//{
//	string s1;					//构造空字符串
//	string s2("hello world");	//构造string类对象
//	string s3(5, 'a');			//用n个字符来构造string类对象
//	string s4(s2);				//拷贝构造函数
//	string s5(s2, 5);			//用s2中的5个字符构造心得string对象
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	cout << s4 << endl;
//	cout << s5 << endl;
//}
//
//
//void TestStringSize()
//{
//	string s1("hello world");
//	cout << s1.size() << endl;		//返回字符串的有效长度
//	cout << s1.length() << endl;	//返回字符串的有效长度
//	cout << s1.capacity() << endl;	//返回字符串的大小
//	cout << s1.empty() << endl;		//判断字符串是否为空，返回bool
//	s1.resize(15, 'a');				//将有效字符变为n个，多余的用字符a填充
//	cout << s1 << endl;
//	s1.reserve(20);					//为字符串预留空间
//	s1.clear();						//清空有效字符串
//	cout << s1 << endl;
//
//}
//
//void TestStringAccess()
//{
//	string s1("hello world");		//返回pos位置的字符
//	cout << s1.operator[](4) << endl;
//}
//
//void TestStringChange()
//{
//	string s1("hello world");
//	s1.push_back('a');			//尾插一个字符
//	cout << s1 << endl;
//	s1.append(5, 'b');			//字符串后追加n个字符b
//	cout << s1 << endl;
//	s1.operator+=("people");	//字符串后追加一个字符串
//	cout << s1 << endl;
//	s1.operator+=('b');			//字符串后追加一个字符
//	cout << s1 << endl;
//	int c=s1.find('b', 1);		//从pos位置往后开始找字符b，找到后返回位置
//	cout << c << endl;
//	int d = s1.rfind('b', 10);	//从pos位置往前开始找字符b，找到后返回位置
//	cout << c << endl;
//	s1.substr(2, 2);			//从pos位置开始截取n个字符返回
//	
//}
//
//int main()
//{
//	TestString();
//	TestStringSize();
//	TestStringAccess();
//	TestStringChange();
//	system("pause");
//	return 0;
//}


//-----------------------------String的传统写法-------------------------
//注意字符串和单个字符一个用""一个用''

//class String
//{
//public:
//	String(const char* str = "")
//	{
//		if (nullptr == str)
//		{
//			str = "";
//		}
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//
//	String(const String& s)
//		:_str(new char[strlen(s._str) + 1])
//	{	
//		strcpy(_str, s._str);
//	}
//
//	void Print()
//	{
//		cout << _str << endl;
//	}
//
//	String& operator=(const String& s)
//	{
//		if (this != &s)
//		{
//			char* pStr = new char[strlen(s._str) + 1];
//			strcpy(pStr, s._str);
//			delete[]_str;
//			_str = pStr;
//		}
//		return *this;
//	}
//
//	friend ostream& operator<<(ostream& _cout, const String& s)
//	{
//		_cout << s._str;
//		return _cout;
//	}
//
//	~String()
//	{
//		if (_str)
//		{
//			delete[]_str;
//			_str = nullptr;
//		}
//	}
//
//private:
//	char *_str;
//};
//
//
//void TestString()
//{
//	String s1("hello world");
//	String s2(s1);
//	cout << s1 << endl;
//	/*String s2;
//	s2 = s1;*/
//	s2.Print();
//	/*cout << s1;*/
//}
//int main()
//{
//	TestString();
//	system("pause");
//	return 0;
//}


//-----------------------------模拟实现String类--------------------------
//class String
//{
//public:
//	typedef char* Iterator;
//
//public:
//	String(const char* str = "")
//	{
//		if (nullptr == str)
//		{
//			str = "";
//		}
//		_size = strlen(str);
//		_capacity = _size;
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//
	//String(const char* str, size_t size)  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//{
	//	
	//}

	//String(const String& s)
	//	:_str(new char[strlen(s._str) + 1])
	//{
	//	strcpy(_str, s._str);
	//}

	//String& operator=(const String& s)
	//{
	//	if (this != &s)
	//	{
	//		char* pStr = new char[strlen(s._str) + 1];
	//		strcpy(pStr, s._str);
	//		delete[]_str;
	//		_str = pStr;
	//	}
	//	return *this;
	//}

	//~String()
	//{
	//	if (_str)
	//	{
	//		delete[]_str;
	//		_str = nullptr;
	//	}
	//}

	//Iterator Begin()			
	//{
	//	return _str;
	//}
	//Iterator End()
	//{
	//	return _str + _size;
	//}
	//Iterator RBegin()
	//{
	//	return End();
	//}
	//Iterator REnd()
	//{
	//	return Begin();
	//}

	//void Reserve(size_t newCapacity)
	//{
	//	// 如果新容量大于旧容量，则开辟空间
	//	if (newCapacity > _capacity)
	//	{
	//		char* str = new char[newCapacity + 1];
	//		strcpy(str, _str);
	//		// 释放原来旧空间,然后使用新空间
	//		delete[] _str;
	//		_str = str;
	//		_capacity = newCapacity;
	//	}

	//}

	//void PushBack(char c)//尾插一个单个字符
	//{
	//	if (_size == _capacity)
	//	{
	//		Reserve(_capacity * 2);
	//	}
	//	_str[_size++] = 'c';
	//	_str[_size] = '\0';
	//}

	//void Append(const char* str)//拼接一个字符串
	//{
	//	if (_size == _capacity)
	//	{
	//		Reserve(_capacity * 5);
	//	}
	//	strcat(_str, str);
	//}

	//char& operator[](size_t index)
	//{
	//	//通过指针实现
	///*	String tmp(*this);
	//	char *p = tmp._str;
	//	while (index != 0)
	//	{
	//		*(p++);
	//		index--;
	//	}		
	//	char a = *p;
	//	return a;*/

	//	//通过_str实现
	//	assert(index < _size);
	//	return _str[index];
	//}

//	const char& operator[](size_t index)const
//	{
//		assert(index <= _size);
//		return _str[index];
//	}
//
//	void ReSize(size_t newSize, char c);
//	int Size()const;
//	bool Empty()const;
//	void Clear();
//	int Find(char c, size_t pos = 0);
//	int rFind(char c);
//	const char* C_Str()const;
//	void Swap(String& s);
//	String StrSub(size_t pos, size_t size);
//
//	bool operator<(const String& s);
//	bool operator<=(const String& s);
//	bool operator>(const String& s);
//	bool operator>=(const String& s);
//	bool operator==(const String& s);
//	bool operator!=(const String& s);
//	friend ostream& operator<<(ostream& _cout, const String& s)
//	{
//		_cout << s._str;
//		return _cout;
//	}
//	friend istream& operator>>(istream& _cout, String& s);
//
//private:
//	char* _str;
//	size_t _capacity;
//	size_t _size;
//};
//
//void TestString()
//{
//	String s1("hello world");
//	cout << s1[2] << endl;
//}
//
//int main()
//{
//	TestString();
//	system("pause");
//	return 0;
//}

//auto和const auto&的使用
//int main()
//{
//	/*int a = 10;
//	auto b = 10;
//	std::cout << typeid(a).name() << std::endl;
//	std::cout << typeid(b).name() << std::endl;*/
//	std::vector<int> a = { 1, 5, 8, 9, 4, 6 };
//	auto s = a.begin();
//	std::cout << typeid(a).name() << std::endl;
//	std::cout << typeid(s).name() << std::endl;
//	return 0;
//}

//using namespace std;
//
//int main()
//{
//	string s1;
//	getline(cin, s1);
//	int k;
//	cin >> k;
//	if (s1.size()% k == 0 )
//	{
//		cout << s1 << endl;
//	}
//	else
//	{
//		/*s1.pop_back();
//		reverse(s1.begin(), s1.end());
//		s1.pop_back();
//		reverse(s1.begin(), s1.end());*/
//		reverse(s1.begin(), s1.begin() +k+1);
//		/*s1.push_back(']');
//		reverse(s1.begin(), s1.end());
//		s1.push_back('[');*/
//		/*reverse(s1.begin(), s1.end());*/
//		cout << s1 << endl;
//	}
//	return 0;
//}

//int main()
//{
//	int b = 100;
//	return 0;
//}