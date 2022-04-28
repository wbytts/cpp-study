#include <iostream>
using namespace std;

void fun()
{
	// 静态局部变量，在程序中只初始化一次，并且会一直保持其生命周期
	static int m = 3;

	m += 1;

	cout << m << endl;
}

int main()
{
	fun(); // 第一次调用，m初始化，函数结束后，m仍然存在
	fun(); // 第二次调用，m不再初始化，使用之前的值
	fun(); // 同上

	return 0;
}