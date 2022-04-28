#include "Book.h"

string Book::get_Name()
{
	return this->name;
}

void Book::setName(string name)
{
	this->name = name;
}

double Book::get_Price()
{
	return this->price;
}

void Book::SetPrice(double price)
{
	this->price = price;
}

