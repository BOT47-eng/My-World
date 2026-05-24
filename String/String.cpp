#include "String.hpp"
#include "cstring" // Only using it if user wants to assign my String a string from original library


/////////////////////////////////////////////
////// Constructors Definition

String::String() : Array(nullptr) , size(0)
{
}
String::String(char *arr) : Array(nullptr) , size(0)
{
    size = sizeOf(arr); 
    this->Array = new char[size + 1] ;
    for(int st =  0 ; st <= size - 1 ; st++)
    {
        this->Array[st] = *(arr + st) ; 
    } 
    this->Array[size] = '\0' ;  
}
String::String(const int number) : Array(nullptr) , size(0)
{
    // It has three different cases 
    // 1. Positive Number
    // 2. Negative Number
    // 3. Zero or Multiple Zeros

    // Getting the size
    if(number >  0)
    {
        int copy = number ; 
        while(copy > 0)
        {
            copy /= 10 ;
            size++ ;
        }
        copy = number;
        Array  = new char[size +  1] ;
        int st = size - 1 ;  
        while(copy > 0)
        {
            Array[st] = ((copy  % 10) + '0') ; 
            copy /= 10 ; 
            st-- ;
            st = (st < 0) ?  0 : st ; 
        }
        Array[size] = '\0' ;
    }
    else if(number < 0)
    {

    } 
}
String::String(const String& s)
{
    size = s.size ;  
    this->Array = new char[size + 1] ;
    for(int st =  0 ; st <= size - 1 ; st++)
    {
        this->Array[st] = *(s.Array + st) ; 
    } 
    this->Array[size] = '\0' ;  
}
////// Constructor Definition Section Ends
////////////////////////////////////////////


////////////////////////////////
//// Destructors

String::~String()
{
    if(Array != nullptr)
    {
        delete [] Array ; 
        Array = nullptr ; 
    }
}
//// Destructor Definition Ends
////////////////////////////////




/////////////////////////////////
/// Operator Overloaing
std::ostream& operator <<(std::ostream &os  , const String& s)
{
    os << s.Array ; 
    return os  ; 
}









////////////////////////////
/// Helper functions 
int String::sizeOf(char * arr)
{
    int c = 0 ; 
    char *temp = arr ; 
    while(*temp != '\0')
    {
        c++ ; 
        temp++ ;
    }
    return c ;
}
