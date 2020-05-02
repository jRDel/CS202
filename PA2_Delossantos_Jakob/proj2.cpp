//This program helps users who want to rent a car, using a user menu that provides information obtained from a cars file.

#include <iostream>
#include <fstream>
#define NO_CARS 5
using namespace std;

//Function prototypes.
void readInFile(struct RentalCar carArray[]);
void outputTerminal(struct RentalCar carArray[], int orderArray[]);
void outputFile(struct RentalCar carArray[]);
void sortCars(struct RentalCar carArray[], int orderArray[]);
void swapCars(char a[10], char b[10]);
void rentCar(struct RentalCar carArray[], int orderArray[]);
void whichCar(struct RentalCar carArray[], int orderArray[]);

//Making the struct.
struct RentalCar{
		int year;
		char make[10];
		char model[10];
		float price;
		bool available;
		}car[NO_CARS];
int main()
{


int order[5]={0, 1, 2, 3, 4};
int option=0;



do //do-while for the user menu, with a switch statement for user to choose option.
{
	cout<<"Hello, welcome to Delossantos Car Rental Service. Please choose from our following options:"<<endl;
	cout<<"(1) Read data from input file."<<endl;
	cout<<"(2) Print out all data for each of our cars."<<endl;
	cout<<"(3) Print out all data for each of our cars to an output file."<<endl;
	cout<<"(4) Sort our list of cars by ascending price."<<endl;
	cout<<"(5) Estimated costs for available rental cars."<<endl;
	cout<<"(6) Choose an available car to rent."<<endl;
	cout<<"(7) Exit program."<<endl;

	cin>>option;

	switch(option)
	{
		case 1: readInFile(car);
			break;
		
		case 2: outputTerminal(car, order);
			break;
	
		case 3: outputFile(car);
			break;
		
		case 4: sortCars(car, order);
			break;

		case 5: rentCar(car, order);
			break;

		case 6: whichCar(car, order);
			break;

	}

}while(option!=7);

return 0;

}

//Reads from input.
void readInFile(struct RentalCar carArray[])
{
char inputFileName[50];
cout<<"What is the input file name?:"<<endl;
cin>>inputFileName;
ifstream inputStream;
inputStream.open(inputFileName);

	for(int index=0; index<NO_CARS; index++)
	{
		inputStream>>car[index].year>>car[index].make>>car[index].model>>car[index].price>>car[index].available;
	}
}

//Outputs to terminal.
void outputTerminal(struct RentalCar carArray[],int orderArray[])
{
int index=0;	

for(index=0; index<NO_CARS; index++)
	{
		cout<<"["<<orderArray[index]<<"]:"<<car[index].year<<" "<<car[index].make<<" "<<car[index].model<<" , $"<<car[index].price<<" per day , Available:"<<boolalpha<<car[index].available<<endl;
	}
}

//Outputs to user chosen output file.
void outputFile(struct RentalCar carArray[])
{
char outputFileName[50];
cout<<"What is the output file name?:"<<endl;
cin>>outputFileName;
ofstream outputStream;
outputStream.open(outputFileName);
	
	for(int index=0; index<NO_CARS; index++)
	{
		outputStream<<car[index].year<<" "<<car[index].make<<" "<<car[index].model<<" , $"<<car[index].price<<" per day , Available:"<<boolalpha<<car[index].available<<endl;
	}
}

//Used to swap the make or model strings for cars.
void swapCars(char a[10], char b[10])
{
char tempc[10];

	for(int index=0; index<10; index++)
	{
		tempc[index]=a[index];
	}
	
	for(int index=0; index<10; index++)
	{
		a[index]=b[index];
	}

	for(int index=0; index<10; index++)
	{
		b[index]=tempc[index];
	}
}

//Sorts cars using a bubblesort, in ascending price order. Switches positions using swapCars function.
void sortCars(struct RentalCar carArray[], int orderArray[])
{

struct RentalCar tempcar;
int temporder[NO_CARS];

for(int index=0; index<NO_CARS;index++){
temporder[index]=orderArray[index];
}

for(int index=0;index<NO_CARS; index++)
{
	for(int index2=index+1; index2<NO_CARS; index2++)
	{
		if(carArray[index].price>carArray[index2].price)
		{
			tempcar.year=carArray[index].year;
			swapCars(tempcar.make, carArray[index].make);
			swapCars(tempcar.model, carArray[index].model);
			tempcar.price=carArray[index].price;
			tempcar.available=carArray[index].available;
			temporder[index]=orderArray[index];
				
				carArray[index].year=carArray[index2].year;
				swapCars(carArray[index].make, carArray[index2].make);
				swapCars(carArray[index].model, carArray[index2].model);
				carArray[index].price=carArray[index2].price;
				carArray[index].available=carArray[index2].available;
				orderArray[index]=orderArray[index2];				

			carArray[index2].year=tempcar.year;
			swapCars(carArray[index2].make, tempcar.make);
			swapCars(carArray[index2].model, tempcar.model);
			carArray[index2].price=tempcar.price;
			carArray[index2].available=tempcar.available;
			orderArray[index2]=temporder[index];

		}
	}
}

}

//Prints estimates to rent any of the available cars.
void rentCar(struct RentalCar carArray[], int orderArray[])
{

int days;
int number[5]={0,1,2,3,4};

cout<<"How many days would you like to rent a car?:"<<endl;
cin>>days;



	for(int index=0; index<NO_CARS; index++)
	{
		if(carArray[index].available==true)
		{
			cout<<"["<<number[index]<<"]:"<<carArray[index].year<<" "<<carArray[index].make<<" "<<carArray[index].model<<" ,Total Cost: $"<<carArray[index].price*days<<endl;
		}
	}


}

//Accepts user input to choose a car to rent, then prints success or error messages, as well as changing availability if rented.
void whichCar(struct RentalCar carArray[], int orderArray[])
{

int car;
int days;

cout<<"Which car would you like to rent?:"<<endl;
cin>>car;
cout<<"For how many days?:"<<endl;
cin>>days;

	if(carArray[car].available==true) 
	{
		carArray[car].available=false;
		cout<<"Rented successfully for $"<<carArray[car].price*days<<endl;
	}
	
	else
	{
		cout<<"Car is not available."<<endl;
	}
}
	
































