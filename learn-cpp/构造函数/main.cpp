#include <iostream>
using namespace std;

class A
{
public:
    A() = default;
    A(int a)
    {
        this->a = a;
    }
private:
    int a;
};

int main()
{
    A a(123);



    return 0;
}