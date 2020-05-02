//This file contains the template implementation of an ArrayStack class.

#ifndef ARRAYSTACK_HPP_
#define ARRAYSTACK_HPP_

#include <cstddef>
#include <iostream>

const size_t ARRAY_CAPACITY = 1000;

template <typename T>
class ArrayStack{

	template <class U>
	friend std::ostream & operator<<(std::ostream & os, const ArrayStack<U> & arrayStack);
	
	public:
		ArrayStack();
		ArrayStack(std::size_t count, const T & value);
		ArrayStack(const ArrayStack<T> & other);
		~ArrayStack();
		
		ArrayStack<T> & operator=(const ArrayStack<T> & rhs);
		
		T & top();
		const T & top() const;
		
		void push(const T & value);
		void pop();
		
		std::size_t size() const;
		bool empty() const;
		bool full() const;
		void clear();
		void serialize(std::ostream & os) const;
	private:
		T m_container[ARRAY_CAPACITY];
		std::size_t m_top;
		
};

//class template ArrayStack method implementations

template <class U>
std::ostream & operator<<(std::ostream & os, const ArrayStack<U> & arrayStack){

	arrayStack.serialize(os);
	
	return os;
	
}

template <typename T>
ArrayStack<T>::ArrayStack(){ //no valid data

	m_top=0;

std::cout<<"Template : ArrayStack : Default-ctor"<<std::endl;

}

template <typename T>
ArrayStack<T>::ArrayStack(std::size_t count, const T & value){ //initializes all values to passed value of type T

	m_top=count;

	for(int i=m_top; i>0; i--)
	{
		m_container[i]=value;
	}
	
std::cout<<"Template : ArrayStack : Param-ctor"<<std::endl;	
	
}

template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T> & other){ //technically works exact same as operator=

	m_top=other.m_top;
	
	for(int i=m_top; i>0; i--)
	{
		m_container[i]=other.m_container[i];
	}
	
std::cout<<"Template : ArrayStack : Copy-ctor"<<std::endl;	
	
}

template <typename T>
ArrayStack<T>::~ArrayStack(){
	
std::cout<<"Template : ArrayStack : Destructor"<<std::endl;	
	
}

template <typename T>		
ArrayStack<T> & ArrayStack<T>::operator=(const ArrayStack<T> & rhs){ //works same as copy ctor except not new obj

	m_top=rhs.m_top;
	
	for(int i=m_top; i>0; i--)
	{
		m_container[i]=rhs.m_container[i];
	}
	
std::cout<<"Template : ArrayStack : Operator= success"<<std::endl;

return *this;

}

template <typename T>		
T & ArrayStack<T>::top(){ //returns reference to top element

	return m_container[m_top];
	
std::cout<<"Template : ArrayStack : Top() success"<<std::endl;
	
}

template <typename T>
const T & ArrayStack<T>::top() const{

	return m_container[m_top];
	
std::cout<<"Template : ArrayStack : Top() success"<<std::endl;

}

template <typename T>		
void ArrayStack<T>::push(const T & value){ //pushes new element at the top as long as not full.

	if(m_top==ARRAY_CAPACITY)
	{
		std::cout<<"Cannot push new value on top of the ArrayStack. Stack full."<<std::endl;
	}
	else
	{
		m_top=m_top+1;
		m_container[m_top]=value;
		std::cout<<"Template : ArrayStack : New element pushed to the top."<<std::endl;
	}

}
		

template <typename T>
void ArrayStack<T>::pop(){ //pops element from the top as long as the stack is not empty

	if(m_top==0)
	{
		std::cout<<"Cannot pop value from ArrayStack. Stack empty."<<std::endl;
	}
	else
	{
		--m_top;
		std::cout<<"Template : ArrayStack : Element popped from the top."<<std::endl;
	}
	
}

template <typename T>		
std::size_t ArrayStack<T>::size() const{ //returns the m_top, or number of elements in the container

	return m_top;
	std::cout<<"Template : ArrayStack : Returned size of stack."<<std::endl;
	
}

template <typename T>
bool ArrayStack<T>::empty() const{ //if m_top is 0, then stack empty

	if(m_top==0)
	{
		std::cout<<"Template : ArrayStack : The stack is empty."<<std::endl;
		return true;
	}
	else
	{
		std::cout<<"Template : ArrayStack : The stack is not empty."<<std::endl;
		return false;
	}
	
}

template <typename T>
bool ArrayStack<T>::full() const{ //if m_top is at capacity, then full

	if(m_top==ARRAY_CAPACITY)
	{
		std::cout<<"Template : ArrayStack : The stack is full."<<std::endl;
		return true;
	}
	else
	{
		std::cout<<"Template : ArrayStack : The stack is not full."<<std::endl;
		return false;
	}

}
template <typename T>
void ArrayStack<T>::clear(){ //setting m_top to 0 technically is clearing the stack, as pushing new elements just overwrites everything

	m_top=0;
	std::cout<<"Template : ArrayStack : Stack is now cleared."<<std::endl;
	
}

template <typename T>
void ArrayStack<T>::serialize(std::ostream & os) const{ //prints out stack from top to bottom

	if(m_top==0)
	{
		os<<"Template : ArrayStack : Cannot output an empty stack."<<std::endl;
	}
	else
	{
		os<<"Template : ArrayStack : The stack contains (from top to bottom): " <<std::endl;
		
		for(int i=m_top; i>0; i--)
		{
			os<<m_container[i]<<", ";
		}
	}
	
}
		
#endif





		
