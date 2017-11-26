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
    int choice = 0;
    bool INmenu = false;
    cout<<"Welcome -name-\n"
        <<"//////////////////////////////////////////////"<<endl;
    do 
    {
        INmenu = false;
        cout<<"What would you like to do? - Please choose a number corresponding to the menu item:"<<endl;
        cout<<menues[user_type];
        cin>>choice;
        cin.ignore(100,'\n');
        if(!choice);
        else if((user_type == 0) && (choice < 4 && choice > 0))
            providers(choice);
        else if((user_type == 1) && (choice < 3 && choice > 0))
            managers(choice);
        else if((user_type == 2) && (choice < 5 && choice > 0))
            operators(choice);
        else
            INmenu = true;
    }while(INmenu);
    cout<<"\n~~~LOGOUT~~~\n";
    return 1;
}
void Terminal::providers(int choice)
{
    if(choice == 1);
    //disk recored 
    //verfication from
    else if(choice == 2);
    else;
}
void Terminal::managers(int choice)
{
    if(choice == 1);
    else;
}
void Terminal::operators(int choice)
{
    if(choice == 1);
    else if(choice == 2);
    else if(choice == 3);
    else;
}
int Terminal::member_number_validation(int user_entry)
{return 1;}
int Terminal::account_number_validation(int user_entry)
{return 1;}

