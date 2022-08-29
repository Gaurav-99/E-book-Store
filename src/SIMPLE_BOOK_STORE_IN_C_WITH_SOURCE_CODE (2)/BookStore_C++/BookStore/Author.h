#ifndef AUTHOR_H
#define AUTHOR_H

#include "Person.h"
#include <string>

using namespace std;

class Author: public Person
{
public:
	Author();
	int getIdNumber() const;
	int getYearOfDeath() const;
	void setIdNumber(const int newIdNumber);
	void setYearOfDeath(const int newYearOfDeath);
	void printAuthorInfo() const;

	~Author();
private:
	int idNumber, yearOfDeath;
};
#endif