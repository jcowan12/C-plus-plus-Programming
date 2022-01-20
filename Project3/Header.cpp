/*
	Jonathan Cowan
	PA2, CPSC 1020, 11/02/2021
	Implementation file for header stuff
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"



// Header Class
// default const
Header::Header() {
	magicNum = "P6";
	width = 0;
	height = 0;
	maxVal = 0;
}

// parameterized const
Header::Header(string magicNum1, int width1, int height1, int maxVal1) {
	magicNum = magicNum1;
	width = width1;
	height = height1;
	maxVal = maxVal1;
}

// by pointer
Header::Header(ifstream& filePointer) {
	filePointer >> magicNum >> width >> height >> maxVal;
}

// methods go here
// getters
string Header::getMagic() {
	return magicNum;
}

int Header::getWidth() {
	return width;
}

int Header::getHeight() {
	return height;
}

int Header::getMax() {
	return maxVal;
}

// overloaded input to input header values
istream& operator>>(istream& in, Header& H) {
	in >> H.magicNum >> H.width >> H.height >> H.maxVal;

	return in;
}
// Overloaded output to output header values
ostream& operator<<(ostream& out, const Header& H) {
	out << H.magicNum << endl << H.width << " "
	<< H.height << endl << H.maxVal << endl;

	return out;
}
