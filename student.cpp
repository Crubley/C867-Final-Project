#include "student.h"

Student::Student()		// Constructor set to default values
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->studentAge = 0;
	for (int i = 0; i < numOfDaysSize; i++) this->numOfDays[i] = 0;
	this->degreeProgram = DegreeProgram::UNDECIDED;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int numOfDays[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->studentAge = studentAge;
	for (int i = 0; i < numOfDaysSize; i++) this->numOfDays[i] = numOfDays[i];
	this->degreeProgram = degreeProgram;
}

// FIXME: Destructor

string Student::getID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmail() { return this->emailAddress; }
int Student::getNumDays() { return this->numOfDays; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

void Student::setID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmail(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setNumDays(int numOfDays[])
{
	for (int i = 0; i < numOfDaysSize; i++) this->numOfDays[i] = numOfDays[i];
}
void Student::setDegreeProgram(DegreeProgram) { this->degreeProgram = dp; }

void Student::print()
{
	cout << this->getID() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmail() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getNumDays[0] << ',';
	cout << this->getNumDays[1] << ',';
	cout << this->getNumDays[2] << ',';
	cout << this->getNumDays[3] << '\t';
	cout << degreeProgramStrings[this->getDegreeProgram()] << '\t';
}