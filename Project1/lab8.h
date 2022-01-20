/*
	Jonathan Cowan
	Lab 8, 10/19/2021, CPSC1020
	Header file for Lab 8
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

class Person {
	private:
		string name;
	   string birthday;

	public:
		Person();
		string getName() const;
		string getBirthday() const;
		void setName(string name1);
		void setBirthday(string birthday1);
};

const int SIZE = 10;

// Function prototypes
void getData(Person []);
void selectionSort(Person []);
void displayBirthdays(const Person []);
