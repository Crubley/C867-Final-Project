#pragma once
#include "student.h"
#include "degree.h"
#include <iostream>

using namespace std;

// Create the Roster class
class Roster {

private:
	int lastIndex = -1;
	const static int numStudents = 5;		// Set array size as a constant
	Student* classRosterArray[numStudents];		// Array to hold data provided in the student data table

public:
	void parse(string row);		// Method to parse through the string to extract student data
	void add(string sID,		// Method to add the parsed student data and create the object
		string sFirstName,
		string sLastName,
		string sEmail,
		int sAge,
		double sDays1,
		double sDays2,
		double sDays3,
		DegreeProgram dp);
	void remove(string sID);		// Method to find student by student ID and remove from the object
	void printAll();				// Method to print student data
	void printAverageDaysInCourse(string sID);		// Method to print a given student's average number of days in three courses
	void printInvalidEmails();		// Method to display all invalid email addresses
	void printByDegreeProgram(DegreeProgram dp);	// Method that prints student data based on the degree program

};