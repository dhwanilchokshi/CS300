#include "terminal.h"
using namespace std;

//Terminal class

Terminal::Terminal(): member_numbers(0), provider_numbers(0), manager_numbers(NULL), operator_numbers(NULL), member_status(NULL)
{
    read();
}
int Terminal::read()
{
    return 1;
}
int Terminal::menu_selector(int menu_choice, bool sub_menu)
{
    int choice;
    cout<<"What would you like to do? - Please choose a number corresponding to the menu item:";
    if(sub_menu)
        cout<<"\n0 - Previous mene"<<endl;
    else 
        cout<<"\n0 - LOGOUT"<<endl;
    cout<<menues[menu_choice];
    cout<<"CHOICE: ";
    cin>>choice;
    cin.ignore(100,'\n');
    return choice;
}
int Terminal::menu(int user_type)
{
    int choice = 0;
    bool INmenu = true;
    cout<<"Welcome -name-\n"
        <<"//////////////////////////////////////////////"<<endl;
    do 
    {
        choice = menu_selector(user_type, 0);
        if(!choice)
            INmenu = false;
        else if((user_type == 0) && (choice < 4 && choice > 0))
            providers(choice);
        else if((user_type == 1) && (choice < 3 && choice > 0))
            managers(choice);
        else if((user_type == 2) && (choice < 5 && choice > 0))
            operators(choice);

    }while(INmenu);
    cout<<"\n~~~LOGOUT~~~\n";
    return 1;
}
void Terminal::providers(int choice)
{
    information info;

    if(choice == 1)
    {
        cout << "You are about to provide a service!" << endl;
        char file[] = "ChocAn_members.txt";
        provide_service(info, file);
    }
    else if(choice == 2)
    {
        bool INmenu = true;
        string to_find_str;
        int to_find_int;
        do
        {
            choice = menu_selector(3, 1);
            if(!choice)
                INmenu = false;
            if(choice < 4 && choice > 0)
            {
                if(choice == 1)
                {
                    cout<<"Please enter the name of the service:"<<endl;
                    cin>>to_find_str;
                    cin.ignore(100,'\n');
                    directory.display_service(to_find_str,0);
                }
                else if(choice == 2)
                {
                    cout<<"Please enter the code of the service:"<<endl;
                    cin>>to_find_int;
                    cin.ignore(100,'\n');
                    directory.display_service(to_find_str,to_find_int);
                }
                else
                    directory.display_services();
            }
            else 
                cout<<"Invalid Choice"<<endl;
        }while(INmenu);
    }
    else
        directory_file_request();
}
void Terminal::managers(int choice)
{
    if(choice == 1);
    else;
}
void Terminal::operators(int choice)
{
    common_info to_add;

    if(choice == 1)
    {
        char file[] = "new_members.txt";
        add_members(to_add, file);
    }
    else if(choice == 2)
    {
        char file[] = "new_providers.txt";
        add_providers(to_add, file);
    }
    else if(choice == 4)
    {
        int choice;
        cout << "1 - Remove Members" << endl;
        cout << "2 - Remove Providers" << endl;
        cin >> choice;
        cin.ignore();
        remove(choice);
    }
    else;
}
int Terminal::member_number_validation(int user_entry)
{return 1;}
int Terminal::account_number_validation(int user_entry)
{return 1;}


int Terminal::provide_service(information &info, char *file)
{
    member.read_forms(file);
    //temporary
    info.member_number = 103678233; info.provider_number = 910344322; info.service_code = 661390; 
    info.service_fee = 45.25; 
    info.member_name = "John Smith";


/*
        Zack's member validation stuff
*/
    time_t now = time(0);
    tm * ltm = localtime(&now);

    do
    {
       cout << "Please enter the service month (MM): ";
       cin >> info.service_month;
       cin.ignore();
       cout << "month: " << 1 + ltm->tm_mon;
    }while(valid(info.service_month, 2) && (info.service_month != (1+ ltm->tm_mon)));

   do
   {
       cout << "Please enter the service day (DD): ";
       cin >> info.service_day;
       cin.ignore();
   }while(valid(info.service_day, 2) && (info.service_day != ltm->tm_mday));

   do
   {
       cout << "Please enter the service year (YYYY): ";
       cin >> info.service_year;
       cin.ignore();
   }while(valid(info.service_year, 4) && (info.service_year != (1900 + ltm->tm_year)));

   cout << "\nYour input has been saved!" << endl;

   info.current_month = 1 + ltm->tm_mon; info.current_day = ltm->tm_mday; info.current_year = 1900 + ltm->tm_year;
   info.current_hour = ltm->tm_hour; info.current_min = 1 + ltm->tm_min; info.current_sec = 1 + ltm->tm_sec;
   cout << "\nCurrent date and time have been logged in the system!" << endl;

   cout << "Additional Comments: ";
   cin.get(info.comments, SIZE, '\n');
   cin.ignore(100,'\n');

    //get member name
   member.get_member_name(info);


   //at very end
   return get_disk_info(info);
}

int Terminal::get_disk_info(information& info)
{

/*
        ------------------UNIT TEST FOR ACCEPTABLE LENGTH-------------------
   if(VERIFY_NUMBER_TEST(info.member_number, 9) && VERIFY_NUMBER_TEST(info.provider_number, 9) && VERIFY_NUMBER_TEST(info.service_code, 6))
       cout << "UNIT TEST PASSED" << endl;
   else
       cout << "UNIT TEST FAILED" << endl;
*/

   if(!write_to_file(info))
       cout << "Unable to write information to file" << endl;

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

    if(info >= 1 && info <=9)
        success = true;

    while(info > 0)
    {
        info = info/10;
        ++counter;
    }

    if(counter == acceptable_length)
        success = true;
    return success;
}

int Terminal::VERIFY_NUMBER_TEST(int number, int length)
{
    if(valid(number, length))
        return 1;
    return 0;
}
int Terminal::directory_file_request()
{
    ofstream write;
    write.open("copy_of_provider_directory.txt");
    
    if(write)
        directory.copy(write);
    else
    {
        cout<<"ABORT. Something went wrong.\n";
        return 0;
    }
    return 1;
    write.close();
    write.clear();
}

int Terminal::add_members(common_info &to_add, char *file)
{
    cout << "Full Name: ";
    getline(cin, to_add.Name);

    do
    {
        cout << "Number (9 digits): ";
        cin >> to_add.Number;
        cin.ignore();
    }while(!valid(to_add.Number, 9));

    cout << "Street Address: ";
    getline(cin, to_add.Street_address);

    cout << "City: ";
    getline(cin, to_add.City);

    cout << "State: ";
    getline(cin, to_add.State);

    do
    {
        cout << "Zip (5 digits): ";
        cin >> to_add.Zip;
        cin.ignore();
    }while(!valid(to_add.Zip, 5));

    write_to_file(to_add, file);
    member.read_forms(file);        //add members to bst
    //member.display();
}

int Terminal::write_to_file(common_info to_add, char *file)
{
    ofstream output;
    output.open(file, ios::app);

    if(!output)
        return 0;

    output << to_add.Name << ":" << to_add.Number << ":" << to_add.Street_address << ":" << to_add.City << ":" << to_add.State << 
        ":" << to_add.Zip << '\n';
    output.close();
}

int Terminal::add_providers(common_info &to_add, char *file)
{
    cout << "Full Name: ";
    getline(cin, to_add.Name);

    do
    {
        cout << "Number (9 digits): ";
        cin >> to_add.Number;
        cin.ignore();
    }while(!valid(to_add.Number, 9));

    cout << "Street Address: ";
    getline(cin, to_add.Street_address);

    cout << "City: ";
    getline(cin, to_add.City);

    cout << "State: ";
    getline(cin, to_add.State);

    do
    {
        cout << "Zip (5 digits): ";
        cin >> to_add.Zip;
        cin.ignore();
    }while(!valid(to_add.Zip, 5));

    write_to_file(to_add, file);
    provider.read_forms(file);        //add providers to bst
    //provider.display();
}

int Terminal::remove(int choice)
{
    if(choice == 1)
    {
        int member_id;
        do
        {
            cout << "Please type ID# of member to remove (9 - digits): ";
            cin >> member_id;
            cin.ignore();
        
        }while(!valid(member_id, 9));

        if(member.remove(member_id)){
            cout << "Member removed" << endl;
            return 1;
        }
        else
            cout << "Member not removed" << endl;

        member.display();       //copy function in info creating duplicates
    }

    else if(choice == 2)
    {
        int provider_id;
        do
        {
            cout << "Please type ID# of provider to remove (9 - digits): ";
            cin >> provider_id;
            cin.ignore();
        
        }while(!valid(provider_id, 9));

        if(provider.remove(provider_id)){
            cout << "Provider removed" << endl;
            return 1;
        }
        else
            cout << "Provider not removed" << endl;
    }

return 0;
}
