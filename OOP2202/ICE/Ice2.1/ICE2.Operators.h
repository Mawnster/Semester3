/** ICE4.Operators.h
 *	
 *	Starter file for ICE 4 - ICE 4 - Operators and Conversions.
 *  Modify as per the directions given in class.
 *   
 *	@author		Thom MacDonald (Starter file)
 *	@author		Zachary king 100534535 (Solution)
 *	@version	2018.01
 *	@since		28 Jul 2018 (UPDATE TO TODAY'S DATE)
*/

#include <iostream>
#include <iomanip> 		// for output formatting
#include <sstream>		// for stringstream
#include <cmath>		// for sqrt()
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
    CartesianPoint(int x = 1, int y = 1) : myX(x), myY(y) {}
	 
	/* Accessors: Used to query the state of the object
	 *	- never modifies the object
	 *	- should specify const at the end of the prototype/header
	 */    
	int GetX() const {return myX;}
	int GetY() const {return myY;}
	
	
	double GetDistanceTo(CartesianPoint pointTo) const;  // get the 
 		   								// distance between this point
 		   								// and a second point
 		   								
	// TO-DO: Add operator-
	double operator-(CartesianPoint pointTo ) const  { return /*this->*/ GetDistanceTo(pointTo);}

	string ToString() const; // convert the obj to a string.
	
	// TO-DO: Add (string) operator
	operator string() const { return ToString(); } 
	/* Mutator(s): Used to change the state of the object
	*	- should contain logic to ensure object remains in a valid state.
	*	- typically sets a member variable to a parameter
	*/
	void SetX(int x) { myX = x; }
	void SetY(int y) { myY = y; }
	void SetPoint(int x, int y){ SetX(x); SetY(y); }
	
	// TO-DO: Add operator <<
	friend ostream& operator<<( ostream& out, const CartesianPoint& thePoint );
	// TO-DO: Add operator >>
	friend istream& operator>>( istream& in, CartesianPoint& thePoint);
  private: // private data members for the dimensions of the point
    int myX; // x-axis (horizontal) value
    int myY;  // y-axis (vertical) value
    
};

// Class defintion section

/** toString Method for CartesianPoint class
 *	Converts the obj to a string.
 *	@return	the obj state as a string
 */
string CartesianPoint::ToString() const
{
	// declare a stringstream object
	stringstream strOut; 
	// build the string
	strOut << "(" << myX << ", " << myY << ")";
	// return the string
	return strOut.str();
}

/** GetDistanceTo Method for CartesianPoint class
 *	Determines the distance between this point and a second point.
 *	@param	pointTo: CartesianPoint
 *	@return	the distance as a double
 */
double CartesianPoint::GetDistanceTo(CartesianPoint pointTo) const 
{
    int xDelta = pointTo.myX - myX; // difference between x values
    int yDelta = pointTo.myY - myY; // difference between y values
    // return the formula (based on Pythagorean theorem)
	return sqrt((xDelta * xDelta) + (yDelta * yDelta));
} 

ostream& operator<<( ostream& out, const CartesianPoint& thePoint )
{
	out << (string) thePoint; // cout << ToString(); 
	return out; 
}
//
istream& operator>>( istream& in, CartesianPoint& thePoint)
{
	in >> thePoint.myX;
	in.ignore(1); 
	in >> thePoint.myY;
	
	return in;
}
