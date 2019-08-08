#include<iostream>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS

//----------------为什么要用指针和引用--------------
//class A
//{
//public:
//	virtual void Func()
//	{
//		cout << "A中的虚函数" << endl;
//	}
//
//	void Func1()
//	{
//		cout << "A中的普通函数" << endl;
//	}
//};
//
//class B :public A
//{
//public:
//	virtual void Func()
//	{
//		cout << "B中的虚函数" << endl;
//	}
//
//	void Func1()
//	{
//		cout << "B中的普通函数" << endl;
//	}
//};
//
//int main()
//{
//	A a;
//	a.Func();//调用A的Func
//	a.Func1();//调用A的Func1
//	B b;
//	b.Func();//调用B的Func
//	b.Func1();//调用B的Func1
//
//	A *pa;
//	
//	pa = &a;
//	pa->Func();//pa实际指向的对象是A类型，此时就调用A类的Fun函数
//	pa->Func1();//Fun1是普通函数，调用A类的Fun1函数
//
//	pa = &b;//pa是父类型指针，但是此时pa实际指向的是子类的对象b
//	pa->Func();//此时虽然pa是A类指针，但是调用的函数会是B类的Fun函数
//	pa->Func1();//虽然pa实际指向的对象是b，但是pa本身是A*类型，对普通函数，就会调用A类的Fun1函数
//	system("pause");
//	return 0;
//}

////-------------------改写版----------------------
//
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//
//private:
//	int _b = 1;
//};
//
//class Derive :public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//private:
//	int _d = 2;
//};
//
//int main()
//{
//	Base b;
//	Derive d;
//	system("pause");
//	return 0;
//}

////----------------虚函数表-------------------
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//
//private:
//	int _b = 1;
//};
//
//int main()
//{
//	Base b;
//	int a;
//	a = sizeof(b);
//	cout << a  << endl;
//	system("pause");
//	return 0;
//}

////------------------final修饰------------------
//class Car
//{
//public:
//	virtual void Drive() final
//	{}
//};
//
//class Benz :public Car
//{
//public:
//	//会出现警告
//	virtual void Drive()
//	{
//		cout << "good" << endl;
//	}
//};

////------------------虚函数的强制重写-------------
//
//class Car
//{
//public:
//	virtual void Drive()
//	{}
//};
//
//class Benz :public Car
//{
//public:
//	virtual void Drive() override
//	{
//		cout << "舒适" << endl;
//	}
//};
//
//int main()
//{
//	Car *pBenz = new Benz;
//	pBenz->Drive();
//	system("pause");
//	return 0;
//}

////----------------抽象类----------------------
////抽象类无法实例化对象，必须重写纯虚函数，派生类才可以实例化

//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "舒适" << endl;
//	}
//};
//
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "操控" << endl;
//	}
//};
//
//int main()
//{
//	Car* pBenz = new Benz;
//	Car* pBMW = new BMW;
//	pBenz->Drive();
//	pBMW->Drive();
//	system("pause");
//	return 0;
//}

////---------------------析构函数的重写-----------------
//
//class Person
//{
//public:
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
//
//class Student :public Person
//{
//	virtual ~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//};
//
//int main()
//{
//	Person *p1 = new Person;
//	Person *p2 = new Student;
//
//	delete p1;
//	delete p2;
//	system("pause");
//	return 0;
//}

//----------虚函数的重写------------------
//class Person
//{
//public:
//	virtual void  BuyTicket()
//	{
//		cout << "买票--全价" << endl;
//	}
//};
//
//class Student :public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票--半价" << endl;
//	}
//};
//
//void Func(Person&p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person ps;
//	Student st;
//	Func(ps);
//	Func(st);
//	system("pause");
//	return 0;
//}
//----------多态的概念-》买票--------------

//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "全价买票" << endl;
//	}
//};
//
//class Student :public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票半价" << endl;
//	}
//};
//
//void Func(Person&people)
//{
//	people.BuyTicket();
//}
//
//void Test()
//{
//	Person Mike;
//	Func(Mike);
//
//	Student(Jason);
//	Func(Jason);
//}
//int main()
//{
//	Test();
//	system("pause");;
//	return 0;
//}

//class Person
//{
//public:
//	virtual void Buy()
//	{
//		cout << "全价" << endl;
//	}
//};
//
//class Student :public Person
//{
//public:
//	virtual void Buy()
//	{
//		cout <<"八折" << endl;
//	}
//};
//
//void Func(Person &people)
//{
//	people.Buy();
//}
//
//int main()
//{
//	Person Mike;
//	Student Jack;
//	Func(Mike);
//	Func(Jack);
//	system("pause");
//	return 0;
//}

//-----------------为什么析构函数为虚函数--------------
//声明为虚函数

//class ClxBase
//{
//public:
//	ClxBase()
//	{};
//	~ClxBase()
//	{
//		std::cout << "lalala" << std::endl;
//	}
//
//	void DoSomething()
//	{
//		std::cout << "zuole" << std::endl;
//	}
//};
//
//class ClxDerived :public ClxBase
//{
//public:
//	ClxDerived()
//	{};
//	~ClxDerived()
//	{
//		std::cout << "lalalpaisheng" << std::endl;
//	}
//	void DoSomething()
//	{
//		std::cout << "zuole paisheng" << std::endl;
//	}
//};
//
//int main()
//{
//	ClxDerived *p = new ClxDerived;
//	p->DoSomething();
//	delete p;
//	return 0;
//}

//int main()
//{
//	ClxBase *p = new ClxDerived;
//	p->DoSomething();
//	delete p;
//	return 0;
//}

//定义为虚函数

class ClxBase
{
public:
	ClxBase()
	{};
	virtual ~ClxBase()
	{
		std::cout << "xigoujilei" << std::endl;
	}

	virtual void DoSomething()
	{
		std::cout << "hanshujilei" << std::endl;
	}
};

class ClxDerived :public ClxBase
{
public:
	ClxDerived()
	{};
	~ClxDerived()
	{
		std::cout << "xigoupasheng" << std::endl;
	}

	virtual void DoSomething()
	{
		std::cout << "hanshupaisheng" << std::endl;
	}
};

int main()
{
	ClxBase *p = new ClxDerived;
	p->DoSomething();
	delete p;
	return 0;
}