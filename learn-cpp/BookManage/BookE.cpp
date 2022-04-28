#include "BookE.h"

string BookE::get_writer()
{
	return this->writer;
}

void BookE::setWriter(string writer)
{
	this->writer = writer;
}

string BookE::get_publisher()
{
	return this->publisher;
}

void BookE::setPublisher(string publisher)
{
	this->publisher = publisher;
}

int BookE::get_quantity()
{
	return this->quantity;
}

void BookE::setQuantity(int quantity)
{
	this->quantity = quantity;
}

string BookE::get_isbn()
{
	return this->isbn;
}

void BookE::setIsbn(string isbn)
{
	this->isbn = isbn;
}

// 这里使用外部函数重载，而不是成员函数重载
ostream& operator<<(ostream& output, const BookE& be)
{
	output
		<< ((Book)be).get_Name()
		<< "\t\t" << ((Book)be).get_Price()
		<< "\t\t" << be.isbn
		<< "\t\t" << be.publisher
		<< "\t\t" << be.writer
		<< "\t\t" << be.quantity
		;
	return output;
}
