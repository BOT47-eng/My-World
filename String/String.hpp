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
String(const int number);
String(const String &s) ;
////////////////////////
////// Destructors 
~String() ;

///////////////////////////
////// Operator Overloading
friend std::ostream& operator <<(std::ostream &os  , const String& s) ; 






////////////////////////////
/// Helper functions 
int sizeOf(char * arr) ;

}; 




#endif