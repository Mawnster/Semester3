/*  tm_io.cpp - Chapter 11 Sample Program
	- Adding I/O operators to the Date class.
	
	Modified by: T. MacDonald, 3 Oct 2016
	For: OOP 3200 - OOP II
	Reference:
	Bronson, G. (2011). A First Book of testDate3++, Fourth Edition. Course Technology.
*/

#include <iostream>
#include <iomanip>
using namespace std;

// class declaration section
class Date
{
	private:
		int myMonth; // 1 - 12  
		int myDay; 	 // 1 - 30, 360 days in a year
		int myYear;  
	public:
		Date(int month = 10, int day = 3, int year = 2016) { SetDate(month, day, year); };  // constructor
		// To-Do: Add Accessors, Mutators, Validation, etc.
		
		void SetDate(int, int, int); // mutator - member method to copy a date
		
		friend ostream& operator<<(ostream&, const Date&);
		friend istream& operator>>(istream&, Date &);
    
};

int main()
{
	// Create a Date object
	Date aDate;
	
	// User input into the Date object using cin.
	cout << "Please enter a date: ";
	while (!(cin >> aDate)) // loop while cin has failed
	{
		cin.clear(); // clear the fail flag
		cin.sync();  // empty the input buffer
		cout << "Input error. Please try again in the format mm/dd/yyyy: "; // re-prompt
	}
	
	// Output the date using cout.
	cout << endl << aDate << endl;
	
	cout << endl << endl;
	return 0;
}

// class implementation section
void Date::SetDate(int month, int day, int year)
{
	// To-do: Add validation.
	myMonth = month;
	myDay = day;
	myYear = year;
}

ostream& operator<<(ostream &out, const Date& theDate)
{
    out << setfill('0')
         << setw(2) << theDate.myMonth << '/'
         << setw(2) << theDate.myDay << '/'
         << setw(2) << theDate.myYear % 100 // extract the last 2 year digits
         << setfill(' ');
         
    return out;          
}

istream& operator>>(istream &in, Date& theDate)
{
    // Temporary variables 
	int month;
	int day;
	int year;
	
	// Extract month/day/year from the input stream
	in >> month;
    in.ignore(1);
    in >> day;
    in.ignore(1);
    in >> year;
    
    // if the input stream has not failed
    if(!in.fail())
    {
    	theDate.SetDate(month, day, year); // Set the Date object's attributes
	}
	
    return in;          
}


