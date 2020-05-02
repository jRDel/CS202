//This program expands on Project 2 by adding additional functionality, such as three agencies with five cars each.-Jakob Delossantos
#include "RentalCar.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	RentalAgency agencyCars[3];
	RentalCar detail;
	
	int option = 0;
	int anum=0;
	int cnum=0;
	int days=0;


	while (option != 6) //User menu that calls functions based on input.
	{
		cout << "Hello, welcome to our car rental program. Please choose from the following options:" << endl;
		cout << "(1) Read data from a file." << endl << "(2) Print data from all agencies and their corresponding cars." << endl << "(3) Estimate the car rental cost for a car of your choice." << endl <<
			"(4) Find the most expensive car from all three agencies." << endl << "(5) Print out to a seperate output file the available cars." << endl << "(6) Exit program." << endl;
		
		cin >> option;

		switch (option)
		{

		case 1: readFile(agencyCars);
			break;

		case 2: detail.print(agencyCars);
			break;

		case 3:
			cout << "What agency would you like to rent from?(number 1, 2, or 3)" << endl;
			cin >> anum;
			cout << "What car would you like?(number 1-5)" << endl;
			cin >> cnum;
			cout << "How many days would you like to rent it for?" << endl;
			cin >> days;
			
			anum = anum - 1;
			cnum = cnum - 1;

			
			detail.estimateCost(agencyCars, anum, cnum, days);
			break;

		case 4:mostExpensive(agencyCars);
			break;

		case 5:printAvailable(agencyCars);
			break;

		}

	}
	cout << "Goodbye!" << endl;
	return 0;
}


