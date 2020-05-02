//This source file contains the class definition for ArrayList.

#include <iostream>
#include <sourceFolder/ArrayList.h>
#include <sourceFolder/DataType.h>
#include <cstring>

using namespace std;

ostream & operator<<(std::ostream & os, const ArrayList & arrayList){ //(i)

	os<<"The array list holds the following DataType valid values:"<<endl;
	
	for(int i=0; i<arrayList.m_size; i++)
	{
	
		os<<arrayList.m_array[i]<<", ";
		
	}
	
	os<<"There are "<<arrayList.m_maxsize-arrayList.m_size<<" invalid values in the container"<<endl;
	
return os;

}
						   
ArrayList::ArrayList(){	//(1)

	m_size=0;
	m_maxsize=m_size+1;
	m_array=new DataType[m_maxsize];
	
	cout<<"Default-ctor call (Array)"<<endl;
	
}
							    		
ArrayList::ArrayList(size_t count, const DataType & value){		//(2)
	
	m_size=count;
	m_maxsize=m_size;
	m_array=new DataType[m_maxsize];
	
	for(int i=0; i<m_maxsize; i++)
	{
		m_array[i]=value;
	}
	
	cout<<"Parametrized-ctor call (Array)"<<endl;
	
}

ArrayList::ArrayList(const ArrayList & other){				    	//(3)

	m_size=other.m_size;
	m_maxsize=other.m_maxsize;
	
	m_array=new DataType[other.m_maxsize];
	
	for(int i=0; i<m_maxsize; i++)
	{
	
		m_array[i]=other.m_array[i];
	}
	
	cout<<"Copy-ctor call (Array)"<<endl;
	
}

ArrayList::~ArrayList(){							    			//(4)

	delete [] m_array;
	m_array=nullptr;

	cout<<"Destructor call (Array)"<<endl;

}

ArrayList & ArrayList::operator= (const ArrayList & rhs){		//(5)
	
	delete [] m_array;
	
	m_array=new DataType[m_maxsize];
	
	m_size=rhs.m_size;
	m_maxsize=rhs.m_maxsize;
	
	for(int i=0; i<m_maxsize; i++)
	{
	
		m_array[i]=rhs.m_array[i];
		
	}
	
	
cout<<"Operator= successful."<<endl;
	
return *this;

}

DataType * ArrayList::front(){

	DataType empty;
							     		//(6)
	if(m_array[0]==empty)
	{
		cout<<"There is no front. List empty."<<endl;
		return nullptr;
	}
	
	else
	{
		cout<<"Front succeeded."<<endl;
		return m_array;
	}

}

DataType * ArrayList::back(){						                //(7)

	DataType empty;

	if(m_array[m_size-1]==empty)
	{
		cout<<"There is no back. List empty."<<endl;
		return nullptr;
	}
	
	else
	{
		cout<<"Back succeeded."<<endl;
		
		/*for(int i=0; i<m_size; i++)
		{
			m_array++;
		}*/
		return m_array;
	}
	
}
DataType * ArrayList::find(const DataType & target, DataType * & previous, DataType * start){	//(8)

		int i=0;
		
		DataType empty;
		
		
		
		if(start!=nullptr)
		{
			m_array=start;
			m_array++;
		}
		
		DataType * startSpot=m_array;
		
		while(!(m_array[i]==empty))
		{
	
			if(m_array[i]==target)
			{
				if(i=0) //only works on if the first is the target
				{
					previous=nullptr;
					cout<<"Target found as first element."<<endl;
					return m_array;
				}
				else{}
				
			//previous=m_array[i-1];
			
			for(int z=0; z<i-1; z++)
			{
				m_array++;
			}
			
			previous=m_array;
			
			m_array=startSpot;
			
			cout<<"Target found."<<endl;
			
			for(int j=0; j<i; j++)
			{
				m_array++;
			}
			
			return m_array;
			
			}
			else{}
		i++;
		}
		
		previous=nullptr;
		cout<<"Target not found in the list."<<endl;
		return nullptr;
		
}
	
DataType * ArrayList::insertAfter(const DataType & target, const DataType & value){	//(9) 

for(int i=0; i<m_maxsize; i++)
{
	if(m_array[i]==target) //is container big enough to hold another value, and spot in array is the target
	{
	resize(m_maxsize+1);
		if(m_size<m_maxsize) 
		{
		int targetSpot=i; //saves spot of target
		++i;  //increment one to make sure target isnt moved over also
		int insertSpot=i; //saves spot of where element is inserted.
			for(int j=m_size; j>insertSpot; j--)
			{ //moves elements over to make room for new element.
				m_array[j]=m_array[j-1];
			}
		
		
	
		m_array[insertSpot]=value;
		
		cout<<"Inserted after successfully."<<endl;
		m_size=m_size+1;
		return m_array+insertSpot;
	
		}
		
	}
	
	else
	{}
	
}


cout<<"Could not insert."<<endl;
return nullptr;

}
	
DataType * ArrayList::insertBefore(const DataType & target, const DataType & value){ //(10)

for(int i=0; i<m_maxsize; i++)
{
	if(m_array[i]==target) //is container big enough to hold another value, and spot in array is the target
	{
	resize(m_maxsize+1);
	
		if(m_size<m_maxsize)
		{
		int insertSpot=i; //saves spot of where element is inserted.

			for(int j=m_size; j>insertSpot; j--) //moves the elements after target over.
			{ 
				m_array[j]=m_array[j-1];
			}
		
		m_array[i]=value; //i was where the original target was but it moved one over, so now the element we inserted is in that spot.
		
		cout<<"Inserted before successfully."<<endl;
		m_size=m_size+1;
		return m_array+insertSpot;
	
		}
		
	}
	
	else
	{}
	
	
}

}

DataType * ArrayList::erase(const DataType & target){		 		//(11)

	for(int i=0; i<m_maxsize; i++)
	{
		if(m_array[i]==target)
		{
			for(int j=i; j<m_size-1; j++)
			{
				m_array[j]=m_array[j+1];
			}
			
		m_size--; //one less valid value
		
		if(i==m_size)
		{
			cout<<"Value was last in list. Still erased."<<endl;
			return nullptr;
		}
		else
		{
			cout<<"Value successfully erased."<<endl;
			for(int j=0; j<i; j++)
			{
				m_array++;
			}
			
			return m_array;
		}
		
		}
	}

}
			
			

			
			

DataType & ArrayList::operator[] (size_t position){				//(12)

	return m_array[position];
	
	/*for(int i=0; i<position; i++)
	{
		m_array++;
	}
	
	return m_array;*/
	
}
    
size_t ArrayList::size() const{									//(13)
	return m_size;
	
}

bool ArrayList::empty() const{										//(14)

	if(m_array==nullptr){
		cout<<"The list is empty."<<endl;
		return true;
	}
	else{
		cout<<"The list is not empty."<<endl;
		return false;
	}
	
}

void ArrayList::clear(){											//(15)	

delete [] m_array;
m_array = new DataType[m_maxsize];
m_array=nullptr;
m_size=0;

	cout<<"List is now clear."<<endl;
}
  
void ArrayList::resize(size_t count){		               			//(16)	

	DataType defaultItem(1, 0.0);

	//cout<<"HERE"<<endl;

	ArrayList tempArrayList(count, defaultItem);
	
	for(int i=0; i<m_size; i++){
		tempArrayList.m_array[i]=m_array[i];
	}
	
	
	tempArrayList.m_size=m_size;

	m_maxsize=count;



		delete [] m_array;

		m_maxsize=count;
		
		m_array = new DataType[count]; //something wrong here
		
		m_size=tempArrayList.m_size;
		
		for(int j=0; j<m_size; j++){
			m_array[j]=tempArrayList.m_array[j];
		}
		
		
			
cout<<"List is now resized to fit specified count: "<<count<<endl;			

}



	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

