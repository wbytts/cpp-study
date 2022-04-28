#include <fstream>
using namespace std;
#include "BookList.h"


BookList::BookList()
{
	this->size = 0;
}

void BookList::Insert(BookE& be)
{
	this->booklist[this->size] = be;
	this->size++;
}

void BookList::ShowBook(int i)
{
	cout << this->booklist[i] << endl;
}

int BookList::Search(const string& name)
{
	for (int i = 0; i < this->size; i++)
	{
		if (name == this->booklist[i].get_Name())
		{
			return i;
		}
	}
	return -1;
}

int BookList::SearchIsbn(const string& isbn)
{
	for (int i = 0; i < this->size; i++)
	{
		if (isbn == this->booklist[i].get_isbn())
		{
			cout << (isbn == this->booklist[i].get_isbn()) << endl;
			cout << isbn << "==" << this->booklist[i].get_isbn() << endl;
			return i;
		}
	}
	return -1;
}

int BookList::SearchWriter(const string& writer)
{
	for (int i = 0; i < this->size; i++)
	{
		if (writer == this->booklist[i].get_writer())
		{
			return i;
		}
	}
	return -1;
}

int BookList::SearchPublisher(const string& publisher)
{
	for (int i = 0; i < this->size; i++)
	{
		if (publisher == this->booklist[i].get_publisher())
		{
			return i;
		}
	}
	return -1;
}

void BookList::Update(int i, string newName)
{
	this->booklist[i].setName(newName);
}

void BookList::Delete(int i)
{
	if (i < 0 || i >= this->size)
	{
		cout << "删除的索引超出范围" << endl;
		exit(1);
	}
	for (int j = i; j < this->size - 1; j++)
	{
		ShowBook(i);
	}
	this->size--;
}

void BookList::ShowBookTitle()
{
	cout << "书名\t价格\tISBN\t\t出版社\t\t作者\t数量" << endl;
}

void BookList::ShowAll()
{
	for (int i = 0; i < this->size; i++)
	{
		cout << this->booklist[i] << endl;;
	}
}

void BookList::WriteBook()
{
	ofstream outfile;
	outfile.open("book_list.dat", ios::binary);
	outfile.write((char*)this, sizeof(*this));
	outfile.close();
}

void BookList::ReadBook()
{
	ifstream infile;
	infile.open("book_list.dat", ios::binary);
	infile.read((char*)this, sizeof(*this));
	infile.close();
}
