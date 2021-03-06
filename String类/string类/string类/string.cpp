#include<iostream>
#include<string>
#include<assert.h>

using namespace std;

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
class String
{
public:
	typedef char* Iterator;

public:
	String(const char* str = "")
	{
		if (nullptr == str)
		{
			str = "";
		}
		_size = strlen(str);
		_capacity = _size;
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	//String(const char* str, size_t size)  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//{
	//	
	//}

	String(const String& s)
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pStr = new char[strlen(s._str) + 1];
			strcpy(pStr, s._str);
			delete[]_str;
			_str = pStr;
		}
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[]_str;
			_str = nullptr;
		}
	}

	Iterator Begin()
	{
		return _str;
	}
	Iterator End()
	{
		return _str + _size;
	}
	Iterator RBegin()
	{
		return End();
	}
	Iterator REnd()
	{
		return Begin();
	}

	void Reserve(size_t newCapacity)
	{
		// 如果新容量大于旧容量，则开辟空间
		if (newCapacity > _capacity)
		{
			char* str = new char[newCapacity + 1];
			strcpy(str, _str);
			// 释放原来旧空间,然后使用新空间
			delete[] _str;
			_str = str;
			_capacity = newCapacity;
		}

	}

	void PushBack(char c)//尾插一个单个字符
	{
		if (_size == _capacity)
		{
			Reserve(_capacity * 2);
		}
		_str[_size++] = 'c';
		_str[_size] = '\0';
	}

	void Append(const char* str)//拼接一个字符串
	{
		if (_size == _capacity)
		{
			Reserve(_capacity * 5);
		}
		strcat(_str, str);
	}

	char& operator[](size_t index)
	{
		//通过指针实现
		/*	String tmp(*this);
		char *p = tmp._str;
		while (index != 0)
		{
		*(p++);
		index--;
		}
		char a = *p;
		return a;*/

		//通过_str实现
		assert(index < _size);
		return _str[index];
	}

	const char& operator[](size_t index)const
	{
		assert(index <= _size);
		return _str[index];
	}

	void ReSize(size_t newSize, char c);

	int Size()const
	{
		return _size;
	}

	bool Empty()const
	{
		return 0 == _size;
	}

	void Clear()
	{
		_size = 0;
		_str[_size] = '\0';
	}

	int Find(char c, size_t pos = 0)
	{
		for (; pos < _size; pos++)
		{
			if (_str[pos] == c)
			{
				return pos;
			}
		}
		return -1;
	}

	int rFind(char c)
	{
		int pos = _size;
		for (; pos >= 0; pos--)
		{
			if (_str[pos] == c)
			{
				return pos;
			}
		}
		return -1;
	}

	const char* C_Str()const
	{
		return _str;
	}

	void Swap(String& s)
	{
		swap(_str,s._str);
		swap(_size, s._size);
		swap(_capacity, s._capacity);
	}


	friend ostream& operator<<(ostream& _cout, const String& s)
	{
		_cout << s._str;
		return _cout;
	}
	friend istream& operator>>(istream& _cout, String& s);

private:
	char* _str;
	size_t _capacity;
	size_t _size;
};

void TestString()
{
	String s1("hello world");
}

int main()
{
	TestString();
	system("pause");
	return 0;
}


