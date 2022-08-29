#include "Book.h"
#include "BookDatabase.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const char STUDENT_DATA[] = "student_data.txt";

void createBookList(ifstream& infile, BookDatabase& Database)
{


	Book tempBook;
	string bookID,title,author,publisher;
	int publication, edition, cost, retailPrice;

	infile >> bookID;

	while (bookID != "END")
	{
		if (infile.peek() == ' ')
			infile.ignore();
		getline(infile, title);
		getline(infile, author);
		getline(infile, publisher);


		infile >> publication >> edition >> cost >> retailPrice;


		tempBook.setBook(bookID, title, author, publisher, publication, edition, cost, retailPrice);
		Database.addBook(tempBook);

		infile >> bookID;
	}
}

void readBookData(BookDatabase& Database)
{
	ifstream infile;

	infile.open(STUDENT_DATA);

	if (!infile)
	{
		cerr << "Input file does not exist." << endl;
		system("Pause");
		exit(1);
	}

	createBookList(infile, Database);

	infile.close();
}
