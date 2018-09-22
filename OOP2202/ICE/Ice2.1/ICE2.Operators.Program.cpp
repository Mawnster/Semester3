/** ICE2.Operators.Program.cpp
 *	
 *	DO NOT MODIFY THIS FILE.
 *   
 *	@author		Thom MacDonald
 *	@version	2018.01
 *	@since		28 Jul 2018
*/

#include <iostream>
#include "ICE2.Operators.h"

using namespace std;

// main() function
int main()
{
	// Declarations
	const int QTY = 2; // the quantity of objects in the array
	CartesianPoint pointArray[QTY]; // an array of objects
	double distance; // to store the distance between two points
	
	// Input loop
	// for each object in the array
	for(int point = 0; point < QTY; point++)
	{
		// get the coordinates from the user
		cout << "\nEnter point # " << (point + 1) << ": ";
		
		// REQUIRES INPUT OPERATOR METHOD
		// (No validation is required for this exercise)
		 cin >> pointArray[point];
	}
	
	// Processing
	// determine the distance between the two points in the array
	
	// REQUIRES SUBTRACTION OPERATOR METHOD
	distance = pointArray[0] - pointArray[1];

	// Output 
	// Show the points and the distance
	cout << fixed << setprecision(1); // formatting
	
	// REQUIRES OUTPUT OPERATOR METHOD
	cout << "\nThe distance between " << pointArray[0]
		 << " and " << pointArray[1] << " is " 
		 << distance << ". " << endl;
	
	// done.
	cout << endl << endl;
	return 0;
} // end of main()






