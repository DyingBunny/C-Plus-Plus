#include<iostream>
#include<vector>

using namespace std;

//--------------һ������ģʽ������-----------
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

//--------------------ѧ����----------------------
class Student
{
private:
	Student()//���캯��Ϊ˽�У��������޷��������ط�������ʵ��
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

	static Student *person;//����һ��Ψһָ��ʵ���ľ�ָ̬�룬������˽�е�
	static int num; 
public:
	static Student* GetStudent()//���еĺ������Ի�����Ψһ��ʵ�������ʵ���������򴴽�
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