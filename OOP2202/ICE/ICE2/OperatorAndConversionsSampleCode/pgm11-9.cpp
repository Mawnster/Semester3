/* pgm11-9.cpp - Chapter 11 Sample Program
   - Adding an overloaded subscript operator to the Date Class
   	
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
		
		int operator[](int element) const;   // overload the subscript operator
		void ShowDate() const;   // member function to display a date
};


int main()
{
	Date testDate;
	
	cout << "Showing ";
	testDate.ShowDate();
	cout << ", element-by-element: " << endl;
	
	for(int index; index < 4; index++)
	{
		cout << "\nElement " << index << ": " << testDate[index] << endl; 
	}
	
	cout << endl << endl;
  	return 0;
}


// class implementation section
int Date::operator[](int element) const
{
	int elementValue = -1; // -1 indicates an error
	
	switch(element)
	{
		case 0:
			elementValue = myDay;
			break;
	   case 1:
			elementValue = myMonth;
			break;
		case 2:
			elementValue = myYear;
	}
	return elementValue;
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




