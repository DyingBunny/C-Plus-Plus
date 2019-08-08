#include<iostream>
#include<string>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

////----------------------实现一个不能被继承的类----------------
//class NonInherit
//{
//public:
//	static NonInherit GetInstance()
//	{
//		return NonInherit();
//	}
//private:
//	NonInherit()
//	{}
//};
//
//class Non :public NonInherit
//{};
//
//int main()
//{
//	Non a;
//	a.GetInstance();
//	system("pause");
//	return 0;
//}

////-------------------------菱形继承的数据冗余问题---------------
//class A
//{
//public:
//	int _a;
//};
//
//class B :virtual public A
//{
//public:
//	int _b;
//};
//
//class C :virtual public A
//{
//public:
//	int _c;
//};
//
//class D :public B, public C
//{
//public:
//	int _d;
//};
//
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	cout << d._b<< endl;
//	system("pause");
//	return 0;
//}
////-------------------------菱形继承和虚拟菱形继承-----------------
////虚拟继承的使用来解决冗余性的问题
//class Person
//{
//public:
//	string _name;
//};
//
//class Student :virtual public Person
//{
//protected:
//	int _num;
//};
//
//class Teacher :virtual public Person
//{
//protected:
//	int _id;
//};
//
//class Assistant :public Student, public Teacher
//{
//protected:
//	string _majorCourse;
//};
//
//void Test()
//{
//	Assistant a;
//	a._name = "Peter";
//}
//
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}

////单继承：一个子类只有一个直接父类时称这个继承关系为单继承
////多继承：一个子类有两个或以上直接父类时称这个继承关系为多继承
//
//class Person
//{
//public:
//	string _name;
//};
//
//class Student :public Person
//{
//protected:
//	int _num;
//};
//
//class Teacher :public Person
//{
//protected:
//	int _id;
//};
//
//class Assistant :public Student, public Teacher
//{
//protected:
//	string _majorCourse;
//};
//
//void Test()
//{
//	//这样会有二义性无法明确知道访问是哪一个
//	Assistant a;
//	a._name = "Peter";//指定不明确
//	//需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//}
//
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}

////------------------继承与静态成员---------------
//class Person
//{
//public:
//	Person()
//	{
//		++_cout;
//	}
//protected:
//	string _name;//姓名
//public:
//	static int _cout;//统计的人数
//};
//
//int Person::_cout = 0;
//
//class Student :public Person
//{
//protected:
//	int _stuNum;
//};
//
//class Graduate:public Student
//{
//protected:
//	string  _seminarCourse;
//};
//
//void Test()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduate s4;
//	cout << "人数：" << Person::_cout << endl;
//	Student::_cout = 0;
//	cout << "人数：" << Person::_cout << endl;
//}
//
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}

////----------------继承和友元函数--------------
////友元的关系无法进程，下面的代码中，Student中的_stuNUm是protected,即使是public继承了
////Person，其中的frined友元函数并不会继承，因此_stuNum是无法访问的
//class Student;
//
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name;
//};
//
//class Student :public Person
//{
//protected:
//	int _stuNum;
//};
//
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//}
//
//int main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//	system("pause");
//	return 0;
//}

////--------构造函数的六个默认参数----------------
//class Person
//{
//public:
//	//构造函数
//	Person(const char* name = "peter")//缺省参数
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person& operator=(const Person& p)//等号运算符的重载
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//		{
//			_name = p._name;
//		}
//		return *this;
//	}
//	
//	~Person()//析构函数，这边不进行空间的释放，只是用来判断析构函数是否执行
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name;
//};
//
//class Student :public Person
//{
//public:
//	Student(const char* name, int num)
//		:Person(name)
//		, _num(num)
//	{
//		cout << "Student()" << endl;
//	}
//	Student(const Student& s)//拷贝构造函数
//		:Person(s)
//		, _num(s._num)
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//
//	Student& operator=(const Student& s)
//	{
//		cout << "Studnet operator=(const Student& s)" << endl;
//		if (this != &s)
//		{
//			Person::operator=(s);
//			_num = s._num;
//		}
//		return *this;
//	}
//
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//
//protected:
//	int _num;
//};
//
//void Test()
//{
//	Student s1("jack", 18);
//	Student s2(s1);
//	Student s3("rose", 17);
//	s1 = s3;
//}
//
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}

////-------------------继承中的作用域-------------
////B中的fun和A中的fun不构成重载，因为处在不同的作用域内
////B中的fun和A中的fun构成隐藏，成员函数如果名字相同的话就构成隐藏关系
//
//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//
//class B :public A
//{
//public:
//	void fun(int i)
//	{
//		A::fun();
//		cout << "func(int i)->" << i << endl;
//	}
//};
//
//void Test()
//{
//	B b;
//	b.fun(10);
//}
//
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}
////Person和Student中_num形成混淆，需要指定作用域
//class Person
//{
//protected:
//	string _name = "小李子";
//	int _num = 111;
//};
//
//class Student :public Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl;
//		cout << Person::_num << endl;
//		cout << _num << endl;
//	}
//protected:
//	int _num=999;
//};
//
//void Test()
//{
//	Student s1;
//	s1.Print();
//}
//
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}
////------------------赋值对象转换-----------
//class Person
//{
//protected:
//	string _name;
//	string _sex;
//	int _age;
//};
//
//class Student :public Person
//{
//public:
//	int _No;
//};
//
//void Test()
//{
//	Student s1;
//	Person p1 = s1;
//	Person p2;
//	cout << "helllo" << endl;
//}
//
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}
//public:
//	data(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
////-------------------has-a关系-------------
//class Tire
//{
//protected:
//	string _brand = "BWM";
//	size_t size = 17;
//};
//
//class Car
//{
//protected:
//	string _color = "white";
//	string _num = "123456";
//	Tire _t;
//};
//
//int main()
//{
//	Car c1;
//	system("pause");
//	return 0;
//}
////-----------------------is-a--------------
//class Car
//{
//protected:
//	string _color = "白色";
//	string _num = "陕ABIT00";
//};
//
//class BWM :public Car
//{
//public:
//	void Drive()
//	{
//		cout << "great" << endl;
//	}
//};
//
//class Tire
//{
//public:
//	void Drive()
//	{
//		cout << "good" << endl;
//	}
//};
//
//int main()
//{
//	BWM b1;
//	b1.Drive();
//	system("pause");
//	return 0;
//}
//----------------访问关系的变化-------------------
//class Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl;
//	}
//protected:
//	string _name;
//private:
//	int _age;
//};
//
////class Sttudent :protected Person
////class Sttudent :private Person
//class Sttudent :public Person
//{
//	int _Studentnum
//};

////----------------赋值兼容规则->前提：public继承方式--------------
//class Base
//{
//public:
//	void SetBase(int b)
//	{
//		cout << "Base::SetBase(int)" << endl;
//		_b = b;
//	}
//
//	void Print()
//	{
//		cout << _b << endl;
//	}
//
////protected:
//public:
//	int _b;
//};
//
//class Derived :public Base
//{
//public:
//	void SetDerived(int d)
//	{
//		_d = d;
//	}
////private:
//public:
//	int _d;
//};
////is-a的关系->可以将派生类的对象看成是基类的对象
////在所有使用基类对象的位置，都可以使用派生类对象进行替换
//int main()
//{
//	Base b;
//	Derived d;
//	//在类外函数调用
//	b.SetBase(20);
//	b.Print();
//
//	d.SetBase(20);
//	d.Print();
//	//对象模型:对象中的成员在内存中的布局形式
//	b._b = 10;
//	d._b = 10;
//	d._d = 20;
//
//	d.SetDerived(10);
//	//public继承方式：子类对象可以直接复制给基类对象
//	b = d;
//
//	//基类对象不能给子类对象进行赋值
//	//d=b;
//
//	
//	Base* pb = &b;
//	pb = &d;
//	Base& rd = d;
//	//Derived* pd = &d;
//	//pd = (Derived*)&b;	必须进行强制类型转换
//	system("pause");
//	return 0;
//}

//----------------继承的概念-------------
//protected可以运用到继承当中，基类的对象就无法再类外被随意访问
//class person
//{
//public:
//	void print()
//	{
//		cout << "name" << _name << endl;
//		cout << "age" << _age << endl;
//	}
//
//protected:
//	string _name = "Jack";
//	int _age = 18;
//};
//
//class Teacher :public person
//{
//protected:
//	int _job;
//};
//
//int main()
//{
//	person s;
//	Teacher t;
//	s.print();
//	t.print();
//	system("pause");
//	return 0;
//}

//class A
//{
//public:
//	void Print()
//	{
//		cout << "yes its a" << endl;
//	}
//};
//
//class B:public A
//{
//public:
//	void Print()
//	{
//		cout << "yes its b" << endl;
//	}
//};
//
//class C :public B
//{
//public:
//	void Print()
//	{
//		cout << "yes its c" << endl;
//	}
//};
//
//int main()
//{
//	A *peter;
//	B jack;
//	peter = &jack;
//	(*peter).Print();
//	return 0;
//}

//class Person
//{
//public:
//	string _name;
//};
//
//class Student :public Person
//{
//protected:
//	int _num;
//};
//
//class Teacher :public Person
//{
//protected:
//	int _id;
//};
//
//class Assistant :public Student, public Teacher
//{
//protected:
//	string _majorCourse;
//};
//
//void Test()
//{
//	Assistant a;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//----------------虚拟继承---------------
class A
{
public:
	int _a;
};

class B :virtual public A
{
public:
	int _b;
};

class C :virtual public A
{
public:
	int _c;
};

class D :public B, public C
{
public:
	int _d;
};

int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
	return 0;
}