#include "terminal.h"
#include "Provider_Directory.h"

int main()
{  
    Terminal terminal;
    manage obj;
    obj.read_forms("member_info.txt");
    obj.display();

    information info; 

    int count = 0;

    terminal.menu(0);
    terminal.menu(2);
/*
    1) after service has been provided, provider checks member validity again
    2) provider is asked to write the date (MM-DD-YYYY)
    3) provider uses the provider directory to look up service code
    4) service code has to be typed in to check that the correct service name comes up

    WRITE TO DISK RECORD:
        - Current date and time (MM-DD-YYYY HH:MM:SS)
        - Date service was provided (MM-DD-YYYY) --> keyed in by the provider after service
        - Provider Number (9 digits) --> already stored
        - Member Number (9 digits) --> already stored
        - Service Code (6 digits) --> already stored
        - Comments (100 chars) (optional)
    
    5) look up fee to be paid for the service and display it on terminal
*/
    //manage_member.read_forms(file);
    //manage_member.display();
    //get_disk_info(info);
    
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
        - Service Fee (already stored)
*/


return 0;
}
/*
int get_disk_info(information &info)
{
   info.member_number = 103678233; info.provider_number = 910344322; info.service_code = 661390; //temp
   info.service_fee = 45.25; //temp
   info.member_name = "John Smith"; //temp


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
   cout << "\nCurrent date and time have been logged in the system: " << endl;

   cout << "Additional Comments: ";
   cin.get(info.comments, SIZE, '\n');
   cin.ignore(100,'\n');

   if(!write_to_file(info))
       cout << "Unable to write information to file" << endl;

    6) Use Service Code to look up fee and display it (+save it) 

    7) get information from provider to enter on the provider verification form

    WRITE TO PROVIDER VERIFICATION FORM:
        - Enter current date and time (MM-DD-YYYY HH:MM:SS)
        - Date service was provided (MM-DD-YYYY)
        - Member Name and Number (Member Name from Member BST, Number already stored)
        - Service Code (already stored)
        - Service Fee (look up)

        *Going to have to look up Member Name using # and Service Fee using service #
    

    return write_provider_verification(info);
}


int write_provider_verification(information info)
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

int write_to_file(information info)
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

int valid(int info, int acceptable_length)
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
=======
>>>>>>> 78a9f54e3dcb786e3a27741a139cbae2e9b10171

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

<<<<<<< HEAD
    return success;
}
*/
