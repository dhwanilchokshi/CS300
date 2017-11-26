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
    information info;

    if(choice == 1)
    {
        get_disk_info(info);     //disk record and verification form
    }
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

int Terminal::get_disk_info(information& info)
{
   info.member_number = 103678233; info.provider_number = 910344322; info.service_code = 661390; //temp
   info.service_fee = 45.25; //temp
   info.member_name = "John Smith"; //temp

/*
        ------------------UNIT TEST FOR ACCEPTABLE LENGTH-------------------
   if(VERIFY_NUMBER_TEST(info.member_number, 9) && VERIFY_NUMBER_TEST(info.provider_number, 9) && VERIFY_NUMBER_TEST(info.service_code, 6))
       cout << "UNIT TEST PASSED" << endl;
   else
       cout << "UNIT TEST FAILED" << endl;
*/


   time_t now = time(0);
   tm * ltm = localtime(&now);

   do
   {
       cout << "Please enter the service month (MM): ";
       cin >> info.service_month;
       cin.ignore();
   }while(!valid(info.service_month, 2));

   do
   {
       cout << "Please enter the service day (DD): ";
       cin >> info.service_day;
       cin.ignore();
   }while(!valid(info.service_day, 2));

   do
   {
       cout << "Please enter the service year (YYYY): ";
       cin >> info.service_year;
       cin.ignore();
   }while(!valid(info.service_year, 4));

   cout << "\nYour input has been saved!" << endl;

   info.current_month = 1 + ltm->tm_mon; info.current_day = ltm->tm_mday; info.current_year = 1900 + ltm->tm_year;
   info.current_hour = ltm->tm_hour; info.current_min = 1 + ltm->tm_min; info.current_sec = 1 + ltm->tm_sec;
   cout << "\nCurrent date and time have been logged in the system!" << endl;

   cout << "Additional Comments: ";
   cin.get(info.comments, SIZE, '\n');
   cin.ignore(100,'\n');

   if(!write_to_file(info))
       cout << "Unable to write information to file" << endl;

   //member.get_member_name(info);

/*
    6) Use Service Code to look up fee and display it (+save it) 
*/

/*
    7) get information from provider to enter on the provider verification form

    WRITE TO PROVIDER VERIFICATION FORM:
        - Enter current date and time (MM-DD-YYYY HH:MM:SS)
        - Date service was provided (MM-DD-YYYY)
        - Member Name and Number (Member Name from Member BST, Number already stored)
        - Service Code (already stored)
        - Service Fee (look up)

        *Going to have to look up Member Name using # and Service Fee using service #
*/
    

    return write_provider_verification(info);

}

int Terminal::write_to_file(information info)
{
   ofstream output;
   output.open("disk_record.txt", ios::app);

   if(!output)
       return 0;

    output << "Logged Date and Time: " << info.current_month << "-" << info.current_day << "-" << info.current_year << " " << info.current_hour 
    << ":" << info.current_min << ":" << info.current_sec << endl;
    output << "Entered date: " << info.service_month << "-" << info.service_day << "-" << info.service_year << endl;
    output << "Provider Number: " << info.provider_number << endl;
    output << "Member Number: " << info.member_number << endl;
    output << "Service Code: " << info.service_code << endl;
    output << "Comments: " << info.comments << endl;
    output << "-------------------------------------------------------------" << endl;
    output.close();

return 1; 

}

int Terminal::write_provider_verification(information info)
{
    ofstream output;
    output.open("provider_verification.txt", ios::app);

    if(!output)
        return 0;

    output << "Logged Date and Time: " << info.current_month << "-" << info.current_day << "-" << info.current_year << " " << info.current_hour 
    << ":" << info.current_min << ":" << info.current_sec << endl;
    output << "Entered date: " << info.service_month << "-" << info.service_day << "-" << info.service_year << endl;
    output << "Member Name: " << info.member_name << "       " << "Member Number: " << info.member_number << endl;
    output << "Service Code: " << info.service_code << endl;
    output << "Service Fee: " << info.service_fee << endl;
    output << "-------------------------------------------------------------" << endl;
    output.close();

return 1;

}

int Terminal::valid(int info, int acceptable_length)
{
    int counter = 0;
    bool success = false;

    if(acceptable_length == 2)
    {
        while(info > 0)
        {
            info = info/10;
            ++counter;
        }

        if(counter == 2)
            success = true;
    }
    
    else if(acceptable_length == 4)
    {
        while(info > 0)
        {
            info = info/10;
            ++counter;
        }
        if(counter == 4)
            success = true;
    }

    else if(acceptable_length == 9)
    {
        while(info > 0)
        {
            info = info/10;
            ++counter;
        }
        if(counter == 9)
            success = true;
    }
    
    else if(acceptable_length == 6)
    {
        while(info > 0)
        {
            info = info/10;
            ++counter;
        }
        if(counter == 6)
            success = true;
    }

    return success;

}

int Terminal::VERIFY_NUMBER_TEST(int number, int length)
{
    if(valid(number, length))
        return 1;

    return 0;
}
