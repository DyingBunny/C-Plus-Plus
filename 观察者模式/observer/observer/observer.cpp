//1.��һ������ģ�����������棬����һ��������������һ���档������߷�װ�ڶ����Ķ�������ʹ���ǿ��Ը��Զ����ĸı�͸��ã�
//2.����һ������ĸı���Ҫͬʱ�ı��������󣬶���֪�������ж��ٶ����д��ı䣻
//3.��һ���������֪ͨ�������󣬶����ֲ��ܼٶ�����������˭��Ҳ����˵���㲻ϣ����Щ�����ǽ�����ϵġ�

#include<iostream>
#include<list>

class Observer
{
public:
	virtual void Update(int) = 0;
};

class Subject
{
public:
	virtual void Attach(Observer *) = 0;
	virtual void Detach(Observer *) = 0;
	virtual void Notify() = 0;
};

class ConcreateObserver :public Observer
{
public:
	ConcreateObserver(Subject *pSubject) :m_pSubject(pSubject)
	{}

	void Update(int value)
	{
		std::cout << "ConcreteObserver get the update. New State:" << value << std::endl;
	}

private:
	Subject *m_pSubject;
};

class ConcreateObserver2 :public Observer
{
public:
	ConcreateObserver2(Subject *pSubject) :m_pSubject(pSubject)
	{}
	void Update(int value)
	{
		std::cout << "ConcreteObserver2 get the update. New State:" << value << std::endl;
	}

private:
	Subject *m_pSubject;
};

class ConcreateSubject :public Subject
{
public:
	void Attach(Observer *pObserver);
	void Detach(Observer *pObserver);
	void Notify();

	void SetState(int state)
	{
		m_iState = state;
	}
private:
	std::list<Observer *>m_ObserverList;
	int m_iState;
};

void ConcreateSubject::Attach(Observer *pObserver)
{
	m_ObserverList.push_back(pObserver);
}

void ConcreateSubject::Detach(Observer *pObserver)
{
	m_ObserverList.remove(pObserver);
}

void ConcreateSubject::Notify()
{
	std::list<Observer *>::iterator it = m_ObserverList.begin();
	while (it != m_ObserverList.end())
	{
		(*it)->Update(m_iState);
		++it;
	}
}

int main()
{
	//Create Subject
	ConcreateSubject *pSubject = new ConcreateSubject();

	//Create Boserver
	Observer *pObserver = new ConcreateObserver(pSubject);
	Observer *pObserver2 = new ConcreateObserver2(pSubject);

	//Change the state
	pSubject->SetState(2);

	//Register the observer
	pSubject->Attach(pObserver);
	pSubject->Attach(pObserver2);

	pSubject->Notify();

	//Unregister the observer
	pSubject->Detach(pObserver);

	pSubject->SetState(3);
	pSubject->Notify();

	delete pObserver;
	delete pObserver2;
	delete pSubject;
}