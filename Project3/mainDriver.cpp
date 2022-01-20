/*
	Jonathan Cowan
	PA2, CPSC 1020, 11/12/2021
	main driver file for PA2
*/

#include <iostream>
#include <iomanip>
#include "Pixel.h"
#include "Header.h"
#include "Image.h"
#include "manip.h"

using namespace std;

// function prototypes
int printMenu();
int whichImage();

int main (int argc, char** argv) {

	int imageCount = 0;

	// file pointers for 2 inputted images
	ifstream image1(argv[1]);
	ifstream image2(argv[2]);

	// ensure opening
	if (!image1 || !image2) {
		cout << "ERROR: File(s) could not be opened" << endl;
		return -1;
	}

	// instantiate images
	Image imageOne(image1);
	Image imageTwo(image2);

	// print main menu
	int choice = 1;

	// loop to interate while manipulation is wanted
	while (choice != 0) {

		choice = printMenu();

		// create output file name
		string count = to_string(imageCount);
		string outImage = "out_"+count+".ppm";

		// ofstream pointer to file
		ofstream rOutImage(outImage);

		// GRAY
		if (choice == 1) {
			int imageChoice = whichImage();

			// determine image choice and continue function call
			if (imageChoice == 1) {
				Image grayedImage = imageOne;
				gray(grayedImage);
				grayedImage.write_to(rOutImage);
			}

			else {
				Image grayedImage = imageTwo;
				gray(grayedImage);
				grayedImage.write_to(rOutImage);
			}
		}

		// MIRROR
		if (choice == 2) {
			int imageChoice = whichImage();

			//determine image choice and contine function call
			if (imageChoice == 1) {
				Image mirrorImage = imageOne;
				mirror(mirrorImage);
				mirrorImage.write_to(rOutImage);
			}

			else {
				Image mirrorImage = imageTwo;
				mirror(mirrorImage);
				mirrorImage.write_to(rOutImage);
			}
		}

		// GREEN SCREEN
		if (choice == 3) {
			Image disneyCopy(imageTwo);

			// call green screen function
			green_screen(disneyCopy, imageOne);

			cerr << "The Clemson Paw will be copied on top of the Disney image."
			<< endl << endl;

			// write to output pointer
			disneyCopy.write_to(rOutImage);
		}

		rOutImage.close();
		imageCount++;

		image1.close();
		image2.close();
	}

//	image1.close();
//	image2.close();

	return 0;
}

// function defintions

// printMenu to user, manipulation options
// takes in no parameters
// outputs integer corresponding to choice
int printMenu() {
	cout << endl
	<< "PA2 Image Manipulation" << endl
	<< "0. exit program" << endl
	<< "1. gray scale" << endl
	<< "2. mirror" << endl
	<< "3. green screen" << endl <<
	"	- - > ";

	int input = 0;
	cin >> input;

	return input;
}

// whichImage to user, image options
// takes in no parameters
// outputs integer corresponding to choice
int whichImage() {
	cout << endl
	<< "PA1 Image Manipulation" << endl
	<< "1." << "ClemsonPaw.ppm" << endl
	<< "2." << "Disney.ppm" << endl
	<< "	- - > ";

	int input = 0;
	cin >> input;

	return input;
}
