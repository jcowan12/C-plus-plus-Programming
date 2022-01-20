/*
	Jonathan Cowan
	Lab 8, 10/19/21, CPSC1020
	Main driver file for Lab 8
*/

#include "lab8.h"

int main() {
	// Define the array that will hold the names and birthdays
	Person friends[SIZE];

	// Call a function to read the data from a file into the array
	getData(friends);

	// Call a function to sort the data in date order
	selectionSort(friends);

	// Call a function to display the (now sorted) data
	cout << endl << endl;
	cout << "Birthday List \n" << "Date    Name \n" << "============= \n";
	displayBirthdays(friends);

	return 0;
}
