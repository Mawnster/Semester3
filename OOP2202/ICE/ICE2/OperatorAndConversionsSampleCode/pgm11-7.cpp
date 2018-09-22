/* pgm11-7.cpp - Chapter 11 Sample Program
   - Adding a constructor to convert to a Date object
   
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
		Date(int = 10, int = 3, int = 2016);  // constructor
		// To-Do: Add Accessors, Mutators, Validation, etc.
		
		// constructor for converting from long to Date
		Date(long longFormatDate);
		void ShowDate() const;   // member function to display a date
};

int main()
{
	Date testDate1;   // initialized by the default constructor
	Date testDate2(20061225L);  // initialize with a long integer
	Date testDate3(4,1,2007);   // initialize with the specified values
	
	cout << "Test Dates 1, 2, and 3 are ";
	
	testDate1.ShowDate();
	cout << ", ";
	testDate2.ShowDate();
	cout << ", and ";
	testDate3.ShowDate();
	cout << ".\n";
	
	//testDate1 = Date(20160103L);  // convert a long to a Date
	testDate1 = (Date) 20160103L;  // convert a long to a Date
	
	cout << "Test Date 1 is now ";
	testDate1.ShowDate();  // convert a long to a Date.ShowDate();
	cout << ".\n";
	
	cout << endl << endl;
	return 0;
}

// class implementation section

// constructor for converting from long to Date
Date::Date(long longFormatDate)
{
	myYear = (int) (longFormatDate/10000.0);
	myMonth = (int) ((longFormatDate - myYear * 10000.0) / 100.0);
	myDay = (int) (longFormatDate - myYear * 10000.0 - myMonth * 100.0);
}

Date::Date(int month, int day, int year)
{
	// To-do: Add validation.
	myMonth = month;
	myDay = day;
	myYear = year;
}

void Date::ShowDate() const
{
	cout << setfill('0')
		<< setw(2) << myMonth << '/'
		<< setw(2) << myDay << '/'
		<< setw(2) << myYear % 100;
	return; // void
}

