//This is the test driver for Project 9 which tests the ArrayQueue and NodeQueue implementations.

#include <iostream>
#include <sourceFolder/NodeQueue.h>
#include <sourceFolder/ArrayQueue.h>
#include <sourceFolder/DataType.h>
#include <cstring>

using namespace std;

int main()
{

cout<<"-------------------------------------------------------Now testing the ArrayQueue methods-------------------------------------------------------"<<endl;

cout<<"Testing default-ctor (ArrayQueue)"<<endl;

	ArrayQueue queueDefault;
	
cout<<"Testing param-ctor (ArrayQueue)"<<endl;
	
	DataType valueParam(2, 0.0);
	ArrayQueue queueParam(5, valueParam);
	cout<<queueParam<<endl;
	
cout<<"Testing copy-ctor (ArrayQueue)"<<endl;

	ArrayQueue queueCopy(queueParam);
	cout<<queueCopy<<endl;
	
cout<<"Testing operator= (ArrayQueue)"<<endl;

	DataType valueEqual(1,0.5);
	ArrayQueue queueEqual(5, valueEqual);
	queueParam=queueEqual;
	cout<<queueParam<<endl;
	
cout<<"Testing front() (ArrayQueue)"<<endl;

	if(queueParam.size()!=0)
	{
	DataType front=queueParam.front();
	}
	
cout<<"Testing back() (ArrayQueue)"<<endl;
	
	if(queueParam.size()!=0)
	{
	DataType back=queueParam.back();
	}
	
cout<<"Testing push() (ArrayQueue)"<<endl;

	DataType valuePush(4, 0.2);
	queueParam.push(valuePush);
	cout<<queueParam<<endl;
	
cout<<"Testing pop() (ArrayQueue)"<<endl;

	queueParam.pop();
	cout<<queueParam;
	
cout<<"Testing size() (ArrayQueue)"<<endl;
	
	size_t theSizeArray=0;
	theSizeArray=queueParam.size();
	cout<<"The size of the passed queue is: "<<theSizeArray<<endl;
	
cout<<"Testing empty() (ArrayQueue)"<<endl;

	queueParam.empty();
	
cout<<"Testing full() (ArrayQueue)"<<endl;

	queueParam.full();
	
cout<<"Testing clear() (ArrayQueue)"<<endl;

	cout<<queueParam<<endl;
	queueParam.clear();
	cout<<queueParam<<endl;
	
/////////////////////////////////////////////////////////////////////				//////////////////////////////////////////////////////////////////////////////////////////////////////
					/////////////////////////////////// NODE-BASED QUEUE ////////////////////////////////////
					
cout<<"-------------------------------------------------------Now testing the NodeQueue methods-------------------------------------------------------"<<endl;

cout<<"Testing default-ctor (NodeQueue)"<<endl;

	NodeQueue queueDefaultNQ;
	
cout<<"Testing param-ctor (NodeQueue)"<<endl;
	
	NodeQueue queueParamNQ(5, valueParam);
	cout<<queueParamNQ<<endl;
	
cout<<"Testing copy-ctor (NodeQueue)"<<endl;

	NodeQueue queueCopyNQ(queueParamNQ);
	cout<<queueCopyNQ<<endl;
	
cout<<"Testing operator= (NodeQueue)"<<endl;

	NodeQueue queueEqualNQ(5, valueEqual);
	queueParamNQ=queueEqualNQ;
	cout<<queueParamNQ<<endl;
	
cout<<"Testing front() (NodeQueue)"<<endl;

	if(queueParamNQ.empty()==false)
	{
	DataType frontNQ=queueParamNQ.front();
	}
	
cout<<"Testing back() (NodeQueue)"<<endl;

	if(queueParamNQ.empty()==false)
	{
	DataType backNQ=queueParamNQ.back();
	}
	
cout<<"Testing push() (NodeQueue)"<<endl;

	queueParamNQ.push(valuePush);
	cout<<queueParamNQ<<endl;
	
cout<<"Testing pop() (NodeQueue)"<<endl;

	queueParamNQ.pop();
	cout<<queueParamNQ<<endl;
	
cout<<"Testing size() (NodeQueue)"<<endl;
	
	size_t theSizeNode=0;
	theSizeNode=queueParamNQ.size();
	cout<<"The size of the passed queue is: "<<theSizeNode<<endl;
	
cout<<"Testing empty() (NodeQueue)"<<endl;

	queueParamNQ.empty();
	
cout<<"Testing full() (NodeQueue)"<<endl;

	queueParamNQ.full();
	
cout<<"Testing clear() (NodeQueue)"<<endl;

	cout<<queueParamNQ<<endl;
	queueParamNQ.clear();
	cout<<queueParamNQ<<endl;


cout<<"-------------------------------------------------------Now calling all object destructors-------------------------------------------------------"<<endl;

return 0;

}

