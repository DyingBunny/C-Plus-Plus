//������һ��m��n�еķ���һ�������˴�����(0,0)�ĸ��ӿ�ʼ�ƶ�����ÿһ�ο�����
//���������ƶ�һ�񣬵����ܽ�������������������λ֮�ʹ���k�ĸ��ӡ����磬��kΪ
//18ʱ���������ܹ����뷽��(35,37),��Ϊ3+5+3+7=18���������ܽ��뷽��(35,38),��Ϊ
//3+5+3+8=19�����ʸû������ܹ�������ٸ����ӣ�

#include "iostream"
#include "vector"

//using namespace std;
//
//bool condition(int x, int y, int k)
//{
//	if (x < 0 || y < 0 || k < 0)
//		return false;
//	int count = 0;
//	while (x || y)
//	{
//		count += x % 10;
//		count += y % 10;
//		x = x / 10;
//		y = y / 10;
//	}
//	return count <= k;
//}
//
//void backTracking(bool* reachable, int nextX, int nextY, int k, int m, int n, int* count)
//{
//	if (!condition(nextX, nextY, k))
//		return;
//
//	if (nextX >= 0 && nextY >= 0 && nextX < m && nextY < n && !reachable[nextX*m + nextY])
//	{
//		++*count;
//		reachable[nextX*m + nextY] = true;
//		backTracking(reachable, nextX - 1, nextY, k, m, n, count);
//		backTracking(reachable, nextX + 1, nextY, k, m, n, count);
//		backTracking(reachable, nextX, nextY - 1, k, m, n, count);
//		backTracking(reachable, nextX, nextY + 1, k, m, n, count);
//	}
//}
//
//
//int movable(int m, int n, int k)
//{
//	int total = m * n;
//	bool* reachable = new bool[total];
//	for (int i = 0; i < total; ++i)
//		reachable[i] = false;
//
//	int count = 0;
//	backTracking(reachable, 0, 0, k, m, n, &count);
//
//	delete[] reachable;
//	return count;
//}
//
//void test()
//{
//	int m = 12, n = 12, k = 9;
//	cout << movable(m, n, k) << endl;
//}
//
//int main()
//{
//	test();
//	return 0;
//}
//
//class Solution {
//public:
//
//	int movingCount(int threshold, int rows, int cols)
//	{
//		int ** mark = new int *[rows]; //��¼�Ƿ��Ѿ��߹�
//		for (int i = 0; i < rows; ++i){
//			mark[i] = new int[cols];
//		}
//
//		return DFS(0, 0, rows, cols, mark, threshold);
//	}
//
//private:
//
//	int DFS(int x, int y, int rows, int cols, int** mark, int threshold){
//		if (x < 0 || y < 0 || x >= rows || y >= cols || mark[x][y] == 1 || numOfSum(x) + numOfSum(y) > threshold){
//			return 0;
//		}
//		mark[x][y] = 1;
//		return DFS(x + 1, y, rows, cols, mark, threshold) + DFS(x - 1, y, rows, cols, mark, threshold) + 
//			DFS(x, y + 1, rows, cols, mark, threshold) + DFS(x, y - 1, rows, cols, mark, threshold) + 1;
//	}
//
//	int numOfSum(int x){
//		int sum = 0;
//		while (x){
//			sum += x % 10;
//			x /= 10;
//		}
//
//		return sum;
//	}
//};

int main()
{
	int input = -5;
	std::cout << input << std::endl;
	//input >>= 1;
	std::cout << abs(input) << std::endl;
	return 0;
}