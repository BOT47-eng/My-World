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
String();
String(char  * arr);
String(const int number , const int totalNumberOfZeros = -1); // Number you wanna convert to string and if you wanna have multiple zeros , pass the 0 as number and numberOfZeros you wanna add.
String(const String &s) ;
////////////////////////
////// Destructors 
~String() ;

///////////////////////////
////// Operator Overloading


/// TODO

///Done 
String operator=(String &s) ; 
String operator=(char *arr) ; 
String operator=(const int& number) ; 
String operator=(std::string &s) ; 


String operator+= (String &s);
friend std::ostream& operator <<(std::ostream &os  , const String& s) ; 






////////////////////////////
/// Helper functions 


/// TODO 


/// Done 
int sizeOf(char * arr) ;

}; 




#endif