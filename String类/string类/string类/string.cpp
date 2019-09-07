#include<iostream>
#include<string>
#include<assert.h>

using namespace std;

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
		// ������������ھ��������򿪱ٿռ�
		if (newCapacity > _capacity)
		{
			char* str = new char[newCapacity + 1];
			strcpy(str, _str);
			// �ͷ�ԭ���ɿռ�,Ȼ��ʹ���¿ռ�
			delete[] _str;
			_str = str;
			_capacity = newCapacity;
		}

	}

	void PushBack(char c)//β��һ�������ַ�
	{
		if (_size == _capacity)
		{
			Reserve(_capacity * 2);
		}
		_str[_size++] = 'c';
		_str[_size] = '\0';
	}

	void Append(const char* str)//ƴ��һ���ַ���
	{
		if (_size == _capacity)
		{
			Reserve(_capacity * 5);
		}
		strcat(_str, str);
	}

	char& operator[](size_t index)
	{
		//ͨ��ָ��ʵ��
		/*	String tmp(*this);
		char *p = tmp._str;
		while (index != 0)
		{
		*(p++);
		index--;
		}
		char a = *p;
		return a;*/

		//ͨ��_strʵ��
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


