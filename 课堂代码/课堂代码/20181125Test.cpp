#include <iostream>
using namespace std;

#if 0
#include <stack>

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int, int, int):" << this << endl;
	}

	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		cout << "Date(const Date&):" << this << endl;
	}


private:
	int _year;
	int _month;
	int _day;
};
void TestStack()
{
	stack<Date> s;
	Date d(2018, 11, 25);
	s.push(d);
	s.emplace(2018, 11, 26); // C++11
	s.emplace(2018, 11, 27);

	stack<Date> s1;
	//s.swap(s1);
	swap(s, s1);
}

int main()
{
	//TestStack();
	cout << atoi("-123") << endl;
	return 0;
}
#endif

#if 0
#include <vector>
#include <queue>
#include <functional>

int main()
{
	vector<int> v{ 3, 2, 7, 6, 0, 4, 1, 9, 8, 5 };
	priority_queue<int> maxHeap;
	for (auto e : v)
		maxHeap.push(e);

	cout << maxHeap.top() << endl;

	priority_queue<int, vector<int>, greater<int> > minHeap;
	for (auto e : v)
		minHeap.push(e);

	cout << minHeap.top() << endl;
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

// 	bool operator<(const Date& d)const
// 	{
// 		return (_year < d._year) ||
// 			(_year == d._year && _month < d._month) ||
// 			(_year == d._year && _month == d._month && _day < d._day);
// 	}

// 	bool operator>(const Date& d)const
// 	{
// 		return (_year > d._year) ||
// 			(_year == d._year && _month > d._month) ||
// 			(_year == d._year && _month == d._month && _day > d._day);
// 	}

	friend ostream& operator<<(ostream& _cout, const Date& d)
	{
		_cout << d._year << "-" << d._month << "-" << d._day;
		return _cout;
	}

//private:
	int _year;
	int _month;
	int _day;
};


// 大堆： < 
class Greater
{
public:
	bool operator()(const Date& left, const Date& right)
	{
		return left._year < right._year ||
			left._year == right._year && left._month < right._month ||
			left._year == right._year && left._month == right._month && left._day < right._day;
	}
};

class Less
{
public:
	bool operator()(const Date& left, const Date& right)
	{
		return left._year > right._year ||
			left._year == right._year && left._month > right._month ||
			left._year == right._year && left._month == right._month && left._day > right._day;
	}
};


#include <vector>
#include <queue>
#include <functional>

int main()
{
	priority_queue<Date, vector<Date>, Greater> q;

	Date d1(2018, 11, 25);
	Date d2(2018, 11, 22);
	Date d3(2018, 11, 23);
	Date d4(2018, 11, 20);
	Date d5(2018, 11, 21);
	Date d6(2018, 11, 24);

	q.push(d1);
	q.push(d2);
	q.push(d3);
	q.push(d4);
	q.push(d5);
	q.push(d6);
	cout << q.top() << endl;

	priority_queue<Date, vector<Date>, Less> q1;
	q1.push(d1);
	q1.push(d2);
	q1.push(d3);
	q1.push(d4);
	q1.push(d5);
	q1.push(d6);
	cout << q1.top() << endl;

	Greater g;
	g.operator()(d1, d2);
	g(d1, d2);   // 仿函数(函数对象)

	return 0;
}
#endif

#if 0
namespace bit
{
	template<class T, class Container = deque<T>>
	class stack
	{
	public:
		stack()
		{}

		void push(const T& data)
		{
			_c.push_back(data);
		}

		void pop()
		{
			_c.pop_back();
		}

		T& top()
		{
			return _c.back();
		}

		const T& top()const
		{
			return _c.back();
		}

		size_t size()const
		{
			return _c.size();
		}

		bool empty()const
		{
			return _c.empty();
		}
	private:
		Container _c;
	};

	template<class T, class Container = deque<T>>
	class queue
	{
	public:
		queue()
		{}

		void push(const T& data)
		{
			_c.push_back(data);
		}

		void pop()
		{
			_c.pop_front();
		}

		T& front()
		{
			return _c.front();
		}

		const T& front()const
		{
			return _c.front();
		}

		T& back()
		{
			return _c.back();
		}

		const T& back()const
		{
			return _c.back();
		}

		size_t size()const
		{
			return _c.size();
		}

		bool empty()const
		{
			return _c.empty();
		}
	private:
		Container _c;
	};
}

int main()
{
	return 0;
}
#endif


// template<class T>
// void PrintArray(const T array, size_t size)
// {
// 	for (size_t i = 0; i < size; ++i)
// 		cout << array[i] << " ";
// 	cout << endl;
// }

#if 0
template<class T, size_t N>
void PrintArray(const T (&array)[N])
{
	for (size_t i = 0; i < N; ++i)
 		cout << array[i] << " ";
}

template<class T, size_t N>
class Array
{
	//...
private:
	T _array[N];
};

int main()
{
	int a = 10;
	int b = 20;

	Array<int, 100> arr;

	int array1[] = { 1, 2, 3, 4 };
	char array2[] = { '1', '2', '3', '4', '5' };
	PrintArray(array1);
	PrintArray(array2);
	return 0;
}
#endif

#if 0
template<class T>
bool IsEqual(T& left, T& right)
{
	return left == right;
}

int main()
{
	int a = 10, b = 20;
	cout << IsEqual(a, b) << endl;

	a = 20;
	cout << IsEqual(a, b) << endl;


	return 0;
}
#endif


#if 0
// Max<int>
template<class T>
T& Max(T& left, T& right)
{
	return left > right ? left : right;
}

// 1. 必须先要存在函数模板
// 2. 那种类型不能处理，特殊化处理该种类型
// template<>
// char*& Max<char*>(char*& left, char*& right)
// {
// 	if (strcmp(left, right) > 0)
// 		return left;
// 
// 	return right;
// }


char* Max(char* left, char* right)
{
	if (strcmp(left, right) > 0)
		return left;

	return right;
}





int main()
{
	int a = 10, b = 20;
	cout << Max(a, b) << endl;

	char* p1 = "world";
	char* p2 = "hello";
	
	cout << Max(p2, p1) << endl;
	cout << Max(p1, p2) << endl;

	return 0;
}
#endif

#if 0
// template<class T>
// void TestFunc(const T pa)   //void TestFunc<int*>(const int* pa)
// {
// 	pa = NULL;
// 	//*pa = 100;
// }

template<class T>
const T& Max(const T& left, const T& right)
{
	return left > right ? left : right;
}

/*
const int& Max<int>(const int& left, const int& right)
{
    return left > right? left:right;
}
*/



template<>
char*&const  Max<char*&>(char*&const left, char*&const right)
{
	if (strcmp(left, right) > 0)
		return left;
	return right;
}


int main()
{
	//int a = 10;
	//TestFunc(&a);

	char* p1 = "world";
	char* p2 = "hello";

	cout << Max(p1, p2) << endl;  // Max<char*>
	return 0;
}
#endif

#if 0
template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

// Data类模板的全特化
template<>
class Data<int, char>
{
public:
	Data() { cout << "Data<int, char>" << endl; }
private:
	int _d1;
	char _d2;
};

void TestVector()
{
	Data<int, int> d1;
	Data<int, char> d2;
}


int main()
{
	TestVector();
	return 0;
}
#endif

#if 0
template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

// 部分特化
template<class T1>
class Data<T1, int>
{
public:
	Data() { cout << "Data<T1, int>" << endl; }
private:
	T1 _d1;
	int _d2;
};

// 让类型更加严格
template<class T1, class T2>
class Data<T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }
private:
	T1* _d1;
	T2* _d2;
};

int main()
{
	Data<char, char> d1;
	Data<char, int> d2;
	Data<char*, char*> d3;
	
	return 0;
}
#endif

#if 0
// XXX
template<int N>
struct Sum
{
	const static int value;
};

template<int N>
const int Sum<N>::value = Sum<N - 1>::value + N;

template<>
struct Sum<0>
{
	const static int value;
};

const int Sum<0>::value = 0;

int main()
{
	Sum<100> s;
	cout << Sum<100>::value << endl;
	return 0;
}
#endif

/*
// 通用的拷贝方法
template<class T>
void Copy(T* dst, T* src, size_t size)
{
	// 浅拷贝
	memcpy(dst, src, sizeof(T)*size);
}

template<class T>
void Copy(T* dst, T* src, size_t size)
{
	for (size_t i = 0; i < size; ++i)
		dst[i] = src[i];
}
*/

#if 0
// 通用的拷贝方法
template<class T>
void Copy(T* dst, T* src, size_t size, bool isPOD)
{
	if (isPOD)
		memcpy(dst, src, sizeof(T)*size);
	else
	{
		for (size_t i = 0; i < size; ++i)
			dst[i] = src[i];
	}
}

#include <string>

int main()
{
	int array1[] = { 1, 2, 3, 4 };
	int array2[4];
	Copy(array2, array1, sizeof(array1) / sizeof(array1[0]), true);

	string str1[] = {"1111", "2222", "3333", "4444"};
	string str2[4];
	Copy(str2, str1, sizeof(str1) / sizeof(str1[0]), true);

	return 0;
}
#endif

#if 0
bool IsPOD(const char* typeName)
{
	const char* types[] = {"char", "int", "short", "long", "float"};
	for (size_t i = 0; i < sizeof(types) / sizeof(types[0]); ++i)
	{
		if (strcmp(types[i], typeName) == 0)
			return true;
	}

	return false;
}

// 通用的拷贝方法
template<class T>
void Copy(T* dst, T* src, size_t size)
{
	if (IsPOD(typeid(T).name()))
		memcpy(dst, src, sizeof(T)*size);
	else
	{
		for (size_t i = 0; i < size; ++i)
			dst[i] = src[i];
	}
}

int main()
{
	int array1[] = { 1, 2, 3, 4 };
	int array2[4];
	Copy(array2, array1, sizeof(array1) / sizeof(array1[0]));

	string str1[] = { "1111", "2222", "3333", "4444" };
	string str2[4];
	Copy(str2, str1, sizeof(str1) / sizeof(str1[0]));

	return 0;
}
#endif

#if 0
// 类型萃取
// 确认：T是否为内置类型

// 对应：内置类型
struct TrueType
{
	static bool Get()
	{
		return true;
	}
};

struct FalseType
{
	static bool Get()
	{
		return false;
	}
};

template<class T>
struct TypeTraits
{
	typedef FalseType PODType;
};

template<>
struct TypeTraits<int>
{
	typedef TrueType PODType;
};

template<>
struct TypeTraits<char>
{
	typedef TrueType PODType;
};

template<>
struct TypeTraits<double>
{
	typedef TrueType PODType;
};

template<>
struct TypeTraits<long>
{
	typedef TrueType PODType;
};

// ...


template<class T>
void Copy(T* dst, T* src, size_t size)
{
	if (TypeTraits<T>::PODType::Get())
		memcpy(dst, src, sizeof(T)*size);
	else
	{
		for (size_t i = 0; i < size; ++i)
			dst[i] = src[i];
	}
}

int main()
{
	int array1[] = { 1, 2, 3, 4 };
	int array2[4];
	Copy(array2, array1, sizeof(array1) / sizeof(array1[0]));

	string str1[] = { "1111", "2222", "3333", "4444" };
	string str2[4];
	Copy(str2, str1, sizeof(str1) / sizeof(str1[0]));

	return 0;
}
#endif


#if 0
struct TrueType
{};

struct FalseType
{};

template<class T>
struct TypeTraits
{
	typedef FalseType PODType;
};

template<>
struct TypeTraits<int>
{
	typedef TrueType PODType;
};

template<>
struct TypeTraits<char>
{
	typedef TrueType PODType;
};

template<>
struct TypeTraits<double>
{
	typedef TrueType PODType;
};

template<>
struct TypeTraits<long>
{
	typedef TrueType PODType;
};

// ...


template<class T>
void Copy(T* dst, T* src, size_t size, TrueType)
{
	memcpy(dst, src, sizeof(T)*size);
}

template<class T>
void Copy(T* dst, T* src, size_t size, FalseType)
{
	for (size_t i = 0; i < size; ++i)
		dst[i] = src[i];
}

template<class T>
void Copy(T* dst, T* src, size_t size)
{
	Copy(dst, src, size, TypeTraits<T>::PODType());
}

int main()
{
	int array1[] = { 1, 2, 3, 4 };
	int array2[4];
	Copy(array2, array1, sizeof(array1) / sizeof(array1[0]));

	string str1[] = { "1111", "2222", "3333", "4444" };
	string str2[4];
	Copy(str2, str1, sizeof(str1) / sizeof(str1[0]));

	return 0;
}
#endif

#include "add.hpp"

/*

template<class T>
T Add(const T& left, const T& right)
{
return left + right;
}

*/

#if 0
int main()
{
	Add(1, 2); // 对函数模板进行实例化  Add<int> ???
	Add(1.0, 2.0);  // Add<double> ???
	Add('1', '2'); // Add<char> ???
	return 0;
}
#endif

/*
int main()
{
	int a = 1;
	scanf("%d", a);
	printf("%d, %lf", 10);
	return 0;
}
*/

#if 0
// IO流
int main()
{
	char ch1, ch2;
	//cin >> ch;
	ch1 = getchar();
	getchar();
	ch2 = getchar();

	int a, b, c;
	//cin >> a >> b >> c;
	cin >> a;
	cin >> b;
	cin >> c;
	return 0;
}
#endif

#if 0
#include <fstream>

struct ServerInfo
{
	char _ip[32]; // ip
	int _port; // 端口
};
struct ConfigManager
{
public:
	ConfigManager(const char* configfile = "bitserver.config")
		:_configfile(configfile)
	{}
	void WriteBin(const ServerInfo& info)
	{
		// 这里注意使用二进制方式打开写
		ofstream ofs(_configfile, ifstream::out | ifstream::binary);
		ofs.write((const char*)&info, sizeof(ServerInfo));
		ofs.close();
	}
	void ReadBin(ServerInfo& info)
	{
		// 这里注意使用二进制方式打开读
		ifstream ifs(_configfile, ifstream::in | ifstream::binary);
		ifs.read((char*)&info, sizeof(ServerInfo));
		ifs.close();
	}
	void WriteText(const ServerInfo& info)
	{
		// 这里会发现IO流写整形比C语言那套就简单多了，
		// C 语言得先把整形itoa再写
		ofstream ofs(_configfile);
		ofs << info._ip << endl;
		ofs << info._port << endl;
		ofs.close();
	}
	void ReadText(ServerInfo& info)
	{
		// 这里会发现IO流读整形比C语言那套就简单多了，
		// C 语言得先读字符串，再atoi
		ifstream ifs(_configfile);
		ifs >> info._ip;
		ifs >> info._port;
		ifs.close();
	}
private:
	string _configfile; // 配置文件
};
int main()
{
	ConfigManager cfgMgr;
	ServerInfo wtinfo;
	ServerInfo rdinfo;
	strcpy(wtinfo._ip, "127.0.0.1");
	wtinfo._port = 80;
	// 二进制读写
// 	cfgMgr.WriteBin(wtinfo);
// 	cfgMgr.ReadBin(rdinfo);
// 	cout << rdinfo._ip << endl;
// 	cout << rdinfo._port << endl;

	// 文本读写
	cfgMgr.WriteText(wtinfo);
	cfgMgr.ReadText(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;
	return 0;
}
#endif

#if 0
int main()
{
	
	int i = 0;
	int a = i++; 
	int b = ++a; 
	int c = a + b;
	cout << (a ? b : c) << endl;

	int *pa[5];
	cout << sizeof(pa) << endl;

	int (*pb)[5];
	cout << sizeof(pb) << endl;
	return 0;
}
#endif

#if 0
#include <vector>
#include <unordered_map>

class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		unordered_map<int, int> m;
		for (int i = 0; i < n; ++i)
		{
			m[gifts[i]]++;
		}

		for (auto& e : m)
		{
			if (e.second > n / 2)
				return e.first;
		}

		return 0;
	}
};

int main()
{
	vector<int> gifts{1,2,2,3,2};
	gifts.reserve(30);
	cout << gifts.capacity() << endl;

	Gift g;
	cout<<g.getValue(gifts, 5)<<endl;
	return 0;
}
#endif

#if 0
// 哈希桶中元素是用链表串接起来的，因此先给出哈希桶的结构
template<class K, class V>
struct HashBucketNode
{
	HashBucketNode(const pair<K, V>& val)
	: _pNext(nullptr)
	, _val(val)
	{}

	HashBucketNode<K, V>* _pNext;
	pair<K, V> _val;
};

// 哈希函数采用处理余数法，被模的key必须要为整形才可以处理，此处提供将key转化为整形的方法
// 整形数据不需要转化
template<class T>
class DefHashF
{
public:
	size_t operator()(const T& val)
	{
		return val;
	}
};

// key为字符串类型，需要将其转化为整形
class Str2Int
{
public:
	size_t operator()(const string& str)
	{
		return BKDRHash(str.c_str());
	}

	size_t BKDRHash(const char * str)
	{
		unsigned int seed = 131; // 31 131 1313 13131 131313
		unsigned int hash = 0;
		while (*str)
		{
			hash = hash * seed + (*str++);
		}

		return (hash & 0x7FFFFFFF);
	}
};


template<class K, class V, class HF = DefHashF<T> >
class HashBucket
{
	typedef HashBucketNode<K, V> Node;
	typedef Node* PNode;

public:
	HashBucket(size_t capacity = 3)
		: _ht(capacity, nullptr)
		, _capacity(capacity)
		, _size(0)
	{}

	// 哈希桶中的元素key不能重复
	bool Insert(const pair<K, V>& val)
	{
		// 1. 计算元素所在的桶号
		size_t bucketNo = HashFunc(val.first);

		// 2. 检测该元素是否在桶中
		PNode pCur = _ht[bucketNo];
		while (pCur)
		{
			if (pCur->val.first == val.first)
				return false;

			pCur = pCur->next;
		}

		// 3. 插入新元素
		pCur = new Node(val);

		// 采用头插法插入，效率高
		pCur->_pNext = _ht[bucketNo];
		_ht[bucketNo] = pCur;
		_size++;

		return true;
	}

	bool Erase(const K& key)
	{
		//1. 通过哈希函数，找key所在的桶号
		size_t bucketNo = HashFunc(key);

		// 检测该元素在桶中是否存在
		PNode pPre = NULL;
		PNode pCur = _ht[bucketNo];
		while (pCur)
		{
			pPre = pCur;
			if (pCur->_val.first == key)
			{
				if (pCur == _ht[bucketNo])
				{
					_ht[bucketNo] = pCur->_pNext;
				}
				else
				{
					pPre->_pNext = pCur->_pNext;
				}

				delete pCur;
				--_size;
				return true;
			}
				

			pCur = pCur->_pNext;
		}

		return false;
	}

	size_t Size()const
	{
		return _size;
	}

	bool Empty()const
	{
		return 0 == _size;
	}

private:
	size_t HashFunc(const K& key)
	{
		return HF()(key) % _capacity;
	}

	void CheckCapacity()
	{
		if (_size == _ht.size())
		{
			HashBucket<K, V, HF> newHt(2*_size);
		}
	}

private:
	vector<PNode*> _ht;
	size_t _capacity;  // 哈希表中通的总个数
	size_t _size;      // 哈希表中有效元素的个数
};

int main()
{
	return 0;
}
#endif



