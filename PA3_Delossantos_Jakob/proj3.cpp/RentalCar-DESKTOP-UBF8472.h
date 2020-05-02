//This is my header file which contains the class RentalCar, the struct RentalAgency, as well as additional functions I created.
#include <iostream>
#include <fstream>

//This class contains all the function prototypes and data types I will be using for my program.
using namespace std;
class RentalCar
{
	int m_year;
	char m_make[255], m_model[255];
	float m_price;
	bool m_available;
public:
	RentalCar();
	RentalCar(int year, const char make[], const char model[], float price, bool available);
	int getYear();
	void setYear(int y);
	const char* getMake();
	void setMake(char make[]);
	const char* getModel();
	void setModel(char model[]);
	float getPrice();
	void setPrice(float p);
	bool getAvailable();
	void setAvailable(bool a);
	void print(struct RentalAgency agencyCars[]);
	void estimateCost(struct RentalAgency agencyCars[], int anum, int cnum, int days);
	
};

struct RentalAgency
{
	char name[255];
	int zipcode[5];
	RentalCar inventory[5];
	
};



//Functions outside of the class

void readFile(RentalAgency agencyCars[]);
void mostExpensive(struct RentalAgency array[]);
void printAvailable(struct RentalAgency array[]);

