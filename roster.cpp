#include "roster.h"
#include "student.h"
#include "degree.h"

// Parse row to extract student data
void Roster::parse(string studentData)
{
	// Find the first comma
	int rightSide = studentData.find(",");
	string sID = studentData.substr(0, rightSide);	// Extracts the string to the left of the first comma = student ID

	// Extracts the string between the next set of commas = first name
	int leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);
	string fn = studentData.substr(leftSide, rightSide - leftSide);

	//  Extracts the string between the next set of commas = last name
	leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);
	string ln = studentData.substr(leftSide, rightSide - leftSide);

	//  Extracts the string between the next set of commas = email address
	leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);
	string em = studentData.substr(leftSide, rightSide - leftSide);

	//  Extracts the string between the next set of commas = age
	leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);
	double age = stod(studentData.substr(leftSide, rightSide - leftSide));

	//  Extracts the string between the next set of commas = number of days 1, 2 & 3
	leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);
	double nod1 = stod(studentData.substr(leftSide, rightSide - leftSide));

	leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);
	double nod2 = stod(studentData.substr(leftSide, rightSide - leftSide));

	leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);
	double nod3 = stod(studentData.substr(leftSide, rightSide - leftSide));

	leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);
	string degree = studentData.substr(leftSide, rightSide - leftSide);

	DegreeProgram dp;
	if (degree.substr() == "SECURITY") {	// Check the string to determine degeree program
		dp = SECURITY;
	}
	else if (degree.substr() == "NETWORK") {
		dp = NETWORK;
	}
	else if (degree.substr() == "SOFTWARE") {
		dp = SOFTWARE;
	}

	// Add parsed data to row
	add(sID, fn, ln, em, age, nod1, nod2, nod3, dp);
}

// Add parsed data to row 
void Roster::add(string sID, string sFirstName, string sLastName, string sEmail, int sAge, double sDays1, double sDays2, double sDays3, DegreeProgram dp)
{
	// Array to hold number of days 
	double daysArray[3] = {static_cast<double>(sDays1), static_cast<double>(sDays2), static_cast<double>(sDays3)};

	// Make the new Student object
	classRosterArray[++lastIndex] = new Student(sID, sFirstName, sLastName, sEmail, sAge, daysArray, dp);
}

// Removes students by student ID. Prints error message if student ID is not found.
void Roster::remove(string studentID)
{
	bool found = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getID() == studentID)
		{
			found = true;
			if (i < numStudents - 1)
			{
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;
		}
	}
	if (found)
	{
		cout << "The student with Student ID: " << studentID << " has been removed from the roster." << endl;
	}
	else
		cout << "student ID: " << studentID << " was not found." << endl;
}

// Prints all student data
void Roster::printAll()
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		cout << classRosterArray[i]->getID() << '\t';
		cout << classRosterArray[i]->getFirstName() << '\t';
		cout << classRosterArray[i]->getLastName() << '\t';
		cout << classRosterArray[i]->getEmail() << '\t';
		cout << classRosterArray[i]->getAge() << '\t';
		cout << classRosterArray[i]->getNumDays()[0] << ", ";
		cout << classRosterArray[i]->getNumDays()[1] << ", ";
		cout << classRosterArray[i]->getNumDays()[2] << '\t';
		cout << degreeProgramStrings[classRosterArray[i]->getDegreeProgram()] << endl;
	}
}

// Prints student data by a specified degree program 
void Roster::printByDegreeProgram(DegreeProgram dp)
{
	for (int i = 0; i <= Roster::lastIndex; i++) 
	{
		if (Roster::classRosterArray[i]->getDegreeProgram() == dp)
			classRosterArray[i]->print();
	}
}

// Prints a student's average number of days in the three courses
void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (this->classRosterArray[i]->getID() == studentID)
		{
			cout << "Student ID: " << classRosterArray[i]->getID();
			double average = (classRosterArray[i]->getNumDays()[0] + classRosterArray[i]->getNumDays()[1] + classRosterArray[i]->getNumDays()[2]) / 3.0;
			cout << " averages " << average << " days per course." << endl;
		}
	}
}

// Finds and prints any invalid email addresses 
void Roster::printInvalidEmails()
{
	bool invalidEmail = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string em = (classRosterArray[i]->getEmail());
		if (em.find('@') == string::npos || (em.find('.') == string::npos) || (em.find(' ') != string::npos))
		{
			invalidEmail = true;
			cout << "The following email addresses are invalid: " << classRosterArray[i]->getEmail() << endl;
		}
	}
	if (!invalidEmail) cout << "All email addresses are valid" << endl;
}




