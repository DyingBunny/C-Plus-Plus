#include<iostream>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS

//----------------ΪʲôҪ��ָ�������--------------
//class A
//{
//public:
//	virtual void Func()
//	{
//		cout << "A�е��麯��" << endl;
//	}
//
//	void Func1()
//	{
//		cout << "A�е���ͨ����" << endl;
//	}
//};
//
//class B :public A
//{
//public:
//	virtual void Func()
//	{
//		cout << "B�е��麯��" << endl;
//	}
//
//	void Func1()
//	{
//		cout << "B�е���ͨ����" << endl;
//	}
//};
//
//int main()
//{
//	A a;
//	a.Func();//����A��Func
//	a.Func1();//����A��Func1
//	B b;
//	b.Func();//����B��Func
//	b.Func1();//����B��Func1
//
//	A *pa;
//	
//	pa = &a;
//	pa->Func();//paʵ��ָ��Ķ�����A���ͣ���ʱ�͵���A���Fun����
//	pa->Func1();//Fun1����ͨ����������A���Fun1����
//
//	pa = &b;//pa�Ǹ�����ָ�룬���Ǵ�ʱpaʵ��ָ���������Ķ���b
//	pa->Func();//��ʱ��Ȼpa��A��ָ�룬���ǵ��õĺ�������B���Fun����
//	pa->Func1();//��Ȼpaʵ��ָ��Ķ�����b������pa������A*���ͣ�����ͨ�������ͻ����A���Fun1����
//	system("pause");
//	return 0;
//}

////-------------------��д��----------------------
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

////----------------�麯����-------------------
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

////------------------final����------------------
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
//	//����־���
//	virtual void Drive()
//	{
//		cout << "good" << endl;
//	}
//};

////------------------�麯����ǿ����д-------------
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
//		cout << "����" << endl;
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

////----------------������----------------------
////�������޷�ʵ�������󣬱�����д���麯����������ſ���ʵ����

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
//		cout << "����" << endl;
//	}
//};
//
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "�ٿ�" << endl;
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

////---------------------������������д-----------------
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

//----------�麯������д------------------
//class Person
//{
//public:
//	virtual void  BuyTicket()
//	{
//		cout << "��Ʊ--ȫ��" << endl;
//	}
//};
//
//class Student :public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "��Ʊ--���" << endl;
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
//----------��̬�ĸ���-����Ʊ--------------

//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "ȫ����Ʊ" << endl;
//	}
//};
//
//class Student :public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "��Ʊ���" << endl;
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
//		cout << "ȫ��" << endl;
//	}
//};
//
//class Student :public Person
//{
//public:
//	virtual void Buy()
//	{
//		cout <<"����" << endl;
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

//-----------------Ϊʲô��������Ϊ�麯��--------------
//����Ϊ�麯��

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

//����Ϊ�麯��

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