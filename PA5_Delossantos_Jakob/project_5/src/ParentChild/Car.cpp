//This source file contains the class definition for the Car derived class.

#include <iostream>
#include <cstring>

#include <ParentChild/Car.h>
#include <ParentChild/Vehicle.h>

using namespace std;

Car::Car() //Default constructor leaves everything except throttle uninitialized.
{

	m_throttle=0;
	
	cout<<"Car #"<<Vehicle::getVin()<<": Default-ctor"<<endl;
	
}
		
Car::Car(char * licensePlate, int vinNumber, float * LLA) : Vehicle(vinNumber, LLA) /*Uses initializer list in parametrized constructor to set vinNumber and LLA of car which has more specialized features like licenseplate.*/
{

	m_throttle=0;
	
	strcpy(m_plates, licensePlate);
	
	cout<<"Car #"<<Vehicle::getVin()<<": Parametrized-ctor"<<endl;
	
}
		
Car::Car(const Car & car) //Copy constructor copies car objects.
{

	strcpy(m_plates, car.m_plates);
	m_throttle=car.m_throttle;
	
	
	
	for(int i=0; i<LLA_SIZE; i++)
	{
		m_lla[i]=car.m_lla[i];
	}
	
	cout<<"Car #"<<Vehicle::getVin()<<": Copy-ctor"<<endl;
	
}
		
Car::~Car() //Car destructor with debug output.
{

	cout<<"Car #"<<Vehicle::getVin()<<": Dtor"<<endl;
	
}
		
Car Car::operator= (const Car & c) //Operator= overload to set car objects equal to eachother, except the vin number.
{

	m_throttle=c.m_throttle;
	
	strcpy(m_plates, c.m_plates);
	
	for(int i=0; i<LLA_SIZE; i++)
	{
		m_lla[i]=c.m_lla[i];
	}
	
	cout<<"Car #"<<Vehicle::getVin()<<": Assignment"<<endl;
	
}
	
char * Car::getPlates() //getters and setters
{

	return m_plates;
	
}
		
void Car::setPlates(char * licensePlate)
{

	strcpy(m_plates, licensePlate);
	
}
		
int Car::getThrottle()
{

	return m_throttle;
	
}
		
void Car::setThrottle(int throttle)
{

	m_throttle=throttle;
	
}
			
void Car::drive(int throttle)
{

	setThrottle(throttle);
	
}
		
void Car::move(float *LLA) //This move function actually works because a specialized derived car object can move, so sets throttle to 75 with drive.
{
	
	drive(75);
	
	cout<<"Car #"<<getVin()<<": DRIVE to destination, with throttle @ "<<m_throttle<<endl;
	
	setLLA(LLA);
	
}
		
ostream & operator<< (ostream & os, const Car & c) /*Operator<< overload to output all car objects.*/
{

	static_cast<const Vehicle&>(c); //Static cast the car object so it can access the vehicle values vin and LLA.
	os << "Car #" <<c.m_vin<<" Plates: "<<c.m_plates<<", Throttle:"<<c.m_throttle<<" @ [";
	
	

	for(int i=0; i<LLA_SIZE; i++)
	{
		if(i!=2)
		{
			os<<c.m_lla[i]<<", ";
		}
		else
		{
			os<<c.m_lla[i]<<"]"<<endl;
		}
	}
}






		
