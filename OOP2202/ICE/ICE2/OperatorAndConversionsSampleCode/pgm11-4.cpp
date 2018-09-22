/* pgm11-4.cpp - Chapter 11 Sample Program

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
		
		Date operator=(const Date & dateToCopy);  // assignment operator prototype
		
		void ShowDate() const;   // member function to display a date
};

int main()
{
	Date testDate1(4,1,1999);
	Date testDate2(12,18,2012);
	Date testDate3(1,1,2014); // declare three objects
	
	cout << "Before assignment testDate1's date value is ";
	testDate1.ShowDate();
	cout << "\nBefore assignment testDate2's date value is ";
	testDate2.ShowDate();
	cout << "\nBefore assignment testDate1's date value is ";
	testDate3.ShowDate();
	
	testDate1 = testDate2 = testDate3;    // multiple assignment
	
	cout << "\n\nAfter assignment testDate1's date value is ";
	testDate1.ShowDate();
	cout << "\nAfter assignment testDate2's date value is ";
	testDate2.ShowDate();
	cout << "\nAfter assignment testDate1's date value is ";
	testDate3.ShowDate();
	
	cout << endl << endl;
	return 0;
}


//The new assignment operator returns an object of type Date
Date Date::operator=(const Date& dateToCopy)
{
	myDay = dateToCopy.myDay;        // assign the day
	myMonth = 10; //dateToCopy.myMonth;    // assign the month
	myYear = dateToCopy.myYear;      // assign the year
	
	return *this;
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


