#include <iostream>
using namespace std;


#if 0
class Base
{
public:
	void SetBase(int pri, int pro, int pub)
	{
		_pri = pri;
		_pro = pro;
		_pub = pub;
	}

	void Print()
	{
		cout << _pri << endl;
		cout << _pro << endl;
		cout << _pub << endl;
	}

private:
	int _pri;
protected:
	int _pro;
public:
	int _pub;
};

// ���ṩһ������
// class ���������� : �̳�Ȩ��(public/protected/private) ��������
// {
//     // �������Լ��ĳ�Ա����&��Ա����
// };


class Derived: public Base
{};



int main()
{
	// ��֤�����ཫ�������еĳ�Ա�����̳�
	cout << sizeof(Base) << endl;
	cout << sizeof(Derived) << endl;

	// ��֤�����ཫ���������еĳ�Ա�����̳�
	Derived d;
	d.SetBase(10, 20, 30);
	d.Print();
	return 0;
}
#endif


#if 0
class Base
{
public:
	void SetBase(int pri, int pro, int pub)
	{
		_pri = pri;
		_pro = pro;
		_pub = pub;
	}

	void Print()
	{
		cout << _pri << endl;
		cout << _pro << endl;
		cout << _pub << endl;
	}

private:
	int _pri;
protected:
	int _pro;
public:
	int _pub;
};

// ���ṩһ������
// class ���������� : �̳�Ȩ��(public/protected/private) ��������
// {
//     // �������Լ��ĳ�Ա����&��Ա����
// };


class Derived : public Base
{
public:
	void SetDerived(int pri, int pro, int pub)
	{
		// ���Ի���
		_pub = pub;   // public�̳з�ʽ��������public�ĳ�Ա���������еķ���Ȩ��Ҳ��public
		_pro = pro;   // public�̳з��ǣ�������protected�ĳ�Ա�������������з���Ȩ��Ҳ��protected
		//_pri = pri;  public�̳з�ʽ��������˽�еĳ�Ա������������������ֱ�ӷ���(ȷʵ���̳е�������)

		// �������Լ���
		_priD = pri;
		_proD = pro;
		_pubD = pub;
	}

private:
	int _priD;
protected:
	int _proD;
public:
	int _pubD;
};

// ���裺������protected��Ա�����ڻ����еķ���ȨҲ��protected
class D : public Derived
{
public:
	void TestFunc()
	{
		_pro = 10;
	}
};



int main()
{
	cout << sizeof(Derived) << endl;
	Derived d;
	d._pub = 10;
	d._pubD = 10;
	return 0;
}
#endif


#if 0
class Base
{
public:
	void SetBase(int pri, int pro, int pub)
	{
		_pri = pri;
		_pro = pro;
		_pub = pub;
	}

	void Print()
	{
		cout << _pri << endl;
		cout << _pro << endl;
		cout << _pub << endl;
	}

private:
	int _pri;
protected:
	int _pro;
public:
	int _pub;
};

// ���ṩһ������
// class ���������� : �̳�Ȩ��(public/protected/private) ��������
// {
//     // �������Լ��ĳ�Ա����&��Ա����
// };


class Derived : protected Base
{
public:
	void SetDerived(int pri, int pro, int pub)
	{
		// ���Ի���
		_pub = pub;   // protected�̳з�ʽ��������public�ĳ�Ա���������еķ���Ȩ��Ҳ��protected
		_pro = pro;   // protected�̳з��ǣ�������protected�ĳ�Ա�������������з���Ȩ��Ҳ��protected
		//_pri = pri;  //public�̳з�ʽ��������˽�еĳ�Ա������������������ֱ�ӷ���(ȷʵ���̳е�������)

		// �������Լ���
		_priD = pri;
		_proD = pro;
		_pubD = pub;
	}

private:
	int _priD;
protected:
	int _proD;
public:
	int _pubD;
};

// ���裺������protected��Ա�����ڻ����еķ���ȨҲ��protected
class D : public Derived
{
public:
	void TestFunc()
	{
		_pub = 10;
		_pro = 20;
	}
};



int main()
{
	cout << sizeof(Derived) << endl;
	Derived d;
	//d._pub = 10;
	d._pubD = 10;
	return 0;
}
#endif

#if 0
class Base
{
public:
	void SetBase(int pri, int pro, int pub)
	{
		_pri = pri;
		_pro = pro;
		_pub = pub;
	}

	void Print()
	{
		cout << _pri << endl;
		cout << _pro << endl;
		cout << _pub << endl;
	}

private:
	int _pri;
protected:
	int _pro;
public:
	int _pub;
};

// ���ṩһ������
// class ���������� : �̳�Ȩ��(public/protected/private) ��������
// {
//     // �������Լ��ĳ�Ա����&��Ա����
// };


struct Derived : Base
{
public:
	void SetDerived(int pri, int pro, int pub)
	{
		// ���Ի���
		_pub = pub;   // private�̳з�ʽ��������public�ĳ�Ա���������еķ���Ȩ��Ҳ��private
		_pro = pro;   // private�̳з��ǣ�������protected�ĳ�Ա�������������з���Ȩ��Ҳ��private
		//_pri = pri;  //public�̳з�ʽ��������˽�еĳ�Ա������������������ֱ�ӷ���(ȷʵ���̳е�������)

		// �������Լ���
		_priD = pri;
		_proD = pro;
		_pubD = pub;
	}

private:
	int _priD;
protected:
	int _proD;
public:
	int _pubD;
};

// ���裺������protected��Ա�����ڻ����еķ���ȨҲ��protected
class D : public Derived
{
public:
	void TestFunc()
	{
		_pub = 10;
		//_pro = 20;
	}
};



int main()
{
	cout << sizeof(Derived) << endl;
	Derived d;
	//d._pub = 10;
	d._pubD = 10;
	return 0;
}
#endif

#if 0
// ��ֵ���ݹ���---->public�̳з�ʽ
class Base
{
public:
	void SetBase(int b)
	{
		cout << "Base::SetBase(int)" << endl;
		_b = b;
	}

	void Print()
	{
		cout << _b<<endl;
	}

protected:
public:
	int _b;
};

class Derived : public Base
{
public:
	void SetDerived(int d)
	{
		_d = d;
	}

//private:
public:
	int _d;
};


// Derived �� Base�Ǽ̳еĹ�ϵ  public
// is-a: ���Խ�������Ķ��󿴳��ǻ���Ķ���
//       ������ʹ�û�������λ�ã�������ʹ���������������滻
// �����ָ������ÿ���ֱ��ָ������Ķ���
int main()
{
	Base b;
	Derived d;

	// �����⺯������
	b.SetBase(20);
	b.Print();

	d.SetBase(20);
	d.Print();

	// ����ģ�ͣ������еĳ�Ա���ڴ��еĲ�����ʽ
	b._b = 10;
	d._b = 10;
	d._d = 20;



	d.SetBase(10);

	// public�̳з�ʽ������������ֱ�Ӹ��Ƹ��������
	b = d;

	// ��������ܸ�������������и�ֵ
	//d = b;

	Base* pb = &b;
	pb = &d;
	Base& rd = d;

	Derived* pd = &d;

	// 
	pd = (Derived*)&b;
	pd->_b = 10;
	pd->_d = 20;


	return 0;
}
#endif

#if 0
// ͬ������
class Base
{
public:
	void SetBase(int b)
	{
		cout << "Base::SetBase(int)" << endl;
		_b = b;
	}

	void TestFunc()
	{
		cout << "Base::TestFunc()" << endl;
	}


	void Print()
	{
		cout << _b << endl;
	}

public:
	int _b;
};

class Derived : public Base
{
public:
	void SetDerived(int d)
	{
		_b = d;
	}

	/*
	void Base::TestFunc()
	{
	cout << "Base::TestFunc()" << endl;
	}

	*/


	/*
	void Derived::TestFunc(int a)
	{
	cout << "TestFunc(int)" << endl;
	}
	*/
	void TestFunc(int a)
	{
		cout << "Derived:TestFunc(int)" << endl;
	}

	void TestFunc()
	{
		cout << "Derived::TestFunc()" << endl;
	}

public:
	char _b;
};


// ͬ������
// ������������о�����ͬ���Ƶĳ�Ա(��Ա����(���Ա�����������Ƿ���ͬ�޹�)����Ա����(���Ա����ԭ���Ƿ���ͬ���޹�))
// ʹ����������������ͬ���Ƶĳ�Աʱ�����ȵ����������Լ�
// ����ͬ����Ա�ͱ�������
int main()
{
	Derived d;
	d.Base::_b = 10;

	d.Derived::TestFunc(10);
	d.Base::TestFunc();
	return 0;
}
#endif

/*
1. ���ڱ��������ɹ��캯������
    �﷨�����һ����û����ʽ���幹�캯�����������ͻ�����һ��Ĭ�ϵĹ��캯��
	ʵ�ʣ����һ����û����ʽ���幹�캯���������������Ҫ���캯�����ͻ�����һ���޲εĹ��캯��
	     �������Ҫ���������Ͳ�������

2. �������Ĺ��캯�����ڣ������������
     >> �������Ĺ��캯����ȱʡ�Ĺ��캯����
	      ���������û����ʽ���幹�캯����������������һ��Ĭ�ϵĹ��캯����Ҫ������Ĭ�Ϲ��캯����ʼ���б��λ����ɻ����Ա�ĳ�ʼ��
		  �����������ʽ�����˹��캯�������������ʼ���б��λ�õ��û���Ĺ��캯������ɻ����Ա��
		  ��ʼ��
	 >> �������Ĺ��캯���Ƿ�ȱʡ
	      �û�������ʽ�������ඨ�幹�캯�����������乹�캯����ʼ���б��λ����ʽ���û���Ĺ��캯����ɻ����Ա�ĳ�ʼ��
*/

#if 0
// ͬ������
class Base
{
public:
	Base(int b)
		: _b(b)
	{
		cout << "Base()" << endl;
	}

	Base(const Base& b)
		: _b(b._b)
	{}

	void SetBase(int b)
	{
		_b = b;
	}

	void Print()
	{
		cout << _b << endl;
	}

	Base& operator=(const Base& b)
	{
		cout << "Base& operator=(const Base& b)" << endl;
		if (this != &b)
		{
			_b = b._b;
		}

		return *this;
	}

	~Base()
	{
		cout << "~Base()" << endl;
	}

public:
	int _b;
};

class Derived : public Base
{
public:
	Derived()
		: Base(10)
	{
		cout << "Derived()" << endl;
	}

	Derived(const Derived& d)
		: Base(d)
	{}

	void SetDerived(int d)
	{
		_b = d;
	}

	Derived& operator=(const Derived& b)
	{
		
		cout << "Derived& operator=(const Derived& b)" << endl;
		if (this != &b)
		{
			(*this).Base::operator=(b);
			_b = b._b;
		}

		return *this;
	}

	~Derived()
	{
		cout << "~Derived()" << endl;
		// call ~Base();
	}

public:
	int _d;
};


void TestFunc()
{
	/*
	���죺����������Ķ����ȵ���������Ĺ��캯�����������๹�캯����ʼ���б��λ���������������г�Ա�ĳ�ʼ��
	       ��ʼ�������Ա�����û���Ĺ��캯��
		   ��ʼ���������Լ��ĳ�Ա��ִ�г�ʼ�����
	     ����ִ�������๹�캯���ĺ�����

	����������������Ķ����ȵ���������������������������������������������һ���������������������ĵ���
	*/
	Derived d;
}

int main()
{
	TestFunc();

	Base b(10);
	Derived d1; // call Base()

	Derived d2(d1);

	d1 = d2;
	return 0;
}
#endif

/*
// ���һ���࣬���ܱ��̳�
// �Ƚ����캯��˽�л�
class Base
{
public:
	static Base GetStackInstrance(int a)
	{
		return Base(a);
	}

	static Base* GetHeapInstrance(int a)
	{
		return new Base(a);
	}

	// ������ʽ�ṩ�������캯�����������ǳ����
	Base(const Base& b)
	{}

private:
	Base(int)
	{}
};
*/



#if 0
class Derived : public Base
{
	/*
	public:
	    Derived()
		   : Base()
		{}
	*/
};



int main()
{
	Base d1(Base::GetStackInstrance(10));

	Base* pd = Base::GetHeapInstrance(20);
	return 0;
}
#endif

#if 0
// C++
class Base final
{
public:
	Base(int b)
		: _b(b)
	{
		cout << "Base()" << endl;
	}

	Base(const Base& b)
		: _b(b._b)
	{}

	void SetBase(int b)
	{
		_b = b;
	}

	void Print()
	{
		cout << _b << endl;
	}

	Base& operator=(const Base& b)
	{
		cout << "Base& operator=(const Base& b)" << endl;
		if (this != &b)
		{
			_b = b._b;
		}

		return *this;
	}

	~Base()
	{
		cout << "~Base()" << endl;
	}

public:
	int _b;
};

// class Derived : public Base
// {};

int main()
{
	Base b(10);
	Base* pb = new Base(20);
	delete pb;
	return 0;
}
#endif


#if 0
class Base
{
	friend void Print();
public:
	void SetBase(int b)
	{
		_b = b;
	}

protected:
	int _b;
};

class Derived : public Base
{
	//friend void Print();
protected:
	int _d;
};


void Print()
{
	Base b;
	b.SetBase(10);
	cout << b._b << endl;

	Derived d;
	d.SetBase(10);
	cout << d._d << endl;
}

int main()
{
	return 0;
}
#endif


#if 0
class B
{
public:
	B(int b)
		: _b(b)
	{
		_count++;
	}

	B(const B& b)
		: _b(b._b)
	{
		_count++;
	}


	~B()
	{
		--_count;
	}

	static int GetCount()
	{
		return _count;
	}

protected:
	int _b;

public:
	static int _count;
};

int B::_count = 0;

class D1 : public B
{
public:
	D1(int b, int d)
		: B(b)
		, _d1(d)
	{}

protected:
	int _d1;
};

class D2 : public B
{
public:
	D2(int b, int d)
		: B(b)
		, _d1(d)
	{}

protected:
	int _d1;
};



int main()
{
	B b(10);
	D1 d1(20, 20);
	D2 d2(30, 20);
	cout << &B::_count << endl;
	cout << &D1::_count << endl;
	cout << &D2::_count << endl;
	return 0;
}
#endif


// ��ͬ�̳���ϵ�µĶ���ģ�ͣ�������Ķ���ģ��
// ���̳У����ಿ��+�������Լ�
// ��̳У��������
// ���ؼ̳��п��ܻ���ڶ���������
class B1
{
public:
	B1(int b)
		: _b1(b)
	{}

	void Set(int b, int d)
	{
		_b1 = b;
	}

protected:
	int _b1;
};

class B2
{
public:
	B2(int b)
		: _b2(b)
	{}

	void Set(int b)
	{
		_b2 = b;
	}

protected:
	int _b2;
};

class D : public B1, public B2
{
public:
	D(int b1, int b2, int d)
		: B1(b1)
		, B2(b2)
		, _d(d)
	{}

protected:
	int _d;
};

int main()
{
	cout << sizeof(D) << endl;
	D d(1,2,3);
	d.B1::Set(10, 20);
	//d.Set(10, 20);
	d.B2::Set(20);
	
	return 0;
}