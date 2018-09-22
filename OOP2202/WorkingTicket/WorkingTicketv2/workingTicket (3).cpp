/*
	WorkingTicket
	
	About***
	
	@Author 	Zachary King 			& David Oakes 100627317
	@Version 	1
	@Since 		9/13/2018


This is a program to help users to log IT support requests from clients.
To do this we create a class for the ticket. It includes 
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
		
		string toString() const; // to string method returning the entire ticket
		
		// mutator
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
	
	tempYear = 2000;
	
	
	//input
	
	for ( int i; i < TICKET_ARRAY; i++ )
	{
		ClearInputBuffer();
		
		cout << "\nEnter your date for ticket number: " << i+1 << endl;
		cout << "day: ";
		tempDay = GetValidInteger(MINIMUM_DAY, MAXIMUM_DAY);
		cin.clear();
		cout << "month: ";
		tempMonth = GetValidInteger(MINIMUM_MONTH, MAXIMUM_MONTH);
		cout << "year: ";
		tempYear = GetValidInteger(MINIMUM_YEAR, MAXIMUM_YEAR);
		WorkingTicket::myNumber ++;
		
		//totalTickets[i].SetDate(tempDay, tempMonth, tempYear);	//set date
		

		//add client ID here
		cout << "\nEnter the client ID." << endl;
		
		cin >> tempClientID;
		
		cout << "\nEnter the description." << endl;
		cin >> tempDescription;
		//add ticket description here
		//cout <<"\nEnter the support description." << endl;
		//cin >> totalTickets[ticketNumber].myDescription;
		
		validation = totalTickets[i].SetWorkTicket(i+5, tempDay, tempMonth, tempYear, tempClientID, tempDescription);
		
		if(!validation)
		{	
			cout << "\nThe work ticket failed" << endl;
		}
		
			for ( int t; t < TICKET_ARRAY; t++)
	{
		cout << "\n\n*************************************************\n\n\n"
		<< totalTickets[t].toString()
		<<"\n\n*************************************************" << endl;
	}
	}
	cout << "gt";
	//output
	for ( int t; t < TICKET_ARRAY; t++)
	{
		cout << "\n\n*************************************************\n\n\n"
		<< totalTickets[t].toString()
		<<"\n\n*************************************************" << endl;
	}
	//	cout << "the ticket:" << totalTickets[i] <<  " was: " << totalTickets[i].toString();
	cout << "gt";
}
// output layout - needs to add the rest of the output for the ticket
string WorkingTicket::toString() const
{
	stringstream strOut;
	strOut 	<< "Ticket number:" << myNumber << endl
			<< "Date:" << myDay << " " << myMonth << " " << myYear << endl
			<< "Client ID: " << myClientID << endl
			<< "Description: " << myDescription << endl;
	return strOut.str(); 
}

bool WorkingTicket::SetWorkTicket(int i, int tempDay, int tempMonth, int tempYear, string clientID, string description)		//sets the entire ticket
{
	SetDay(tempDay);
	SetMonth(tempMonth);
	SetYear(tempYear);
	SetClientID(clientID);
	SetDescription(description);
	return true;
}
