#include <iostream>
//This class contains all the function prototypes and data types I will be using for my program.
class RentalCar
{
	int m_year;
	char m_make[256], m_model[256];
	float m_price;
	bool m_available;
public:
	RentalCar();
	RentalCar(int year, char make[], char model[], float price, bool available);
	int getYear();
	void setYear(int y);
	char getMake();
	void setMake(char make[]);
	char getModel();
	void setModel(char model[]);
	float getPrice();
	void setPrice(float p);
	bool getAvailable();
	void setAvailable(bool a);

	void print();
	void estimateCost(int days);

};




//Functions outside of the class

void printAll(struct RentalAgency inventory[]);
void mostExpensive(struct RentalAgency inventory[]);
void printAvailable(struct RentalAgency inventory[]);

