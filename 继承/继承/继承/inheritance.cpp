#include<iostream>
#include<string>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

////----------------------ʵ��һ�����ܱ��̳е���----------------
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

////-------------------------���μ̳е�������������---------------
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
////-------------------------���μ̳к��������μ̳�-----------------
////����̳е�ʹ������������Ե�����
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

////���̳У�һ������ֻ��һ��ֱ�Ӹ���ʱ������̳й�ϵΪ���̳�
////��̳У�һ������������������ֱ�Ӹ���ʱ������̳й�ϵΪ��̳�
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
//	//�������ж������޷���ȷ֪����������һ��
//	Assistant a;
//	a._name = "Peter";//ָ������ȷ
//	//��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷����
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

////------------------�̳��뾲̬��Ա---------------
//class Person
//{
//public:
//	Person()
//	{
//		++_cout;
//	}
//protected:
//	string _name;//����
//public:
//	static int _cout;//ͳ�Ƶ�����
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
//	cout << "������" << Person::_cout << endl;
//	Student::_cout = 0;
//	cout << "������" << Person::_cout << endl;
//}
//
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}

////----------------�̳к���Ԫ����--------------
////��Ԫ�Ĺ�ϵ�޷����̣�����Ĵ����У�Student�е�_stuNUm��protected,��ʹ��public�̳���
////Person�����е�frined��Ԫ����������̳У����_stuNum���޷����ʵ�
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

////--------���캯��������Ĭ�ϲ���----------------
//class Person
//{
//public:
//	//���캯��
//	Person(const char* name = "peter")//ȱʡ����
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person& operator=(const Person& p)//�Ⱥ������������
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//		{
//			_name = p._name;
//		}
//		return *this;
//	}
//	
//	~Person()//������������߲����пռ���ͷţ�ֻ�������ж����������Ƿ�ִ��
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
//	Student(const Student& s)//�������캯��
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

////-------------------�̳��е�������-------------
////B�е�fun��A�е�fun���������أ���Ϊ���ڲ�ͬ����������
////B�е�fun��A�е�fun�������أ���Ա�������������ͬ�Ļ��͹������ع�ϵ
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
////Person��Student��_num�γɻ�������Ҫָ��������
//class Person
//{
//protected:
//	string _name = "С����";
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
////------------------��ֵ����ת��-----------
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
////-------------------has-a��ϵ-------------
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
//	string _color = "��ɫ";
//	string _num = "��ABIT00";
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
//----------------���ʹ�ϵ�ı仯-------------------
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

////----------------��ֵ���ݹ���->ǰ�᣺public�̳з�ʽ--------------
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
////is-a�Ĺ�ϵ->���Խ�������Ķ��󿴳��ǻ���Ķ���
////������ʹ�û�������λ�ã�������ʹ���������������滻
//int main()
//{
//	Base b;
//	Derived d;
//	//�����⺯������
//	b.SetBase(20);
//	b.Print();
//
//	d.SetBase(20);
//	d.Print();
//	//����ģ��:�����еĳ�Ա���ڴ��еĲ�����ʽ
//	b._b = 10;
//	d._b = 10;
//	d._d = 20;
//
//	d.SetDerived(10);
//	//public�̳з�ʽ������������ֱ�Ӹ��Ƹ��������
//	b = d;
//
//	//��������ܸ����������и�ֵ
//	//d=b;
//
//	
//	Base* pb = &b;
//	pb = &d;
//	Base& rd = d;
//	//Derived* pd = &d;
//	//pd = (Derived*)&b;	�������ǿ������ת��
//	system("pause");
//	return 0;
//}

//----------------�̳еĸ���-------------
//protected�������õ��̳е��У�����Ķ�����޷������ⱻ�������
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

//----------------����̳�---------------
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