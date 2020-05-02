#include "RentalCar.h"
#include <iostream>
#include "RentalAgency.h"
#include <fstream>

using namespace std;
//Function definitions

//Function for copying into the char strings.

void copyString(char a[], const char b[])
{
	int index;

	for (int index = 0; index < 256; index++)
	{
		a[index] = b[index];
	}
	a[index] = '\0';

}

//Default Constructor

RentalCar::RentalCar()
{
	m_year = 1000;
	copyString(m_make, "");
	copyString(m_model, "");
	m_price = 775.00;
	m_available = false;
}

//Parameterized Constructor

RentalCar::RentalCar(int year, char make[], char model[], float price, bool available)
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

char RentalCar::getMake()
{
	return m_make[256];
}

void RentalCar::setMake(char make[])
{
	copyString(m_make, make);
}

char RentalCar::getModel()
{
	return m_model[256];
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

void RentalCar::print()
{
	cout << m_year << " " << m_make << " " << m_model << " " << m_price << " " << m_available << endl;
}

void RentalCar::estimateCost(int days)
{
	int estimate = m_price * days;
	cout << "Estimated car cost is:" << estimate << endl;
}

void printAll(struct RentalAgency array[])
{
	for (int index = 0; index < 3; index++)
	{
		c
	}
}
