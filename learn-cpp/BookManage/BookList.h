#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "BookE.h"

#define BOOK_LIST_SIZE 100 // 定义BookList 存储的最大图书数量（还是建议用动态的内存分配吧）

/*
	封装了BookE类的对象数组 booklist[]（数据成员）
	用于存放图书列表数据
*/
class BookList
{
private:
	int size; // 当前存储的图书的数量
	BookE booklist[BOOK_LIST_SIZE];
public:
	BookList();
	// 按指定图书名称、书号等信息输入一本图书信息
	void Insert(BookE& be);
	// 用于显示下标为i的图书信息
	void ShowBook(int i);
	// 用于按书名查找图书，返回找到的图书列表下标
	int Search(const string& name);
	// 用于按书号查找图书，返回找到的图书列表下标
	int SearchIsbn(const string& isbn);
	// 用于按作者查找图书，返回找到的图书列表下标
	int SearchWriter(const string& writer);
	// 用于按出版社查找图书，返回找到的图书列表下标
	int SearchPublisher(const string& publisher);
	// 用于修改下标为i的图书书名
	void Update(int i, string newName);
	// 用于删除下标为i的图书列表项
	void Delete(int i);
	// 用于显示图书馆信息表头
	void ShowBookTitle();
	// 用于输出（浏览）所有图书信息
	void ShowAll();
	// 用于将内存中的图书列表booklist[]信息输出（写入）到（磁盘）文件
	void WriteBook();
	// 用于将（磁盘）文件中的图书信息读入内存图书列表booklist[]
	void ReadBook();
};