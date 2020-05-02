//This source file contains the class definition for the Vehicle base class.

#include <iostream>
#include <fstream>
#include <cstring>

#include <ParentChild/Vehicle.h>

using namespace std;

int Vehicle::s_idgen=0;

Vehicle::Vehicle() : m_vin(getIdgen())
{
	
	cout<<"Vehicle #"<<m_vin<<": Default-ctor"<<endl;
	
}	

Vehicle::Vehicle(int vinNumber, float * LLA) : m_vin(checkIfUnique(vinNumber)) /*Constructs vehicle parametrized if the vin is unique.*/
{
	s_idgen=vinNumber; //Sets idgen to the vinNumber, relates to checkIfUnique to see if its unique vin or not.
	for(int i=0; i<LLA_SIZE; i++)
	{
		m_lla[i]=*LLA;
		LLA++;
	}
	
	cout<<"Vehicle #"<<m_vin<<": Parametrized-ctor"<<endl;
	
}

Vehicle::Vehicle(const Vehicle & vehicle) : m_vin(getIdgen())
{
	
	for(int i=0; i<LLA_SIZE; i++) //This loops assigns the LLA array.
	{
		m_lla[i]=vehicle.m_lla[i];
	}
	
	cout<<"Vehicle #"<<m_vin<<": Copy-ctor"<<endl;
	
}

Vehicle::~Vehicle() //Destructor for vehicle objects
{

	cout<<"Vehicle #"<<m_vin<<": Dtor"<<endl;
	
}		

Vehicle Vehicle::operator= (const Vehicle & v)
{
	for(int i=0; i<LLA_SIZE; i++) //Overloaded operator sets LLA's equal to eachother, but not the vin.
	{
		m_lla[i]=v.m_lla[i];
	}
	cout<<"Vehicle #"<<m_vin<<": Assignment"<<endl;
	
}
		
const int Vehicle::getVin() //getters and setters
{

	return m_vin;
	
}
		
const float * Vehicle::getLLA()
{

	return m_lla;
	
}

void Vehicle::setLLA(float * LLA)
{

	for(int i=0; i<LLA_SIZE; i++)
	{
		m_lla[i]=*LLA;
		LLA++;
	}
	
}
		
void Vehicle::move(float * LLA) //Base move function takes in LLA, but cannot move because it is general parent class.
{

	setLLA(LLA);
	
	cout<<"Vehicle #"<<m_vin<<": CAN'T MOVE - I DON'T KNOW HOW"<<endl;
	
}
	
		
int Vehicle::getIdgen()
{

	s_idgen++;
	
	return s_idgen;
	
}
		
ostream & operator<< (ostream & os, const Vehicle & v) //Operator overload that outputs individual vehicle information.
{

	os<<"Vehicle #"<<v.m_vin<<" @ ["<<v.m_lla[0]<<", "<<v.m_lla[1]<<", "<<v.m_lla[2]<<"]"<<endl;
	
	return os;
	
}

int Vehicle::checkIfUnique(int vinNumber) /*Checks if the vehicle vinNumber is unique, as the parametrized constructor sets  s_idgen=last constructed object vinNumber. */
{

	if(vinNumber<s_idgen) //If new vin is less than the s_idgen then it is okay.
	{
		return vinNumber;
	}
	else if(vinNumber>s_idgen) //If new vin is greater than s_idgen then it is okay.
	{
		return vinNumber;
	}
	else //else is same as equal to, so s_idgen must be incremented and vinNumber is equal to that new s_idgen. Then returns vinNumber.
	{
		s_idgen++;
		vinNumber=s_idgen;
		return vinNumber;
	}
}















