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
 // new/delete--->操作符
 // new+类型
 // new/delete--->单个元素空间的申请与释放
 // new[]/delete[]--->连续空间的申请与释放
 // 成对来使用
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
 
 // 没有匹配使用后果：1. 代码存在内存泄漏
 //                2. 立马崩溃
 
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
 	// malloc不会调用构造函数
 	// free: 不会调用析构函数
 	//Test* p = (Test*)malloc(sizeof(Test));
 	
 	// new: 会调用类型的构造函数 
 	Test* p = new Test;
 
 	// 释放堆内存时，会调用析构函数
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

	 AVLTreeNode<T>* _pLeft;   // 该节点的左孩子
	 AVLTreeNode<T>* _pRight;  // 该节点的右孩子
	 AVLTreeNode<T>* _pParent; // 该节点的双亲
	 T _data;
	 int _bf;                  // 该节点的平衡因子
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
		 // 1. 先按照二叉搜索树的规则将节点插入到AVL树中
		 if (nullptr == _pRoot)
		 {
			 _pRoot = new Node(data);
			 return true;
		 }

		 // 按照二叉搜索树的性质找data在AVL中的插入位置
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
				 return false;   // 该节点在二叉搜索树中存在
		 }

		 // 插入新节点：新节点一定插入在pParent的左侧或者右侧
		 if (data < pParent->_data)
			 pParent->_pLeft = pCur;
		 else
			 pParent->_pRight = pCur;

		 // 更新pCur的双亲节点
		 pCur->_pParent = pParent;

		 /*
		 pCur插入后，pParent的平衡因子一定需要调整，在插入之前，pParent
		 的平衡因子分为三种情况：-1，0, 1, 分以下两种情况：
		 1. 如果pCur插入到pParent的左侧，只需给pParent的平衡因子-1即可
		 2. 如果pCur插入到pParent的右侧，只需给pParent的平衡因子+1即可
		 此时：pParent的平衡因子可能有三种情况：0，正负1， 正负2
		 1. 如果pParent的平衡因子为0，说明插入之前pParent的平衡因子为正负1，插入后被调整成0，此时满足AVL树的性质，插入成功
		 2. 如果pParent的平衡因子为正负1，说明插入前pParent的平衡因子一定为0，插入后被更新成正负1，此时以pParent为根的树的高度增加，需要继续向上更新
		 3. 如果pParent的平衡因子为正负2，则pParent的平衡因子违反平衡树的性质，需要对其进行旋转处理
		 */

		 while (pParent)
		 {
			 // 更新双亲的平衡因子
			 if (pCur == pParent->_pLeft)
				 pParent->_bf--;
			 else
				 pParent->_bf++;

			 // 更新后检测双亲的平衡因子
			 if (0 == pParent->_bf)
				 break;
			 else if (1 == pParent->_bf || -1 == pParent->_bf)
			 {
				 pCur = pParent;
				 pParent = pCur->_pParent;
			 }
			 else
			 {
				 // 双亲的平衡因子为正负2，违反了AVL树的平衡性，需要对以pParent
				 // 为根的树进行旋转处理
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
		 // 空树也是AVL树
		 if (nullptr == pRoot)
			 return true;

		 // 计算pRoot节点的平衡因子：即pRoot左右子树的高度差
		 int leftHeight = _Height(pRoot->_pLeft);
		 int rightHeight = _Height(pRoot->_pRight);
		 int diff = rightHeight - leftHeight;

		 // 如果计算出的平衡因子与pRoot的平衡因子不相等，或者
		 // pRoot平衡因子的绝对值超过1，则一定不是AVL树
		 if (diff != pRoot->_bf || (diff > 1 || diff < -1))
			 return false;

		 // pRoot的左和右如果都是AVL树，则该树一定是AVL树
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

		 RBTreeNode<ValueType>* _pLeft;   // 节点的左孩子
		 RBTreeNode<ValueType>* _pRight;  // 节点的右孩子
		 RBTreeNode<ValueType>* _pParent; // 节点的双亲
		 ValueType _data;           // 节点的值域，注意红黑树中我们存储键值对
		 Color _color;               // 节点的颜色
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

				 // 根节点没有右子树
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
		 // 在红黑树中插入data的键值对
		 // 若data中的key已经在红黑树中，则插入失败，返回<该节点的Iterator, false>
		 // 若data中的key不存在，则插入成功，返回<新节点的迭代器, true>
		 pair<Iterator, bool> Insert(const ValueType& data)
		 {
			 PNode& pRoot = GetRoot();
			 PNode pNewNode = nullptr;
			 // 树为空
			 if (nullptr == pRoot)
			 {
				 pNewNode = pRoot = new Node(data, BLACK);
				 pRoot->_pParent = _pHead;
			 }
			 else
			 {
				 // 非空
				 // 1. 按照二叉搜索树的规则插入新节点
				 // ...

				 // 2. 新节点插入后如果破坏红黑树的性质，对红黑树进行旋转着色处理
				 // ...
			 }

			 // 调整头节点中左右指针域的指向以及根节点的颜色
			 _pHead->_pLeft = LeftMost();
			 _pHead->_pRight = RightMost();
			 pRoot->_color = BLACK;
			 ++_size;

			 return make_pair(Iterator(pNewNode), true);
		 }

		 // 将红黑树中的节点清空
		 void Clear()
		 {
			 _DestroyRBTree(GetRoot());
			 _pHead->_pLeft = _pHead;
			 _pHead->_pRight = _pHead;
			 _size = 0;
		 }

		 // 如果key存在，返回key的位置,否则返回end
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

			 // 返回end的位置
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

		 // 获取红黑树中最左侧节点
		 PNode LeftMost()
		 {
			 PNode pCur = GetRoot();

			 if (nullptr == pCur)
				 return _pHead;

			 while (pCur->_pLeft)
				 pCur = pCur->_pLeft;

			 return pCur;
		 }

		 // 获取红黑树中最右侧节点
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
		 PNode _pHead;  // 红黑树头指针
		 size_t _size;  // 红黑树中有效节点的个数
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

 // 节点的颜色
 enum Color{ RED, BLACK };

 // 红黑树节点的定义
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

	 RBTreeNode<ValueType>* _pLeft;   // 节点的左孩子
	 RBTreeNode<ValueType>* _pRight;  // 节点的右孩子
	 RBTreeNode<ValueType>* _pParent; // 节点的双亲(因为红黑树也需要旋转，为了实现简单给出该字段)
	 ValueType _data;            // 节点的值域
	 Color _color;               // 节点的颜色
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

	 // 找迭代器的下一个节点，下一个节点肯定比其大
	 void Increasement()
	 {
		 /*
		 分两种情况讨论:
		 1. _pNode的右子树存在
		 2. _pNode的右子树不存在
		 */

		 // 1. _pNode的右子树存在，则在右子树中找最小(最左侧)的节点
		 if (_pNode->_pRight)
		 {
			 // 右子树中最小的节点，即右子树中最左侧节点
			 _pNode = _pNode->_pRight;
			 while (_pNode->_pLeft)
				 _pNode = _pNode->_pLeft;
		 }
		 else
		 {
			 /*
			 2. _pNode的右子树不存在
			 一般情况情况：             特殊情况：迭代器在根节点位置，并且根节点无右孩子
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
			 一般情况：
			 如果_pNode在节点5的位置，该节点没有右子树，只能向上方去查找，可能需要找多次：
			 _pNode-->5   pParent-->4   _pNode == pParent->right
			 _pNode-->4   pParent-->8   _pNode ！= pParent->right
			 结束后：需要将_pNode置于pParent的位置

			 特殊情况：
			 对于节点8，最后应该将其放在head的位置
			 _pNode-->8     pParent-->head _pNode == pParent->right
			 _pNode-->head  pParent-->8    _pNode != pParent->right
			 结束后：_pNode即为所求取位置，不需将_pNode置于pParent的位置
			 */
			 // 向上查找，直到_pNode != pParent->right
			 PNode pParent = _pNode->_pParent;
			 while (pParent->_pRight == _pNode)
			 {
				 _pNode = pParent;
				 pParent = _pNode->_pParent;
			 }

			 // 特殊情况：根节点没有右子树
			 if (_pNode->_pRight != pParent)
				 _pNode = pParent;
		 }
	 }

	 // 获取迭代器指向节点的前一个节点
	 void Decreasement()
	 {
		 /*
		 分三种情况讨论：
		 1. _pNode 在head的位置
		 2. _pNode 左子树存在
		 3. _pNode 左子树不存在
		 */

		 // 1. _pNode 在head的位置，--应该将_pNode放在红黑树中最大节点的位置
		 //    _pNode->_pParent->_pParent == _pNode 可判断出_pNode在根或者head
		 //    _pNode->_color == RED 可排除根节点
		 if (_pNode->_pParent->_pParent == _pNode && _pNode->_color == RED)
			 _pNode = _pNode->_pRight;
		 else if (_pNode->_pLeft)
		 {
			 // 2. _pNode的左子树存在
			 //   在左子树中找最大的节点即可，最大的节点即左子树中最右侧节点
			 _pNode = _pNode->_pLeft;
			 while (_pNode->_pRight)
				 _pNode = _pNode->_pRight;
		 }
		 else
		 {
			 /*
			 3. _pNode的左子树不存在
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

			 _pNode如果在节点7的位置，该节点没有左子树，只能向上找
			 _pNode-->7  pParent-->8   _pNode == pParent->_pLeft
			 _pNode-->8  pParent-->4   _pNode != pParent->_pLeft
			 结束后：需将_pNode置于pParent的位置

			 _pNode如果在节点3的位置，注意3是红黑树中最小的节点，不能进行--操作，因此该种情
			 况不需要考虑
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
	 // 在红黑树中插入data的键值对
	 // 若data中的key已经在红黑树中，则插入失败，返回<该节点的Iterator, false>
	 // 若data中的key不存在，则插入成功，返回<新节点的迭代器, true>
	 pair<Iterator, bool> Insert(const ValueType& data)
	 {
		 PNode& pRoot = GetRoot();
		 PNode pNewNode = nullptr;
		 // 树为空
		 if (nullptr == pRoot)
		 {
			 pNewNode = pRoot = new Node(data, BLACK);
			 pRoot->_pParent = _pHead;
		 }
		 else
		 {
			 // 非空
			 // 1. 按照二叉搜索树的规则插入新节点
			 // ...

			 // 2. 新节点插入后如果破坏红黑树的性质，对红黑树进行旋转着色处理
			 // ...
		 }

		 // 调整头节点中左右指针域的指向以及根节点的颜色
		 _pHead->_pLeft = LeftMost();
		 _pHead->_pRight = RightMost();
		 pRoot->_color = BLACK;
		 ++_size;

		 return make_pair(Iterator(pNewNode), true);
	 }

	 // 将红黑树中的节点清空
	 void Clear()
	 {
		 _DestroyRBTree(GetRoot());
		 _pHead->_pLeft = _pHead;
		 _pHead->_pRight = _pHead;
		 _size = 0;
	 }

	 // 如果key存在，返回key的位置,否则返回end
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

		 // 返回end的位置
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

	 // 获取红黑树中最左侧节点
	 PNode LeftMost()
	 {
		 PNode pCur = GetRoot();

		 if (nullptr == pCur)
			 return _pHead;

		 while (pCur->_pLeft)
			 pCur = pCur->_pLeft;

		 return pCur;
	 }

	 // 获取红黑树中最右侧节点
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
	 PNode _pHead;  // 红黑树头指针
	 size_t _size;  // 红黑树中有效节点的个数
 };

#if 1
	 template<class K, class V>
	 class Map
	 {
		 typedef pair<K, V> ValueType;

		 // 该内部类的作用是：将value中的key提取出来
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

		 // 该内部类的作用是：将value中的key提取出来
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
		 // 用<单词，单词出现次数>构建键值对，然后将vector中的单词放进去，统计每个单词出现的次数
		 map<string, int> m;
		 for (size_t i = 0; i < words.size(); ++i)
			 ++(m[words[i]]);

		 // 将单词按照其出现次数进行排序
		 multiset<pair<string, int>, Compare> ms(m.begin(), m.end());

		 // 将相同次数的单词放在set中，然后再放到vector中
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
				 // 相同次数的单词已经全部放到set中
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