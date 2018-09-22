/* pgm11-3.cpp - Chapter 11 Sample Program
   - Adding a copy constructor to the Date class
   
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
		
		Date(const Date& dateToCopy);   // copy constructor
		void ShowDate() const;   // member function to display a date
};

int main()
{
	Date testDate1(4,1,2011);
	Date testDate2(12,18,2012); // use the constructor
	Date testDate3(testDate1);   // use the copy constructor
	Date testDate4 = testDate2;  // use the copy constructor
	
	cout << "\nThe date stored in testDate1 is ";
	testDate1.ShowDate();
	
	cout << "\nThe date stored in testDate2 is ";
	testDate2.ShowDate();
	
	cout << "\nThe date stored in testDate3 is ";
	testDate3.ShowDate();
	
	cout << "\nThe date stored in testDate4 is ";
	testDate4.ShowDate();
	
	cout << endl << endl;
	return 0;
}

// class implementation section

Date::Date(const Date& dateToCopy)
{
	myMonth = dateToCopy.myMonth;
	myDay = dateToCopy.myDay;
	myYear = dateToCopy.myYear;
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


