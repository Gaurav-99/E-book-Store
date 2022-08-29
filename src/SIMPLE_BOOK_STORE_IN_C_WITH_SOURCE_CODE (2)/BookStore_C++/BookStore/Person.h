#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

using namespace std;

class Person
{
public:
	Person();
	string getLastName() const;
	string getFirstName() const;
	int getDateOfBirth() const;
	void setName(const string& newLastName, const string& newFirstName);
	void setDateOfBirth(const int newDateOfBirth);
	void printName() const;

	~Person();

private:
	string lastName, firstName;
	int dateOfBirth;

};


#endif

