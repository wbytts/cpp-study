#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class A
{
private:
    void fun();
};


void A::fun()
{

}

int main() 
{
    /*
        cout 是输出流
        << 是流插入运算符
        endl 换行
    */
    cout << "Hello World" << endl;

    /*
        cin 输入流
        >> 流提取运算符
        cin 输入的分隔符一般是 回车 Enter
    */
    int a;
    cin >> a;
    cout << "输入了:" << a << endl;

    // 控制输出的数字的进制
    /*
        dec         设置整数的基数为10
        hex         设置整数的基数为16
        oct         设置整数的基数为8
    */
    cout << "123 转换为各种进制的数字:" << endl;
    cout << dec << 123 << endl;
    cout << hex << 123 << endl;
    cout << oct << 123 << endl;
    cout << setbase(16) << 14 << endl;

    
    return 0;
}