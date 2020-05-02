//This is the test driver for the NodeStack and ArrayStack template class implementations of project 10.

#include <ArrayStack/ArrayStack.hpp>
#include <NodeStack/NodeStack.hpp>

#include <iostream>

using namespace std;

int main()

{

////////////////////////////////////////////////////////////ArrayStack Testing-methods////////////////////////////////////////////////////////////

cout<<"Now testing ArrayStack methods with int type stacks..."<<endl;

cout<<"Testing default-ctor (1):"<<endl;

	ArrayStack <int> int_arrayStackDefault;

cout<<"Testing param-ctor (2):"<<endl;

	ArrayStack <int> int_arrayStackParam(5,1);
	cout<<int_arrayStackParam<<endl;
	
cout<<"Testing copy-ctor (3):"<<endl;

	ArrayStack <int> int_arrayStackCopy(int_arrayStackParam);
	cout<<int_arrayStackCopy<<endl;
	
cout<<"Testing operator= (5):"<<endl;

	ArrayStack <int> int_arrayOperatorEqual(5,3);
	int_arrayStackParam=int_arrayOperatorEqual;
	cout<<int_arrayStackParam<<endl;
	
cout<<"Testing top (6):"<<endl;

	if((int_arrayStackParam.empty())==false)
	{
	
		int_arrayStackParam.top();
		
	}
	else{}

cout<<"Testing push (7):"<<endl;

	int_arrayStackParam.push(45);
	cout<<int_arrayStackParam<<endl;
	
cout<<"Testing pop (8):"<<endl;

	int_arrayStackParam.pop();
	cout<<int_arrayStackParam<<endl;
	
cout<<"Testing size (9):"<<endl;

	std::size_t sizeOf=0;
	sizeOf=int_arrayStackParam.size();
	
	cout<<"The size of the specified int type stack is: "<<sizeOf<<endl;
	
cout<<"Testing empty (10):"<<endl;

	int_arrayStackParam.empty();
	
cout<<"Testing full (11):"<<endl;

	int_arrayStackParam.full();
	
cout<<"Testing clear (12):"<<endl;

	cout<<"Before clear..."<<endl<<int_arrayStackParam<<endl;
	int_arrayStackParam.clear();
	cout<<"After clear..."<<endl<<int_arrayStackParam<<endl;
	
////////////////////////////////////////////////////////////NodeStack Testing-methods////////////////////////////////////////////////////////////
	
cout<<"Now testing NodeStack methods with double type stacks..."<<endl;

cout<<"Testing default-ctor (1):"<<endl;

	NodeStack <double> double_nodeStackDefault;

cout<<"Testing param-ctor (2):"<<endl;

	NodeStack <double> double_nodeStackParam(5,1.2);
	cout<<double_nodeStackParam<<endl;
	
cout<<"Testing copy-ctor (3):"<<endl;

	NodeStack <double> double_nodeStackCopy(double_nodeStackParam);
	cout<<double_nodeStackCopy<<endl;
	
cout<<"Testing operator= (5):"<<endl;

	NodeStack <double> double_nodeOperatorEqual(5,3.5);
	double_nodeStackParam=double_nodeOperatorEqual;
	cout<<double_nodeStackParam<<endl;
	
cout<<"Testing top (6):"<<endl;

	if((double_nodeStackParam.empty())==false)
	{
	
		double_nodeStackParam.top();
		
	}
	else{}

cout<<"Testing push (7):"<<endl;

	double_nodeStackParam.push(32.7);
	cout<<double_nodeStackParam<<endl;
	
cout<<"Testing pop (8):"<<endl;

	double_nodeStackParam.pop();
	cout<<double_nodeStackParam<<endl;
	
cout<<"Testing size (9):"<<endl;

	std::size_t sizeOfTwo=0;
	sizeOfTwo=double_nodeStackParam.size();
	
	cout<<"The size of the specified int type stack is: "<<sizeOfTwo<<endl;
	
cout<<"Testing empty (10):"<<endl;

	double_nodeStackParam.empty();
	
cout<<"Testing full (11):"<<endl;

	double_nodeStackParam.full();
	
cout<<"Testing clear (12):"<<endl;

	cout<<"Before clear..."<<endl<<double_nodeStackParam<<endl;
	double_nodeStackParam.clear();
	cout<<"After clear..."<<endl<<double_nodeStackParam<<endl;

cout<<"Now calling all object destructors..."<<endl;

return 0;

}






