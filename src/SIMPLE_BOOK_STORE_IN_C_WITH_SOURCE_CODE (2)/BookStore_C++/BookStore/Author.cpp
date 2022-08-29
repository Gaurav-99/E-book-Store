#include "Author.h"

Author::Author()
{
	idNumber = 1234;
	yearOfDeath = 1234;
}

int Author::getIdNumber() const
{
	return idNumber;
}

int Author::getYearOfDeath() const
{
	return yearOfDeath;
}

void Author::setIdNumber(const int newIdNumber)
{
	idNumber = newIdNumber;
}

void Author::setYearOfDeath(const int newYearOfDeath)
{
	yearOfDeath = newYearOfDeath;
}

void Author::printAuthorInfo() const
{
	printName();
	cout << idNumber << ' ' << getDateOfBirth() << '-' << yearOfDeath << endl;
}

Author::~Author()
{

}
