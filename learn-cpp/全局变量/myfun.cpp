#include <iostream>

// extern 声明外部变量
extern int g_var;

void fun() {
	std::cout << g_var << std::endl;
}