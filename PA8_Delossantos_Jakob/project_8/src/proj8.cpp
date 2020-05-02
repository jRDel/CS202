//This is my test driver for the Node and Array based lists. -Jakob Delossantos

#include <iostream>
#include <sourceFolder/NodeList.h>
#include <sourceFolder/ArrayList.h>
#include <sourceFolder/DataType.h>
#include <cstring>

using namespace std;

int main()
{

cout<<"-------------------------------------------------------Now testing the ArrayList container methods-------------------------------------------------------"<<endl;

cout<<"Testing default-ctor..."<<endl;

	ArrayList arrayContainerOne;
	cout<<arrayContainerOne;


cout<<"Testing param-ctor..."<<endl;

	DataType valuePass(1,0.5);
	ArrayList arrayContainerTwo(5, valuePass); //first the number of elements, then what they will be initialized to.
	cout<<arrayContainerTwo;

cout<<"Testing copy-ctor..."<<endl;

	ArrayList arrayContainerThree(arrayContainerTwo); //should be the same as arrayContainerTwo, or the param-ctor
	cout<<arrayContainerThree;


cout<<"Testing operator=..."<<endl;

	DataType valuePassTwo(2,0.0);
	ArrayList arrayContainerEqual(5, valuePassTwo);
	arrayContainerTwo=arrayContainerEqual;
	cout<<arrayContainerTwo;

cout<<"Testing front()..."<<endl;

	DataType * front = arrayContainerTwo.front();
	
cout<<"Testing back()..."<<endl;

	DataType * back = arrayContainerTwo.back();
	
cout<<"Testing find()..."<<endl;

	DataType findThis(2,0.0);
	DataType * previousPtr;
	arrayContainerTwo.find(findThis, previousPtr);
	
cout<<"Testing insertAfter..."<<endl;
	
	ArrayList insertAfterContainer(5, findThis);
	cout<<insertAfterContainer;
	insertAfterContainer.insertAfter(findThis, valuePass); //purposefully can't this time
	cout<<insertAfterContainer;
	
	
cout<<"Testing insertBefore..."<<endl;

	ArrayList insertBeforeContainer(5, findThis);
	cout<<insertBeforeContainer;
	insertBeforeContainer.insertBefore(findThis, valuePass);
	cout<<insertBeforeContainer;

cout<<"Testing erase..."<<endl;

	cout<<arrayContainerThree;
	arrayContainerThree.erase(valuePass);
	cout<<arrayContainerThree;
	
cout<<"Testing size..."<<endl;

	size_t theSize=0;
	theSize=arrayContainerThree.size();
	cout<<"The size is:"<<theSize<<endl;
	
cout<<"Testing empty..."<<endl;

	arrayContainerThree.empty();
	
cout<<"Testing clear..."<<endl;

	cout<<arrayContainerThree;
	arrayContainerThree.clear();
	cout<<arrayContainerThree;
	arrayContainerThree.empty();
	

	
/////////////////////////////////////////////////////////////////////				//////////////////////////////////////////////////////////////////////////////////////////////////////
					/////////////////////////////////// NODE-BASED LIST ////////////////////////////////////
					
cout<<"-------------------------------------------------------Now testing the NodeList container methods-------------------------------------------------------"<<endl;

cout<<"Testing default-ctor..."<<endl;

	NodeList nodeContainerOne;
	cout<<nodeContainerOne;

cout<<"Testing param-ctor..."<<endl;

	NodeList nodeContainerTwo(5, valuePass); //first the number of elements, then what they will be initialized to.
	cout<<nodeContainerTwo;
	
cout<<"Testing copy-ctor..."<<endl;

	NodeList nodeContainerThree(nodeContainerTwo); //should be the same as arrayContainerTwo, or the param-ctor
	cout<<nodeContainerThree;

cout<<"Testing operator=..."<<endl;

	NodeList nodeContainerEqual(5, valuePassTwo);
	nodeContainerTwo=nodeContainerEqual;
	cout<<nodeContainerTwo;

cout<<"Testing front()..."<<endl;

	Node * frontOne = nodeContainerTwo.front();
	
cout<<"Testing back()..."<<endl;

	Node * backOne = nodeContainerTwo.back();
	
cout<<"Testing find()..."<<endl;

	Node * previousPtrOne;
	nodeContainerTwo.find(findThis, previousPtrOne);
	
cout<<"Testing insertAfter..."<<endl;

	
	cout<<nodeContainerTwo;
	nodeContainerTwo.insertAfter(findThis,valuePass);
	cout<<nodeContainerTwo;
	
cout<<"Testing insertBefore..."<<endl;

	cout<<nodeContainerThree;
	nodeContainerThree.insertBefore(valuePass,findThis);
	cout<<nodeContainerThree;
	
cout<<"Testing erase..."<<endl;

	cout<<nodeContainerThree;
	nodeContainerThree.erase(findThis);
	cout<<nodeContainerThree;
	
cout<<"Testing size..."<<endl;

	size_t theSizeOne=0;
	theSizeOne=nodeContainerThree.size();
	cout<<"The size is:"<<theSizeOne<<endl;
	
cout<<"Testing empty..."<<endl;

	nodeContainerThree.empty();
	cout<<nodeContainerThree;
	
cout<<"Testing clear..."<<endl;

	nodeContainerThree.clear();
	cout<<nodeContainerThree;
	nodeContainerThree.empty();
	

cout<<"-------------------------------------------------------Now calling all object destructors-------------------------------------------------------"<<endl;

return 0;

}

	





