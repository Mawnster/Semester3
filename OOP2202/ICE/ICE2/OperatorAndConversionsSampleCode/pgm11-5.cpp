/* pgm11-5.cpp - Chapter 11 Sample Program
   - Object pointers as parameters
 	
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
		
		void ShowDate() const;  // member function to display a date
		void Swap(Date * ptrDateToSwap);  // method to swap two dates
};

int main()
{
	Date oldDate(4,3,1999);
	Date newDate(12,18,2012);
	
	cout << "The date stored in oldDate is ";
	oldDate.ShowDate();
	cout << "\nThe date stored in newDate is ";
	newDate.ShowDate();
	
	newDate.Swap(&oldDate);  // swap dates by passing an address
	
	cout << "\n\nAfter the swap:\n" <<endl;
	
	cout << "The date stored in oldDate is ";
	oldDate.ShowDate();
	cout << "\nThe date stored in newDate is ";
	newDate.ShowDate();
	
	cout << endl << endl;
	return 0;
}

void Date::Swap(Date *ptrDateToSwap) // method to swap two dates
{
	int temporaryStorage;
	
	// swap the day member
	temporaryStorage = ptrDateToSwap->myDay;
	ptrDateToSwap->myDay = this->myDay;
	this->myDay = temporaryStorage;
	
	// swap the month member
	temporaryStorage = ptrDateToSwap->myMonth;
	ptrDateToSwap->myMonth = this->myMonth;
	this->myMonth = temporaryStorage;
	
	// swap the year member
	temporaryStorage = ptrDateToSwap->myYear;
	ptrDateToSwap->myYear = this->myYear;
	this->myYear = temporaryStorage;
	
	return; // void
}

// class implementation section
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


