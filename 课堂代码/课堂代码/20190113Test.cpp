#include <iostream>
using namespace std;


// 1. �����˳�
// 2. �쳣�˳�

#if 0
#include <windows.h>

int Div(int left, int right)
{
	if (0 == right)
		exit(1);

	return left / right;
}

void TestFunc()
{
	FILE* pf = fopen("333.txt", "rb");
	if (nullptr == pf)
	{
		int errNo = GetLastError();
		cout << errNo << endl;
		cout << errno << endl;
		//return;
		goto L;
	}

L:
	http://www.baidu.com;
	return;
}



int main()
{
	TestFunc();
	//Div(10, 0);
	
	return 0;
}
#endif

#if 0
#include <setjmp.h>

jmp_buf g_buff;

void TestFunc1()
{
	FILE* pf = fopen("333.txt", "rb");
	if (nullptr == pf)
		longjmp(g_buff, 1);

	//.....
	fclose(pf);
}

void TestFunc2()
{
	int* p = (int*)malloc(sizeof(int)*0xffffffff);
	if (nullptr == p)
		longjmp(g_buff, 2);

	//.....
	free(p);
}


int main()
{
	int iState = 0;
	if (0 == iState)
	{
		TestFunc1();
		TestFunc2();
	}
	else
	{
		switch (iState)
		{
		case 1:
			cout << "TestFunc1: err" << endl;
			break;
		case 2:
			cout << "TestFunc2: err" << endl;
			break;
		default:
			cout << "δ֪����" << endl;
		}
	}

	iState = setjmp(g_buff);
	
	return 0;
}
#endif

#if 0
void TestFunc1(int* p)
{
	FILE* pf = fopen("333.txt", "rb");
	if (nullptr == pf)
		throw 1;
	//...

	fclose(pf);
}

void TestFunc2()
{
	int* p = nullptr;//(int*)malloc(sizeof(int)* 0xffffffff);
//  	if (nullptr == p)
//  		throw '1';

	try
	{
		TestFunc1(p);
	}
	catch (char err)
	{
		cout << err << endl;
	}
	
	// ....
	free(p);
}


int main()
{
	try
	{
		TestFunc2();
	}
	catch (int err)  // catch--����������͵��쳣
	{
		cout << err << endl;
	}
	catch (char ch)
	{
		cout << ch << endl;
	}

	//


	//....
	return 0;
}
#endif

#if 0
class Exception
{
public:
	Exception()
	{
		cout << "Exception::Exception()" <<this<< endl;
	}

	Exception(const Exception&)
	{
		cout << "Exception::Exception(const Exception&)" <<this<< endl;
	}

	~Exception()
	{
		cout << "Exception::~Exception()" <<this<< endl;
	}
};

void TestFunc()
{
	Exception e;
	cout << &e << endl;
	throw e;   // ��e��������һ����ʱ���������׳�������ʱ���������e
}

int main()
{
	try
	{
		TestFunc();
	}
	catch (const Exception& e)
	{
		cout << &e << endl;
	}

	return 0;
}
#endif

#if 0
int TestFunc1()
{
	FILE* pf = fopen("333.txt", "rb");
	if (nullptr == pf)
		throw 2;

	// ... 
	fclose(pf);
}

// �쳣�������׳�
void TestFunc2()
{
	int* p = (int*)malloc(sizeof(int)* 10);
	if (nullptr == p)
		throw 1;

	try
	{
		TestFunc1();
	}
	catch (...) // ����δ֪�쳣
	{
		free(p);
		throw;
	}
	

	// ...
	free(p);
}

int main()
{
	try
	{
		TestFunc2();
	}
	catch (int err)
	{
		cout << err << endl;
	}
	return 0;
}
#endif


#if 0
void TestFunc1()
{
	//throw '1';
	int array[10];
	throw array;
}



int main()
{
	try
	{
		TestFunc1();
	}
	catch (int* err)
	{
		cout << err << endl;
	}
	catch (char err)
	{
		cout << err << endl;
	}
	
	return 0;
}
#endif


/*
void TestFunc1()
{
	int e = 1;
	cout << &e << endl;
	throw e;
}

void TestFunc2()
{
	int* p = new int[10];

	try
	{
		TestFunc1();
	}
	catch (int& err)
	{
		delete[] p;
		cout << &err << endl;
		return;
	}
	
	//....
	delete[] p;
}

int main()
{
	try
	{
		TestFunc2();
	}
	catch (int err)
	{
		cout << err << endl;
	}
	
	return 0;
}
*/

#if 0
class Exception
{
public:
	Exception()
	{
		cout << "Exception():" << this << endl;
	}

	Exception(const Exception&)
	{
		cout << "Exception(const Exception&):" << this << endl;
	}

	~Exception()
	{
		cout << "~Exception():" << this << endl;
	}
};


void TestFun()
{
	Exception e;
	cout << &e << endl;
	throw e;
}

int main()
{
	try
	{
		TestFun();
	}
	catch (...)
	{
		cout << "δ֪�쳣" << endl;
	}
// 	catch (const Exception& e)
// 	{
// 		cout << &e << endl;
// 	}

	return 0;
}
#endif


#if 0
// �쳣�������׳�
void TestFunc1()
{
	throw 1;
}

void TestFunc2()
{
	int* p = new int[10];

	//....

	try
	{
		TestFunc1();
	}
	catch (...)
	{
		delete[] p;
		throw;
	}
	


	//...

	delete[] p;
}
int main()
{
	try
	{
		TestFunc2();
	}
	catch (int err)
	{
		cout << err << endl;
	}
	return 0;
}
#endif


#if 0
void TestFunc1()throw()//throw (int,double)
{
	throw 1.0;
}

void TestFunc2()
{
	TestFunc1();
}

void TestFunc3()
{
	TestFunc2();
}

void TestFunc4()
{
	try
	{
		TestFunc3();
	}
	catch (int err)
	{
		cout << err << endl;
	}
	
}


int main()
{
	try
	{
		TestFunc4();
	}
	catch (int err)
	{
		cout << err << endl;
	}
	catch (...)
	{
		;
	}

	return 0;
}
#endif

#if 0
#include <string>

class Exception
{
public:
	Exception(int errID, const string& errInfo)
		: _errID(errID)
		, _errInfo(errInfo)
	{}

	virtual void What()const = 0;

protected:
	int _errID;
	string _errInfo;
};

class NetException : public Exception
{
public:
	NetException(int errID, const string& errInfo)
		: Exception(errID, errInfo)
	{}

	virtual void What()const
	{
		cout << _errID << " " << _errInfo << endl;
	}
};

class DBException : public Exception
{
public:
	DBException(int errID, const string& errInfo)
		: Exception(errID, errInfo)
	{}

	virtual void What()const
	{
		cout << _errID << " " << _errInfo << endl;
	}
};


void TestFunc1()
{
	throw NetException(404, "��Դ�Ҳ���");
}

void TestFunc2()
{
	throw DBException(604, "���ݿ��");
}

int main()
{
	try
	{
		char* p = new char[0x7fffffff];
		TestFunc1();
		TestFunc2();
	}
	catch (const Exception& e)
	{
		e.What();
	}
	catch (const exception& e)
	{
		e.what();
	}
	catch (...)
	{
		cout << "δ֪�쳣" << endl;
	}

	return 0;
}
#endif

#if 0
void f1()
{
	//...
	throw 1;
}

bool f2()
{
	//...
	return false;
}


void TestFunc()
{
	FILE* pf = fopen("1111.txt", "rb");
	int* p = new int[10];
	
	if (nullptr == pf)
	{
		delete[] p;
		return;
	}

	// 
	try
	{
		f1();
	}
	catch (...)
	{
		delete[] p;
		fclose(pf);
		throw;
	}

	if (!f2())
	{
		delete[] p;
		fclose(pf);
		return;
	}
	

	delete[] p;
	fclose(pf);
}

int main()
{
	return 0;
}
#endif

/*
//����ָ�룺RAII������Ҫ����ʲôʱ���ͷ���Դ�� + operator*()/operator->()���ö��������ָ��һ��ʹ��
// ǳ����--->����ʹ������ķ�ʽ���
template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr = nullptr)
		: _ptr(ptr)
	{}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	~SmartPtr()
	{
		if (_ptr)
			delete _ptr;
	}

protected:
	T* _ptr;
};


struct A
{
	int a;
	int b;
	int c;
};

void TestFunc()
{
	int* p = new int;
	delete p;
	A * pa = new A;
	pa->a = 10;

	SmartPtr<int> sp(new int);
	*sp = 10;

	SmartPtr<A> spa1(new A);
	spa1->a = 10;

	SmartPtr<A> spa2(spa1);
}

int main()
{
	TestFunc();
	return 0;
}
*/

#if 0
// ��Դ����Ȩ(ӵ��)��ת��
// �⣺auto_ptr C++98  ���飺ʲô����¶���Ҫʹ��
template<class T>
class AutoPtr
{
public:
	AutoPtr(T* ptr)
		: _ptr(ptr)
	{}

	AutoPtr(AutoPtr<T>& ap)
		: _ptr(ap._ptr)
	{
		ap._ptr = nullptr;
	}

	// spa1 = spa2;
	AutoPtr<T>& operator=(AutoPtr<T>& sp)
	{
		if (this != &sp)
		{
			if (_ptr)
				delete _ptr;

			_ptr = sp._ptr;
			sp._ptr = nullptr;
		}
	}

	~AutoPtr()
	{
		if (_ptr)
			delete _ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	T* Get()
	{
		return _ptr;
	}

private:
	T* _ptr;
};

void TestFunc()
{
	int* pa1 = new int;
	int* pa2 = pa1;

	*pa1 = 10;
	*pa2 = 20;

	AutoPtr<int> ap1(new int);
	AutoPtr<int> ap2(ap1);

	*ap1 = 10;  // �����ϣ�ִ���ڻ����
	*ap2 = 20;
}

int main()
{
	TestFunc();
	return 0;
}
#endif

#if 0
// �汾2����Դ�ͷ�Ȩ����ת��
template<class T>
class AutoPtr
{
public:
	AutoPtr(T* ptr = nullptr)
		: _ptr(ptr)
		, _owner(false)
	{
		if (_ptr)
			_owner = true;
	}

	AutoPtr(const AutoPtr<T>& sp)
		: _ptr(sp._ptr)
		, _owner(sp._owner)
	{
		sp._owner = false;
	}

	AutoPtr<T>& operator=(const AutoPtr<T>& sp)
	{
		if (this != &sp)
		{
			Release();
			_ptr = sp._ptr;
			_owner = sp._owner;
			sp._owner = false;
		}

		return *this;
	}

	~AutoPtr()
	{
		Release();
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	T* Get()
	{
		return _ptr;
	}

private:
	void Release()
	{
		if (_ptr && _owner)
		{
			delete _ptr;
			_owner = false;
		}
	}

private:
	T* _ptr;
	mutable bool _owner;
};

void TestFunc()
{
	AutoPtr<int> ap1(new int);
	AutoPtr<int> ap2(ap1);

	*ap1 = 10;
	*ap2 = 20;
}

int main()
{
	TestFunc();
	return 0;
}
#endif

#if 0
// ��Դ��ռ(��Դֻ�ܱ�һ���������)
template<class T>
class UniquePtr
{
public:
	UniquePtr(T* ptr = nullptr)
		: _ptr(ptr)
	{}

	~UniquePtr()
	{
		if (_ptr)
			delete _ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	// C++98
// private:
// 	UniquePtr(const UniquePtr<T>&);
// 	UniquePtr<T>& operator=(const UniquePtr<T>&);

	// delete

	UniquePtr(const UniquePtr<T>&) = delete;
	UniquePtr<T>& operator=(const UniquePtr<T>&) = delete;
protected:
	T* _ptr;
};


void TestUniquePtr()
{
	UniquePtr<int> up1(new int);
	UniquePtr<int> up2(up1);

	UniquePtr<int> up3;
	up3 = up1;
}

int main()
{
	return 0;
}
#endif

#if 0
#include <mutex>

// �������ü����ķ�ʽ�ö������֮�乲����Դ
template<class T>
class SharedPtr
{
public:
	SharedPtr(T* ptr = nullptr)
		: _ptr(ptr)
		, _pCount(nullptr)
	{
		if (_ptr)
		{
			_pCount = new int(1);
			_pm = new mutex;
		}
			
	}

	// SharedPtr<int> ap2(ap1);
	SharedPtr(const SharedPtr<T>& sp)
		: _ptr(sp._ptr)
		, _pCount(sp._pCount)
		, _pm(sp._pm)
	{
		if (_ptr)
			AddRefCount();
	}

	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
	{
		if (this != &sp)
		{
			Release();

			_ptr = sp._ptr;
			_pCount = sp._pCount;
			if (_ptr)
				AddRefCount();
		}

		return *this;
	}

	~SharedPtr()
	{
		Release();
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	int UseCount()
	{
		assert(_pCount);
		return *_pCount;
	}

private:
	void Release()
	{
		if (_ptr && 0 == SubRefCount())
		{
			delete _ptr;
			delete _pCount;
			delete _pm;
		}
	}

	void AddRefCount()
	{
		_pm->lock();
		++(*_pCount);  //---
		_pm->unlock();
	}

	int SubRefCount()
	{
		_pm->lock();
		++(*_pCount); // d������������--- 
		_pm->unlock();

		return *_pCount;
	}

private:
	T* _ptr;
	int* _pCount;
	mutex* _pm;
};




void TestSharedPtr()
{
	SharedPtr<int> sp1(new int);
	SharedPtr<int> sp2(sp1);

	SharedPtr<int> sp3(new int);
	SharedPtr<int> sp4(sp3);

	sp1 = sp3;  // sp1-->--��������sp3������Դ
	sp2 = sp3;  // sp2-->--�����ͷ�Դ��Դ����sp3������Դ
}



#include <thread>

struct Date
{
	Date()
	{
		_year = _month = _day = 0;
	}

	unsigned long long _year;
	unsigned long long _month;
	unsigned long long _day;
};



void SharePtrFunc(SharedPtr<Date>& sp, size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		// ��������ָ�뿽����++����������ָ��������--�������������̰߳�ȫ�ġ�
		SharedPtr<Date> copy(sp);

		// ��������ָ����ʹ������Դ�������̰߳�ȫ�ġ��������ǿ�����Щֵ�����߳�++��2n�Σ�������
		copy->_year++;
		copy->_month++;
		copy->_day++;
	}
}

int main()
{
	//TestSharedPtr();
	SharedPtr<Date> sp(new Date);

	for (int i = 0; i < 20; ++i)
	{
		SharePtrFunc(sp, 100000);

	}
	
	cout << sp->_year << " " << sp->_month << " " << sp->_day << endl;
	return 0;
}
#endif

#if 0
// ����ɾ����
template<class T>
class DFDef
{
public:
	void operator()(T*& p)
	{
		if (p)
		{
			delete p;
			p = nullptr;
		}
	}
};

template<class T>
class Free
{
public:
	void operator()(T*& p)
	{
		if (p)
		{
			free(p);
			p = nullptr;
		}
	}
};

class FClose
{
public:
	void operator()(FILE* p)
	{
		if (p)
		{
			fclose(p);
			p = nullptr;
		}
	}
};
#include <mutex>

// �������ü����ķ�ʽ�ö������֮�乲����Դ
template<class T, class DF = DFDef<T>>
class SharedPtr
{
public:
	SharedPtr(T* ptr = nullptr)
		: _ptr(ptr)
		, _pCount(nullptr)
	{
		if (_ptr)
		{
			_pCount = new int(1);
			_pm = new mutex;
		}
	}

	// SharedPtr<int> ap2(ap1);
	SharedPtr(const SharedPtr<T>& sp)
		: _ptr(sp._ptr)
		, _pCount(sp._pCount)
		, _pm(sp._pm)
	{
		if (_ptr)
			AddRefCount();
	}

	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
	{
		if (this != &sp)
		{
			Release();

			_ptr = sp._ptr;
			_pCount = sp._pCount;
			if (_ptr)
				AddRefCount();
		}

		return *this;
	}

	~SharedPtr()
	{
		Release();
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	int UseCount()
	{
		assert(_pCount);
		return *_pCount;
	}

private:
	void Release()
	{
		if (_ptr && 0 == SubRefCount())
		{
			//delete _ptr;
			DF()(_ptr);
			delete _pCount;
			delete _pm;
		}
	}

	void AddRefCount()
	{
		_pm->lock();
		++(*_pCount);  //---
		_pm->unlock();
	}

	int SubRefCount()
	{
		_pm->lock();
		--(*_pCount); // d������������--- 
		_pm->unlock();

		return *_pCount;
	}

private:
	T* _ptr;
	int* _pCount;
	mutex* _pm;
};


int main()
{
	SharedPtr<int> sp1(new int);
	SharedPtr<int, Free<int>> sp2((int*)malloc(sizeof(int)));
	SharedPtr<FILE, FClose> sp3(fopen("1.txt", "w"));
	
	// XXX
	//SharedPtr<int> sp1(new int[10]);
	return 0;
}
#endif


#if 0
#include <memory>

// shared_ptr: ȱ�ݴ���ѭ������

struct ListNode
{
	ListNode(int data = 0)
	:_data(data)
// 		: _pPre(nullptr)
// 		, _pNext(nullptr)
// 		, _data(data)
	{
		cout << "ListNode():" << this << endl;
	}

	~ListNode()
	{
		cout << "~ListNode():" << this << endl;
	}

	weak_ptr<ListNode> _pPre;
	weak_ptr<ListNode> _pNext;

	//shared_ptr<ListNode> _pPre;
	//shared_ptr<ListNode> _pNext;

	//ListNode* _pPre;
	//ListNode* _pNext;
	int _data;
};

void TestSharedPtr()
{
	shared_ptr<ListNode> sp1(new ListNode(10));
	shared_ptr<ListNode> sp2(new ListNode(20));
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;

	sp1->_pNext = sp2;
	sp2->_pPre = sp1;
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;
}

int main()
{
	// weak_ptr�����ܶ���������Դ
	// ���ã�ר�Ž��shared_ptr���ڵ�ѭ�����õ�����
	//weak_ptr<int> wp(new int);
	TestSharedPtr();
	return 0;
}
#endif

#if 0
#include <map>
#include <string>

int main()
{
	map<string, string> m1;
	map<string, string> m2{ { "apple", "ƻ��" }, { "orange", "����" }, {"banana", "�㽶"} };
	m2.insert(pair<string, string>("peach", "����"));
	m2.insert(make_pair("pear", "��"));
	cout << m2["apple"] << endl;
	cout << m2.size() << endl;

	m2["red-appple"] = "��ƻ��";
	cout << m2.size() << endl;

	//map<string, string>::iterator it = m2.begin();
	auto it = m2.begin();
	while (it != m2.end())
	{
		cout << it->first << "--->" << it->second << endl;
		++it;
	}
	cout << endl;

	for (auto& e : m2)
	{
		cout << e.first << "--->" << e.second << endl;
	}

	return 0;
}
#endif


#if 0
#include <set>

int main()
{
	int array[] = { 1, 1, 2, 2, 3, 4, 5, 4, 5, 6, 7, 7, 6, 8, 8, 9, 0, 0, 9 };
	set<int> s1;
	for (auto e : array)
		s1.insert(e);

	cout << s1.size() << endl;

	for (auto e : s1)
		cout << e << " ";
	cout << endl;

	cout << s1.count(1) << endl;

	multiset<int> s2;
	for (auto e : array)
		s2.insert(e);

	cout << s2.size() << endl;

	for (auto e : s2)
		cout << e << " ";
	cout << endl;

	cout << s2.count(1) << endl;
	return 0;
}
#endif

//#include "BinarySearchTree.hpp"

//#include "AVLTree.hpp"
#include "RBTree.hpp"


int main()
{
	//TestBSTree();
	//TestAVLTree();
	TestRBTree();
	return 0;
}