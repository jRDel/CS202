//This is my header file. It contains the function definitions for all class RentalCar functions as well as local functions to help me perform tasks.
#include "RentalCar.h"
#include <iostream>
#include <fstream>


using namespace std;



//Function definitions

//Function for copying into the char strings.

void copyString(char a[], const char b[])
{
	int index=0;
	while (b[index]!='\0')
	{
		a[index] = b[index];
		index++;
	}
	
	a[index] = '\0';
}



//Default Constructor

RentalCar::RentalCar()
{
	m_year = 1000;
	copyString(m_make, " ");
	copyString(m_model, " ");
	m_price = 1.00;
	m_available = false;
}

//Parameterized Constructor

RentalCar::RentalCar(int year, const char make[], const char model[], float price, bool available)
{
	m_year = year;
	copyString(m_make, make);
	copyString(m_model, model);
	m_price = price;
	m_available = available;
}

//Getters and Setters

int RentalCar::getYear() 
{
	return m_year;
}

void RentalCar::setYear(int y)
{
	m_year = y;
}

const char* RentalCar::getMake()
{
	return m_make;
}

void RentalCar::setMake(char make[])
{
	copyString(m_make, make);
}

const char* RentalCar::getModel()
{
	return m_model;
}

void RentalCar::setModel(char model[])
{
	copyString(m_model, model);
}

float RentalCar::getPrice()
{
	return m_price;
}

void RentalCar::setPrice(float p)
{
	m_price = p;
}

bool RentalCar::getAvailable()
{
	return m_available;
}

void RentalCar::setAvailable(bool a)
{
	m_available = a;
}

void readFile(RentalAgency agencyCars[])
{
	 //Read into seperate variables, then call the set functions to put each value into that spot.
	char inputFileName[50];
	int tempyear=0;
	char tempmake[255];
	char tempmodel[255];
	float tempprice=0;
	bool tempavail=0;
	int up = 0;
	int tempzip=0;
	int tempnum=0;

	ifstream inputStream;
	cout << "Enter filename for input:" << endl;
	cin >> inputFileName;

	inputStream.open(inputFileName);
	
	for (int i = 0; i < 3; i++) //Number of agencies
	{
		inputStream >> agencyCars[i].name >> tempzip;
		 //Reads in zipcode
			
		for (int index = 0; index < 5; index++) //Number of cars per agency, e.g. inventory object array.
		{	
			tempnum = tempzip % 10; //Takes last number off of zipcode.
			agencyCars[i].zipcode[index] = tempnum; //Stores that number in zipcode int array.
			tempzip /= 10; //Shortens by one place.
 
			inputStream >> tempyear >> tempmake >> tempmodel >> tempprice >> tempavail;
			
			agencyCars[i].inventory[index].setYear(tempyear); 
			agencyCars[i].inventory[index].setMake(tempmake);
			agencyCars[i].inventory[index].setModel(tempmodel);
			agencyCars[i].inventory[index].setPrice(tempprice);
			agencyCars[i].inventory[index].setAvailable(tempavail);
		}
	}
	cout << "Successfully read file." << endl;
	inputStream.close();
}

void RentalCar::estimateCost(RentalAgency array[], int anum, int cnum, int days) //Estimates the cost by multiplying price of chosen car by days.
{
	float cost;

	cost = (array[anum].inventory[cnum].getPrice()) * days;

	cout << "The estimated cost to rent the selected car is: $" << cost << endl;
}






void RentalCar::print(RentalAgency agencyCars[])
{
	int z = 5; //Variable to start at the end of the array because readFile reads into int array backwards zipcodes.
	for (int i = 0; i < 3; i++)
	{
		cout << agencyCars[i].name << " ";
		
		for (int z = 4; z >= 0; z--)
		{
			cout << agencyCars[i].zipcode[z]; //Prints out the zipcode starting from back of array, because read-in backwards.
		}
		cout << endl;
			for (int index = 0; index < 5; index++)
			{
			
				cout << agencyCars[i].inventory[index].getYear() << " " << agencyCars[i].inventory[index].getMake() << " " <<agencyCars[i].inventory[index].getModel() << " ,$" << agencyCars[i].inventory[index].getPrice() << " per day , Available:" << boolalpha<< agencyCars[i].inventory[index].getAvailable() << endl;
			}
			cout << endl;
	}
}

void mostExpensive(RentalAgency array[]) //Sorts through agency inventories until all cars have been seen and prints out most expensive one.
{
	RentalAgency tempcar;
	
	char tempmodel[255];
	int tempyear = 1900;
	char tempmake[255];
	int* typtr = &tempyear;
	char* tmptr = tempmake;
	char* tmoptr = tempmodel;
	float topprice = 0.0f;

	for (int i = 0; i < 3; i++)
	{
		for (int index = 0; index < 5; index++)
		{
			if (array[i].inventory[index].getPrice() > topprice)
			{
				topprice = array[i].inventory[index].getPrice();
				tempyear= array[i].inventory[index].getYear();
				copyString(tempmake, array[i].inventory[index].getMake());
				copyString(tempmodel, array[i].inventory[index].getModel());
			}
		}
	
	}
	cout << "The single most expensive car out of all 3 agencies is:" << tempyear << " " << tempmake << " " << tempmodel << endl;
}

void printAvailable(RentalAgency array[]) //Prints to output file the car information.
{
	char outputFileName[50];
	ofstream outputStream;

	cout << "What is the output file name?:" << endl;
	cin >> outputFileName;
	outputStream.open(outputFileName);

	for (int i = 0; i < 3; i++)
	{
		outputStream << array[i].name << " ";
		for (int z = 4; z >= 0; z--)
		{
			outputStream << array[i].zipcode[z]; //Prints out the zipcode starting from back of array, because read-in backwards.
		}
		outputStream<<endl;
			for (int index = 0; index < 5; index++)
			{

				if (array[i].inventory[index].getAvailable() == true)
				{
					outputStream << array[i].inventory[index].getYear() << " " << array[i].inventory[index].getMake() << " " << array[i].inventory[index].getModel() << " ,$" << array[i].inventory[index].getPrice() << "per day , Available:" << boolalpha<< array[i].inventory[index].getAvailable() << endl;
				}
			}
			outputStream << endl;
	}
	cout << "Printed to output successfully." << endl;
}