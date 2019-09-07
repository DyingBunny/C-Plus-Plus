#include<iostream>

using namespace std;

int main(){
	/*int i;
	char* ptr = "1";
	i = reinterpret_cast<char>(ptr);
	std::cout << i << std::endl;*/
	char *s = "1234";
	s[1] = '5';
	cout << *s << endl;
	return 0;
}