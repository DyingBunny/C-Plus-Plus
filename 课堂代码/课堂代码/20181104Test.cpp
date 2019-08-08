 #include <iostream>
 using namespace std;
 
 /*
 int main()
 {
 	int* p = (int*)malloc(sizeof(int)* 10);
 	p[0] = 0;
 	p[1] = 1;
 	p[8] = 8;
 	p[9] = 9;
 	return 0;
 }
 */
 
 
 /*
 // new/delete--->������
 // new+����
 // new/delete--->����Ԫ�ؿռ���������ͷ�
 // new[]/delete[]--->�����ռ���������ͷ�
 // �ɶ���ʹ��
 int main()
 {
 	int* p1 = new int;
 	int* p2 = new int(10);
 	int* p3 = new int[10];
 
 	delete p1;
 	delete p2;
 	delete[] p3;
 	return 0;
 }
 */
 
 // malloc/free
 // new/delete
 // new[] / delete[]
 
 // û��ƥ��ʹ�ú����1. ��������ڴ�й©
 //                2. �������
 
 /*
 int main()
 {
 	int* p1 = (int*)malloc(sizeof(int));
 	int* p2 = (int*)malloc(sizeof(int));
 
 
 	int* p3 = new int;
 	int* p4 = new int;
 
 	int* p5 = new int[10];
 	int* p6 = new int[10];
 
 	delete p1;
 	delete[] p2;
 
 	free(p3);
 	delete[] p4;
 
 	free(p5);
 	delete[] p6;
 
 	return 0;
 }
 */
 
 #if 0
 class Test
 {
 public:
 	Test()
 		: _pa(new int)
 	{
 		cout << "Test():" << this << endl;
 	}
 
 	~Test()
 	{
 		if (_pa)
 			delete _pa;
 
 		cout << "~Test():" << this << endl;
 	}
 
 	int _data;
 	int* _pa;
 };
 
 
 int main()
 {
 	// malloc������ù��캯��
 	// free: ���������������
 	//Test* p = (Test*)malloc(sizeof(Test));
 	
 	// new: ��������͵Ĺ��캯�� 
 	Test* p = new Test;
 
 	// �ͷŶ��ڴ�ʱ���������������
 	delete p;
 	return 0;
 }
 #endif
 
 #if 0
 class Test
 {
 public:
 	Test()
 	{
 		cout << "Test():" << this << endl;
 	}
 
 	~Test()
 	{
 		cout << "~Test():" << this << endl;
 	}
 
 	int _data;
 };
 
 int main()
 {
 	//Test* p = (Test*)malloc(sizeof(Test));
 	Test* p = new Test[10];
 	delete[] p;
 	return 0;
 }
 #endif

#if 0
 template<class T>
 struct AVLTreeNode
 {
	 AVLTreeNode(const T& data)
	 : _pLeft(nullptr)
	 , _pRight(nullptr)
	 , _pParent(nullptr)
	 , _data(data)
	 , _bf(0)
	 {}

	 AVLTreeNode<T>* _pLeft;   // �ýڵ������
	 AVLTreeNode<T>* _pRight;  // �ýڵ���Һ���
	 AVLTreeNode<T>* _pParent; // �ýڵ��˫��
	 T _data;
	 int _bf;                  // �ýڵ��ƽ������
 };

 template<class T>
 class AVLTree
 {
	 typedef AVLTreeNode<T> Node;
	 typedef Node* PNode;
 public:
	 AVLTree()
		 : _pRoot(nullptr)
	 {}

	 bool Insert(const T& data)
	 {
		 // 1. �Ȱ��ն����������Ĺ��򽫽ڵ���뵽AVL����
		 if (nullptr == _pRoot)
		 {
			 _pRoot = new Node(data);
			 return true;
		 }

		 // ���ն�����������������data��AVL�еĲ���λ��
		 PNode pCur = _pRoot;
		 PNode pParent = nullptr;
		 while (pCur)
		 {
			 pParent = pCur;
			 if (data < pCur->_data)
				 pCur = pCur->_pLeft;
			 else if (data > pCur->_data)
				 pCur = pCur->_data;
			 else
				 return false;   // �ýڵ��ڶ����������д���
		 }

		 // �����½ڵ㣺�½ڵ�һ��������pParent���������Ҳ�
		 if (data < pParent->_data)
			 pParent->_pLeft = pCur;
		 else
			 pParent->_pRight = pCur;

		 // ����pCur��˫�׽ڵ�
		 pCur->_pParent = pParent;

		 /*
		 pCur�����pParent��ƽ������һ����Ҫ�������ڲ���֮ǰ��pParent
		 ��ƽ�����ӷ�Ϊ���������-1��0, 1, ���������������
		 1. ���pCur���뵽pParent����ֻ࣬���pParent��ƽ������-1����
		 2. ���pCur���뵽pParent���Ҳֻ࣬���pParent��ƽ������+1����
		 ��ʱ��pParent��ƽ�����ӿ��������������0������1�� ����2
		 1. ���pParent��ƽ������Ϊ0��˵������֮ǰpParent��ƽ������Ϊ����1������󱻵�����0����ʱ����AVL�������ʣ�����ɹ�
		 2. ���pParent��ƽ������Ϊ����1��˵������ǰpParent��ƽ������һ��Ϊ0������󱻸��³�����1����ʱ��pParentΪ�������ĸ߶����ӣ���Ҫ�������ϸ���
		 3. ���pParent��ƽ������Ϊ����2����pParent��ƽ������Υ��ƽ���������ʣ���Ҫ���������ת����
		 */

		 while (pParent)
		 {
			 // ����˫�׵�ƽ������
			 if (pCur == pParent->_pLeft)
				 pParent->_bf--;
			 else
				 pParent->_bf++;

			 // ���º���˫�׵�ƽ������
			 if (0 == pParent->_bf)
				 break;
			 else if (1 == pParent->_bf || -1 == pParent->_bf)
			 {
				 pCur = pParent;
				 pParent = pCur->_pParent;
			 }
			 else
			 {
				 // ˫�׵�ƽ������Ϊ����2��Υ����AVL����ƽ���ԣ���Ҫ����pParent
				 // Ϊ������������ת����
			 }
		 }

		 return true;
	 }

	 bool IsBalanceTree()
	 {
		 return _IsBalanceTree(_pRoot);
	 }

 private:
	 bool _IsBalanceTree(PNode pRoot)
	 {
		 // ����Ҳ��AVL��
		 if (nullptr == pRoot)
			 return true;

		 // ����pRoot�ڵ��ƽ�����ӣ���pRoot���������ĸ߶Ȳ�
		 int leftHeight = _Height(pRoot->_pLeft);
		 int rightHeight = _Height(pRoot->_pRight);
		 int diff = rightHeight - leftHeight;

		 // ����������ƽ��������pRoot��ƽ�����Ӳ���ȣ�����
		 // pRootƽ�����ӵľ���ֵ����1����һ������AVL��
		 if (diff != pRoot->_bf || (diff > 1 || diff < -1))
			 return false;

		 // pRoot��������������AVL���������һ����AVL��
		 return _IsBalanceTree(pRoot->_pLeft) && _IsBalanceTree(pRoot->_pRight);
	 }

	 int _Height(PNode pRoot)
	 {
		 if (nullptr == pRoot)
			 return 0;

		 int leftHeight = _Height(pRoot->_pLeft);
		 int rightHeight = _Height(pRoot->_pRight);

		 return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
	 }

 private:
	 PNode _pRoot;
 };

 int main()
 {
	 AVLTree<int> t;
	 t.IsBalanceTree();
	 return 0;
 }
#endif

#if 0
 namespace bit
 {
	 enum Color{ RED, BLACK };

	 template<class ValueType>
	 struct RBTreeNode
	 {
		 RBTreeNode(const ValueType& data = ValueType(), Color color = RED)
		 : _pLeft(nullptr)
		 , _pRight(nullptr)
		 , _pParent(nullptr)
		 , _data(data)
		 , _color(RED)
		 {}

		 RBTreeNode<ValueType>* _pLeft;   // �ڵ������
		 RBTreeNode<ValueType>* _pRight;  // �ڵ���Һ���
		 RBTreeNode<ValueType>* _pParent; // �ڵ��˫��
		 ValueType _data;           // �ڵ��ֵ��ע�����������Ǵ洢��ֵ��
		 Color _color;               // �ڵ����ɫ
	 };

	 template<class ValueType, class Ptr, class Ref>
	 struct RBTreeIterator
	 {
		 typedef RBTreeNode<ValueType> Node;
		 typedef Node* PNode;
		 typedef RBTreeIterator<ValueType, Ptr, Ref> Self;
	 public:
		 RBTreeIterator()
			 : _pNode(NULL)
		 {}

		 RBTreeIterator(PNode pNode)
			 : _pNode(pNode)
		 {}

		 RBTreeIterator(const Self& s)
			 : _pNode(s._pNode)
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
			 Increasement();
			 return *this;
		 }

		 Self operator++(int)
		 {
			 Self temp(*this);
			 Increasement();
			 return temp;
		 }

		 Self& operator--()
		 {
			 Decreasement();
			 return *this;
		 }

		 Self operator--(int)
		 {
			 Self temp(*this);
			 Decreasement();
			 return temp;
		 }

		 bool operator!=(const Self& s)
		 {
			 return _pNode != s._pNode;
		 }

		 bool operator==(const Self& s)
		 {
			 return _pNode == s._pNode;
		 }

		 // 
		 void Increasement()
		 {
			 if (_pNode->_pRight)
			 {
				 _pNode = _pNode->_pRight;
				 while (_pNode->_pLeft)
					 _pNode = _pNode->_pLeft;
			 }
			 else
			 {
				 PNode pParent = _pNode->_pParent;
				 while (pParent->_pRight == _pNode)
				 {
					 _pNode = pParent;
					 pParent = _pNode->_pParent;
				 }

				 // ���ڵ�û��������
				 if (_pNode->_pRight != pParent)
					 _pNode = pParent;
			 }
		 }

		 void Decreasement()
		 {
			 if (_pNode->_pParent->_pParent == _pNode && _pNode->_color == RED)
				 _pNode = _pNode->_pRight;
			 else if (_pNode->_pLeft)
			 {
				 _pNode = _pNode->_pLeft;
				 while (_pNode->_pRight)
					 _pNode = _pNode->_pRight;
			 }
			 else
			 {
				 PNode pParent = _pNode->_pParent;
				 while (_pNode == pParent->_pLeft)
				 {
					 _pNode = pParent;
					 pParent = _pNode->_pParent;
				 }

				 _pNode = pParent;
			 }
		 }

	 private:
		 PNode _pNode;
	 };


	 template<class K, class ValueType, class KeyOfValue>
	 class RBTree
	 {
		 typedef RBTreeNode<ValueType> Node;
		 typedef Node* PNode;

	 public:
		 typedef RBTreeIterator<ValueType, ValueType*, ValueType&> Iterator;

	 public:
		 RBTree()
			 : _pHead(new Node)
			 , _size(0)
		 {
			 _pHead->_pLeft = _pHead;
			 _pHead->_pRight = _pHead;
			 _pHead->_pParent = nullptr;
		 }

		 ~RBTree()
		 {
			 Clear();
			 delete _pHead;
			 _pHead = nullptr;
		 }

		 /////////////////////////////////////////////////////////////////////
		 // Iterator
		 Iterator Begin()
		 {
			 return Iterator(_pHead->_pLeft);
		 }

		 Iterator End()
		 {
			 return Iterator(_pHead);
		 }

		 //////////////////////////////////////////////////////////////////
		 // Modify
		 // �ں�����в���data�ļ�ֵ��
		 // ��data�е�key�Ѿ��ں�����У������ʧ�ܣ�����<�ýڵ��Iterator, false>
		 // ��data�е�key�����ڣ������ɹ�������<�½ڵ�ĵ�����, true>
		 pair<Iterator, bool> Insert(const ValueType& data)
		 {
			 PNode& pRoot = GetRoot();
			 PNode pNewNode = nullptr;
			 // ��Ϊ��
			 if (nullptr == pRoot)
			 {
				 pNewNode = pRoot = new Node(data, BLACK);
				 pRoot->_pParent = _pHead;
			 }
			 else
			 {
				 // �ǿ�
				 // 1. ���ն����������Ĺ�������½ڵ�
				 // ...

				 // 2. �½ڵ���������ƻ�����������ʣ��Ժ����������ת��ɫ����
				 // ...
			 }

			 // ����ͷ�ڵ�������ָ�����ָ���Լ����ڵ����ɫ
			 _pHead->_pLeft = LeftMost();
			 _pHead->_pRight = RightMost();
			 pRoot->_color = BLACK;
			 ++_size;

			 return make_pair(Iterator(pNewNode), true);
		 }

		 // ��������еĽڵ����
		 void Clear()
		 {
			 _DestroyRBTree(GetRoot());
			 _pHead->_pLeft = _pHead;
			 _pHead->_pRight = _pHead;
			 _size = 0;
		 }

		 // ���key���ڣ�����key��λ��,���򷵻�end
		 Iterator Find(const K& key)
		 {
			 PNode pCur = GetRoot();
			 while (pCur)
			 {
				 if (key == KeyOfValue()(pCur->_data))
					 return Iterator(pCur);
				 else if (key < KeyOfValue()(pCur->_data))
					 pCur = pCur->_pLeft;
				 else
					 pCur = pCur->_pRight;
			 }

			 // ����end��λ��
			 return Iterator(_pHead);
		 }

		 //////////////////////////////////////////////////////////////////
		 // capacity
		 size_t Size()const
		 {
			 return _size;
		 }

		 bool Empty()const
		 {
			 return 0 == _size;
		 }


	 private:
		 PNode& GetRoot()
		 {
			 return _pHead->_pParent;
		 }

		 // ��ȡ������������ڵ�
		 PNode LeftMost()
		 {
			 PNode pCur = GetRoot();

			 if (nullptr == pCur)
				 return _pHead;

			 while (pCur->_pLeft)
				 pCur = pCur->_pLeft;

			 return pCur;
		 }

		 // ��ȡ����������Ҳ�ڵ�
		 PNode RightMost()
		 {
			 PNode pCur = GetRoot();

			 if (nullptr == pCur)
				 return _pHead;

			 while (pCur->_pRight)
				 pCur = pCur->_pRight;

			 return pCur;
		 }

		 void _DestroyRBTree(PNode& pRoot)
		 {
			 if (pRoot)
			 {
				 _DestroyRBTree(pRoot->_pLeft);
				 _DestroyRBTree(pRoot->_pRight);
				 delete pRoot;
				 pRoot = nullptr;
			 }
		 }


	 private:
		 PNode _pHead;  // �����ͷָ��
		 size_t _size;  // ���������Ч�ڵ�ĸ���
	 };

	 template<class K, class V>
	 class Map
	 {
		 typedef pair<K, V> ValueType;

		 struct KeyOfValue
		 {
			 const K& operator()(const ValueType& v)
			 {
				 return v.first;
			 }
		 };

		 typedef RBTree<K, ValueType, KeyOfValue> RBTree;

	 public:
		 typedef typename RBTree::Iterator Iterator;
	 public:
		 Map()
		 {}

		 /////////////////////////////////////////////
		 // Iterator
		 Iterator Begin()
		 {
			 return _t.Begin();
		 }

		 Iterator End()
		 {
			 return _t.End();
		 }

		 /////////////////////////////////////////////////
		 // Capacity
		 size_t Size()const
		 {
			 return _t.Size();
		 }

		 bool Empty()const
		 {
			 return _t.Empty();
		 }

		 /////////////////////////////////////////////////
		 // Acess
		 V& operator[](const K& key)
		 {
			 return (*(_t.Insert(ValueType(key, V()))).first).second;
		 }

		 const V& operator[](const K& key)const
		 {
			 return (*(_t.Insert(ValueType(key, V()))).first).second;
		 }

		 ////////////////////////////////////////////////////
		 // modify
		 pair<Iterator, bool> Insert(const ValueType& data)
		 {
			 return _t.Insert(data);
		 }

		 void Clear()
		 {
			 _t.Clear();
		 }

		 Iterator Find(const K& key)
		 {
			 return _t.Find(key);
		 }

	 private:
		 RBTree _t;
	 };

	 template<class K>
	 class Set
	 {
		 typedef K ValueType;

		 struct KeyOfValue
		 {
			 const K& operator()(const ValueType& key)
			 {
				 return key;
			 }
		 };

		 typedef RBTree<K, ValueType, KeyOfValue> RBTree;

	 public:
		 typedef typename RBTree::Iterator Iterator;
	 public:
		 Set()
		 {}

		 /////////////////////////////////////////////
		 // Iterator
		 Iterator Begin()
		 {
			 return _t.Begin();
		 }

		 Iterator End()
		 {
			 return _t.End();
		 }

		 /////////////////////////////////////////////////
		 // Capacity
		 size_t Size()const
		 {
			 return _t.Size();
		 }

		 bool Empty()const
		 {
			 return _t.Empty();
		 }

		 ////////////////////////////////////////////////////
		 // modify
		 pair<Iterator, bool> Insert(const K& key)
		 {
			 return _t.Insert(key);
		 }

		 void Clear()
		 {
			 _t.Clear();
		 }

		 Iterator Find(const K& key)
		 {
			 return _t.Find(key);
		 }

	 private:
		 RBTree _t;
	 };
 }

 int main()
 { 
	return 0;
 }
#endif

#if 0

 // �ڵ����ɫ
 enum Color{ RED, BLACK };

 // ������ڵ�Ķ���
 template<class ValueType>
 struct RBTreeNode
 {
	 RBTreeNode(const ValueType& data = ValueType(), Color color = RED)
	 : _pLeft(nullptr)
	 , _pRight(nullptr)
	 , _pParent(nullptr)
	 , _data(data)
	 , _color(color)
	 {}

	 RBTreeNode<ValueType>* _pLeft;   // �ڵ������
	 RBTreeNode<ValueType>* _pRight;  // �ڵ���Һ���
	 RBTreeNode<ValueType>* _pParent; // �ڵ��˫��(��Ϊ�����Ҳ��Ҫ��ת��Ϊ��ʵ�ּ򵥸������ֶ�)
	 ValueType _data;            // �ڵ��ֵ��
	 Color _color;               // �ڵ����ɫ
 };


 template<class ValueType, class Ptr, class Ref>
 struct RBTreeIterator
 {
	 typedef RBTreeNode<ValueType> Node;
	 typedef Node* PNode;
	 typedef RBTreeIterator<ValueType, Ptr, Ref> Self;
 public:
	 RBTreeIterator()
		 : _pNode(nullptr)
	 {}

	 RBTreeIterator(PNode pNode)
		 : _pNode(pNode)
	 {}

	 RBTreeIterator(const Self& s)
		 : _pNode(s._pNode)
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
		 Increasement();
		 return *this;
	 }

	 Self operator++(int)
	 {
		 Self temp(*this);
		 Increasement();
		 return temp;
	 }

	 Self& operator--()
	 {
		 Decreasement();
		 return *this;
	 }

	 Self operator--(int)
	 {
		 Self temp(*this);
		 Decreasement();
		 return temp;
	 }

	 bool operator!=(const Self& s)
	 {
		 return _pNode != s._pNode;
	 }

	 bool operator==(const Self& s)
	 {
		 return _pNode == s._pNode;
	 }

	 // �ҵ���������һ���ڵ㣬��һ���ڵ�϶������
	 void Increasement()
	 {
		 /*
		 �������������:
		 1. _pNode������������
		 2. _pNode��������������
		 */

		 // 1. _pNode�����������ڣ�����������������С(�����)�Ľڵ�
		 if (_pNode->_pRight)
		 {
			 // ����������С�Ľڵ㣬���������������ڵ�
			 _pNode = _pNode->_pRight;
			 while (_pNode->_pLeft)
				 _pNode = _pNode->_pLeft;
		 }
		 else
		 {
			 /*
			 2. _pNode��������������
			 һ����������             ����������������ڸ��ڵ�λ�ã����Ҹ��ڵ����Һ���
			 [head]                                  head
			 |                                      |
			 8                                      8
			 /   \                                   / \
			 /     \                                 /   \
			 4       9                               4    nul
			 / \     / \                             / \
			 /   \   /   \                           /   \
			 nul    5 nul  nul                       nul   nul
			 / \
			 /   \
			 nul  nul
			 һ�������
			 ���_pNode�ڽڵ�5��λ�ã��ýڵ�û����������ֻ�����Ϸ�ȥ���ң�������Ҫ�Ҷ�Σ�
			 _pNode-->5   pParent-->4   _pNode == pParent->right
			 _pNode-->4   pParent-->8   _pNode ��= pParent->right
			 ��������Ҫ��_pNode����pParent��λ��

			 ���������
			 ���ڽڵ�8�����Ӧ�ý������head��λ��
			 _pNode-->8     pParent-->head _pNode == pParent->right
			 _pNode-->head  pParent-->8    _pNode != pParent->right
			 ������_pNode��Ϊ����ȡλ�ã����轫_pNode����pParent��λ��
			 */
			 // ���ϲ��ң�ֱ��_pNode != pParent->right
			 PNode pParent = _pNode->_pParent;
			 while (pParent->_pRight == _pNode)
			 {
				 _pNode = pParent;
				 pParent = _pNode->_pParent;
			 }

			 // ������������ڵ�û��������
			 if (_pNode->_pRight != pParent)
				 _pNode = pParent;
		 }
	 }

	 // ��ȡ������ָ��ڵ��ǰһ���ڵ�
	 void Decreasement()
	 {
		 /*
		 ������������ۣ�
		 1. _pNode ��head��λ��
		 2. _pNode ����������
		 3. _pNode ������������
		 */

		 // 1. _pNode ��head��λ�ã�--Ӧ�ý�_pNode���ں���������ڵ��λ��
		 //    _pNode->_pParent->_pParent == _pNode ���жϳ�_pNode�ڸ�����head
		 //    _pNode->_color == RED ���ų����ڵ�
		 if (_pNode->_pParent->_pParent == _pNode && _pNode->_color == RED)
			 _pNode = _pNode->_pRight;
		 else if (_pNode->_pLeft)
		 {
			 // 2. _pNode������������
			 //   ���������������Ľڵ㼴�ɣ����Ľڵ㼴�����������Ҳ�ڵ�
			 _pNode = _pNode->_pLeft;
			 while (_pNode->_pRight)
				 _pNode = _pNode->_pRight;
		 }
		 else
		 {
			 /*
			 3. _pNode��������������
			 head
			 |
			 4
			 /   \
			 /     \
			 3       8
			 / \     / \
			 /   \   /   \
			 nul  nul 7  nul
			 / \
			 /   \
			 nul   nul

			 _pNode����ڽڵ�7��λ�ã��ýڵ�û����������ֻ��������
			 _pNode-->7  pParent-->8   _pNode == pParent->_pLeft
			 _pNode-->8  pParent-->4   _pNode != pParent->_pLeft
			 �������轫_pNode����pParent��λ��

			 _pNode����ڽڵ�3��λ�ã�ע��3�Ǻ��������С�Ľڵ㣬���ܽ���--��������˸�����
			 ������Ҫ����
			 */

			 PNode pParent = _pNode->_pParent;
			 while (_pNode == pParent->_pLeft)
			 {
				 _pNode = pParent;
				 pParent = _pNode->_pParent;
			 }

			 _pNode = pParent;
		 }
	 }

 private:
	 PNode _pNode;
 };

 template<class K, class ValueType, class KeyOfValue>
 class RBTree
 {
	 typedef RBTreeNode<ValueType> Node;
	 typedef Node* PNode;

 public:
	 typedef RBTreeIterator<ValueType, ValueType*, ValueType&> Iterator;

 public:
	 RBTree()
		 : _pHead(new Node)
		 , _size(0)
	 {
		 _pHead->_pLeft = _pHead;
		 _pHead->_pRight = _pHead;
		 _pHead->_pParent = nullptr;
	 }

	 ~RBTree()
	 {
		 Clear();
		 delete _pHead;
		 _pHead = nullptr;
	 }

	 /////////////////////////////////////////////////////////////////////
	 // Iterator
	 Iterator Begin()
	 {
		 return Iterator(_pHead->_pLeft);
	 }

	 Iterator End()
	 {
		 return Iterator(_pHead);
	 }

	 //////////////////////////////////////////////////////////////////
	 // Modify
	 // �ں�����в���data�ļ�ֵ��
	 // ��data�е�key�Ѿ��ں�����У������ʧ�ܣ�����<�ýڵ��Iterator, false>
	 // ��data�е�key�����ڣ������ɹ�������<�½ڵ�ĵ�����, true>
	 pair<Iterator, bool> Insert(const ValueType& data)
	 {
		 PNode& pRoot = GetRoot();
		 PNode pNewNode = nullptr;
		 // ��Ϊ��
		 if (nullptr == pRoot)
		 {
			 pNewNode = pRoot = new Node(data, BLACK);
			 pRoot->_pParent = _pHead;
		 }
		 else
		 {
			 // �ǿ�
			 // 1. ���ն����������Ĺ�������½ڵ�
			 // ...

			 // 2. �½ڵ���������ƻ�����������ʣ��Ժ����������ת��ɫ����
			 // ...
		 }

		 // ����ͷ�ڵ�������ָ�����ָ���Լ����ڵ����ɫ
		 _pHead->_pLeft = LeftMost();
		 _pHead->_pRight = RightMost();
		 pRoot->_color = BLACK;
		 ++_size;

		 return make_pair(Iterator(pNewNode), true);
	 }

	 // ��������еĽڵ����
	 void Clear()
	 {
		 _DestroyRBTree(GetRoot());
		 _pHead->_pLeft = _pHead;
		 _pHead->_pRight = _pHead;
		 _size = 0;
	 }

	 // ���key���ڣ�����key��λ��,���򷵻�end
	 Iterator Find(const K& key)
	 {
		 PNode pCur = GetRoot();
		 while (pCur)
		 {
			 if (key == KeyOfValue()(pCur->_data))
				 return Iterator(pCur);
			 else if (key < KeyOfValue()(pCur->_data))
				 pCur = pCur->_pLeft;
			 else
				 pCur = pCur->_pRight;
		 }

		 // ����end��λ��
		 return Iterator(_pHead);
	 }

	 //////////////////////////////////////////////////////////////////
	 // capacity
	 size_t Size()const
	 {
		 return _size;
	 }

	 bool Empty()const
	 {
		 return 0 == _size;
	 }


 private:
	 PNode& GetRoot()
	 {
		 return _pHead->_pParent;
	 }

	 // ��ȡ������������ڵ�
	 PNode LeftMost()
	 {
		 PNode pCur = GetRoot();

		 if (nullptr == pCur)
			 return _pHead;

		 while (pCur->_pLeft)
			 pCur = pCur->_pLeft;

		 return pCur;
	 }

	 // ��ȡ����������Ҳ�ڵ�
	 PNode RightMost()
	 {
		 PNode pCur = GetRoot();

		 if (nullptr == pCur)
			 return _pHead;

		 while (pCur->_pRight)
			 pCur = pCur->_pRight;

		 return pCur;
	 }

	 void _DestroyRBTree(PNode& pRoot)
	 {
		 if (pRoot)
		 {
			 _DestroyRBTree(pRoot->_pLeft);
			 _DestroyRBTree(pRoot->_pRight);
			 delete pRoot;
			 pRoot = nullptr;
		 }
	 }


 private:
	 PNode _pHead;  // �����ͷָ��
	 size_t _size;  // ���������Ч�ڵ�ĸ���
 };

#if 1
	 template<class K, class V>
	 class Map
	 {
		 typedef pair<K, V> ValueType;

		 // ���ڲ���������ǣ���value�е�key��ȡ����
		 struct KeyOfValue
		 {
			 const K& operator()(const ValueType& v)
			 {
				 return v.first;
			 }
		 };

		 typedef RBTree<K, ValueType, KeyOfValue> RBTree;

	 public:
		 typedef typename RBTree::Iterator Iterator;

	 public:
		 Map()
		 {}

		 /////////////////////////////////////////////
		 // Iterator
		 Iterator Begin()
		 {
			 return _t.Begin();
		 }

		 Iterator End()
		 {
			 return _t.End();
		 }

		 /////////////////////////////////////////////////
		 // Capacity
		 size_t Size()const
		 {
			 return _t.Size();
		 }

		 bool Empty()const
		 {
			 return _t.Empty();
		 }

		 /////////////////////////////////////////////////
		 // Acess
		 V& operator[](const K& key)
		 {
			 return (*(_t.Insert(ValueType(key, V()))).first).second;
		 }

		 const V& operator[](const K& key)const
		 {
			 return (*(_t.Insert(ValueType(key, V()))).first).second;
		 }

		 ////////////////////////////////////////////////////
		 // modify
		 pair<Iterator, bool> Insert(const ValueType& data)
		 {
			 return _t.Insert(data);
		 }

		 void Clear()
		 {
			 _t.Clear();
		 }

		 Iterator Find(const K& key)
		 {
			 return _t.Find(key);
		 }

	 private:
		 RBTree _t;
	 };
#endif

	 template<class K>
	 class Set
	 {
		 typedef K ValueType;

		 // ���ڲ���������ǣ���value�е�key��ȡ����
		 struct KeyOfValue
		 {
			 const K& operator()(const ValueType& key)
			 {
				 return key;
			 }
		 };

		 typedef RBTree<K, ValueType, KeyOfValue> RBTree;

	 public:
		 typedef typename RBTree::Iterator Iterator;

	 public:
		 Set()
		 {}

		 /////////////////////////////////////////////
		 // Iterator
		 Iterator Begin()
		 {
			 return _t.Begin();
		 }

		 Iterator End()
		 {
			 return _t.End();
		 }

		 /////////////////////////////////////////////////
		 // Capacity
		 size_t Size()const
		 {
			 return _t.Size();
		 }

		 bool Empty()const
		 {
			 return _t.Empty();
		 }

		 ////////////////////////////////////////////////////
		 // modify
		 pair<Iterator, bool> Insert(const ValueType& data)
		 {
			 return _t.Insert(data);
		 }

		 void Clear()
		 {
			 _t.Clear();
		 }

		 Iterator Find(const K& key)
		 {
			 return _t.Find(key);
		 }

	 private:
		 RBTree _t;
	 };


 int main()
 {
	 Set<int> m;
	 m.Insert(1);
	 cout << m.Size() << endl;

	 auto it = m.Begin();
	 while (it != m.End())
	 {
		 cout << *it << " ";
		 ++it;
	 }

	 m.Clear();
	 
	 cout << *(m.Find(1)) << endl;

	 return 0;
 }
#endif

#if 0
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>

 class Solution {
 public:

	 class Compare
	 {
	 public:
		 bool operator()(const pair<string, int>& left, const pair<string, int>& right)
		 {
			 return left.second > right.second;
		 }
	 };

	 vector<string> topKFrequent(vector<string>& words, int k)
	 {
		 // ��<���ʣ����ʳ��ִ���>������ֵ�ԣ�Ȼ��vector�еĵ��ʷŽ�ȥ��ͳ��ÿ�����ʳ��ֵĴ���
		 map<string, int> m;
		 for (size_t i = 0; i < words.size(); ++i)
			 ++(m[words[i]]);

		 // �����ʰ�������ִ�����������
		 multiset<pair<string, int>, Compare> ms(m.begin(), m.end());

		 // ����ͬ�����ĵ��ʷ���set�У�Ȼ���ٷŵ�vector��
		 vector<string> ret;
		 set<string> s;
		 size_t count = 0;
		 size_t leftCount = k;
		 int pos = 0;
		 for (auto& e: ms)
		 {
			 ++pos;
			 if (!s.empty())
			 {
				 // ��ͬ�����ĵ����Ѿ�ȫ���ŵ�set��
				 if (count != e.second)
				 {
					 if (s.size() < leftCount)
					 {
						 ret.insert(ret.end(), s.begin(), s.end());
						 leftCount -= s.size();
						 s.clear();
					 }
					 else
					 {
						 break;
					 }
				 }
			 }

			 count = e.second;
			 s.insert(e.first);
		 }

		 for (auto& e : s)
		 {
			 if (0 == leftCount)
				 break;

			 ret.push_back(e);
			 leftCount--;
		 }
		 return ret;
	 }
 };

 int main()
 {
	 vector<string> v = { "rmrypv", "zgsedk", "jlmetsplg", "wnfbo", "hnnftqf", "bxlr", "sviavwoxss", "jdbgvc", "zddeno", "rxgw", "hnnftqf", "hdmvplne", "rlmdt", "jlmetsplg", "ous", "rmrypv", "fwxulnpit", "dmhuq", "rxgw", "ledleb", "bxlr", "indbvb", "ckqqibnx", "cub", "ijww", "ehd", "hfhlfqzkcn", "sviavwoxss", "rxgw", "bxjxpfp", "mgqj", "oic", "ptk", "fwxulnpit", "ijww", "sviavwoxss", "bgfvfa", "zfkgsudxq", "alkq", "dmhuq", "zddeno", "rxgw", "zgsedk", "amarxpg", "bgfvfa", "wnfbo", "sviavwoxss", "sviavwoxss", "alkq", "nmclxk", "zgsedk", "bwowfvira", "ous", "bxlr", "zddeno", "rxgw", "ous", "wnfbo", "rmrypv", "sviavwoxss", "ehd", "zgsedk", "jlmetsplg", "abxvhyehv", "ledleb", "wnfbo", "bgfvfa", "bwowfvira", "amarxpg", "wnfbo", "bwowfvira", "dmhuq", "ouy", "bxlr", "rxgw", "oic", "hnnftqf", "ledleb", "rlmdt", "oldainprua", "ous", "ckqqibnx", "dmhuq", "hnnftqf", "oic", "jlmetsplg", "ppn", "amarxpg", "jlgfgwb", "bxlr", "bwowfvira", "hdmvplne", "oic", "ledleb", "bwowfvira", "oic", "ptk", "dmhuq", "abxvhyehv", "ckqqibnx", "indbvb", "ypzfk", "rmrypv", "bxjxpfp", "amarxpg", "dmhuq", "sviavwoxss", "bwowfvira", "zfkgsudxq", "wnfbo", "rxgw", "jxkvrmajri", "cub", "abxvhyehv", "bwowfvira", "indbvb", "ehd", "ckqqibnx", "oic", "ptk", "hnnftqf", "ouy", "oic", "zgsedk", "abxvhyehv", "ypzfk", "ptk", "sviavwoxss", "rmrypv", "oic", "ous", "abxvhyehv", "hnnftqf", "hfhlfqzkcn", "ledleb", "cub", "ppn", "zddeno", "indbvb", "oic", "jlmetsplg", "ouy", "bwowfvira", "bklij", "gucayxp", "zfkgsudxq", "hfhlfqzkcn", "zddeno", "ledleb", "zfkgsudxq", "hnnftqf", "bgfvfa", "jlmetsplg", "indbvb", "ehd", "wnfbo", "hnnftqf", "rlmdt", "bxlr", "indbvb", "jdbgvc", "jlmetsplg", "cub", "jlgfgwb", "ypzfk", "indbvb", "dmhuq", "jlmetsplg", "zgsedk", "rmrypv", "cub", "rxgw", "ledleb", "rxgw", "sviavwoxss", "ckqqibnx", "hdmvplne", "dmhuq", "wnfbo", "jlmetsplg", "bxlr", "zfkgsudxq", "bxjxpfp", "ledleb", "indbvb", "ckqqibnx", "ous", "ckqqibnx", "cub", "ous", "abxvhyehv", "bxlr", "hfhlfqzkcn", "hfhlfqzkcn", "oic", "ten", "amarxpg", "indbvb", "cub", "alkq", "alkq", "sviavwoxss", "indbvb", "bwowfvira", "ledleb" };
	 Solution s;
	 v = s.topKFrequent(v, 41);
	 return 0;
 }
#endif

 int main()
 {
	 return 0;
 }