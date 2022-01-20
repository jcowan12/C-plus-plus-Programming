/*
	Jonathan Cowan
	PA2, CPSC 1020, 11/08/2021
	Image implementation  file - responsible for image info
*/


#include "Image.h"

// constructors

//instantiate from input file
Image::Image(ifstream& filePointer) {
	this->header = read_header(filePointer);
	this->Pixels = read_pixels(filePointer, header);
}

// Instantiate from another image
Image::Image(const Image& inImage) {
	this->header = inImage.header;
	this->Pixels = inImage.Pixels;
}

//destructor
Image::~Image() {
	Pixels.clear();
}

//methods to build

// read in pixels
// takes in a Header obj and ifstream obj
// returns a 2d vector
vector<vector<Pixel>> Image::read_pixels(ifstream& filePointer, Header& header1) {

	// Define 2d vecotr using height and width as para.
	vector<vector<Pixel>> pixels (header1.getHeight(), vector<Pixel>(header1.getWidth()));

	// read in pixels
	for (int i = 0; i < header.getHeight(); ++i) {
		for (int j = 0; j < header.getWidth(); ++j) {
			char r, g, b;
			filePointer.read(&r, 1);
			filePointer.read(&g, 1);
			filePointer.read(&b, 1);

			pixels[i][j] = Pixel((unsigned char)r,(unsigned char)g,
			(unsigned char)b);
		}
	}

	filePointer.ignore(256, '\n');

	return pixels;
}

// read header
// takes in ifstream obj
// returns header obj
Header Image::read_header(ifstream& filePointer) {
	Header header1(filePointer);

	return header1;
}


//overloading operators

// Overloaded = operator
Image& Image::operator=(const Image& I) {
	if (&I == this) {
		return *this;
	}

	header = I.header;
	Pixels = I.Pixels;

	return *this;
}

// Overloaded () operator
Pixel& Image::operator()(int x, int y) {

	return Pixels.at(x).at(y);
}

//methods to write out

// write header to output file
void Image::write_header(ofstream& out) {

	out << header;
	/*
	out << header.getMagic() << endl << header.getWidth() <<
	" " << header.getHeight() << " " << header.getMax()
	<< endl;
	*/

}

// write pixel info to output file
void Image::write_to(ofstream& out) {
	write_header(out);

	// loop through pixels
	for (int i = 0; i < header.getHeight(); ++i) {
		for (int j = 0; j < header.getWidth(); ++j) {
			out << Pixels[i][j].r()
			<< Pixels[i][j].g() << Pixels[i][j].b();
		}
	}
}

//getters
Header Image::getHeader() {
	return header;
}

vector<vector<Pixel>> Image::getPixels() {
	return Pixels;
}
