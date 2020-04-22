//This program reads in names from a file then sorts them alphabetically and by length; Then, it prints them to the screen.

#include <iostream>
#include <fstream>

#define ENTRIES 10
#define MAX_LENGTH 8
#define FILESIZE 50

using namespace std;

void readNames(char inputFile[], char namesArray[][MAX_LENGTH+1]); //Reads names from file.

void printNamesToTerminal(char namesArray[][MAX_LENGTH+1], int originalOrder[], int newOrder[], int colAmount); //Prints names from namesArray to terminal.

void sortNamesAlphabetic(char namesArray[][MAX_LENGTH+1], int originalOrder[], int newOrder[], int colAmount); //Sorts names alphabetically in the array.

void sortNamesByLength(char namesArray[][MAX_LENGTH+1], int originalOrder[], int newOrder[], int colAmount); //Sorts names by length in the array.

void printNamesToFile(char outputFile[],char namesArray[][MAX_LENGTH+1], int originalOrder[], int newOrder[], int colAmount); //Prints names alphabetically and by length to an output file.

void myStringCopy( char destination[], const char source[]); //copies characters from a source into destination until NULL is found.

int myStringLength(const char str[]); //counts the number of characters in an array until NULL is found.

int myStringCompare(const char str1 [], const char str2[]); //returns 0 when strings match; returns <=-1 if the first char that does not match has a lower value in str1 than in str2; returns >=1 if the first char that does not match has a higher value in str1 than in str2.


int main()
{

	char listNames[ENTRIES][MAX_LENGTH+1]; //Initializing arrays and variables.
	char fileNameInput[FILESIZE];
	char fileNameOutput[FILESIZE];
	int listOrder[ENTRIES];
	int newListOrder[ENTRIES];
	int length=ENTRIES;

	for(int i=0;i<ENTRIES; i++) //Populating the order list.
	{
		listOrder[i]=i;
		newListOrder[i]=i;
	}

	cout<<"Please enter the name of the file for input:"<< endl;
	cin >> fileNameInput;

	cout<<"Please enter the name of the file for output:"<< endl;
	cin>> fileNameOutput;

	readNames(fileNameInput, listNames); //Reads in the names from file to listNames array.

	cout<<"Unsorted Data (Original Input Order and Name)"<<endl;
	cout<<"============================="<<endl;

		printNamesToTerminal(listNames, listOrder, newListOrder, length); //Prints names from listNames to terminal.
	
	cout<<"Alphabetically Sorted Data (Original Input Order and Name)"<<endl;
	cout<<"============================="<<endl;

		sortNamesAlphabetic(listNames, listOrder, newListOrder, length); //Alphabetically sorts the names in listNames with their original order preceding them.
		printNamesToTerminal(listNames, listOrder, newListOrder, length); //Prints the alphabetically sorted names to the terminal.

	cout<<"Sorted-by-Length -and- Alphabetically Data (Original Input Order and Name)"<<endl;
	cout<<"============================="<<endl;

		sortNamesByLength(listNames, listOrder, newListOrder, length); //Sorts the name by length first, and then alphabetically.
		printNamesToTerminal(listNames, listOrder, newListOrder, length); //Prints the names sorted by length, then alphabetically to the terminal and to the output file.
		printNamesToFile(fileNameOutput, listNames, listOrder, newListOrder, length);


return 0;

}

void readNames(char inputFile[], char namesArray[][MAX_LENGTH+1])
{

	ifstream inputStream;

	inputStream.open(inputFile); //Opens the file for input.

	for(int i=0; i<ENTRIES; i++)
	{
		
			inputStream >> namesArray[i];
	}
	
	inputStream.close();
}

void printNamesToTerminal(char namesArray[][MAX_LENGTH+1], int originalOrder[], int newOrder[], int colAmount)
{
	
	for(int i=0; i<ENTRIES; i++)
	{
		cout << originalOrder[i] <<" "<< namesArray[i] << endl; //Prints to terminal using loop over array.
	}

}

void sortNamesAlphabetic(char namesArray[][MAX_LENGTH+1], int originalOrder[], int newOrder[], int colAmount)
{
	
	char namesArrayCopy[MAX_LENGTH+1];
	int temporder=0;
	int result=0;
		
	
	for(int i=0; i<ENTRIES-1; i++)
	{
		for(int j=i+1; j<ENTRIES; j++)
		{
		result=myStringCompare(namesArray[i], namesArray[j]); //Takes result of myStringCompare to decide to sort or not.
			
			if(result==-1)
			{
				//do nothing because already sorted correctly.
			
			}
			else if(result==1)
			{
				myStringCopy(namesArrayCopy, namesArray[i]);
				myStringCopy(namesArray[i], namesArray[j]);
				myStringCopy(namesArray[j], namesArrayCopy);
				temporder=originalOrder[i];
				originalOrder[i]=originalOrder[j];
				originalOrder[j]=temporder;
			}
			else if(result==0)
			{
				//do nothing because already sorted correctly.
			}
		
		}

	}
}

void sortNamesByLength(char namesArray[][MAX_LENGTH+1], int originalOrder[], int newOrder[], int colAmount)
{

	char namesArrayCopy[MAX_LENGTH+1];
	int temporder=0;
	int result=0;
	int resultone=0;


	for(int i=0; i<ENTRIES-1; i++)
	{
		for(int j=i+1; j<ENTRIES; j++)
		{
			result=myStringLength(namesArray[i]); //Gets results of string lengths of adjacent element then decides to sort or not.
			resultone=myStringLength(namesArray[j]);
			
			if(result>resultone)
			{
				myStringCopy(namesArrayCopy, namesArray[i]);
				myStringCopy(namesArray[i], namesArray[j]);
				myStringCopy(namesArray[j], namesArrayCopy);
				temporder=originalOrder[i];
				originalOrder[i]=originalOrder[j];
				originalOrder[j]=temporder;
			}
			else
			{
				//do nothing
			}
	
		}
	}
}
void printNamesToFile(char outputFile[],char namesArray[][MAX_LENGTH+1], int originalOrder[], int newOrder[], int colAmount)
{
	
	ofstream outputStream;
	outputStream.open(outputFile); //Prints names to file, whether it be alphabetically or by length.

	for(int i=0; i<ENTRIES; i++)
	{
		outputStream << originalOrder[i] <<" "<< namesArray[i] << endl;
	}
	
	outputStream.close();
	
}

void myStringCopy( char destination[], const char source[])
{
	int stop=0;
	for(int i=0; source[i]!='\0'; i++) //Copies the string until NULL is found, then sets last spot in destination to NULL.
	{	
		destination[i]=source[i];
		stop=i;
	}
	
	destination[stop+1]='\0';
}
		

int myStringLength(const char str[])
{
	int length=0;
	
	for(int i=0; str[i]!='\0'; i++)
	{
		length++;
	}
	
	return length;

}

int myStringCompare(const char str1 [], const char str2[])//returns 0 when strings match; returns <=-1 if the first char that does not match has a lower value in str1 than in str2; returns >=1 if the first char that does not match has a higher value in str1 than in str2.
{
	
	for(int i=0; str1[i]!='\0' || str2[i]!='\0'; ++i)
	{
		
		if(str1[i]<str2[i])
		{
		return -1;
		}
		else if(str1[i]>str2[i])
		{
		return 1;
		}
	}

return 0;

}

		
		

	





			
	

	


		


	
	






