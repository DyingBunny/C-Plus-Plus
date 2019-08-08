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

// 先提供一个基类
// class 派生类名字 : 继承权限(public/protected/private) 基类名字
// {
//     // 派生类自己的成员变量&成员方法
// };


class Derived: public Base
{};



int main()
{
	// 验证派生类将基类所有的成员变量继承
	cout << sizeof(Base) << endl;
	cout << sizeof(Derived) << endl;

	// 验证派生类将基类中所有的成员函数继承
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

// 先提供一个基类
// class 派生类名字 : 继承权限(public/protected/private) 基类名字
// {
//     // 派生类自己的成员变量&成员方法
// };


class Derived : public Base
{
public:
	void SetDerived(int pri, int pro, int pub)
	{
		// 来自基类
		_pub = pub;   // public继承方式，基类中public的成员在派生类中的访问权限也是public
		_pro = pro;   // public继承凡是，基类中protected的成员变量在派生类中访问权限也是protected
		//_pri = pri;  public继承方式，基类中私有的成员变量不能在派生类中直接访问(确实被继承到子类中)

		// 派生类自己的
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

// 假设：基类中protected成员变量在基类中的访问权也是protected
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

// 先提供一个基类
// class 派生类名字 : 继承权限(public/protected/private) 基类名字
// {
//     // 派生类自己的成员变量&成员方法
// };


class Derived : protected Base
{
public:
	void SetDerived(int pri, int pro, int pub)
	{
		// 来自基类
		_pub = pub;   // protected继承方式，基类中public的成员在派生类中的访问权限也是protected
		_pro = pro;   // protected继承凡是，基类中protected的成员变量在派生类中访问权限也是protected
		//_pri = pri;  //public继承方式，基类中私有的成员变量不能在派生类中直接访问(确实被继承到子类中)

		// 派生类自己的
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

// 假设：基类中protected成员变量在基类中的访问权也是protected
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

// 先提供一个基类
// class 派生类名字 : 继承权限(public/protected/private) 基类名字
// {
//     // 派生类自己的成员变量&成员方法
// };


struct Derived : Base
{
public:
	void SetDerived(int pri, int pro, int pub)
	{
		// 来自基类
		_pub = pub;   // private继承方式，基类中public的成员在派生类中的访问权限也是private
		_pro = pro;   // private继承凡是，基类中protected的成员变量在派生类中访问权限也是private
		//_pri = pri;  //public继承方式，基类中私有的成员变量不能在派生类中直接访问(确实被继承到子类中)

		// 派生类自己的
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

// 假设：基类中protected成员变量在基类中的访问权也是protected
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
// 赋值兼容规则---->public继承方式
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


// Derived 和 Base是继承的关系  public
// is-a: 可以将派生类的对象看成是基类的对象
//       在所有使用基类对象的位置，都可以使用派生类对象进行替换
// 基类的指针或引用可以直接指向子类的对象
int main()
{
	Base b;
	Derived d;

	// 在类外函数调用
	b.SetBase(20);
	b.Print();

	d.SetBase(20);
	d.Print();

	// 对象模型：对象中的成员在内存中的布局形式
	b._b = 10;
	d._b = 10;
	d._d = 20;



	d.SetBase(10);

	// public继承方式：子类对象可以直接复制给基类对象
	b = d;

	// 基类对象不能给子类对象来进行赋值
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
// 同名隐藏
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


// 同名隐藏
// 基类和派生类中具有相同名称的成员(成员变量(与成员变量的类型是否相同无关)、成员函数(与成员函数原型是否相同过无关))
// 使用派生类对象调用相同名称的成员时，优先调用派生类自己
// 基类同名成员就被隐藏了
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
1. 关于编译器生成构造函数问题
    语法：如果一个类没有显式定义构造函数，编译器就会生成一个默认的构造函数
	实际：如果一个类没有显式定义构造函数，假如编译器需要构造函数，就会生成一个无参的构造函数
	     如果不需要，编译器就不会生成

2. 如果基类的构造函数存在，分两种情况：
     >> 如果基类的构造函数是缺省的构造函数，
	      派生类如果没有显式定义构造函数，编译器就生成一个默认的构造函数，要在生成默认构造函数初始化列表的位置完成基类成员的初始化
		  派生类如果显式定义了构造函数，必须在其初始化列表的位置调用基类的构造函数，完成基类成员的
		  初始化
	 >> 如果基类的构造函数是非缺省
	      用户必须显式给派生类定义构造函数，并且在其构造函数初始化列表的位置显式调用基类的构造函数完成基类成员的初始化
*/

#if 0
// 同名隐藏
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
	构造：创建派生类的对象，先调用派生类的构造函数，在派生类构造函数初始化列表的位置完成派生类对象中成员的初始化
	       初始化基类成员：调用基类的构造函数
		   初始化派生类自己的成员：执行初始化语句
	     再来执行派生类构造函数的函数体

	析构：析构派生类的对象，先调用派生类的析构函数，编译器在派生类析构函数最后一条语句后插入基类析构函数的调用
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
// 设计一个类，不能被继承
// 先将构造函数私有化
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

	// 必须显式提供拷贝构造函数，否则就是浅拷贝
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


// 不同继承体系下的对象模型：派生类的对象模型
// 单继承：基类部分+派生类自己
// 多继承：多个基类
// 多重继承中可能会存在二义性问题
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