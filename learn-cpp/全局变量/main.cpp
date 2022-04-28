#include <iostream>
using namespace std;

// 声明一下要用的函数（在另一个cpp里实现）
// 如果函数多了，这么写麻烦，可以写成 .h
void fun();

// 定义一个全局变量
int g_var = 3;

int main()
{
	// 在主函数中打印全局变量
	cout << g_var << endl;
	g_var = 4;
	// 调用另一个文件中的函数打印全局变量
	fun();

	return 0;
}