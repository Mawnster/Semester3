/* 	pgm11-1.cpp - Chapter 11 Sample Program
	- Overloading the equality operator in the Date class.
	
	Modified by: T. MacDonald, 3 Oct 2016
	For: OOP 3200 - OOP II
	Reference:
	Bronson, G. (2011). A First Book of C++, Fourth Edition. Course Technology.
*/

#include <iostream>
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
		// To-Do: Add Accessors i.e. GetMonth, GetDay, GetYear, etc.
		// To-Do: Add Mutators i.e. SetMonth, SetDay, SetYear, etc.
		// To-Do: Add a helper function for validation
		
		bool operator==(const Date& right) const;  // prototype for the operator== function
		bool operator!=(const Date& right) const {return !(*this == right); }
};

int main()
{
	Date testDate1(4, 1, 2012); 
	Date testDate2(12, 18, 2010);
	Date testDate3(4, 1, 2012); // declare 3 objects
	
	if (testDate1 != testDate2)
	{
		cout << "Test dates 1 and 2 are different." << endl;
	}
	else
	{
		cout << "Test dates 1 and 2 are not the same." << endl;
	}
	
	//if (testDate1 == testDate3)
	if(testDate1.operator==(testDate3))
	{
		cout << "Test dates 1 and 3 are the same." << endl;
	}
	else
	{
		cout << "Test dates 1 and 3 are not the same." << endl;
	}
	cout << endl << endl;
	return 0;
}

// class implementation section
Date::Date(int month, int day, int year)
{
	// To-do: Add validation.
	myMonth = month;
	myDay = day;
	myYear = year;
}

bool Date::operator==(const Date& right) const
{
	return (myDay == right.myDay 
		&& myMonth == right.myMonth 
		&& myYear == right.myYear);
}
