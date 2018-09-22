/*
	WorkingTicket
	
	About***
	
	@Author 	Zachary King & ???
	@Version 	1
	@Since 		9/13/2018


Done so far the Basic layout for the WorkTicketDate, Defaults and some input 
Just need to add everything else and some validation. Let me know what else you need me to do 
and what you change/add, My validation was simply for testing i havent made any methods for it yet.
*/

#include <cstdio>
#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;
//int validTicketNumber();
class WorkingTicket
{

	public:
		
		// constructor
		WorkingTicket(int x = 1, int y = 1, int z = 2000, int ticket = 0) 
		: myDay(x), myMonth(y), myYear(z), myTicket(ticket) {		}
		
		// accessor
		int getDay() const { return myDay; }
		int getMonth() const { return myMonth; }
		int getYear() const { return myYear; }
		int getTicket() const { return myTicket; }
		
		// methods
		string toString() const; // to string method
		static validTicketNumber(int); // Whole positive number validation method
		
		// mutator
		void setDay(int x) { myDay = x; }
		void setMonth(int y) { myMonth = y; }
		void setYear(int z) { myYear = z; }
		void setTicket(int ticket) { myTicket = ticket; }
		void setDate( int x, int y, int z) { setDay(x), setMonth(y), setYear(z); }
		
		// private members
	private:
		int myDay;	 	
		int myMonth;
		int myYear;
		int myTicket;
};

int main() 
{
		
	//total arrays to 3 
	const int TICKET_ARRAY = 3;
	//array of objects
	WorkingTicket totalTickets[TICKET_ARRAY];
	// temp variables for processing
	int tempDay;
	int tempMonth;
	int tempYear;
	int tempTicket;
	int ticket;
	
	// loop to iterate through all 3 objects and set the values, Temporary validation for testing 
	for ( int ticketNumber; ticketNumber < TICKET_ARRAY; ticketNumber++ )
	{
		cout << "\nEnter your date for :" << (ticketNumber + 1) << endl;
		cout << "day: ";
		cin >> tempDay;
		cout << "month: ";
		cin >> tempMonth;
		cout << "year: ";
		cin >> tempYear;
		cout << "Enter your ticket Number: ";
		ticket = WorkingTicket::validTicketNumber(tempTicket);
		cout << ticket; 
		cout << "--------------------"; 
		
		//quick testing for requirements
		if ( tempDay >=1 && tempMonth >=1 && tempYear >=2000)
		{		
		totalTickets[ticketNumber].setDate(tempDay, tempMonth, tempYear);
		}
		else
		{
		}
		cout << "the date was: " << totalTickets[ticketNumber].toString();
	}
	
	
	
}


int WorkingTicket::validTicketNumber( int result )
{
	result = 0;
	cin >> result;

    //data type validation
    while (cin.fail() || result < 1)
    {
    	throw std::invalid_argument("Valie wasnt Numeric > 0");	
        cin.clear();
        cin.ignore();
        cout << "Enter a valid integer above 0: ";
        cin >> result;
    }
    return result;
}
    

/*int WorkingTicket::validTicketNumber(int result)
{
	if ( result < 1) 
	{
		cin.clear();
		cin.ignore();
		throw std::invalid_argument ("Working Ticket Number must be a whole number above 0!!!");
	}
	else 
	{
		return result;
	}
};*/
// output layout - needs to add the rest of the output for the ticket
string WorkingTicket::toString() const
{
	stringstream strOut;
	strOut << "day:" << myDay << " Month:" << myMonth  << " Year:"<< myYear;
	return strOut.str(); 
}
