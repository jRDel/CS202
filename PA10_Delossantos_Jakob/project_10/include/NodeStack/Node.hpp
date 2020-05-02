//This file shows a sample implementation of a Node class template, for the purposes of CS-202
 
#ifndef NODE_HPP_
#define NODE_HPP_

#include <cstddef>
#include <iostream>

// forward declaration of a Queue class template
template <typename> class NodeStack;

template <typename T>
class Node{

  // friendship relationship to Queue class template FOR THE SAME type T as Node
  friend class NodeStack<T>;

  public:
	Node(const T & value, Node<T> * next = nullptr); 
	
	T & data();
	const T & data() const;
	
  private:
	T m_data;
	Node<T> * m_next;
};
	
//class template Queue method implementations

template <typename T>
Node<T>::Node(const T & value, Node<T> * next) 
  : m_data(value)
  , m_next(next)
{}

template <typename T>
T & Node<T>::data() {
	return m_data;
}

template <typename T>
const T & Node<T>::data() const {
	return m_data;
}

#endif
