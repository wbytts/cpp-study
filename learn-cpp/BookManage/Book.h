#pragma once
#include <iostream>
#include <string>
using namespace std;


class Book
{
private:
	string name;   // 书名
	double price;  // 价格
public:
	Book() {};
	Book(string name, double price) : name(name), price(price) {};
	string get_Name();				// 获取书名
	void setName(string name);		// 设置书名
	double get_Price();				// 获取价格
	void SetPrice(double price);	// 设置价格
};