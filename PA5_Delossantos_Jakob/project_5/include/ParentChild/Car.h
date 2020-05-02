//This header file contains the class declaration for the derived Car class.

#ifndef CAR_H_
#define CAR_H_

#include <iostream>
#include <ParentChild/Vehicle.h>

using namespace std;

class Car : public Vehicle {

	public:
		
		Car();
		Car(char * licensePlate, int vinNumber, float * LLA);
		Car(const Car & car);
		~Car();
		
		Car operator= (const Car & c);
		
		char * getPlates();
		void setPlates(char * licensePlate);
		int getThrottle();
		void setThrottle(int throttle);
		
		void drive(int throttle);
		void move(float *LLA);
		
		friend ostream & operator<< (ostream & os, const Car & c);
		
	
	private:
		
		char m_plates[MAX_ARRAY_SIZE];
		int m_throttle;
		
	
};

#endif
