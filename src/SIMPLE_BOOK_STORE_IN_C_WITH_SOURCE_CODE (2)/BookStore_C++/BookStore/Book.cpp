#include "Book.h"

Book::Book()
{
	bookID = "";
	title = "";
	author = "";
	publisher = "";
	publication = 0;
	edition = 0;
	bookCondition = good;
	isSold = false;
}

void Book::setBook(const string& newBookID, const string& newTitle, const string& newAuthor, const string& newPublisher,
	int newPublication, int newEditon, int newCost, int newRetailPrice)
{
	bookID = newBookID;
	title = newTitle;
	author = newAuthor;
	publisher = newPublisher;
	publication = newPublication;
	edition = newEditon;
	cost = newCost;
	retailPrice = newRetailPrice;
	bookCondition = good;
}

void Book::addNewBook(istream& ins)
{
		cout << "Name: ";
		getline(ins, title);

		cout << "Enter Id Number ";
		getline(ins, bookID);

		cout << "Enter author: ";
		//if (ins.peek() == '\n')
		//	ins.ignore();
		getline(ins, author);

		cout << "Enter Publisher: ";
		getline(ins, publisher);
		
		cout << "Enter Publication Year: ";
		ins >> publication;

		cout << "Enter edition number: ";
		ins >> edition;

		cout << "Enter cost: ";
		ins >> cost;

		cout << "Enter retail price: ";
		ins >> retailPrice;

		cout << "Enter Condition of the Book";
		int newCondition = -1;
		while (newCondition < 0 || newCondition > 3)
		{
			ins >> newCondition;
			if (newCondition == 0)
				bookCondition = excellent;
			else if (newCondition == 1)
				bookCondition = good;
			else if (newCondition == 2)
				bookCondition = fair;
			else if (newCondition == 3)
				bookCondition = poor;
			else
				cout << "Invalid Entry, Try Again. ";
		}
}
string Book::getBookID() const
{
	return bookID;
}

string Book::getTitle() const
{
	return title;
}

string Book::getAuthor() const
{
	return author;
}
string Book::getPublisher() const
{
	return publisher;
}

condition Book::getCondition() const
{
	return bookCondition;
}

int Book::getPublication() const
{
	return publication;
}

int Book::getEdition()const
{
	return edition;
}

int Book::getCost() const
{
	return cost;
}

int Book::getRetail()const
{
	return retailPrice;
}

void Book::setBookID(const string& newID)
{
	bookID = newID;
}

void Book::setTitle(const string& newTitle)
{
	title = newTitle;
}

void Book::setAuthor(const string& newAuthor)
{
	author = newAuthor;
}

void Book::setPublisher(const string& newPublisher)
{
	publisher = newPublisher;
}

void Book::setCondition(condition& newCondition)
{
	bookCondition = newCondition;
}

void Book::setPublication(int newPublication)
{
	publication = newPublication;
}

void Book::setEdition(int newEdition)
{
	edition = newEdition;
}

void Book::setCost(int newCost)
{
	cost = newCost;
}

void Book::setRetailPrice(int newRetailPrice)
{
	retailPrice = newRetailPrice;
}

void Book::printBook() const
{
	cout << "Book ID: " << bookID << endl;
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;
	cout << "Publisher: " << publisher << endl;
	cout << "Published " << publication << endl;
	cout << "Edition: " << edition << endl;
	cout << "Condition: " << bookCondition << endl;

	if (isSold)
		cout << "Sold to" << endl;
	else
		cout << "In Stock" << endl;
	cout << endl;

}

void Book::printBookToFile(ofstream& out)
{
	out << bookID << " " << title << endl;
	out << author << endl;
	out << publisher << endl;
	out << publication <<" "<< edition << " "<< cost << " " << retailPrice << endl;
	out << endl;
}
Book::~Book()
{

}

istream& operator >> (istream& ins, Book& tempBook)
{
	tempBook.addNewBook(ins);
	return ins;
}
