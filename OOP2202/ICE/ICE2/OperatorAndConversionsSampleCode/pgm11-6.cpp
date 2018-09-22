/* pgm11-6.cpp - Chapter 11 Sample Program
   - Adding a converstion operator to the Date class
		
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
		
		operator long();     // conversion operator prototype
		void ShowDate() const;   // member function to display a date
};

int main()
{
	Date testDate(4,1,2012);  // declare and initialize one object of type Date
	long value;            // declare an object of type long
	
	value = long(testDate);       // call the conversion function
	//value = (long) testDate;       // call the conversion function
	
	cout << "testDate's date is ";
	testDate.ShowDate();
	
	cout << "\n\nThis date, as a long integer, is " << value << endl;
	//cout << "\n\nThis date, as a long integer, is " << (long) testDate << endl;
	
	cout << endl << endl;
	return 0;
}

// class implementation section

// conversion operator definition for converting a Date to a long int
Date::operator long()   // must return a long, as its name implies
{
	long yyyymmdd;
	yyyymmdd = myYear * 10000 + myMonth * 100 + myDay;
	return yyyymmdd;
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







