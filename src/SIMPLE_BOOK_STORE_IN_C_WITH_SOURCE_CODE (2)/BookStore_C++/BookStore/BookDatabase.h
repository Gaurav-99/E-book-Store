#ifndef BOOKDATABASE_H
#define BOOKDATABASE_H

#include "Book.h"
#include <iostream>

class BookDatabase
{
public:
	BookDatabase();
	void addBook(const Book& newBook);
	void printall() const;
	void editBookAt(int index);
	Book getBook(int index) const;
	void printBookTitle() const;
	void saveToFile(ofstream& out);
	~BookDatabase();
private:
	void make_bigger();
	Book* bookPtr;
	int capacity, used;
};
#endif // !BOOKDATABASE_H