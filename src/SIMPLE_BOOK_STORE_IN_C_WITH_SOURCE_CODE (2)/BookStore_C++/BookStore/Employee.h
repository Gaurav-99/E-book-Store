#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

using namespace std;
class Employee
{
public:
	//TODO::
	//ACCESSORS + MUTATORS
private:
	string lastName, firstName, address, city, state;
	int dateOfBirth, socialSecurity;
	double salary;
};
#endif // !EMPLOYEE_H