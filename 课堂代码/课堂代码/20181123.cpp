#include <iostream>
using namespace std;

#if 0
#include <list>

void PrintList(list<int>& l)
{
	for (auto e : l)
		cout << e << " ";
	cout << endl;
}

void ReversePrintList(list<int>& l)
{
	auto it = l.rbegin();
	while (it != l.rend())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void TestList1()
{
	list<int> l1;
	list<int> l2(10, 5);
	PrintList(l2);

	list<int> l3(l2);
	ReversePrintList(l3);

	int array[] = { 1, 2, 3, 4 };
	list<int> l4(array, array+sizeof(array)/sizeof(array[0]));
	PrintList(l4);
}

void TestList2()
{
	int array[] = { 1, 2, 3, 4 };
	list<int> l1(array, array + sizeof(array) / sizeof(array[0]));
	PrintList(l1);
	cout << l1.size() << endl;

	l1.push_back(5);
	l1.push_front(0);
	cout << l1.front() << endl;
	cout << l1.back() << endl;
	PrintList(l1);

	l1.insert(l1.begin(), 10, 5);
	PrintList(l1);

	l1.pop_back();
	l1.pop_front();

	l1.erase(find(l1.begin(), l1.end(), 4));
	PrintList(l1);
}

int main()
{
	//TestList1();
	TestList2();
	return 0;
}
#endif


namespace bit
{
	template<class T>
	struct ListNode
	{
		ListNode(const T& data = T())
		: _pPre(nullptr)
		, _pNext(nullptr)
		, _data(data)
		{}

		ListNode<T>* _pPre;
		ListNode<T>* _pNext;
		T _data;
	};

	// 迭代器：将指针封装
	// operator*()/operator->()/operator++/operator--(需要根据具体的结构来确定是否需要给出)
	// operator!= operator==
	template<class T, class Ref, class Ptr>
	class ListIterator
	{
		typedef ListNode<T> Node;
		typedef Node* PNode;
		typedef ListIterator<T, Ref, Ptr> Self;

	public:
		ListIterator(PNode pNode = nullptr)
			: _pNode(pNode)
		{}

		ListIterator(const Self& li)
			: _pNode(li._pNode)
		{}

		Ref operator*()
		{
			return _pNode->_data;
		}

		Ptr operator->()
		{
			return &(operator*());
		}

		Self& operator++()
		{
			_pNode = _pNode->_pNext;
			return *this;
		}

		Self operator++(int)
		{
			Self temp(*this);
			_pNode = _pNode->_pNext;
			return temp;
		}

		Self& operator--()
		{
			_pNode = _pNode->_pPre;
			return *this;
		}

		Self operator--(int)
		{
			Self temp(*this);
			_pNode = _pNode->_pPre;
			return temp;
		}

		bool operator!=(const Self& li)
		{
			return _pNode != li._pNode;
		}

		bool operator==(const Self& li)
		{
			return _pNode == l1._pNode;
		}

		PNode _pNode;
	};

	template<class T>
	class list
	{
		typedef ListNode<T> Node;
		typedef Node* PNode;
	public:
		typedef ListIterator<T, T&, T*> iterator;

	public:
		list()
		{
			CreateHead();
		}

		list(size_t n, const T& data = T())
		{
			CreateHead();
			for (size_t i = 0; i < n; ++i)
				push_back(data);
		}

		list(T* first, T* last)
		{
			CreateHead();
			while (first != last)
				push_back(*first++);
		}

		list(const list<T>& l);
		list& operator=(const list<T>& l);

		~list()
		{
			clear();
			delete _pHead;
			_pHead = nullptr;
		}

		////////////////////////////////////////
		size_t size()const
		{
			size_t count = 0;
			PNode pCur = _pHead->_pNext;
			while (pCur != _pHead)
			{
				count++;
				pCur = pCur->_pNext;
			}

			return count;
		}

		void resize(size_t newSize, const T& data = T())
		{
			size_t oldSize = size();
			if (oldSize < newSize)
			{
				for (size_t i = oldSize; i < newSize; ++i)
					push_back(data);
			}
			else
			{
				for (size_t i = newSize; i < oldSize; ++i)
					pop_back();
			}
		}

		bool empty()const
		{
			return _pHead->_pNext == _pHead;
		}

		void clear()
		{
			PNode pCur = _pHead->_pNext;
			while (pCur != _pHead)
			{
				_pHead->_pNext = pCur->_pNext;
				delete pCur;
				pCur = _pHead->_pNext;
			}

			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
		}

		////////////////////////////////////////
		//
		void push_back(const T& data)
		{
			PNode pNewNode = new Node(data);
			pNewNode->_pNext = _pHead;
			pNewNode->_pPre = _pHead->_pPre;
			pNewNode->_pPre->_pNext = pNewNode;
			_pHead->_pPre = pNewNode;
		}

		void pop_back()
		{
			PNode pDelNode = _pHead->_pPre;
			if (pDelNode != _pHead)
			{
				pDelNode->_pPre->_pNext = _pHead;
				_pHead->_pPre = pDelNode->_pPre;
				delete pDelNode;
			}
		}

		void push_front(const T& data)
		{
			PNode pNewNode = new Node(data);
			pNewNode->_pNext = _pHead->_pNext;
			pNewNode->_pPre = _pHead;
			pNewNode->_pNext->_pPre = pNewNode;
			_pHead->_pNext = pNewNode;
		}

		void pop_front()
		{
			PNode pDelNode = _pHead->_pNext;
			if (pDelNode != _pHead)
			{
				pDelNode->_pNext->_pPre = _pHead;
				_pHead->_pNext = pDelNode->_pNext;
				delete pDelNode;
			}
		}

		iterator insert(iterator pos, const T& data)
		{
			PNode pNewNode = new Node(data);

			pNewNode->_pNext = pos._pNode;
			pNewNode->_pPre = pos._pNode->_pPre;
			pNewNode->_pPre->_pNext = pNewNode;
			pNewNode->_pNext->_pPre = pNewNode;

			return iterator(pNewNode);
		}

		iterator erase(iterator pos)
		{
			if (pos._pNode == _pHead)
				return pos;

			PNode pRet = pos._pNode->_pNext;
			pos._pNode->_pPre->_pNext = pos._pNode->_pNext;
			pos._pNode->_pNext->_pPre = pos._pNode->_pPre;
			delete pos._pNode;

			return iterator(pRet);
		}

		iterator begin()
		{
			return iterator(_pHead->_pNext);
		}

		iterator end()
		{
			return iterator(_pHead);
		}

		/////////////////////////////////////////
		//
		T& front()
		{
			return _pHead->_pNext->_data;
		}

		const T& front()const
		{
			return _pHead->_pNext->_data;
		}

		T& back()
		{
			return _pHead->_pPre->_data;
		}

		const T& back()const
		{
			return _pHead->_pPre->_data;
		}
	private:
		void CreateHead()
		{
			_pHead = new Node;
			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
		}
	private:
		PNode _pHead;
	};
}


#include <vector>

void PrintList(bit::list<int>& l)
{
	for (auto& e : l)
		cout << e << " ";
	cout << endl;

	//bit::list<int>::iterator it = l.begin();
	auto it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void TestList1()
{
	bit::list<int> l1;
	bit::list<int> l2(10, 5);
	PrintList(l2);
	//vector<int> v{1,2,3,4,5,6,7,8,9,0};
	// bit::list<int> l3(v.begin(), v.end());

	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	bit::list<int> l3(array, array+sizeof(array)/sizeof(array[0]));
	PrintList(l3);
}

namespace bit
{
	template<class iterator, class T>
	iterator find(iterator first, iterator last, const T& data)
	{
		while (first != last)
		{
			if (*first == data)
				break;

			++first;
		}

		return first;
	}
}

void TestList2()
{
	int array[] = { 1, 2, 3, 4};
	bit::list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	PrintList(l);
	cout << l.front() << endl;
	cout << l.back() << endl;

	l.push_back(5);
	l.pop_back();
	cout << l.size() << endl;
	PrintList(l);

	l.push_front(0);
	PrintList(l);

	l.pop_front();
	PrintList(l);

	auto pos = bit::find(l.begin(), l.end(), 2);

	if (pos != l.end())
	{
		l.insert(pos, 5);
		PrintList(l);

		l.erase(pos);
		PrintList(l);
	}

	l.resize(10, 8);
	cout << l.size() << endl;
	PrintList(l);

	l.resize(2);
	cout << l.size() << endl;
	PrintList(l);

	l.clear();
	cout << l.size() << endl;
}

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}


	int _year;
	int _month;
	int _day;
};


void TestListDate()
{
	bit::list<Date> l;
	l.push_back(Date(2018, 11, 25));
	l.push_back(Date(2018, 11, 26));
	l.push_back(Date(2018, 11, 27));

	auto it = l.begin();
	cout << it->_year << "-" << (*it)._month << "-" << it->_day << endl;
}

int main()
{
	//TestListDate();
	//TestList1();
	TestList2();
	return 0;
}
