//This file contains the NodeList class definition.

#include <iostream>
#include <sourceFolder/NodeList.h>
#include <sourceFolder/DataType.h>
#include <cstring>

using namespace std;

ostream & operator<<(std::ostream & os, const NodeList & nodeList){ //(i)
		
		const Node * curr=nodeList.m_head;
		
		cout<<"The node list holds the following values:"<<endl;
		
		while(curr!=NULL)
		{
			os << curr->data()<< " ,";
			curr=curr->getNextPtr();
			
		}
		
		
		cout<< endl;
		
return os;

}

NodeList::NodeList(){								    		  //(1)

	m_head=nullptr;
	cout<<"Default-ctor call"<<endl;
	
}

NodeList::NodeList(size_t count, const DataType & value) : m_head (nullptr) {		  //(2)

	for(size_t i=0; i<count; i++)
	{
		Node * newNode = new Node(value, m_head); //makes a new node at beginning
		m_head=newNode; //makes the head point to this new node
	}
	
	cout<<"Param-ctor call"<<endl;
	
}

NodeList::NodeList(const NodeList & other) : m_head (nullptr) {					  //(3)

	for(Node * currOther = other.m_head; currOther!=nullptr; currOther=currOther->m_next)
	{
	
		Node * newNode = new Node(currOther->m_data, m_head);
		m_head=newNode;
		
	}
	
	cout<<"Copy-ctor call"<<endl;
	
}

NodeList::~NodeList(){							   			  //(4)

	Node * curr=m_head;
	
	while(curr!=nullptr)
	{
		Node * temp=curr->m_next;
		delete curr;
		curr=temp;
	}
	
m_head=nullptr;

cout<<"Destructor call (Node)"<<endl;

}


NodeList & NodeList::operator= (const NodeList & rhs){		  //(5)

	Node * curr=m_head;
	
	while(curr!=nullptr)
	{
		Node *temp=curr->m_next;
		delete curr;
		curr=temp;
	}
	
	m_head=nullptr;

	for(Node * currOther = rhs.m_head; currOther!=nullptr; currOther=currOther->m_next)
	{
	
		Node * newNode = new Node(currOther->m_data, m_head);
		m_head=newNode;
		
	}
	
cout<<"Operator= successful"<<endl;	
	
return *this;
	
}

Node * NodeList::front(){							    		  //(6)

	if(m_head==nullptr)
	{
		cout<<"There is no front. List is empty."<<endl;
		return nullptr;
	}
	else
	{
		cout<<"Front succeeded."<<endl;
		Node * current=m_head;
		return current;
	}
}

Node * NodeList::back(){										  //(7)

	if(m_head==nullptr)
	{
		cout<<"There is no back. List is empty."<<endl;
		return nullptr;
	}
	else
	{
		Node * curr=m_head;
	
		while(curr!=nullptr)
		{
			curr=curr->m_next;
		}
		
		cout<<"Back succeeded."<<endl;
		return curr;
	}
	
}
	
Node * NodeList::find(const DataType & target, Node * & previous, const Node * start){	//(8)

	int firstTime=0;

	for(Node * curr = (start==nullptr) ? m_head: start->m_next; curr!=nullptr; curr=curr->m_next)
	{
		
		if(firstTime==0)
		{
			if(curr->m_data==target)
			{
				cout<<"Target found as first element."<<endl;
				previous=nullptr;
				return curr;
			}
		}
		else
		{
		
		Node * lookAhead = curr->m_next;
		
			if(lookAhead->m_data==target)
			{
				cout<<"Target found."<<endl;
				previous=curr;
				return lookAhead;
			
			}
			
		}
	
	firstTime++;
	
	}
	
	/*while(curr!=nullptr)
	{
		if(curr->m_data == target)
		{
			if(firstTime==0)
			{
				previous=nullptr; //first time through the loop and first element is target, then previous is nullptr
				return curr; //found
			}
			else
			{
				curr = (start==nullptr) ? m_head : start -> m_next; //set curr equal to where the search first started.
				
				for(int i=0; i<=count; i++) //count will be the number of times loop iterated before the target was found.
				{
					curr=curr->m_next; 
				}
				
				previous=curr; //curr should now be at the previous spot of target
				
				curr = (start==nullptr) ? m_head : start -> m_next; //restart curr again 
				
				for(int j=0; i<=count+1; j++)
				{
					curr=curr->m_next; //go to spot of target, which is the time the loop iterated before the target was found +1
				}
				
				return curr; //found
			
			}
	
		count++;	
		firstTime++;	
		curr=curr->m_next; //traverse list
	
		}
	}*/
	
cout<<"Target not found."<<endl;
return nullptr;

}
	
Node * NodeList::insertAfter(const DataType & target, const DataType & value){	 //(9)   

	Node * newNode = new Node(value);
	
	
if(m_head==nullptr)
{
	m_head=newNode;
	newNode->m_next=nullptr;
	cout<<"List was empty so created new node at the beginning."<<endl;
	return newNode;
}

else
{

	for(Node * curr = m_head; curr!=nullptr; curr=curr->m_next)
	{
		if(curr->m_data == target)
		{
			Node * orig_next=curr->m_next;
			curr->m_next=newNode;
			newNode->m_next=orig_next;
			cout<<"Inserted successfully."<<endl;
			return newNode;
		}
	}

cout<<"Could not insert."<<endl;	
return nullptr;
	
}

}

    
Node * NodeList::insertBefore(const DataType & target, const DataType & value){ //(10)

	Node * newNode = new Node(value);
	
	
if(m_head==nullptr)
{
	m_head=newNode;
	newNode->m_next=nullptr;
	cout<<"List was empty so created new node at the beginning."<<endl;
	return newNode;
}

else
{

	Node * newNode = new Node(value);

	for(Node * curr = m_head; curr!=nullptr; curr=curr->m_next)
	{
	Node * previous=curr-1;
	//Node * aheadNode= curr->m_next; //looks ahead of the curr by two
	
		if(curr->m_data == target) //if we know the next node will be the target, we need to insert after the curr spot and remap to target.
		{	
			if(m_head==curr)
			{
			newNode->m_next=curr;
			m_head=newNode;
			}
			else
			{
			previous->m_next=newNode;
			newNode->m_next=curr;
			}
		}
			
			
			cout<<"Inserted successfully."<<endl;
			return newNode;
		}
	}
	
	
cout<<"Could not insert."<<endl;
return nullptr;
	
}



Node * NodeList::erase(const DataType & target){ 			      //(11)

if(m_head->m_data==target) //if first element is the one to be deleted
{

Node * orig_head = m_head;
m_head = m_head->m_next;
delete orig_head;

cout<<"Erased the first element."<<endl;

return m_head;

}

else
{


	for(Node * curr=m_head; curr!=nullptr; curr=curr->m_next)
	{
		Node * del_node=curr->m_next;
		
		if(del_node!=nullptr && del_node->m_data == target) //if the next node is the target, then we will remap the curr next to the node two spots over
		{
				
			if(del_node->m_next==nullptr)
			{
			
			curr->m_next=del_node->m_next; //del node is curr next, so the next is technically curr next next
			
			delete del_node;
			cout<<"Element erased was the last in the list."<<endl;
			return nullptr;
			
			}
			else
			{
			
			curr->m_next=del_node->m_next; //del node is curr next, so the next is technically curr next next
			
			delete del_node;
			cout<<"Element erased successfully."<<endl;
			return curr->m_next;
			}
		}
		
	}
	
}

}

DataType & NodeList::operator[] (size_t position){			  //(12a)

	Node * curr=m_head;
	
	for(int i=0; i<position; i++)
	{
		curr=curr->m_next;
	}
	
	return curr->m_data;
	
}

const DataType & NodeList::operator[] (size_t position) const{  //(12b)

	Node * curr=m_head;
	
	for(int i=0; i<position; i++)
	{
		curr=curr->m_next;
	}
	
	return curr->m_data;
	
}
    
size_t NodeList::size() const{								  //(13)

	size_t count=0;
	
	for(Node * curr=m_head; curr!=nullptr; curr=curr->m_next)
	{
		count++;
	}
	
return count;	
	
}

bool NodeList::empty() const{									  //(14)

	if(m_head==nullptr)
	{
		cout<<"The list is empty"<<endl;
		return true;
		
	}
	else
	{
		cout<<"The list is not empty."<<endl;
		return false;
		
	}
	
}

void NodeList::clear(){										  //(15)

	Node * curr=m_head;
	
	while(curr!=nullptr)
	{
	
		Node * temp=curr->m_next;
		
		curr=nullptr;
		
		curr=temp;
		
	}
	
	cout<<"The list is now clear."<<endl;
	
	m_head=nullptr;
	
}	






























