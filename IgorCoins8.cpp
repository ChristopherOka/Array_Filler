#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>

bool check_if_exists(int& potential_integer, int array[]) { 
	//PURPOSE: check if a potential integer to fill the array has already been inputted into the array 
	//INPUTS: the potential integer and the array
	//OUTPUTS: returns the boolean "exists" value, which is true if a number already exists, and false if it doesn't
	bool exists = false; //declares the bool exists variable which is automatically set to false
	for (int i = 0; i < 15; i++) { //repeats until i is 15 (the size of the array)
		if (potential_integer == array[i]) { //checks if the potential number is equal to a number already in the array
			exists = true; //sets the exists value to true
		}
	}
	return exists;
}

void output(int array[]) {
	//PURPOSE: output the array
	//INPUTS: the array
	//OUTPUTS: prints the array to the console
	for (int i = 0; i < 15; i++) { //repeats until all the values in the array are printed
		std::setw(2); 
		std::setfill('0');
			std::cout << std::setw(2) << std::setfill('0') << array[i] << "\n"; //prints the array
	}
}

void generate_values() {
	//PURPOSE: generates a potential integer to input into the array
	//INPUTS: N/A
	//OUTPUTS: the generated integer
	int array[15];
	int potential_integer; //declare integer that will be used to check 
	srand((unsigned)time(0)); //seeds the random number generator
	for (int i = 0; i < 15;) { //repeats until i is greater than 14
		potential_integer = rand() % 15 + 1; //sets the potential integer to a random number from 1 to 15
		if (check_if_exists(potential_integer, array) == false) { //checks if potential_integer is already in the array
			array[i] = potential_integer; //sets the array index to potential integer if it's not in the array
			i++; //increments i
		}
	}
	output(array); //outputs the array
}

int main() {
	generate_values();
}