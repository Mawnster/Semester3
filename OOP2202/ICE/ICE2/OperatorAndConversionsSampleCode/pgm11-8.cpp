/* pgm11-8.cpp - Chapter 11 Sample Program
   - Converting from one class to another class
   	
   Modified by: T. MacDonald, 3 Oct 2016
   For: OOP 3200 - OOP II
   Reference:
   Bronson, G. (2011). A First Book of testDate3++, Fourth Edition. Course Technology.
*/

#include <iostream>
#include <iomanip>
#include <sstream> // for stringstream
using namespace std;

class StringDate; // forward declaration

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
		
		operator StringDate();  // conversion operator from Date to StringDate
		void ShowDate() const;   // member function to display a date
};

// class declaration section for StringDate
class StringDate
{
	private:
		string myDateString;
	public:
		StringDate(string date = "20161004");    // constructor
		// To-Do: Add Accessors, Mutators, Validation, etc.
		operator Date();  // conversion operator from StringDate to Date
		void ShowDateString() const { cout << myDateString; }
};

int main()
{
	Date numericDate1 (4,1,2011);
	Date numericDate2;
	
	StringDate stringDate1; 
	StringDate stringDate2 ("20121215");  
	
	//  Casting
	stringDate1 = (StringDate) numericDate1;  // cast Date object into an StringDate object
	numericDate2 = (Date) stringDate2; // cast StringDate object into a Date object
	
	
	// Output	
	numericDate1.ShowDate();
	cout << " as an StringDate object is ";
	stringDate1.ShowDateString();
	
	cout << endl << endl;
	
	stringDate2.ShowDateString();
	cout << " as an Date object is ";
	numericDate2.ShowDate();
	
	
	cout << endl << endl;
	
	return 0;
}

// class implementation section for Date
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


// conversion operator function converting from Date to StringDate class
Date::operator StringDate()   // must return an StringDate object
{
	string dateString;
	stringstream converter; // for converting the string to a numeric
	
	
	converter << (myYear * 10000 + myMonth * 100 + myDay); // insert the value into the stream
	converter >> dateString; // extract a string from the stream
	
	return (StringDate(dateString));
}

// class implementation section for StringDate
StringDate::StringDate(string date)  // constructor
{
	// To-do: add validation
	myDateString = date;
}

// conversion operator function converting from StringDate to Date class
StringDate::operator Date()   // must return a Date object
{
	int dateValue = 0; // holds the date string converted to numeric
	int day;	 // hold the extracted day
	int month; // hold the extracted month
	int year;  // hold the extracted year
	
	stringstream converter; // for converting the string to a numeric
	
	converter << myDateString; // insert the string into the stream
	converter >> dateValue; // extract an int from the stream
	
	// break the date value into month, day, year
	year = (int) (dateValue/10000.0);
	month = (int) ((dateValue - year * 10000.0)/100.0);
	day = (int) (dateValue - year * 10000.0 - month * 100.0);
	
	// return a new Date object using month, day, year
	return( Date(month, day, year) );
}

