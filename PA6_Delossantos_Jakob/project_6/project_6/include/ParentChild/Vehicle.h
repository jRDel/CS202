//This header file contains the class declaration for the Vehicle base class.

#ifndef VEHICLE_H_
#define VEHICLE_H_

#define MAX_ARRAY_SIZE 256
#define LLA_SIZE 3

#include <iostream>
#include <fstream>

using namespace std;

class Vehicle {

	public:
		
		Vehicle();
		Vehicle(int vinNumber, float * LLA);
		Vehicle(const Vehicle & vehicle);
		~Vehicle();
		
		Vehicle operator= (const Vehicle & v);
		
		const int getVin();
		
		const float * getLLA();
		void setLLA(float * LLA);
		
		void move(float * LLA);
		
		static int getIdgen();
		
		friend ostream & operator<< (ostream & os, const Vehicle & v);
		
		int checkIfUnique(int vinNumber);
		

	protected:
	
		float m_lla[LLA_SIZE];
		const int m_vin;
	
	private:
	
		static int s_idgen;
		
};

#endif
	
	
