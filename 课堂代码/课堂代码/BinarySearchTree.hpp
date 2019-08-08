#pragma once
#include <iostream>
using namespace std;

template<class T>
struct  BSTNode
{
	BSTNode(const T& data)
	    : _pLeft(nullptr)
	    , _pRight(nullptr)
	    , _data(data)
	{}

	BSTNode<T>* _pLeft;
	BSTNode<T>* _pRight;
	T _data;
};


template<class T>
class BSTree
{
	typedef BSTNode<T> Node;
	typedef Node* PNode;
public:
	BSTree()
		: _pRoot(nullptr)
	{}

	~BSTree()
	{
		_Destroy(_pRoot);
	}

	bool Insert(const T& data)
	{
		// 树空
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}

		// 非空：找当前节点在树中的插入位置
		PNode pCur = _pRoot;
		PNode pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else if (data > pCur->_data)
				pCur = pCur->_pRight;
			else
				return true;
		}

		// 插入节点
		pCur = new Node(data);
		if (data < pParent->_data)
			pParent->_pLeft = pCur;
		else
			pParent->_pRight = pCur;

		return true;
	}

	bool Erase(const T& data)
	{
		// 找待删除节点的位置
		PNode pCur = _pRoot;
		PNode pParent = nullptr;
		while (pCur)
		{
			if (data == pCur->_data)
				break;
			else if (data < pCur->_data)
			{
				pParent = pCur;
				pCur = pCur->_pLeft;
			}
			else
			{
				pParent = pCur;
				pCur = pCur->_pRight;
			}
		}

		if (nullptr == pCur)
			return false;

		// 分情况删除节点：
		/*
		1. 叶子节点||只有右孩子
		2. 只有左孩子
		3. 左右孩子均存在
		*/
		if (nullptr == pCur->_pLeft) // 情况1
		{
			if (_pRoot == pCur)
				_pRoot = pCur->_pRight;
			else
			{
				if (pCur == pParent->_pLeft)
					pParent->_pLeft = pCur->_pRight;
				else
					pParent->_pRight = pCur->_pRight;
			}
		}
		else if (nullptr == pCur->_pRight)  // 情况2
		{
			if (pCur == _pRoot)
				_pRoot = pCur->_pLeft;
			else
			{
				if (pCur == pParent->_pLeft)
					pParent->_pLeft = pCur->_pLeft;
				else
					pParent->_pRight = pCur->_pLeft;
			}
		}
		else
		{
			// 左右孩子均存在---不能直接删除，找一个替代节点
			// 可以在左子树中找：左子树中最右侧节点
			// 可以在右子树中找：右子树中最左侧节点
			PNode pFirstOfIn = pCur->_pRight;
			pParent = pCur;
			while (pFirstOfIn->_pLeft)
			{
				pParent = pFirstOfIn;
				pFirstOfIn = pFirstOfIn->_pLeft;
			}

			// pFirstOfIn: 替代节点，该节点一定没有左孩子(可能有右孩子)
			pCur->_data = pFirstOfIn->_data;

			// 删除替代节点
			if (pFirstOfIn == pParent->_pLeft)
				pParent->_pLeft = pFirstOfIn->_pRight;
			else
				pParent->_pRight = pFirstOfIn->_pRight;

			pCur = pFirstOfIn;
		}

		delete pCur;
		return true;
	}

	PNode Find(const T& data)
	{
		PNode pCur = _pRoot;
		while (pCur)
		{
			if (data == pCur->_data)
				return pCur;
			else if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else
				pCur = pCur->_pRight;
		}

		return nullptr;
	}

	void InOrder()
	{
		_InOrder(_pRoot);
	}

private:
	void _InOrder(PNode pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->_pLeft);
			cout << pRoot->_data << " ";
			_InOrder(pRoot->_pRight);
		}
	}

	void _Destroy(PNode& pRoot)
	{
		if (pRoot)
		{
			_Destroy(pRoot->_pLeft);
			_Destroy(pRoot->_pRight);
			delete pRoot;
			pRoot = nullptr;
		}
	}
private:
	PNode _pRoot;
};

void TestBSTree()
{
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	BSTree<int> t;
	for (auto e : a)
		t.Insert(e);

	t.InOrder();

	BSTNode<int>* pNode = t.Find(9);
	if (pNode)
	{
		cout << "9 is in BSTree" << endl;
	}
	else
	{
		cout << "9 is not in BSTree" << endl;
	}

	t.Erase(6);
	t.InOrder();

	t.Erase(8);
	t.InOrder();

	t.Erase(5);
	t.InOrder();
}