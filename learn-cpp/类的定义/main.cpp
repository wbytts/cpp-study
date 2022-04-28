#include <iostream>
using namespace std;

class Student
{
public:
    Student(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    ~Student()
    {

    }
private:
    string name;
    int age;
};

int main()
{
    return 0;
}