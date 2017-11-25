#include "string.h"

//initialzition list 
String::String():name(NULL),len(0){}
String::~String()
{
    if(name)
    {
        delete [] name;
        name = NULL;
    }
}
String::String(const String & obj){
    //oper_string(obj);
}
//the = operator function for an object it will only call the oper string function 
String & String::operator =(const String & obj)
{
    if(this == &obj)
        return *this;
    oper_string(obj);
        return *this;
}
//the function that will do the work for the = operator for a class object 
//it will check if there's data first and delete it if there is 
//then it will get the length and then create a new char based on that and then copy into it 
int String::oper_string(const String & obj)
{
        if(this->name)
            delete [] this->name;
        this->len = strlen(obj.name);
        this->name = new char [this->len +1];
        strcpy(this->name,obj.name);
        return 1;
}
//the wrapper for the == operator it will return the op check function and that it 
bool String::operator ==(const String & obj) const
{
    return op_check(obj);
}
//the the check function for the == operator for an obj 
//it will check the name memebers by using str compare and return false and treu based on that 
int String::op_check(const String & obj) const
{
    if(strcmp(this->name,obj.name) == 0)
        return 1;
    else 
        return 0;
}

//the wrapper function for the assgin operator that will call the oper char function to do the work
String & String::operator =(const char * temp)
{
    if(this->name == temp)
        return *this;
    oper_char(temp);
    return *this;
}
//the = operator second function that will be doing the work for the wrapper 
//it will get len of the char and make a new name and then copy the data to it from the char 
int String::oper_char(const char * temp)
{
        if(this->name)
            delete [] this->name;
        this->len = strlen(temp);
        this->name = new char [len+1];
        strcpy(this->name,temp);
        return 1;
}
//the == operator which will only call the op check function to do the work
bool String::operator ==(const char * temp) const
{
    return op_check_char(temp);
}
//the check function that will compare a string class with a char and return false or true based on that 
//also it will check first before comaring if both are not NULL
int String::op_check_char(const char * temp) const
{
    if(!temp || !this->name)
        return 0;
    if(strcmp(temp,this->name) == 0)
        return 1;
    else
        return 0;
}

//the extraction operator that will cout whatever inside the string class which is the name char
ostream & operator <<(ostream & out,const String & obj)
{
    if(obj.name)
        out << obj.name;
    return out;
}
//the insertion operator for the string class that will make insert thing dierctly into the class which will make my program much easier;
istream & operator >>(istream & in, String & obj)
{
    if(obj.name)
        delete [] obj.name;
    char temp [SIZE];
    in.get(temp,SIZE,'\n');
    cin.ignore(100,'\n');
    obj.len = strlen(temp);
    obj.name = new char[obj.len+1];
    strcpy(obj.name,temp);
    return in;
}
//the less than operator which will basically will take care of comparing both names and return true and false based on that 
bool String::operator <(const String & source) const
{
    if(strcmp(this->name,source.name) < 0)
        return false;
    else
        return true;
}
//the bigger than operator which will be taking care of doing strcmp for both names and return true and false based on that 
bool String::operator >(const String &source) const
{
    if(strcmp(this->name,source.name) > 0 || strcmp(this->name,source.name) ==0)
        return true;
    else
        return false;
}
/// Apps Functions ///
//just a function to ask yuser for repeatation and return true or false based on that 
bool again()
{
    char response;
    cout << "\n\nWould You Like To See The MENU AGAIN(y- Yes/n- Quit): ";
    cin >> response; cin.ignore(100,'\n');
    if(response == 'y' || response == 'Y')
        return true;
    else
        return false;
}
