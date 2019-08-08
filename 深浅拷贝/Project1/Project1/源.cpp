#include<iostream>

using namespace std;

//class String
//{
//public:
//	String(const char *str="")
//		:_pstr(new char[strlen(str)+1])
//	{
//		strcpy(_pstr, str);
//	}
//
//	~String()
//	{
//		if (_pstr)
//		{
//			delete[] _pstr;
//		}
//	}
//private:
//	char *_pstr;
//};
//
//int main()
//{
//	String str1("hello");
//	String str2(str1);
//	return 0;
//}

//---------string的传统写法----------
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

//---------------------String的现代写法-------------
class String
{
public:
	String(const char * str = "")
		:_str(new char[strlen(str)+1])
	{
		strcpy(_str, str);
	}
	
	String(const String& str)
		:_str(NULL)
	{
		String tmpStr(str._str);
		swap(_str, tmpStr._str);
	}
	//借助构造函数
	/*String& operator=(const String& str)
	{
		if (this!=&str)
		{
			String tmpStr(str._str);
			swap(_str, tmpStr._str);
		}
		return *this;
	}*/
	//借助拷贝构造函数
	/*String& operator=(String str)
	{
		swap(_str, str._str);
		return *this;
	}*/
	~String()
	{
		if (_str)
		{
			delete[]_str;
		}
	}
	const char* c_str()
	{
		return _str;
	}
private:
	char * _str;
};

//explicit禁止隐式类型转换

//class Student
//{
//	explicit Student()
//	{
//
//	}
//};