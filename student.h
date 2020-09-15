#include <iostream>
#include "degree.h"
#include "roster.h"
using namespace std;

// Create the Student class
class Student {			
	
	// Student class' public functions
	public:				
		const static int numOfDaysSize = 3;
	
	// Student class' private data members
	private:			
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int studentAge;
		double numOfDays[numOfDaysSize];
		DegreeProgram degreeProgram;
	
	public:				
		Student();		// Default constructor
		Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, double numOfDays[], DegreeProgram degreeProgram);	// Constructor with parameters
		// FIXME: Destructor

		/* Accessors */
		string getID();
		string getFirstName();
		string getLastName();
		string getEmail();
		int getAge();
		double* getNumDays();
		DegreeProgram getDegreeProgram();

		/* Mutators */
		void setID(string studentID);
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setEmail(string emailAddress);
		void setAge(int studentAge);
		void setNumDays(double numOfDays[]);
		void setDegreeProgram(DegreeProgram dp);

		void print();	// Function to print specific student's data 
};													






