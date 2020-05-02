//This file contains the template implementation of the NodeStack class.

#ifndef NODESTACK_HPP_
#define NODESTACK_HPP_

#include <cstddef>
#include <iostream>
#include <NodeStack/Node.hpp>

template <typename T>
class NodeStack{

	template <class U>
	friend std::ostream & operator<<(std::ostream & os, const NodeStack<U> & nodeStack);
	
	public:
		NodeStack();
		NodeStack(std::size_t count, const T & value = T());
		NodeStack(const NodeStack<T> & other);
		~NodeStack();
		
		NodeStack<T> & operator=(const NodeStack<T> & rhs);
		
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
		Node<T> * m_top;
};

//class template NodeStack method implementations

template <class U>
std::ostream & operator<<(std::ostream & os, const NodeStack<U> & nodeStack){

	nodeStack.serialize(os);
	
	return os;
	
}




template <typename T>
NodeStack<T>::NodeStack() : m_top(nullptr){

	std::cout<<"Template: NodeStack : Default-ctor"<<std::endl;
	
}

template <typename T>
NodeStack<T>::NodeStack(std::size_t count, const T & value) : m_top(nullptr){ //dynamically allocates node elements in the stack count times

	for(int i=0; i<count; i++)
	{
		Node<T> * newNode = new Node<T>(value, m_top);
		
		m_top=newNode;
	}
	
	std::cout<<"Template: NodeStack : Param-ctor"<<std::endl;
	
}

template <typename T>
NodeStack<T>::NodeStack(const NodeStack<T> & other){ //dynamically allocates node elements based on copying the elements of another already existing stack

	for(Node<T> * currOther=other.m_top; currOther!=nullptr; currOther=currOther->m_next)
	{
		
		Node<T> * newNode = new Node<T>(currOther->m_data, m_top);
		m_top=newNode;
	}
	
	std::cout<<"Template: NodeStack : Copy-ctor"<<std::endl;
	
}
		

template <typename T>
NodeStack<T>::~NodeStack(){ //deletes dynamically allocated data when destroying object

	Node<T> * curr = m_top;
	
	while(curr!=nullptr)
	{
		Node<T> * temp=curr->m_next;
		delete curr;
		curr=temp;
	}
	
	m_top=nullptr;
	
	std::cout<<"Template: NodeStack : Destructor"<<std::endl;
		
}

template <typename T>	
NodeStack<T> & NodeStack<T>::operator=(const NodeStack<T> & rhs){ //sets one nodestack equal to the elements of another, by first deallocating then reallocating.

	Node<T> * curr=m_top;

	while(curr!=nullptr)
	{
		Node<T> * temp=curr->m_next;
		delete curr;
		curr=temp;
	}
	
	m_top=nullptr;
	
	for(Node<T> * currOther=rhs.m_top; currOther!=nullptr; currOther=currOther->m_next)
	{
		
		Node<T> * newNode = new Node<T>(currOther->m_data, m_top);
		m_top=newNode;
		
	}
	
	std::cout<<"Template: NodeStack : Operator= success"<<std::endl;
	
return *this;

}
	

template <typename T>		
T & NodeStack<T>::top(){ //returns reference to the data on top of the stack

	std::cout<<"Top returned as reference."<<std::endl;
	return m_top->m_data;
	
}

template <typename T>
const T & NodeStack<T>::top() const{

	std::cout<<"Top returned as reference."<<std::endl;
	return m_top->m_data;
	
}

template <typename T>		
void NodeStack<T>::push(const T & value){ //pushes new element to the top of the stack

	Node<T> * newNode = new Node<T>(value, m_top);
	m_top=newNode;
	
	std::cout<<"Template: NodeStack : New element pushed to the top."<<std::endl;
	
}

template <typename T>
void NodeStack<T>::pop(){ //pops element from the top only if stack is not empty.

	if(m_top==nullptr)
	{
		
		std::cout<<"Cannot pop element from NodeStack. Stack empty."<<std::endl;
		
	}
	else
	{
	
		Node<T> * delNode=m_top;
		Node<T> * temp=m_top->m_next;
		
		delete [] delNode;
		delNode=nullptr;
		
		m_top=temp;
		
		std::cout<<"Template: NodeStack : Element popped from the top."<<std::endl;
		
	}
	
}
	
template <typename T>		
std::size_t NodeStack<T>::size() const{ //iterates through the stack and increments a counter variable to be returned.

	std::size_t count=0;
	
	for(Node<T> * curr=m_top; curr!=nullptr; curr=curr->m_next)
	{
	
		count++;
		
	}
	
return count;

}
		

template <typename T>
bool NodeStack<T>::empty() const{ //if m_top is null, then the stack is empty. Otherwise not empty

	if(m_top==nullptr)
	{
	
		std::cout<<"Template: NodeStack : The stack is empty."<<std::endl;
		return true;
		
	}
	else
	{
	
		std::cout<<"Template: NodeStack : The stack is not empty."<<std::endl;
		return false;
		
	}
	
}

template <typename T>
bool NodeStack<T>::full() const{ //a dynamically allocated stack of nodes can never be full

	std::cout<<"Template: NodeStack : The stack can never be full."<<std::endl;
	
	return false;
	
}

template <typename T>
void NodeStack<T>::clear(){ //sets all elements of the stack to null, effectively clearing it of any valid data.

	Node<T> * curr=m_top;
	
	while(curr!=nullptr) //sets all elements to null ptr
	{
	
		Node<T> * temp=curr->m_next;
		
		curr=nullptr;
		
		curr=temp;
		
	}
	
	std::cout<<"The list is now clear."<<std::endl;
	
	m_top=nullptr;
	
}

template <typename T>
void NodeStack<T>::serialize(std::ostream & os) const{ //prints all elements of the stack top to bottom

	if(m_top==nullptr)
	{
	
		os<<"Template: NodeStack : Cannot output an empty stack."<<std::endl;
		
	}
	else
	{
	
		os<<"Template: NodeStack : The stack contains elements (from top to bottom):"<<std::endl;
		
		for(Node<T> * curr=m_top; curr!=nullptr; curr=curr->m_next)
		{
		
			os<<curr->m_data<<", ";
			
		}
		
	}
	
}
		

		
#endif
		
		
		
