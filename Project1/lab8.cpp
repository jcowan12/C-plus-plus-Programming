/*
	Jonathan Cowan
	Lab 8, 10/19/2021, CPSC1020
	Main file for Lab 8
 */

// lab 8
// This program reads names and birthdays in from a file, stores them in an
// array of objects, sorts the data by birthday, and displays it. To simplify
// the program, the Person class data has been made public. The data
// file, birthdays.dat, in the same directory.

// The class, function implementations, and main function are all
// contained in this one file.


#include "lab8.h"

// Person Implementation
Person::Person() {
	name = " ";
	birthday = " ";
}


// Getter implementations
string Person::getName() const {
	return name;
}

string Person::getBirthday() const {
	return birthday;
}

// Setter Implementations
void Person::setName(string name1) {
	name = name1;
}

void Person::setBirthday(string birthday1) {
	birthday = birthday1;
}

/****************************************************************
 *                            getData                           *
 * Called by: main                                              *
 * Passed   : The array holding the data                        *
 * Purpose  : Reads the data from a file into the array elements*
 ****************************************************************/
void getData(Person friends[]) {
	ifstream dataIn;

	// Open the file and test that it opened correctly
	dataIn.open("birthdays.dat");
	if (!dataIn)
		cout << "Error opening data file\n";
	else {	// Read in all the data
		for (int index = 0; index < SIZE; index++) {
			string temp1, temp2;

			getline(dataIn, temp1);
			friends[index].setName(temp1);

			getline(dataIn, temp2);
			temp2[5] = '\0';
			friends[index].setBirthday(temp2);

		}
		// Close the file
		dataIn.close();
	}
}


/*************************************************************
 *                    selectionSort                          *
 * Called by: main                                           *
 * Passed   : The data array                                 *
 * Purpose  : Sorts the elements in ascending date order     *
 ************************************************************/
void selectionSort(Person friends[]) {
	int startScan,     // Array indexes to be compared
		 minIndex;

	Person temp;       // Used to swap two friend elements
	string minValue;   // Will be in the birthday field of element
	// with minIndex

	// Sort array elements
	for (startScan = 0; startScan < (SIZE - 1); startScan++) {
		minIndex = startScan;
		minValue = friends[startScan].getBirthday();
		for (int index = startScan + 1; index < SIZE; index++) {
			// Compare data in the birthday fields
			if (friends[index].getBirthday() < friends[minIndex].getBirthday()) {
				minValue = friends[index].getBirthday();
				minIndex = index;
			}
		}
		// Move elements to their new positions
		temp = friends[minIndex];
		friends[minIndex] = friends[startScan];
		friends[startScan] = temp;
	}
}


/*************************************************************
 *                   displayBirthdays                        *
 * Called by: main                                           *
 * Passed   : The array of person objects                    *
 * Purpose  : Prints names and bithdays in order of date.    *
 *************************************************************/
void displayBirthdays(const Person friends[]) {
	for (int pos = 0; pos < SIZE; pos++)
		cout << friends[pos].getBirthday() << "   " << friends[pos].getName() << endl;
	cout << endl << endl;
}


/* CORRECT RESULTS

	Birthday List
	Date    Name
	=============
	02/09   Mario Rubio
	03/16   Sandra Day
	06/08   Sean O'Connor
	07/15   Dev Patel
	08/22   Darius Williams
	09/18   Anne Dawson
	10/31   Randy Mack
	11/03   Evelyn Maroto
	11/22   Bill Johnson
	12/01   Jill Benson

 */
