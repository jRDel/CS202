//This file contains the ArrayQueue class definition.

#include <iostream>
#include <sourceFolder/ArrayQueue.h>
#include <sourceFolder/DataType.h>

using namespace std;

ostream & operator<<(std::ostream & os, const ArrayQueue & arrayQueue)
{

	arrayQueue.serialize(os);
	
	return os;
	
}
	
ArrayQueue::ArrayQueue()
{

	DataType emptyType;

	m_front=0;
	m_back=ARRAY_CAPACITY-1;
	m_size=0;
	
	for(int i=0; i<m_back; i++)
	{
		
		m_array[i]=emptyType;
		
	}
	
	cout<<"Default-ctor (ArrayQueue)"<<endl;
	
}

ArrayQueue::ArrayQueue(size_t count, const DataType & value)
{

	m_size=count;
	
	for(int i=0; i<m_size; i++)
	{
		
		m_array[i]=value;
		
	}
	
	m_front=0;
	m_back=m_size-1;
	
	cout<<"Param-ctor (ArrayQueue)"<<endl;
	
}

ArrayQueue::ArrayQueue(const ArrayQueue & other)
{

	m_size=other.m_size;
	
	for(int i=0; i<m_size; i++)
	{
	
		m_array[i]=other.m_array[i];
		
	}
	
	m_front=other.m_front;
	m_back=other.m_back;
	
	cout<<"Copy-ctor (ArrayQueue)"<<endl;
	
}

ArrayQueue::~ArrayQueue()
{

	cout<<"Destructor (ArrayQueue)"<<endl;
	
}
		
ArrayQueue & ArrayQueue::operator= (const ArrayQueue & rhs)
{

	m_size=rhs.m_size;
	
	for(int i=0; i<m_size; i++)
	{
	
		m_array[i]=rhs.m_array[i];
		
	}
	
	m_front=rhs.m_front;
	m_back=rhs.m_back;
	
	cout<<"Operator= success (ArrayQueue)"<<endl;
	
return *this;

}
	
		
DataType & ArrayQueue::front() //front/back only called if not empty (condition loop in test driver)
{

	cout<<"Front was found; Returned pointer to front."<<endl;
	return m_array[m_front];
	
}

const DataType & ArrayQueue::front() const
{

	cout<<"Front was found; Returned pointer to front."<<endl;
	return m_array[m_front];
	
}

DataType & ArrayQueue::back()
{

	cout<<"Back was found; Returned pointer to back."<<endl;
	return m_array[m_back];

}

const DataType & ArrayQueue::back() const
{

	cout<<"Back was found; Returned pointer to back."<<endl;
	return m_array[m_back];
	
}
	
void ArrayQueue::push(const DataType & value) //only pushes if not full
{

	if(m_size==ARRAY_CAPACITY) /*Does not need to check if back passes front vice versa because m_size is incremented if pushed.*/
	{
	
		cout<<"Cannot push new value. Queue is full."<<endl;
	
	}
	else
	{
	
		m_back = (m_back+1) % ARRAY_CAPACITY;
		m_array[m_back] = value;
		++m_size;
		
		cout<<"Element successfully pushed."<<endl;
		
	}
	
}

void ArrayQueue::pop() //only pops if queue is not empty.
{

DataType empty;

	if(m_size==0) /*Does not need to check if back passes front vice versa because m_size is decremented if popped.*/
	{
	
		cout<<"Cannot pop from the front. Queue is empty."<<endl;
	
	}
	else
	{
	
		m_array[m_front]=empty;
		m_front = (m_front+1) % ARRAY_CAPACITY;
		--m_size;
		
		cout<<"Element successfully popped."<<endl;
		
	}
	
}

size_t ArrayQueue::size() const
{

	return m_size;
	
}

bool ArrayQueue::empty() const
{

	if(m_size==0)
	{
	
		cout<<"Queue is empty."<<endl;
		return true;
			
	}
	else
	{
	
		cout<<"Queue is not empty."<<endl;
		return false;
			
	}
	
}

bool ArrayQueue::full() const
{

	if(m_size==ARRAY_CAPACITY)
	{
	
		cout<<"Queue is full."<<endl;
		return true;
			
	}
	else
	{
	
		cout<<"Queue is not full."<<endl;
		return false;
		
	}
	
}

void ArrayQueue::clear() //sets all elements to a default-ctor datatype, so it is technically "empty"
{
	
	DataType emptyType;
	
	if(!empty())
	{
		
		for(int i=0; i<m_size; i++)
		{
		
			m_array[i]=emptyType;
			
		}
		
		m_size=0;
		m_back=m_size;
		m_front=m_size;
		
		cout<<"Queue cleared."<<endl;
		
	}
	else
	{
	
		cout<<"Cannot clear, queue is already empty."<<endl;
		
	}
	
}
void ArrayQueue::serialize(std::ostream & os) const //only outputs if the queue is not empty, and if that specific element is not empty.
{

DataType empty;

	if(m_size==0)
	{
	
		os<<"Cannot output an empty queue."<<endl;
		
	}
	else
	{
	
	os<<"The ArrayQueue contains elements: "<<endl;
	
		for(int i=0; i<ARRAY_CAPACITY; i++)
		{
			if(!(m_array[i]==empty))
			{
			os<<m_array[i]<<", ";
			}
			
		}
		
	cout<<endl;
	
	}
	
}




















