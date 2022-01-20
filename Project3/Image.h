/*
	Jonathan Cowan
	PA2, CPSC 1020, 11/08/2021
	Image header file - responsible for image info
*/

#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "Pixel.h"
#include "Header.h"

using namespace std;

// image class
class Image {
	private:
		Header header;
		vector<vector<Pixel>> Pixels;

	public:
		// constructors

		//instantiate from input file
		Image(ifstream& filePointer);

		// Instantiate from another image
		Image(const Image& inImage);

		//destructor
		~Image();

		//methods to build
		vector <vector<Pixel>> read_pixels(ifstream& filePointer, Header& header1);

		Header read_header(ifstream& filePointer);

		//overloading operators

		// Overloaded parentheses
		Pixel& operator()(int x, int y);

		// overloaded assignment
		Image& operator=(const Image& I);

		//methods to write out
		void write_header(ofstream& out);

		void write_to(ofstream& out);

		//getters
		Header getHeader();

		vector<vector<Pixel>> getPixels();

};



#endif
