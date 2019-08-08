#include <iostream>
using namespace std;
#include <string>

#if 0
// ���μ̳�
class B
{
public:
	// B::TestFunc()
	void TestFunc()
	{
		cout << "B::TestFunc()" << endl;
	}
public:
	int _b;
};

class C1 : public B
{
	// B::TestFunc()
public:
	int _c1;
};


class C2 : public B
{
	// B::TestFunc()
public:
	int _c2;
};

class D : public C1, public C2
{
	// C1::B::TestFunc()
	// C2::B::TestFunc()
public:
	int _d;
};

int main()
{
	cout << sizeof(D) << endl;

	D d;

	// ���μ̳еĶ���������
	d.C1::_b = 0;
	d._c1 = 1;

	d.C2::_b = 2;
	d._c2 = 3;

	d._d = 4;

	// ���μ̳еĶ���������
	d.C1::TestFunc();
	return 0;
}
#endif

#if 0
class B
{
public:
	int _b;
};

class D : virtual public B
{
public:
	int _d;
};

int main()
{
	D d;     // call D()
	d._b = 1;
	d._d = 2;
	cout << sizeof(D) << endl;
	return 0;
}
#endif


#if 0
// ���μ̳�
class B
{
public:
	void TestFunc()
	{
		cout << "B::TestFunc()" << endl;
	}
public:
	int _b;
};

class C1 : virtual public B
{
public:
	int _c1;
};


class C2 : virtual public B
{
public:
	int _c2;
};

class D : public C1, public C2
{
public:
	int _d;
};

int main()
{
	D d;
	d._b = 1;
	d._c1 = 2;
	d._c2 = 3;
	d._d = 4;

	d.TestFunc();
	// 16  20  24
	cout << sizeof(D) << endl;
	return 0;
}
#endif

#if 0
class Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}

protected:
	int _b;
};

// ��д����д�ĺ���һ��Ҫ���麯�������������е��麯������������е��麯��ԭ����ȫ��ͬ
class Derived : public Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Derived::TestFunc1()" << endl;
	}
protected:
	int _d;
};

void TestVirtual(Base& b)
{
	b.TestFunc1();
}

int main()
{
	Base b;
	Derived d;

	TestVirtual(b);
	TestVirtual(d);
	return 0;
}
#endif


#if 0
class Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}

	virtual void TestFunc2()
	{
		cout << "Base::TestFunc2()" << endl;
	}

	void TestFunc3()
	{
		cout << "Base::TestFunc3()" << endl;
	}

	virtual void TestFunc4()
	{
		cout << "Base::TestFunc4()" << endl;
	}

	virtual Base* TestFunc5()
	{
		cout << "Base::TestFunc5()" << endl;
		return this;
	}

	virtual ~Base()
	{
		cout << "Base::~Base()" << endl;
	}

protected:
	int _b;
};

class Derived : public Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Derived::TestFunc1()" << endl;
	}

	void TestFunc2()
	{
		cout << "Derived::TestFunc2()" << endl;
	}

	virtual void TestFunc3()
	{
		cout << "Derived::TestFunc3()" << endl;
	}

	virtual void TestFunc4(int a = 10)
	{
		cout << "Derived::TestFunc4()" << endl;
	}

	virtual Derived* TestFunc5()
	{
		cout << "Derived::TestFunc5()" << endl;
		return this;
	}

	virtual ~Derived()
	{
		cout << "Derived::~Base()" << endl;
	}

protected:
	int _d;
};

void TestVirtual(Base& b)
{
	b.TestFunc1();
	b.TestFunc2();
	b.TestFunc3();
	b.TestFunc4();
	b.TestFunc5();
}

int main()
{
	Base* pb = new Base;
	delete pb;

	pb = new Derived;
	delete pb;

	Base b;
	Derived d;

	TestVirtual(b);
	TestVirtual(d);
	return 0;
}
#endif


#if 0
class Base
{
public:
	virtual ~Base()
	{
		cout << "Base::~Base()" << endl;
	}
};

class Derived : public Base
{
public:
	Derived()
	{
		_pt = new int[10];
	}

	~Derived()
	{
		cout << "Derived::~Derived()" << this << endl;
		if (_pt)
			delete[] _pt;
	}

protected:
	int* _pt;
};


int main()
{
	Base* pb = new Derived;
	delete pb;
	return 0;
}
#endif


#if 0
// �����շѹ���Ա
class WashRoom
{
public:
	void GotoManRoom()
	{
		cout << "Man ----> left" << endl;
	}

	void GotoWomanRoom()
	{
		cout << "Woman----> right" << endl;
	}
};


// ������:�������麯������
// �����಻��ʵ��������
// ���������Ҫ���̳У��������еĴ��麯�������������ļ̳��б��뱻��д
// ���������û����д�����еĴ��麯������������Ҳ�ǳ�����
class Person
{
public:
	// ���麯��
	virtual void GoToWashRoom(WashRoom& w) = 0;
};

class Man : public Person
{
public:
	virtual void GoToWashRoom(WashRoom& w)
	{
		w.GotoManRoom();
	}
};

class Woman : public Person
{
public:
	virtual void GoToWashRoom(WashRoom& w)
	{
		w.GotoWomanRoom();
	}
};


void TestWashRoom(Person& p)
{
	WashRoom wroom;
	p.GoToWashRoom(wroom);
}

#include <windows.h>

int main()
{
	Person* p = nullptr;
	for (size_t i = 0; i < 10; ++i)
	{
		if (rand() % 2 == 0)
		{
			p = new Man;
			TestWashRoom(*p);
		}
		else
		{
			p = new Woman;
			TestWashRoom(*p);
		}

		delete p;

		Sleep(1000);
	}

	return 0;
}
#endif

#if 0
// ʹ��final������������麯�����������麯���ں��������в��ܱ���д
// ��ò�Ҫ��final���λ�����麯��
class Base
{
public:
	virtual void TestFunc()
	{}
};

class Derived : public Base
{
public:
	virtual void TestFunc()final
	{}
};

int main()
{
	return 0;
}
#endif

#if 0
// override����������������и��麯���Ƿ��ǶԻ�����ĳ���麯������д
// override: ֻ��������������麯��
class Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}
};

class Derived : public Base
{
public:
	virtual void/*int*/ TestFunc1(/*int*/) override
	{
		cout << "Derived::TestFunc1()" << endl;
		//return 0;
	}
};

void TestVirtual(Base& b)
{
	b.TestFunc1();
}

int main()
{
	return 0;
}
#endif

#if 0
// �����������������Ĺ�������
class Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}

	virtual void TestFunc2()
	{
		cout << "Base::TestFunc2()" << endl;
	}

	virtual void TestFunc3()
	{
		cout << "Base::TestFunc3()" << endl;
	}

	

	int _b;
};

class Derived : public Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Derived::TestFunc1()" << endl;
	}

	virtual void TestFunc3()
	{
		cout << "Derived::TestFunc3()" << endl;
	}

	virtual void TestFunc5()
	{
		cout << "Derived::TestFunc5()" << endl;
	}

	virtual void TestFunc4()
	{
		cout << "Derived::TestFunc4()" << endl;
	}

	int _d;
};


typedef void(*PVFT)();

// ��ӡ����е�����
void PrintVFT(Base& b, string str)
{
	// 1. ��ȡ�麯���ĵ�ַ
	PVFT* pVFT = (PVFT*)*(int*)&b;

	cout << str << endl;
	// 2. ��ӡ
	while (*pVFT)
	{
		(*pVFT)();
		pVFT++;
	}
}

int main()
{
	cout << sizeof(Base) << endl;

	Base b;
	Derived d;

	b._b = 10;

	PrintVFT(b, "Base VFT:");
	PrintVFT(d, "Derived VFT:");
	return 0;
}
#endif

#if 0
class Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}

	void TestFunc2()
	{
		cout << "Base::TestFunc2()" << endl;
	}

	virtual void TestFunc3()
	{
		cout << "Base::TestFunc3()" << endl;
	}



	int _b;
};

class Derived : public Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Derived::TestFunc1()" << endl;
	}

	virtual void TestFunc3()
	{
		cout << "Derived::TestFunc3()" << endl;
	}

	virtual void TestFunc5()
	{
		cout << "Derived::TestFunc5()" << endl;
	}

	virtual void TestFunc4()
	{
		cout << "Derived::TestFunc4()" << endl;
	}

	int _d;
};


void TestVirtual(Base b)
{
	b.TestFunc1();
	b.TestFunc2();
	b.TestFunc3();
}


int main()
{
	Base b;
	Derived d;

	Base* pb = (Base*)&d;
	pb->TestFunc1();

	TestVirtual(b);
	TestVirtual(d);
	return 0;
}
#endif


/*
class Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}

	virtual void TestFunc2()
	{
		cout << "Base::TestFunc2()" << endl;
	}

	virtual void TestFunc3()
	{
		cout << "Base::TestFunc3()" << endl;
	}

	int _b;
};

class Derived : public Base
{
public:
	virtual void TestFunc4()
	{
		cout << "Derived::TestFunc4()" << endl;
	}

	virtual void TestFunc1()override
	{
		cout << "Derived::TestFunc1()" << endl;
	}

	virtual void TestFunc3()
	{
		cout << "Derived::TestFunc3()" << endl;
	}

	virtual void TestFunc5()
	{
		cout << "Derived::TestFunc5()" << endl;
	}

	int _d;
};


void TestVirtual(Base* pb)
{
	pb->TestFunc1();
	pb->TestFunc2();
	pb->TestFunc3();
}

void TestVirtual(Base b)
{
	b.TestFunc1();
	b.TestFunc2();
	b.TestFunc3();
}

int main()
{
	Base b;
	TestVirtual(&b);
	TestVirtual(b);

	Derived d;
	TestVirtual(&d);
	TestVirtual(d);

	Base* pb = (Base*)&d;
	pb->TestFunc1();

	return 0;
}
*/

/*
class B1
{
public:
	virtual void TestFunc1()
	{
		cout << "B1::TestFunc1()" << endl;
	}

	virtual void TestFunc2()
	{
		cout << "B1::TestFunc2()" << endl;
	}

	int _b1;
};

class B2
{
public:
	virtual void TestFunc3()
	{
		cout << "B2::TestFunc3()" << endl;
	}

	virtual void TestFunc4()
	{
		cout << "B2::TestFunc4()" << endl;
	}

	int _b2;
};

class D : public B1, public B2
{
public:
	virtual void TestFunc1()
	{
		cout << "D::TestFunc1()" << endl;
	}

	virtual void TestFunc4()
	{
		cout << "D::TestFunc4()" << endl;
	}

	virtual void TestFunc5()
	{
		cout << "D::TestFunc5()" << endl;
	}

	int _d;
};

typedef void(*PVFT)();

void PrintVFT1(B1& b, string str)
{
	cout << str << endl;
	PVFT* pVFT = (PVFT*)*(int*)&b;
	while (*pVFT)
	{
		(*pVFT)();
		++pVFT;
	}
	cout << endl;
}

void PrintVFT2(B2& b, string str)
{
	cout << str << endl;
	PVFT* pVFT = (PVFT*)*(int*)&b;
	while (*pVFT)
	{
		(*pVFT)();
		++pVFT;
	}
	cout << endl;
}

int main()
{
	cout << sizeof(D) << endl;

	D d;
	d._b1 = 1;
	d._b2 = 2;
	d._d = 3;

	PrintVFT1(d, "B1 VFT:");
	PrintVFT2(d, "B2 VFT:");
	return 0;
}
*/

#if 0
class B
{
public:
	virtual void TestFunc1()
	{
		cout << "B::TestFunc1()" << endl;
	}

	virtual void TestFunc2()
	{
		cout << "B::TestFunc2()" << endl;
	}

	int _b;
};

class C1 : virtual public B
{
public:
	virtual void TestFunc1()
	{
		cout << "C1::TestFunc1()" << endl;
	}

	virtual void TestFunc3()
	{
		cout << "C1::TestFunc3()" << endl;
	}

	int _c1;
};

class C2 : virtual public B
{
public:
	virtual void TestFunc2()
	{
		cout << "C2::TestFunc2()" << endl;
	}

	virtual void TestFunc4()
	{
		cout << "C2::TestFunc4()" << endl;
	}

	int _c2;
};

class D : public C1, public C2
{
public:
	virtual void TestFunc1()
	{
		cout << "D::TestFunc1()" << endl;
	}

	virtual void TestFunc3()
	{
		cout << "D::TestFunc3()" << endl;
	}

	virtual void TestFunc4()
	{
		cout << "D::TestFunc4()" << endl;
	}

	virtual void TestFunc5()
	{
		cout << "D::TestFunc5()" << endl;
	}

	int _d;
};

int main()
{
	cout << sizeof(D) << endl;
	return 0;
}
#endif

#if 0
// ���캯���������ó��麯��
// ԭ��
class Base
{
public:
	virtual Base()
	{}

// 	virtual inline void TestFunc()
// 	{}

	//virtual static void TestFunc2()
	//{}


};

// ��̬��ȱ�ݣ������˳���������ٶ�
int main()
{
	Base* pb = new Base;
	//pb->TestFunc();

	return 0;
}
#endif

#if 0

class Base
{
public:
	virtual ~Base()
	{
		cout << "Base::~Base()" << endl;
	}

// 	virtual Base& operator=(const Base& d)
// 	{
// 		return *this;
// 	}
};


class Derived : public Base
{
public:
	Derived()
	{
		_p = new int;
	}

	~Derived()
	{
		cout << "Derived::~Derived()" << endl;
		if (_p)
		{
			delete _p;
		}

		// call ~Base()
	}

// 	virtual Derived& operator=(const Base& d)
// 	{
// 		return *this;
// 	}

private:
	int* _p;
};

int g_a = 10;



int main()
{
	char* p = "hello";
	//cout << hex<< &g_a << endl;
	//cout << hex<< (int)p << endl;
	printf("%p\n", &g_a);
	printf("%p\n", p);


	Base* pb = new Derived;
	delete pb;   // ��������������������Դ�� �ͷſռ�
	
	Base b;
	Derived d;
	b = d;
	//d = b;
	return 0;
}
#endif

#if 0
class Base
{
public:
	void TestFunc()
	{}

public:
	int _b;
};


class Derived : protected Base
{
public:
	void SetDrrivedInfo(int b, int d)
	{
		_b = b;
		_d = d;
	}

	/*
	protected:
	void TestFunc()
	{}

	int _b;
	*/

protected:
	int _d;
};


int main()
{
	Derived d;
	d.SetDrrivedInfo(1, 2);
	//d._b = 10;
	//d.TestFunc();

	return 0;
}
#endif


/*
class Trip
{
public:
	void Run()
	{}

protected:
	// ����
};


// has - a: ���
class Car
{
protected:
	Trip _t;
};


int main()
{
	return 0;
}
*/

// C������ģ��ʵ�ֶ�̬
// C������ģ��ʵ�ּ̳� + ���
// C������ģ��ʵ����
int main()
{
	return 0;
}


