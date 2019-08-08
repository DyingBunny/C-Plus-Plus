#include<iostream>
#include<vector>

using namespace std;

//--------------一个单例模式的例子-----------
//class CSingleton
//{
//private:
//	CSingleton()
//	{}
//	~CSingleton()
//	{
//		if (m_pInstance == NULL)
//		{
//			return;
//		}
//		delete m_pInstance;
//		m_pInstance = NULL;
//	}
//
//	static CSingleton *m_pInstance;
//
//public:
//	static CSingleton* GetInstance()
//	{
//		if (m_pInstance == NULL)
//		{
//			m_pInstance = new CSingleton();
//		}
//		return m_pInstance;
//	}
//};
//
//CSingleton* CSingleton::m_pInstance = NULL;
//
//int main()
//{
//	CSingleton* single1 = CSingleton::GetInstance();
//	CSingleton* single2 = CSingleton::GetInstance();
//
//	if (single1 == single2)
//	{
//		cout << "Same" << endl;
//	}
//	return 0;
//}

//--------------------学生类----------------------
class Student
{
private:
	Student()//构造函数为私有，这样就无法在其他地方创建该实例
	{}

	~Student()
	{
		if (person == NULL)
		{
			return;
		}
		delete person;
		person = NULL;
	}

	static Student *person;//定义一个唯一指向实例的静态指针，并且是私有的
	static int num; 
public:
	static Student* GetStudent()//公有的函数可以获得这个唯一的实例，如果实例不存在则创建
	{
		if (person == NULL)
		{
			person = new Student();
		}
		return person;
	}
	void show()
	{
		cout << num << endl;
	}
};

Student* Student::person = NULL;
int Student::num = 1605;

int main()
{
	Student* jack = Student::GetStudent();
	Student* tom = Student::GetStudent();
	jack->show();
	tom->show();
	return 0;
}