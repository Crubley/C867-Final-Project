#pragma once
#include <iostream>
#include "degree.h"
using namespace std;


class Student {			// Create the Student class
	
	public:				// Student class' public functions
		const static int numOfDaysSize = 3;
	
	private:			// Student class' private data members
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int studentAge;
		int numOfDays[numOfDaysSize];
		DegreeProgram degreeProgram;
	
	public:				// Student class' public functions
		Student();		// Default constructor
		Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int numOfDays[], DegreeProgram degreeProgram);	// Constructor with parameters
		// FIXME: Destructor

		/* Accessors */
		string getID();
		string getFirstName();
		string getLastName();
		string getEmail();
		int getAge();
		int getNumDays();
		DegreeProgram getDegreeProgram();

		/* Mutators */
		void setID(string studentID);
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setEmail(string emailAddress);
		void setAge(int studentAge);
		void setNumDays(int numOfDays[]);
		void setDegreeProgram(DegreeProgram dp);

		void print();	// Function to print specific student's data 
};													






