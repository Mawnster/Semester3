/** MyDate_Test.cpp - Testing My Date Class 
 *	
 *	Testing the MyDate class.
 *   
 *	@author		Thom MacDonald <thom.macdonald@durhamcollege.ca>
 *	@author		
 *	@version	2014.02
 *	@since		7 Oct 2014
 *	@see		MyDate.h
 *	@see		
*/

#include <iostream> 	// for console I/O
#include <stdexcept>	// for standard exceptions
#include <cstdlib>		// for system
#include "MyDate.h"

using namespace std;

/** ShowMyDate (Testing Function)
 *	Displays a MyDate object to the console in 3 formats: 
 *	default (dd/mm/yyyy), as a string, and as a long.
 *  @param  date (MyDate) - the MyDate object to display
 */
inline void ShowMyDate(MyDate date) {cout << endl << date << " : " << (string) date << " (" << (long) date << ")" << endl;}

/** PauseAndClear
 *	Pauses and clears the Windows console.
 */
inline void PauseAndClear() { cout << endl << endl; system("pause"); system("cls");}


int main()
{
	try
	{
		// Testing Constructors
		MyDate date1;				// default constructor
		MyDate date2 (8, 10, 2014); // constructor (int, int, int)
		MyDate date3 = date2; 		// copy constructor
		MyDate date4 = 3652059L;	// constructor (long)
		
		// Output
		cout << "\n******************************************************" << endl;
		cout << "*                   Constructors                     *" << endl;
		cout << "******************************************************" << endl << endl;
		
		cout << "\nDefault Constructor: ";
		ShowMyDate(date1);
		cout << "\nParameterized (int, int, int) Constructor: ";
		ShowMyDate(date2);
		cout << "\nCopy Constructor: ";
		ShowMyDate(date3);
		cout << "\nParameterized (long) Constructor: ";
		ShowMyDate(date4);
		PauseAndClear();
		
		// Equality/Relational
		cout << "\n******************************************************" << endl;
		cout << "*           Equality/Relational Operators            *" << endl;
		cout << "******************************************************" << endl << endl;
		
		if(date1 != date2)
		{
			cout << date1 << " is not equal to " << (string) date2 << endl;
		}
		
		if(date2 == date3)
		{
			cout << date2 << " is equal to " << (string) date3 << endl;
		}
		
		if(date1 < date4) // change to <=
		{
			cout << date1 << " is less than " << (string) date4 << endl;
		}
		
		if(date4 >= date1) // change to > 
		{
			cout << date4 << " is greater than or equal to " << (string) date1 << endl;
		}
		PauseAndClear();
	
	
	    // Subscript
		cout << "\n******************************************************" << endl;
		cout << "*                  Subscript Operator                *" << endl;
		cout << "******************************************************" << endl << endl;
	
	 	cout << (string) date2 << endl;
	 	cout << "\n[\'d\']: " << date2['d'] << endl;
	 	cout << "\n[\'m\']: " << date2['m'] << endl;
	 	cout << "\n[\'y\']: " << date2['y'] << endl;
	 	PauseAndClear();
	
	    // IsLeapYear
		cout << "\n******************************************************" << endl;
		cout << "*            IsLeapYear() / IsLeapYear(int)          *" << endl;
		cout << "******************************************************" << endl << endl;
	
		date1.SetYear(2012);
		if(date1.IsLeapYear())
  		    cout << date1 << " is in a leap year!" << endl;
		
		if(MyDate::IsLeapYear(2016))
  		    cout << "2016 is a leap year!" << endl;
		PauseAndClear();
		
	    // Conversion
		cout << "\n******************************************************" << endl;
		cout << "*              MyDate <=> long conversion            *" << endl;
		cout << "******************************************************" << endl << endl;		
		
		date1 = 730000L;
		long daysSince = date1;
		
		cout << "\nMyDate Object: ";
		ShowMyDate(date1);
		cout << "\nlong Value: " << daysSince << endl;
		PauseAndClear();

	    // Assignment
		cout << "\n******************************************************" << endl;
		cout << "*                 Assignment Operators               *" << endl;
		cout << "******************************************************" << endl << endl;			

		date2 = date3 = date1; // multiple assignment
		date2 += 286; // add 286 days
		date3 -= 286; // subtract 286 days
		
		cout << "\n\nDate 1: ";
		ShowMyDate(date1);
		cout << "\n\nDate 2 (+= 284): ";
		ShowMyDate(date2);
		cout << "\n\nDate 3 (-= 284): ";
		ShowMyDate(date3);
		PauseAndClear();

	    // Input
		cout << "\n******************************************************" << endl;
		cout << "*              Extraction (Input) Operator           *" << endl;
		cout << "******************************************************" << endl << endl;
		cout << "Enter a date (dd/mm/yyyy): ";
		
		while(!(cin >> date1))
		{
			cin.clear(); // clear the fail flag
			cin.sync();  // empty the input buffer
			cout << "Input error. Please try again: "; // re-prompt
		}
		cout << "\nYou entered: " << date1 << endl;
		PauseAndClear();
		
	    // Increment/Decrement
		cout << "\n******************************************************" << endl;
		cout << "*            Increment/Decrement Operators           *" << endl;
		cout << "******************************************************" << endl << endl;		
		
		cout << "\nStarting   : " << date2 << endl << endl;
		
		cout << "\nPrefix ++  : " << ++date2 << endl;
		cout << "\nPostfix ++ : " << date2++ << endl;
		cout << "\nFinal      : " << date2 << endl;
		
		cout << "\n\nPrefix --  : " << --date2 << endl;
		cout << "\nPostfix -- : " << date2-- << endl;
		cout << "\nFinal      : " << date2 << endl;
		PauseAndClear();
		
  		// Today
		cout << "\n******************************************************" << endl;
		cout << "*                         Today                      *" << endl;
		cout << "******************************************************" << endl << endl;		
		cout << "\n       Today is " << (string) MyDate::Today() << endl;
		
	}
	catch(const exception& anException)
	{
		cout << anException.what() << endl;
	}

	return 0;
}


