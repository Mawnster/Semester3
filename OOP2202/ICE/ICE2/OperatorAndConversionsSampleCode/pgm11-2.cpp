/* pgm11-2.cpp - Chapter 11 Sample Program
   - Adding arithmetic operators for the Date class
   
   Modified by: T. MacDonald, 3 Oct 2016
   For: OOP 3200 - OOP II
   Reference:
   Bronson, G. (2011). A First Book of C++, Fourth Edition. Course Technology.
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
		
		Date operator+(int daysAdded) const; // prototype for the + operator function
		//date operator-(int daysSubtracted) const;
		//int operator -(const date & right) const; 
		
		void ShowDate() const;     // member function to display a date
};

int main()
{
	Date oldDate(4,1,2011);
	Date newDate; // declare two objects
	
	cout << "The initial date is ";
	oldDate.ShowDate();
	cout << endl;
	
	newDate = oldDate + 284;   // add in 284 days = 9 months and 14 days
	
	cout << "The new date is ";
	newDate.ShowDate();
	
	cout << endl << endl;
	
	return 0;
}

// class implementation section

Date Date::operator+(int daysAdded) const
{
	Date futureDate;  // a temporary date to store the result
	
	futureDate.myDay = this->myDay + daysAdded;   // add the days
	futureDate.myMonth = this->myMonth;
	futureDate.myYear = this->myYear;
	
	while (futureDate.myDay > 30)    // adjust the months
	{
		futureDate.myMonth++;
		futureDate.myDay -= 30;
	}
	
	while (futureDate.myMonth > 12)  // adjust the years
	{
		futureDate.myYear++;
		futureDate.myMonth -= 12;
	}
	
	return futureDate;     // the values in temp are returned
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







