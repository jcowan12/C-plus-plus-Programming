/*
	Jonathan Cowan
	PA2, CPSC 1020, 11/15/2021
	Manip file implementation
*/

#include "manip.h"

// function implementations

// gray scale function
// takes in Image object
// void return type
void gray(Image& gChoice) {
	Header header = gChoice.getHeader();
	int avg = 0;

	// for loop to increment through pixels, calc avg
	for (int i = 0; i < header.getHeight(); ++i) {
		for (int j = 0; j < header.getWidth(); ++j) {
			avg = (gChoice(i, j).r() + gChoice(i, j).g() +
					gChoice(i, j).b()) / 3;

			// assign avg
			gChoice(i, j).r() = avg;
			gChoice(i, j).b() = avg;
			gChoice(i, j).g() = avg;
		}
	}
}
// mirror function
// take in Image object
// void return type
void mirror(Image& mChoice) {
	Header header = mChoice.getHeader();

	Image oldChoice(mChoice);

	for (int i = 0; i < header.getHeight(); i++) {
		int farCol = header.getWidth() - 1;

		for (int j = 0; j < (header.getWidth() / 2); j++) {

		// swap pixels
		mChoice(i, j).r() = oldChoice(i, farCol).r();
		mChoice(i, farCol).r() = oldChoice(i, j).r();
		mChoice(i, j).g() = oldChoice(i, farCol).g();
		mChoice(i, farCol).r() = oldChoice(i, j).r();
		mChoice(i, j).b() = oldChoice(i, farCol).b();
		mChoice(i, farCol).r() = oldChoice(i, j).r();


		--farCol;
		}
	}
}

// green screen function
// takes in two image objects
// void return type
void green_screen(Image& imageC1, Image& imageC2) {
	Header header = imageC2.getHeader();

	// algorithm
	for (int i = 0; i < header.getHeight(); i++) {
		for (int j = 0; j < header.getWidth(); j++) {
			// check for green in imageC1
			if (((imageC2(i, j).g() != 255) &&
				(imageC2(i, j).r() != 0) &&
				(imageC2(i, j).b() != 0))) {
				imageC1(i, j).r() = imageC2(i, j).r();
				imageC1(i, j).g() = imageC2(i, j).g();
				imageC1(i, j).b() = imageC2(i, j).b();
			}
		}
	}
}
