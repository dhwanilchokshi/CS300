#include "terminal.h"
using namespace std;

//Terminal class

Terminal::Terminal(): member_numbers(NULL), provider_numbers(NULL), manager_numbers(NULL), operator_numbers(NULL), member_status(NULL)
{
    read();
}
int Terminal::read()
{
    return 1;
}
int Terminal::menu(int user_type)
{
    cout<<"Welcome -name-\n"
        <<"//////////////////////////////////////////////"<<endl;
    do 
    {
        cout<<"What would you like to do? - Please choose a number corresponding to the menu item:"<<endl;
    }while(1);
    return 1;
}
int Terminal::member_number_validation(int user_entry)
{return 1;}
int Terminal::account_number_validation(int user_entry)
{return 1;}

