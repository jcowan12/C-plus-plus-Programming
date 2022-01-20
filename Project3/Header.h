/*
	Jonathan Cowan
	PA2, CPSC 1020, 11/02/2021
	Header file for header stuff
*/

#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;


// Header Class
class Header {
	private:
		string magicNum;
		int width;
		int height;
		int maxVal;
	public:
		// default const
		Header();

		// parameterized const
		Header(string magicNum1, int width1, int height1, int maxVal1);

		// from file pointer
		Header(ifstream& filePointer);

		// methods go here
		// getters
		string getMagic();

		int getWidth();

		int getHeight();

		int getMax();

		// other methods
		friend istream& operator>>(istream& out, Header& H);
		friend ostream& operator<<(ostream& in, const Header& H);
};


#endif
