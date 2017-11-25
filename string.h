#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

const int SIZE = 50; // const size for all arrays so that the user can input whatever

//const char for each file 
const char games[] = "games.txt"; 
const char edu []= "edu.txt";
const char social [] = "social.txt";

class String 
{
    public:
        String();
        ~String();
        String(const String &);

        //operators for the string class
        String & operator =(const String &);
        String & operator =(const char *);
        bool operator ==(const String &) const;
        bool operator ==(const char *)const;
        bool operator > (const String &) const;
        bool operator < (const String &)const;
        friend ostream & operator <<(ostream &,const String &);
        friend istream & operator >>(istream &,String &);

        //test function 
        void test();


    protected:
        char * name;
        int len;

        //the operators functions 
        int oper_char(const char *);
        int op_check(const String &) const;
        int op_check_char(const char *)const;
        int oper_string(const String &);
};

bool again(); //function for check user for a repeatation 
