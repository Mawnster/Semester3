/** OOP3200-ICE1-Start.cpp
 *	
 *	In this example program, did the following:
 *		- Examined a simple class with 'instance' data-members, a constructor, accessors, mutators.
 *   
 *	@author		Zachary King
 *	@author		Thom MacDonald
 *	@version	2018.02
 *	@since		10 sept 2018
 *	@see		Bronson, G. (2012).  Chapter 10 Introduction to Classes. 
 *				  In A First Book of C++ (4th ed.). Boston, MA: Course Technology.
*/

#include <iostream> 		// cin, cout
#include <iomanip>			// fixed, setprecision()
#include <sstream> 			// stringstream
#include <cmath>			// sqrt()
#include <limits>			// INT_MAX
#include <stdexcept>		// out_of_range
#include "MyConsoleInput.h" // ConsoleInput::ReadInteger()

using namespace std;

// class declaration section
class CartesianPoint
{
  public:
  	
	/* Constructor: Used to initialize objects
	*	- always the same name as the class
	*	- never have a return type
	*	- called automatically when an obj is instantiated
	*	- should set values for each member variable
	*/
	//CartesianPoint() : myX(0) , myY(0)  { }
    CartesianPoint( int x = 0, int y = 0) { SetX(x); SetY(y);  }
	/* Accessors: Used to query the state of the object
	*	- never modifies the object
	*	- should specify const at the end of the prototype/header
	*/

	int GetX() const { return myX; }// get x
	int GetY() const { return myY; }// get y 
	double GetDistanceTo(CartesianPoint secondPoint) const; // get the distance between this point and a second point
	string ToString() const; // convert the obj to a string	
	
	/* Mutator(s): Used to change the state of the object
	*	- should contain logic to ensure object remains in a valid state.
	*	- typically sets a member variable to a parameter
	*/
	
	void SetX(int x) { /* Validation */ myX = x; }// set x
	void SetY(int y) { /* validation */ myY = y; }// set y, 
	void SetPoint(int x, int y) { SetX(x); SetY(y); }// set point (both x and y)	
		
  private: 
  // private data members for the dimensions of the point
    int myX; // x-axis (horizontal) value
    int myY;  // y-axis (vertical) value
	 
};

// main() function
int main()
{
	// Declarations
	CartesianPoint origin(88, 99); // a point called 'origin', initialized to 0, 0
	CartesianPoint destination; // a point called 'destination'
	int inputX; // temporary input variable for x
	int inputY; // temporary input variable for y
	double distance; // to store the distance between two points
	
	try
	{
		// Input
	
		// Prompt the user for the coordinates
		cout << "\nEnter coordinates of the destination point: " << endl;
		// prompt for, read, and store x coordinate:
		cout << "X: ";
		inputX = ConsoleInput::ReadInteger();
		
		
		// prompt for, read, and store y coordinate:
		cout << "Y: ";
		inputY = ConsoleInput::ReadInteger();
		
		destination.SetPoint(inputX, inputY);
		
		// Processing
		// determine the distance between the two points
		distance = origin.GetDistanceTo(destination);
		
		// Output 
		// Show the points and the distance
		cout << fixed << setprecision(3); // formatting
		cout << "/n the distance between " << origin.ToString() << " and" 
			 << destination.ToString() << " is " << distance; 
		
	}
	
	catch(exception &ex)
	{
		cerr << ex.what() << " Ending the program." << endl;
	}
		
	// done.
	cout << endl << endl;
	return 0;
} // end of main()

// Class definition section

/** GetDistanceTo Method for CartesianPoint class
*	Determines the distance between this point and a second point.
*	@param	pointTo: CartesianPoint
*	@return	the distance as a double
*/
double CartesianPoint::GetDistanceTo(CartesianPoint pointTo) const

{
	int xDelta = pointTo.myX - this->myX;// difference between x values
    int yDelta = pointTo.myY - this->myY;// difference between y values
    // return the formula (based on Pythagorean theorem)
	return sqrt((xDelta * xDelta) + (yDelta * yDelta));

} 

/** ToString Method for CartesianPoint class
*	Converts the obj to a string.
*	@return	the obj state as a string
*/
	string CartesianPoint::ToString() const

{
	// declare a stringstream object
	stringstream stringOut;
	// build the string
	stringOut << "(" << myX << ", " << myY << ")";
	// return the string
	return stringOut.str();
}
