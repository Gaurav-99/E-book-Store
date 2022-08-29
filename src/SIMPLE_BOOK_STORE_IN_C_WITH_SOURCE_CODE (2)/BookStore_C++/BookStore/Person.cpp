#include "Person.h"

Person::Person()
{
	firstName = " ";
	lastName = " ";
	dateOfBirth = 1234;
}

string Person::getLastName() const
{
	return lastName;
}

string Person::getFirstName() const
{
	return firstName;
}

int Person::getDateOfBirth() const
{
	return dateOfBirth;
}

void Person::setName(const string& newLastName, const string& newFirstName)
{
	firstName = newFirstName;
	lastName = newLastName;
}

void Person::setDateOfBirth(const int newDateOfBirth)
{
	dateOfBirth = newDateOfBirth;
}

void Person::printName() const
{
	cout << lastName << ", " << firstName << ' ';
}

Person::~Person()
{

}