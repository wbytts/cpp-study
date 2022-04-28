#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Book.h"

class BookE : public Book
{
private:
	string isbn;  // 书号
	string publisher; // 出版社
	string writer; // 作者
	int quantity; // 数量
public:
	BookE() {};
	BookE(string name, double price, string isbn, string publisher
		, string writer, int quantity) :
		Book(name, price), isbn(isbn), publisher(publisher), 
		writer(writer), quantity(quantity) {};
	string get_writer(); // 获取作者
	void setWriter(string writer); // 设置作者
	string get_publisher(); // 获取出版社
	void setPublisher(string publisher); // 设置出版社
	int get_quantity(); // 获取数量
	void setQuantity(int quantity); // 设置数量
	string get_isbn();
	void setIsbn(string isbn);
	friend ostream& operator<<(ostream& output, const BookE& be);  // 流插入运算符重载
};