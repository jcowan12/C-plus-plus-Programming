/*
	Jonathan Cowan
	PA2, CPSC 1020, 11/11/2021
	Header file for 3 manipulation functions
*/

#ifndef MANIP_H
#define MANIP_H

#include <iostream>
#include <fstream>
#include "Image.h"

// prototypes for three manipulation functions

// gray
void gray(Image& gChoice);

// mirror
void mirror(Image& mChoice);

// green screen
void green_screen(Image& imageC1, Image& imageC2);

#endif
