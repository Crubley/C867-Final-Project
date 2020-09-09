#pragma once
#include <iostream>
using namespace std;

enum DegreeProgram(SECURITY, NETWORK, SOFTWARE);	// Enumerated data type for various program degrees


class Student {			// Create the Student class
	public:					// Student class' public functions
		void SetStudentID(int studentID);			// studentID mutator
		void SetFirstName(string firstName);		// firstName mutator
		void SetLastName(string lastName);			// lastName mutator
		void SetEmailAddress(string emailAddress);	// emailAddress mutator
		void SetAge(int studentAge);				// studentAge mutator
		int SetNumOfDays[3];						// array of number of days to complete each course

	private:				// Student class' private functions

};													






