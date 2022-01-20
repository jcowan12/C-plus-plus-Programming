/*
	Jonathan Cowan
	PA2, CPSC 1020, 11/02/2021
	Header file for pixel stuff
*/

#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>

using namespace std;


// Pixel Class
// will contain all data members
// relating to pixel values
class Pixel {
	private:
		unsigned char R;
		unsigned char G;
		unsigned char B;
	public:
		// default const
		Pixel();

		// parameterized const
		Pixel(unsigned char A, unsigned char B, unsigned char C);

		// copy contructor
		Pixel(const Pixel &P);

		// destructor
		~Pixel();

		// methods go here
		// getters
		unsigned char r() const;

		unsigned char g() const;

		unsigned char b() const;

		// reference getters
		unsigned char& r();

		unsigned char& g();

		unsigned char& b();

		// other methods - overloaded operators
		friend ostream& operator<< (ostream& out, const Pixel& P);
		Pixel& operator= (const Pixel &P);
};


#endif
