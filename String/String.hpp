#include <iostream>

#ifndef STRING_CPP
#define STRING_CPP

class String
{
public : // No Concept of encapsulation exists in my dictionary 

char *Array ; 
int size ;




////////////////////////
////// Constructors  


// TODO 
String(const float) ; 
String(const double) ; 


/// Done 
String();
String(char  *);
String(const int , const int = -1); // Number you wanna convert to string and if you wanna have multiple zeros , pass the 0 as number and numberOfZeros you wanna add.
String(const String &) ;
String(const bool) ; 

////////////////////////
////// Destructors 
~String() ;

///////////////////////////
////// Operator Overloading


/// TODO
String operator=(float) ; 
String operator=(double) ; 

String operator+=(float) ; 
String operator+=(double) ;




///Done 
String operator=(String &) ; 
String operator=(String) ; 
String operator=(char *) ; 
String operator=(const int&) ; 
String operator=(std::string &) ; 
String operator=(bool) ; 


String operator+= (String &);
String operator+=(char *) ;
String operator+=(bool);
String operator+=(int); 


bool operator== (const String &) const ; 
bool operator== (std::string &) const ; 
bool operator== (char *) ; 



String operator*(String &) ; 
String operator*(char *) ; 
String operator*(int) ; 



friend std::ostream& operator <<(std::ostream &  , const String&) ; 



///////////////////////////////////////////
//// Templates , Since they are inside the class for some function , i can't define them outside
template <typename T = char> 
T getValue(const int index)
{
    if(index < 0  || index >= size)
    {
        return ' ' ;
    }

    if(typeid(T) == typeid(int) || typeid(T) == typeid(double) || typeid(T) == typeid(float))
    {
        return static_cast<T>(this->Array[index] - '0'); 
    }
    else if(typeid(T) == typeid(bool))
    {
        if(this->Array[index] == '0') return false ; 
        else return true ; 
    }
    else
    {
        return this->Array[index] ; 
    }
    return ' ' ;
}






////////////////////////////
/// Helper functions 


/// TODO 


/// Done 
int sizeOf(char *) ;
};



#endif