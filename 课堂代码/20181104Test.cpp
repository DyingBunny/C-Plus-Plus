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
 
 /*
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
 	//Test* p = new Test;
 	//delete[] p;
 
 	Test* p = new Test[10];
 	delete p;
 
 	return 0;
 }
 */
 
 /*
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
 	Test* p = new Test;
 
 	delete p;
 	return 0;
 }
 */

 
 





