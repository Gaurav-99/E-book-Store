#include "BookDatabase.h"

BookDatabase::BookDatabase()
{
	used = 0;
	capacity = 5;
	bookPtr = new Book[capacity];
}

void BookDatabase::addBook(const Book& newBook)
{
	if (used >= capacity)
	{
		cout << "Database is full, Doubling Size. . ." << endl;
		make_bigger();
	}
	bookPtr[used] = newBook;
	used++;
}
void BookDatabase::printall() const
{
	for (int i = 0; i < used; i++)
		bookPtr[i].printBook();
}

void BookDatabase::editBookAt(int index)
{

	cout << "What would you want to edit?" << endl;
	cout << " 1. Title" << endl;
	cout << " 2. BookID" << endl;
	cout << " 3. Author" << endl;
	cout << " 4. Publisher" << endl;
	cout << " 5. Publication Date" << endl;
	cout << " 6. Edition" << endl;
	cout << " 7. Cost" << endl;

	int choice, intEdit = 0;
	string stringEdit;

	cout << "\nEnter your choice: ";
	cin >> choice;
	cout << endl;

	while (choice != 8)
	{
		switch (choice)
		{
		case 1:
			cout << "Enter new Title" << endl;
			cin.ignore(1, ' ');
			getline(cin, stringEdit);
			bookPtr[index].setTitle(stringEdit);

			break;

		case 2:
			cout << "Enter new bookID" << endl;
			cin.ignore(1, ' ');
			getline(cin, stringEdit);
			bookPtr[index].setBookID(stringEdit);

			break;

		case 3:
			cout << "Enter new author" << endl;
			cin.ignore(1, ' ');
			getline(cin, stringEdit);
			bookPtr[index].setAuthor(stringEdit);

			break;
		case 4:
			cout << "Enter new Publisher" << endl;
			cin.ignore(1, ' ');
			getline(cin, stringEdit);
			bookPtr[index].setPublisher(stringEdit);

			break;

		case 5:
			cout << "Enter new publication date" << endl;
			cin >> intEdit;
			bookPtr[index].setPublication(intEdit);

			break;

		case 6:
			cout << "Enter new edition number" << endl;
			cin >> intEdit;
			bookPtr[index].setEdition(intEdit);

			break;

		case 7:
			cout << "Enter new cost" << endl;
			cin >> intEdit;
			bookPtr[index].setCost(intEdit);

			break;

		default:
			cout << "Invalid Selection" << endl;

			break;
		}

		cout << endl;
		system("Pause");
		cout << endl;
		cout << "What would you want to edit?" << endl;
		cout << " 1. Title" << endl;
		cout << " 2. BookID" << endl;
		cout << " 3. Author" << endl;
		cout << " 4. Publisher" << endl;
		cout << " 5. Publication Date" << endl;
		cout << " 6. Edition" << endl;
		cout << " 7. Cost" << endl;
		cout << "\nEnter your choice: ";
		cin >> choice;
		cout << endl;
	}

}

Book BookDatabase::getBook(int index) const
{	
	return bookPtr[index];
}

void BookDatabase::printBookTitle() const
{
	for (int i = 0; i < used; i++)
		cout << i + 1 <<". " << bookPtr[i].getTitle() << endl;
}

void BookDatabase::saveToFile(ofstream& out)
{
	if (used == 0)
		cerr << "There is nothing to save" << endl;
	else
	{
		for (int i = 0; i < used; i++)
			bookPtr[i].printBookToFile(out);

		out << endl;
		out << "END";
	}

}

void BookDatabase::make_bigger()
{
	Book *temp;
	temp = new Book[capacity * 2];
	for (int i = 0; i < used; i++)
		temp[i] = bookPtr[i];
	delete[] bookPtr;
	bookPtr = temp;
	capacity *= 2;
}

BookDatabase::~BookDatabase()
{

}