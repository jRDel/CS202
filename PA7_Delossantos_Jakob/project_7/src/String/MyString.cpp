//This is the source file for the MyString class.

#include <iostream>
#include <String/MyString.h>
#include <cstring>

using namespace std;

//CONSTRUCTORS AND DESTRUCTORS

MyString::MyString(){                                                //(1)

	m_size=0;
	buffer_allocate(m_size);

}

MyString::MyString(const char * str){                               //(2)

	size_t size=0;
	
	size=strlen(str); //passes the length of the str into buffer_allocate

	buffer_allocate(size); //buffer_allocate takes in the length of the string then adds one to set equal to m_size (+1 for null terminator)

	strcpy(m_buffer, str);

}	
	
MyString::MyString(const MyString & other_myStr){                   //(3)

	size_t size=0;
	
	size=other_myStr.m_size-1;

	buffer_allocate(size);

	strcpy(m_buffer, other_myStr.m_buffer);

}

MyString::~MyString(){                                              //(4)

	buffer_deallocate();

}

//MEMBER FUNCTIONS FOR STRING OPERATIONS

size_t MyString::size() const{                                      //(5)

	return m_size; //returns length of string +1 because null terminator

}

size_t MyString::length() const{                                    //(6)

	return m_size-1; //returns the length of the actual string because m_size is strlength+1 so reverse it with -1

}

const char * MyString::c_str() const{                               //(7)

	return m_buffer;

}
    
//OPERATOR OVERLOADS

bool MyString::operator== (const MyString & other_myStr) const{     //(8)

		if((strcmp(m_buffer, other_myStr.m_buffer))==0){ //checks if str's are same
			return true;
		}
		else{
			return false;
		}
	
	
}

MyString & MyString::operator= (const MyString & other_myStr){      //(9)

	size_t size=0;
	size=other_myStr.m_size-1;

	buffer_deallocate(); //deallocates current info to set equal to other info
	buffer_allocate(size);
	
	strcpy(m_buffer, other_myStr.m_buffer);

return *this;

}

MyString MyString::operator+ (const MyString & other_myStr) const{  //(10)

	char stringArray[m_size+other_myStr.m_size];

	strcpy(stringArray, m_buffer);
	
	strcat(stringArray, other_myStr.m_buffer);
	
	MyString newString(stringArray);

return newString; //concats two str buffers to make an object that gets returned by value.

}

	
char & MyString::operator[] (size_t index){                         //(11a)

	return m_buffer[index];

}

const char & MyString::operator[] (size_t index) const{             //(11b)

	return m_buffer[index];

}

ostream & operator<<(std::ostream & os, const MyString & myStr){   //(12)

	os<<"Allocated Size: "<<myStr.m_size<<" String: "<<myStr.m_buffer<<endl;

return os;

}

	

//PRIVATE MEMBER FUNCTIONS

void MyString::buffer_deallocate(){                                 //(13)

	m_size=0;
	delete [] m_buffer; //deallocates the memory pointed to by m_buffer and sets size, buffer equal to 0 and nullptr
	m_buffer=nullptr;
	

}

void MyString::buffer_allocate(size_t size){                        //(14)

	m_size=size+1; //has to be +1 to account for the null terminator. size is the length of string.

	/*if(m_buffer!=nullptr){
		delete [] m_buffer;
		m_buffer=nullptr;
	}*/
	
	m_buffer=new char[m_size];

	if(m_buffer==nullptr){ //error message for nullptr's
		cout<<"ERROR: Memory allocation failed. Try again."<<endl;
		delete [] m_buffer;
		m_buffer=nullptr;
	}


}
		

	
































