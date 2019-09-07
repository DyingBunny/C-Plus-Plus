//1.当一个抽象模型有两个方面，其中一个方面依赖于另一方面。将这二者封装在独立的对象中以使它们可以各自独立的改变和复用；
//2.当对一个对象的改变需要同时改变其它对象，而不知道具体有多少对象有待改变；
//3.当一个对象必须通知其它对象，而它又不能假定其它对象是谁；也就是说，你不希望这些对象是紧密耦合的。

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