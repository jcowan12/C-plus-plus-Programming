/*
	Jonathan Cowan
	PA2, CPSC 1020, 11/02/2021
	Implementation file for pixel stuff
*/

#include "Pixel.h"

using namespace std;


// Overloaded output to output header values
ostream& operator<< (ostream& out, const Pixel& P) {
	out << "(" << P.R << " " << P.G << " "
	<< P.B << ")";

	return out;
}

// Overloaded = operator to allow for quick copy
Pixel& Pixel::operator=(const Pixel &P) {
	if (&P == this) {
		return *this;
	}

	this->R = P.R;
	this->G = P.G;
	this->B = P.B;

	return *this;
}


// default const
Pixel::Pixel() {
	R = 0;
	G = 0;
	B = 0;
}

// parameterized const
Pixel::Pixel(unsigned char A, unsigned char B, unsigned char C) {
	R = A;
	G = B;
	B = C;
}

// copy contructor
Pixel::Pixel(const Pixel &P) {
	R = P.R;
	G = P.G;
	B = P.B;
}

// destructor
Pixel::~Pixel() {
	return;
}

// methods go here
// getters
unsigned char Pixel::r() const {
	return this->R;
}

unsigned char Pixel::g() const {
	return this->G;
}

unsigned char Pixel::b() const {
	return this->B;
}

// reference getters
unsigned char& Pixel::r() {
	return this->R;
}

unsigned char& Pixel::g() {
	return this->G;
}

unsigned char& Pixel::b() {
	return this->B;
}
