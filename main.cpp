using namespace std; 
#include <iostream>
#include "roster.h"
#include "student.h"
#include "degree.h"
#include <iostream>

int main()
{

	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY,",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK,",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE,",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY,",
		"A5,Dan,Bowering,dboweri@wgu.edu,38,25,40,35,SOFTWARE,"
	};

	// Print out my information
	cout << "Course C867: Scripting and Programming - Applications" << endl;
	cout << "Written in: C++" << endl;
	cout << "Written by: Dan Bowering" << endl;
	cout << "Student ID: #000811635" << endl;
	cout << "******************************" << endl;

	const static int numStudents = 5;
	int i;

	// Create an instance of the Roster class called classRoster
	Roster classRoster;

	// Add each student to classRoster
	for (int i = 0; i < numStudents; i++)
	{
		classRoster.parse(studentData[i]);
	}

	// Print all student data
	cout << "Displaying all student data: " << endl;
	classRoster.printAll();
	cout << endl;
	cout << endl;

	// Show invalid emails
	cout << "Displaying students with invalid email addresses: " << endl;
	classRoster.printInvalidEmails();
	cout << endl;
	cout << endl;

	// Loops through classRoster and prints average days in course for each student
	cout << "Displaying average number of days spent in all courses by student: " << endl;
	for (int i = 0; i < numStudents; i++)
	{
		string thisID = "A" + to_string(i + 1);
		classRoster.printAverageDaysInCourse(thisID);
	}
	cout << endl;
	cout << endl;

	// Prints all data for students in the SOFTWARE degree program
	cout << "Displaying all students in the Software Degree Program: " << endl;
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << endl;
	cout << endl;

	// Remove student with the student ID = A3
	cout << "Removing student with Student ID: A3 " << endl;
	classRoster.remove("A3");
	cout << endl;
	classRoster.printAll();
	cout << endl;
	cout << endl;

	// Try to remove student with the student ID = A3 again
	cout << "Removing student with Student ID: A3 " << endl;
	classRoster.remove("A3");
	cout << endl;
	cout << endl;

	system("pause");
	return 0;
}