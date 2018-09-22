/*
	WorkingTicket
	
	@Author 	Zachary King 100534535 			& David Oakes 100627317
	@Version 	1
	@Since 		9/13/2018
	
	About:

This is a program to help users to log IT support requests from clients.
To do this we create a class for the ticket. we set up an array of up to 3 objects so that the user can type in 3 tickets at a time
(This has to be 3 no less and no more) a header file is attached as MyInputValidation.h for validating user input to integers when called
It includes a constructor to set up all the default values of the class we than set up our accessors for later use. we than set up our mutators
 so that we can later edit the data of each class. we encapsulate the data members into the class as private. in our main we start with a for loop
 to iterate throguh each section checking for validation on entrys. Once it has gone through and validated everything it will than cyle to the next
 object. There is an array of 3 objects in total. after the third object is instanced it will display all 3 of the objects. At the very bottom
 we will have our methods declared. 
 
 
 FOR USERS:
 
 This program lets you add 3 working tickets. You must set the day (1-31) month (1-12) and year (2000-2099). After that you
 enter your client ID and than a description of your ticket, Once all 3 tickets are input it will display the tickets for you.  
*/

#include <cstdio>
#include<string>
#include <iostream>
#include <sstream>
#include "MyInputValidation.h"
using namespace myValidation;
using namespace std;


class WorkingTicket
{

	public:
		
		// constructor
		WorkingTicket() : myNumber(0), myDay(1), myMonth(1), myYear(2000), myClientID(""), myDescription("") {		}
		
		
		// accessor
		int getDay() const { return myDay; }
		int getMonth() const { return myMonth; }
		int getYear() const { return myYear; }
		
		string ShowWorkTicket() const; // to string method returning the entire ticket
		
		// mutator
		void SetNumber(int i) {  myNumber = i; }
		
		void SetDay(int x) {	myDay = x; }
		void SetMonth(int y) {	myMonth = y; }
		void SetYear(int z) {	myYear = z; }
		
		void SetDate(int x, int y, int z) { SetDay(x), SetMonth(y), SetYear(z); }
		
		void SetClientID(string clientID){			myClientID = clientID;};
		void SetDescription(string description){	myDescription = description;};
		
		bool SetWorkTicket(int i, int tempDay, int tempMonth, int tempYear, string clientID, string description);
		
		// private members
	private:
		int myNumber;
		int myDay;	 	
		int myMonth;
		int myYear;
		string myClientID;
		string myDescription;
		
};

int main() 
{
	//total arrays to 3 
	const int TICKET_ARRAY = 3;
	const int MINIMUM_YEAR = 2000;
	const int MAXIMUM_YEAR = 2099;
	const int MINIMUM_MONTH = 1;
	const int MAXIMUM_MONTH = 12;
	const int MINIMUM_DAY = 1;
	const int MAXIMUM_DAY = 31;
	
	//array of objects
	WorkingTicket totalTickets[TICKET_ARRAY];
	
	// temp variables for processing
	int tempDay;
	int tempMonth;
	int tempYear;
	string tempClientID;
	string tempDescription;
	bool validation;
	
	
	//input
	
	// this loop will go through each entry and validate it. It will display each entry in a readable fassion for the user to understand
	for ( int i=0; i < TICKET_ARRAY; i++ )
	{
		try 
		{
			ClearInputBuffer();
			cout << "\nEnter your date for ticket number: " << i+1 << endl;
			cout << "day: ";
			tempDay = GetValidInteger(MINIMUM_DAY, MAXIMUM_DAY);		//day value for the date of the ticket is entered and validated
			cout << "month: ";
			tempMonth = GetValidInteger(MINIMUM_MONTH, MAXIMUM_MONTH);	//month value for the date of the ticket is entered and validated
			cout << "year: ";
			tempYear = GetValidInteger(MINIMUM_YEAR, MAXIMUM_YEAR);		//year value for the date of the ticket is entered and validated
	
			cout << "\nEnter the client ID." << endl;					//client ID alphanumeric value for the ticket is entered
			cin.ignore();
			getline( cin, tempClientID);
		
			cout << "\nEnter the description." << endl;					//description for the ticket is entered
			cin.ignore();
			getline( cin, tempDescription );

		
			validation = totalTickets[i].SetWorkTicket(i+1, tempDay, tempMonth, tempYear, tempClientID, tempDescription);		//SetWorkTicket modifier is called and returns a boolean
		
			if(!validation)
			{	
				cout << "\nThe work ticket failed." << endl;
			}
		}
		catch (exception &ex) 
		{
		cerr << ex.what() << " Fatal Error ! Ending Program !" << endl;		
		}
	}
	//end of input
	//output
	
	
	for ( int t=0; t < TICKET_ARRAY; t++)
	{
		cout << "\n\n*************************************************\n\n\n"
		<< totalTickets[t].ShowWorkTicket()
		<<"\n\n*************************************************" << endl;
	}
}
// output layout - needs to add the rest of the output for the ticket
string WorkingTicket::ShowWorkTicket() const
{
	stringstream strOut;
	strOut 	<< "Ticket number:" << myNumber << endl
			<< "Date:" << myDay << " " << myMonth << " " << myYear << endl
			<< "Client ID: " << myClientID << endl
			<< "Description: " << myDescription << endl;
	return strOut.str(); 
}

// this will set the entire ticket 
bool WorkingTicket::SetWorkTicket(int i, int tempDay, int tempMonth, int tempYear, string clientID, string description)	
{
	SetNumber(i);
	SetDay(tempDay);
	SetMonth(tempMonth);
	SetYear(tempYear);
	SetClientID(clientID);
	SetDescription(description);
	return true;
}
