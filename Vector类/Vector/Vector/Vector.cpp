#include<iostream>
#include<vector>
using namespace std;
//void Test()
//{
//	vector<int> second;
//	second.push_back(1);
//	second.push_back(2);
//	second.push_back(3);
//	second.push_back(4);
//	vector<int>::iterator a = second.begin();
//	*a = 2;
//}
//
//int main()
//{
//	//Test();	
//	int a = 10;
//	int b = 10;
//	int c = 20;
//	int d = 5;
//	int e = 20;
//	int m=0;
//	m ^= a;
//	cout << m << endl;
//	m ^= b;
//	cout << m << endl;
//	m ^= c;
//	cout << m << endl;
//	m ^= d;
//	cout << m << endl;
//	m ^= e;
//	cout << m << endl;
//	system("pause");
//	return 0;
//}
	template<class T>
	class Vector
	{
	public:
		// Vector的迭代器是一个原生指针
		typedef T* Iterator;
		typedef const T* ConstIterator;
		Iterator Begin() { return _start; }
		Iterator End() { return _finish; }
		ConstIterator CBegin() const { return _start; }
		ConstIterator CEnd() const { return _finish; }
		size_t Size() const { return _finish - _start; }
		size_t Capacity() const { return _endOfStorage - _start; }
		Vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{}
		Vector(int n, const T& value = T())
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			Reserve(n);
			while (n--)
			{
				PushBack(value);
			}
		}template<class InputIterator>Vector(InputIterator first, InputIterator last){	Reserve(last - first);	while (first != last)	{		PushBack(*first);	}}



