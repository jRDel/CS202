//This source file contains the class definition for the NodeQueue class.

#include <iostream>
#include <sourceFolder/NodeQueue.h>

using namespace std;


ostream & operator<<(std::ostream & os, const NodeQueue & nodeQueue){

	nodeQueue.serialize(os);
	
	return os;
}
	
NodeQueue::NodeQueue(){

	m_front=nullptr;
	m_back=nullptr;
	
	cout<<"Default-ctor (NodeQueue)"<<endl;
	
}

NodeQueue::NodeQueue(size_t size, const DataType & value) : m_front(nullptr), m_back(nullptr){

	for(int i=0; i<size; i++)
	{
		Node * newNode = new Node(value, m_front);
		
		if(i==0) //sets m_back to the first node created, or when i==0
		{
			m_back=newNode;
			m_back->m_next=nullptr;
		}
		
		m_front=newNode;
	}
	
	cout<<"Param-ctor (NodeQueue)"<<endl;
	
}
	

NodeQueue::NodeQueue(const NodeQueue & other) : m_front(nullptr), m_back(nullptr){

	int first=0;

	for(Node * currOther = other.m_front; currOther!=nullptr; currOther=currOther->m_next) //copies other queue elements based on if it reaches the end of other queue or not
	{
	
		Node * newNode = new Node(currOther->m_data, m_front);
	
		if(first==0) //sets m_back to the first node created, or when i==0
		{
			m_back=newNode;
			m_back->m_next=nullptr;
		}	
		
		m_front=newNode;
		++first;
	}
	
	cout<<"Copy-ctor call (NodeQueue)"<<endl;
	
}

NodeQueue::~NodeQueue(){

	Node * curr=m_front;
	
	while(curr!=nullptr)
	{
		Node * temp=curr->m_next;
		delete curr;
		curr=temp;
	}
	
	m_front=nullptr;
	m_back=nullptr;

cout<<"Destructor call (NodeQueue)"<<endl;

}

	
		
NodeQueue & NodeQueue::operator=(const NodeQueue & rhs){ //works in a similar fashion to copy ctor except it deallocates memory first , then reallocates

	int first=0;
	Node * curr=m_front;
	
	while(curr!=nullptr)
	{
		Node *temp=curr->m_next;
		delete curr;
		curr=temp;
	}
	
	m_front=nullptr;
	m_back=nullptr;

	for(Node * currOther = rhs.m_front; currOther!=nullptr; currOther=currOther->m_next)
	{
	
		Node * newNode = new Node(currOther->m_data, m_front);
	
		if(first==0)
		{
			m_back=newNode;
			m_back->m_next=nullptr;
		}	
		
		m_front=newNode;
		++first;
		
	}
	
cout<<"Operator= successful"<<endl;	
	
return *this;

}
	
DataType & NodeQueue::front(){ //front/back only called if not empty (condition loop in test driver)

	cout<<"Front found. Returned pointer to front."<<endl;
	return m_front->m_data;

}

const DataType & NodeQueue::front() const{

	cout<<"Front found. Returned pointer to front."<<endl;
	return m_front->m_data;

}

DataType & NodeQueue::back(){

	cout<<"Back found. Returned pointer to back."<<endl;
	return m_back->m_data;
	
}

const DataType & NodeQueue::back() const{

	cout<<"Back found. Returned pointer to back."<<endl;
	return m_back->m_data;
	
}

		
void NodeQueue::push(const DataType & value) //inserts new element either after m_back, or if empty, then it inserts and sets front and back to new node
{

	Node * newNode = new Node(value);
  	if(m_back!=nullptr)
  	{
  		cout<<"Node successfully pushed into back of queue."<<endl;
  		m_back->m_next=newNode;
  		m_back=newNode;
  	}
  	else
  	{
  		cout<<"Queue was empty, but inserted new single element into it."<<endl;
  		m_front=newNode;
  		m_back=newNode;
 	}
 	
 
 	
}

void NodeQueue::pop(){ //pops from the back only if the queue is not empty

	if(m_front==nullptr)
	{
		cout<<"Nothing to pop; Queue is empty."<<endl;
	}
	else
	{
		Node * delNode = m_front;
 		Node * temp = m_front->m_next;
  
  		delete [] delNode; 
 		delNode=nullptr;
  
  		m_front=temp;
  		
  		cout<<"Element popped from the front."<<endl;
  	}
  	
}

size_t NodeQueue::size() const{

	size_t count=0;
	
	for(Node * curr=m_front; curr!=nullptr; curr=curr->m_next)
	{
		count++;
	}
	
	return count;
	
}

bool NodeQueue::empty() const{

	if(m_front==nullptr)
	{
		cout<<"Queue empty."<<endl;
		return true;
	}
	else
	{
		cout<<"Queue not empty."<<endl;
		return false;
	}
	
}

bool NodeQueue::full() const{

	cout<<"NodeQueue can never be full."<<endl;
	return false;
	
}

void NodeQueue::clear(){

	Node * curr=m_front;
	
	while(curr!=nullptr) //sets all elements to null ptr
	{
	
		Node * temp=curr->m_next;
		
		curr=nullptr;
		
		curr=temp;
		
	}
	
	cout<<"The list is now clear."<<endl;
	
	m_front=nullptr;
	m_back=nullptr;
	
}
	

void NodeQueue::serialize(std::ostream & os) const{ //outputs only when queue is not empty

	Node * curr = m_front;
	
	if(m_front==nullptr)
	{
		os<<"Cannot output an empty queue."<<endl;
	}
	else
	{
	
  		while(curr!=nullptr)
  		{
  			os<<curr->data()<<", ";
  			curr=curr->m_next;
  		}
  		
  	}
  	
}







