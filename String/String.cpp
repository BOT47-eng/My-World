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
String::String(const int number ,const  int totalNumberOfZeros) : Array(nullptr) , size(0)
{
    // It has three different cases 
    // 1. Positive Number
    // 2. Negative Number
    // 3. Zero or Multiple Zeros

    // Getting the size
    if(number >  0) // Pos Case
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
    else if(number < 0) // Neg Case
    {
        int copy = abs(number) ; 
        while(copy > 0)
        {
            copy /= 10 ;
            size++ ;
        }
        copy = number;
        Array  = new char[size +  2] ; //  +1 extra space for neg sign 
        int st = size - 1 ;  
        while(copy > 0)
        {
            Array[st] = ((copy  % 10) + '0') ; 
            copy /= 10 ; 
            st-- ;
            st = (st < 0) ?  0 : st ; 
        }
        Array[0] = '-' ; 
        Array[size] = '\0' ;
    }
    else if(number == 0) // Zero Case  
    {
        size = (totalNumberOfZeros > 0) ? totalNumberOfZeros : 1 ; 
        Array = new char[size + 1] ; 
        int c = size  ;
        int st = size - 1 ;
        while(c  > 0)
        {
            Array[st] = '0' ;
            c-- ;
            st-- ;
            st = (st < 0) ?  0 : st ; 
        }
        Array[size] = '\0' ;
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
String::String(const bool b)
{
    if(b)
    {
        *(this) += "True" ;
    }
    else 
    {
        *(this) += "False" ;
    }
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

String String::operator+= (String &s)
{
    if(Array == nullptr || s.Array == nullptr)
    {
        return *this ;  
    }
    char arr[size] ;
    const int copySize =  size ;  
    for(int st =  0 ; st <=  size - 1 ; st++)
    {
        arr[st] = this->Array[st] ; 
    }
    delete [] Array  ; 
    Array = nullptr ; 
    size = size + s.size  ;
    Array = new char[size + 1] ;
    int idx  = 0 ; 
    for(int st = 0 ; st  <= copySize - 1 ; st++)
    {
        Array[idx++] = arr[st] ;
    } 
    for(int st = 0 ; st  <= s.size - 1 ; st++)
    {
        Array[idx++] = s.Array[st] ;
    }
    Array[size] = '\0'; 
    return *this ; 
}
String String::operator+=(char * arr)
{
    if(arr == nullptr) return *this ;    
    char copy[size] ; 
    int copySize = size ; 
    for(int st =  0 ; st <= size  - 1  ; st++)
    {
        copy[st] = this->Array[st] ; 
    }
    if(Array != nullptr)
    {
        delete [] Array  ;
        Array = nullptr ; 
    }
    size += sizeOf(arr) ; 
    Array = new char[size + 1] ;

    int idx  = 0 ; 
    for(int st = 0 ; st  <= copySize - 1 ; st++)
    {
        Array[idx++] = copy[st] ;
    } 
    for(int st = 0 ; st  <=  sizeOf(arr) - 1 ; st++)
    {
        Array[idx++] = arr[st] ;
    }
    Array[size] = '\0'; 
    return *this ; 
}
String String::operator+=(int v)
{
    String temp(v) ; 
    *(this) += temp ;
    return *this ; 
}
String String::operator+=(bool b)
{
    if(b)
    {
        *(this) += "True" ;
    }
    else 
    {
        *(this) += "False" ;
    }
    return *this ;
}


String String::operator=(String &s)
{
    if(size != s.size)
    {
        delete [] Array  ;
        Array = nullptr ;
        size = s.size ; 
        Array = new char[size  + 1] ;
        Array[size] = '\0' ; 
    }
    for(int st =  0 ; st <= size -  1 ; st++)
    {
        Array[st] = s.Array[st] ; 
    }
    return *this ; 
}
String String::operator=(String s)
{
    if(size != s.size)
    {
        delete [] Array  ;
        Array = nullptr ;
        size = s.size ; 
        Array = new char[size  + 1] ;
        Array[size] = '\0' ; 
    }
    for(int st =  0 ; st <= size -  1 ; st++)
    {
        Array[st] = s.Array[st] ; 
    }
    return *this ;
}
String String::operator=(char *arr)
{
    if(size != sizeOf(arr))
    {
        delete [] Array  ;
        Array = nullptr ;
        size = sizeOf(arr) ; 
        Array = new char[size  + 1] ;
        Array[size] = '\0' ; 
    }
    for(int st =  0 ; st <= size -  1 ; st++)
    {
        Array[st] = arr[st] ; 
    }
    return *this ; 
}
String String::operator=(const int& number) 
{
    String temp(number) ; 
    *this = temp.Array ;  
    return *this ;
}
String String::operator=(std::string &s)
{
    if(size != s.length())
    {
        delete [] Array  ;
        Array = nullptr ;
        size = s.length(); 
        Array = new char[size  + 1] ;
        Array[size] = '\0' ; 
    }
    for(int st =  0 ; st <= size -  1 ; st++)
    {
        Array[st] = s[st] ; 
    }
    return *this ; 
}
String String::operator=(bool b)
{
    if(b)
    {
        *(this) = "True" ; 
    }
    else 
    {
        *(this) = "False" ; 
    }
    return *this ; 
} 



bool String::operator== (const String & s) const 
{
    if(this->size != s.size)
    {
        return false ; 
    }
    for(int st  = 0 ; st <= size - 1 ; st++)
    {
        if(Array[st] != s.Array[st]) return false  ; 
    }
    return true ;
}
bool String::operator== (char * arr)
{
    const int s  =  sizeOf(arr) ;
    if(this->size != s)
    {
        return false; 
    }
    for(int st = 0 ; st <= s -  1 ; st++)
    {
        if(Array[st] != arr[st]) return false  ; 
    }
    return true ; 
}
bool String::operator== (std::string & S) const
{
    const int s  =  S.length()  ;
    if(this->size != s)
    {
        return false; 
    }
    for(int st = 0 ; st <= s -  1 ; st++)
    {
        if(Array[st] != S[st]) return false  ; 
    }
    return true ;
}


String String::operator*(String & s) 
{
    *(this) += s  ;
    return *this ; 
} 
String String::operator*(char * arr)
{
    *(this) += arr ;
    return *this ;  
}
// Multiplying by 0 will make it empty.
String String::operator*(int value)
{
    String temp(*this) ; 
    if(value <= 0)
    {
        temp = "" ; 
        return  temp ; 
    }
    int times = value - 1 ;
    while(times--)
    {
        temp += *this ; ;
    }
    return temp ; 
} 


std::ostream& operator <<(std::ostream &os  , const String& s)
{
    os << s.Array ; 
    return os  ; 
}

/////// Operator Overloadng Section Ends 
////////////////////////////////////////







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
