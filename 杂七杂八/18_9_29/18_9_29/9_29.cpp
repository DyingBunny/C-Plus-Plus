#include "hehe.h"

////����ջ�ڴ�
//int main()
//{
//	using namespace std;
//	int i = 10; //����i������ջ����
//	const int i2 = 20;
//	int i3 = 30;
//	cout << &i << " " << &i2 << " " << &i3 << endl;
//	system("pause");
//	return 0;
//}




//���Զ��ڴ��ջ�ڴ������
//int main()
//{
//	using namespace std;
//	int i = 10; //����i������ջ����
//	char pc[] = "hello!"; //������ջ��
//	const double cd = 99.2; //������ջ��
//	static long si = 99; //si�����ڿɶ�д����ר����������ȫ�ֱ����;�̬�������ڴ�
//	int* pi = new int(100); //ָ��piָ����ڴ����� ������ר�Ŵ����������ʱ������ڴ�
//	cout << &i << " " << &pc << " " << &cd << " " << &si << " " << pi << endl;
//	delete pi; //�����Ա�Լ��ͷ�
//	return 0;
//}



//��ֵ���ı�����
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



//��ַ
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



//������ʵ�ֽ���j
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

//-----------------------------------------������Ϊ����ֵ--------------------------
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

//-------------------------------------��������------------------------------
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

//------------------------------------�������캯��-----------------------------

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
//	//�������캯��
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

//---------------------------------------thisָ��--------------------------

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
//		this->_month = month;                           //���仰�ǵȼ۵�
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

//----------------------------------------------��������--------------------------------------
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

//------------this��ʵ������--------

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
//		cout << "thisָ�뱣����ڴ��ַΪ:" << this << endl; 
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
//	cout << "����a���ڵ��ڴ��ַΪ:" << &a << endl;
//	cout << "����a�������ֵΪ:" << a.get() << endl;//����ĵ�ַ��thisָ��ĵ�ַ��һ����
//	cout << endl;
//	A b;
//	b.set(999);
//	cout << "����b���ڵ��ڴ��ַΪ:" << &b << endl;
//	cout << "����b�������ֵΪ:" << b.get() << endl;
//	system("pause");
//	return 0;
//}

//--------------------------operator���������-----------------------

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

//-------------------------��һ������---------------------
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

//---------------��ʼ���б�---------------   
//class data                                  //��ʼ��ֻ����һ��
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

//------------------------------static������--------------------
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
//	//�Ǿ�̬��Ա��������������������ʱ��ֱ�ӳ�ʼ��
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

//----------------------��Ԫ����---------------------
//�������������operator���ط����������ڣ�����ռ��һ����������������������⣬����޷��������еĶ���
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

//--------------------------------��ȷ����-------------------------
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


//----------------------String��------------------

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
//	/*TestString(s);*/                                        //���еĹ��캯�������Ķ��������Ϊ�ⲿ�����Ĳ�����
//	system("pause");
//	return 0;
//}

//-------------------------------String�ӿڵ�ʹ��-----------------------------

//void TestString()
//{
//	string s1;					//������ַ���
//	string s2("hello world");	//����string�����
//	string s3(5, 'a');			//��n���ַ�������string�����
//	string s4(s2);				//�������캯��
//	string s5(s2, 5);			//��s2�е�5���ַ������ĵ�string����
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
//	cout << s1.size() << endl;		//�����ַ�������Ч����
//	cout << s1.length() << endl;	//�����ַ�������Ч����
//	cout << s1.capacity() << endl;	//�����ַ����Ĵ�С
//	cout << s1.empty() << endl;		//�ж��ַ����Ƿ�Ϊ�գ�����bool
//	s1.resize(15, 'a');				//����Ч�ַ���Ϊn������������ַ�a���
//	cout << s1 << endl;
//	s1.reserve(20);					//Ϊ�ַ���Ԥ���ռ�
//	s1.clear();						//�����Ч�ַ���
//	cout << s1 << endl;
//
//}
//
//void TestStringAccess()
//{
//	string s1("hello world");		//����posλ�õ��ַ�
//	cout << s1.operator[](4) << endl;
//}
//
//void TestStringChange()
//{
//	string s1("hello world");
//	s1.push_back('a');			//β��һ���ַ�
//	cout << s1 << endl;
//	s1.append(5, 'b');			//�ַ�����׷��n���ַ�b
//	cout << s1 << endl;
//	s1.operator+=("people");	//�ַ�����׷��һ���ַ���
//	cout << s1 << endl;
//	s1.operator+=('b');			//�ַ�����׷��һ���ַ�
//	cout << s1 << endl;
//	int c=s1.find('b', 1);		//��posλ������ʼ���ַ�b���ҵ��󷵻�λ��
//	cout << c << endl;
//	int d = s1.rfind('b', 10);	//��posλ����ǰ��ʼ���ַ�b���ҵ��󷵻�λ��
//	cout << c << endl;
//	s1.substr(2, 2);			//��posλ�ÿ�ʼ��ȡn���ַ�����
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


//-----------------------------String�Ĵ�ͳд��-------------------------
//ע���ַ����͵����ַ�һ����""һ����''

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


//-----------------------------ģ��ʵ��String��--------------------------
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
	//	// ������������ھ��������򿪱ٿռ�
	//	if (newCapacity > _capacity)
	//	{
	//		char* str = new char[newCapacity + 1];
	//		strcpy(str, _str);
	//		// �ͷ�ԭ���ɿռ�,Ȼ��ʹ���¿ռ�
	//		delete[] _str;
	//		_str = str;
	//		_capacity = newCapacity;
	//	}

	//}

	//void PushBack(char c)//β��һ�������ַ�
	//{
	//	if (_size == _capacity)
	//	{
	//		Reserve(_capacity * 2);
	//	}
	//	_str[_size++] = 'c';
	//	_str[_size] = '\0';
	//}

	//void Append(const char* str)//ƴ��һ���ַ���
	//{
	//	if (_size == _capacity)
	//	{
	//		Reserve(_capacity * 5);
	//	}
	//	strcat(_str, str);
	//}

	//char& operator[](size_t index)
	//{
	//	//ͨ��ָ��ʵ��
	///*	String tmp(*this);
	//	char *p = tmp._str;
	//	while (index != 0)
	//	{
	//		*(p++);
	//		index--;
	//	}		
	//	char a = *p;
	//	return a;*/

	//	//ͨ��_strʵ��
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

//auto��const auto&��ʹ��
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