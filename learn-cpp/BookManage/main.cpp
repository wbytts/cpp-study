#include <iostream>
#include <fstream>
#include <string>
#include<conio.h>
#include "BookE.h"
#include "BookList.h"
using namespace std;

BookList list;

void welcome();
void mainMenu();
void add_book();
void search_book();

int main()
{
    list.ReadBook();
    list.ShowBook(1);
    // welcome();
    mainMenu();

    return 0;
}

void welcome()
{
    system("cls");
    cout << "####################################" << endl;
    cout << "图书管理系统" << endl;
    cout << "####################################" << endl;
    cout << "按任意键继续......" << endl;
}

void mainMenu()
{
    while (1)
    {
        system("cls");
        cout << "1. 图书输入" << endl;
        cout << "2. 图书查询" << endl;
        cout << "3. 图书删除" << endl;
        cout << "4. 图书浏览" << endl;
        cout << "5. 图书修改" << endl;
        cout << "6. 保存图书" << endl;
        cout << "7. 退出系统" << endl;
        cout << "请选择你的功能: ";
        int ch;
        cin >> ch;
        switch (ch)
        {
        case 1:
            add_book();
            break;
        case 2:
            search_book();
            break;
        case 3:break;
        case 4:
            system("cls");
            list.ShowBookTitle();
            list.ShowAll();
            system("pause");
            break;
        case 5:break;
        case 6:
            system("cls");
            list.WriteBook();
            cout << "保存成功" << endl;
            system("pause");
            break;
        case 7:
            exit(0);
            break;
        }
    }
}

void add_book()
{


    while (1)
    {
        system("cls");
        string name, isbn, pub, writer;
        double price;
        int quantity;
        cout << "请输入书名:";
        cin >> name;
        cout << "请输入价格:";
        cin >> price;
        cout << "请输入ISBN编号:";
        cin >> isbn;
        cout << "请输入出版社:";
        cin >> pub;
        cout << "请输入作者:";
        cin >> writer;
        cout << "请输入数量:";
        cin >> quantity;
        BookE be(name, price, isbn, pub, writer, quantity);
        list.Insert(be);
        cout << "添加成功!" << endl;

        cout << "------------------------" << endl;;
        cout << "1. 继续添加" << endl;
        cout << "2. 返回" << endl;
        cout << "请选择: ";
        int ch;
        cin >> ch;
        while (ch != 1 && ch != 2)
        {
            cout << "选项错误，重新选择: ";
            cin >> ch;
        }
        if (ch == 2)
        {
            break;
        }
    }
}

void search_book()
{
    while (1)
    {
        system("cls");
        cout << "1. 按图书名称查询" << endl;
        cout << "2. 按ISBN编号查询" << endl;
        cout << "3. 根据作者查询" << endl;
        cout << "4. 根据出版社查询" << endl;
        cout << "请选择: ";
        int ch;
        cin >> ch;
        while (ch != 1 && ch != 2 && ch != 3 && ch != 4)
        {
            cout << "选项错误，重新选择: ";
            cin >> ch;
        }

        int pos = -1;
        if (ch == 1)
        {// 按图书名称查询
            string name;
            cout << "请输入图书名称: ";
            cin >> name;
            pos = list.Search(name);
        }
        else if (ch == 2)
        {// 按ISBN编号查询
            string isbn;
            cout << "请输入ISBN编号:";
            cin >> isbn;
            pos = list.SearchIsbn(isbn);
        }
        else if (ch == 3)
        {// 根据作者查询
            string writer;
            cout << "请输入作者: ";
            cin >> writer;
            pos = list.SearchWriter(writer);
        }
        else if (ch == 4)
        {// 根据出版社查询7
            string publisher;
            cout << "请输入出版社:";
            cin >> publisher;
            pos = list.SearchPublisher(publisher);
        }
        cout << "-------------------------" << endl;
        cout << "查询结果为:" << endl;

        if (pos == -1)
        {
            cout << "未找到" << endl;
        }
        else
        {
            list.ShowBookTitle();
            list.ShowBook(pos);
        }
        cout << "------------------------" << endl;;
        cout << "1. 继续查询" << endl;
        cout << "2. 返回" << endl;
        cout << "请选择: ";
        cin >> ch;
        while (ch != 1 && ch != 2)
        {
            cout << "选项错误，重新选择: ";
            cin >> ch;
        }
        if (ch == 2)
        {
            break;
        }
    }
}