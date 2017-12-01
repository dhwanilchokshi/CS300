#include "terminal.h"
using namespace std;

//Terminal class

const char memberCHOC_AN[] = "ChocAn_members.txt";
const char providerCHOC_AN[] = "ChocAn_providers.txt";

Terminal::Terminal(): member_numbers(0), provider_numbers(0), manager_numbers(NULL), operator_numbers(NULL), member_status(NULL)
{
    srand(time(0));
    char memberCHOC_AN[] = "ChocAn_members.txt";
    char providerCHOC_AN[] = "ChocAn_providers.txt";
    member.read_forms(memberCHOC_AN);
    provider.read_forms(providerCHOC_AN); 
    read_validation(memberCHOC_AN, 0);
    read_validation(providerCHOC_AN, 1);
}
int Terminal::terminal_access()
{ 
    int input;
    cout<<"\n---------------ChocAn Data Center-----------------\n";
    do
    {
        cout<<"\nPlease enter your account number to login\n"
            <<"Account number: ";
        cin>>input;
        cin.ignore(100, '\n');
        input = account_number_validation(input, provider_valid_f, operator_valid_f, manager_valid_f);
        if(input == 2)
            cout<<"\nInvalid account number\n";
        else if(input == 1)
            cout<<"\nAccount does not exsist\n";
        else if(input)
        {
            if(input >= 910000000 && input <= 919999999)
            {
                provider_numbers = input;
                menu(0);
                provider_numbers = 0;
            }
            else if(input >= 920000000 && input <= 929999999)
                menu(2);
            else if(input >= 930000000 && input <= 939999999)
                menu(1);
        }
    }while(1);
    
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
    if(choice == 1)
    {
        cout<<"\nSummary report is avaliable\n";
        provider.create_summary();
    }
    else
    {
        int input = 0;
        bool found = true;
        do{
            cout<<"Please enter a provider number - ex: 91XXXXXXX\ninput: ";
            cin>>input;
            cin.ignore(100, '\n');
            if(input >= 910000000 && input <= 919999999)
            {
                input = account_number_validation(input, provider_valid_f, operator_valid_f, manager_valid_f);
                if(input == 2)
                    cout<<"\nAccount does not exists\n";
                else if(!input || input == 3);
                else
                    found = false;
            }
            else
                cout<<"\nInvalid Number - Please enter a vaild provider number - ex: 91XXXXXXX\n";

        }while(found);
        input = provider.read_provider_individual_files(input);
        if(!input)
            cout<<"\nNew provider - Need to be revised by Acme\n";
    }
}

void Terminal::operators(int choice)
{
    common_info to_add;

    if(choice == 1)
    {
        char file[] = "new_members.txt";
        char check_file[] = "member_validation.txt";
        add_members(to_add, file, check_file);
    }
    else if(choice == 2)
    {
        char file[] = "new_providers.txt";
        char check_file[] = "provider_validation.txt";
        add_providers(to_add, file, check_file);
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

int Terminal::read_validation(char *file, int who)
{
    char file2[SIZE];
    if(who == 0)
    {
        strcpy(file2, "member_validation.txt");
    }
    else if(who == 1)
        strcpy(file2, "provider_validation.txt");
    else
        strcpy(file2, "mock_info_write.txt");


    int count_lines = 0;
    string line;
    ifstream in;
    in.open(file);

    if(!in)
    {
        return 0;
    }

    while(!in.eof() && getline(in, line))
    {
            ++count_lines;
    }
    in.close();              //first read to count lines

    int index = 0;
    int random;
    int number;
    int numbers[count_lines];
    float suspend_fee;
    float suspended[count_lines];
    int suspend_index = 0;
    string status[count_lines];
    char temp[SIZE];

    in.open(file);

    if(who == 0)
    {
        while(!in.eof() && in.get(temp, SIZE, ':'))
        {
            in.ignore(100,':');

            in >> number; numbers[index] = number;
            in.ignore(100,':');

            in.get(temp,SIZE,':');
            in.ignore(100,':'); 

            in.get(temp,SIZE,':');
            in.ignore(100,':');

            in.get(temp,SIZE,':');
            in.ignore(100,':'); 

            in >> random; in.ignore(100,':');

            in.get(temp, SIZE, ':'); status[index] = temp;
            in.ignore(100, ':');

            if(status[index].compare("suspended") == 0)
            {
                in >> suspend_fee; suspended[index] = suspend_fee;
                in.ignore(100, '\n');
                ++suspend_index;
            }
            else
            {
                suspended[index] = 0.0;
                in.ignore(100, '\n');
            }

            ++index;
        }
        in.close();
    }
    else
    {
        while(!in.eof() && in.get(temp, SIZE, ':'))
        {
            in.ignore(100,':');

            in >> number; numbers[index] = number;
            in.ignore(100,':');

            in.get(temp,SIZE,':');
            in.ignore(100,':'); 

            in.get(temp,SIZE,':');
            in.ignore(100,':');

            in.get(temp,SIZE,':');
            in.ignore(100,':'); 

            in >> random; in.ignore(100,':');

            in.get(temp, SIZE, ':'); status[index] = temp;
            in.ignore(100, '\n');

            ++index;
        }
        in.close();
    }

    //write to the file now
    return write_validation(count_lines, numbers, status, suspended, file2);


}

int Terminal::write_validation(int count_lines, int *numbers, string status[], float *suspended, char *file)
{
    int count = 0;
    int index = 0;
    //int suspend_index = 0;
    ofstream output;
    output.open(file, ios::app);

    if(!output)
    {
        cout << "Sorry file could not be found!" << endl;
        return 0;
    }

    while(count < count_lines)
    {
        output << numbers[index] << ":";
        if(status[index].compare("suspended") == 0)
        {
            output << status[index] << ":" << suspended[index] << endl;
        }
        else
            output << status[index]<< ":" << endl;

        ++index;
        ++count;
    }
    output.close();

    return 1;

    
}

int Terminal::member_number_validation(int user_entry, const char * file)
{
    ifstream to_find;
    if(user_entry >= 900000000 && user_entry <= 909999999)
        to_find.open(file);
    else
        return 2;

    int to_comp;
    char status[30];
    float fees;
    bool found = false;
    while(!to_find.eof() && !found)
    {
        to_find>>to_comp;
        to_find.ignore(100,':');
        to_find.get(status,30,':');
        
        if(strcmp(status,"suspended") == 0)
        {
            to_find.ignore(100,':');
            to_find>>fees;
            to_find.ignore(100,'\n');
        }
        else
            to_find.ignore(100,'\n');
        if(to_comp == user_entry)
        {
            if(strcmp(status,"suspended") == 0)
            {
                cout<<"\nMember Number: "<<to_comp
                    <<"\nStatus: "<<status
                    <<"\nUnpaid Fees: $"<<fees<<endl;
                to_comp = 0;
            }
            else if(!strcmp(status,"NA"))
                to_comp = 3;
            found = true;
        }
        fees = 0;
    }
    to_find.clear();
    to_find.close();
    if(found && to_comp > 3)
        return 1;
    else if (!found)
        return 2;
    else
        return to_comp;
}
int Terminal::account_number_validation(int user_entry, const char * provider_f, const char * operator_f, const char * mamager_f)
{
    ifstream to_find;
    if(user_entry >= 910000000 && user_entry <= 919999999)
        to_find.open(provider_f);
    else if(user_entry >= 920000000 && user_entry <= 929999999)
        to_find.open(operator_f);
    else if(user_entry >= 930000000 && user_entry <= 939999999)
        to_find.open(mamager_f);
    else
        return 2;
    int to_comp;
    char status[30];
    bool found = true;
    while(!to_find.eof() && found)
    {
        to_find>>to_comp;
        to_find.ignore(100,':');
        to_find.get(status,30,':');
        to_find.ignore(100,'\n');
        if(user_entry == to_comp)
        {
            if(!strcmp(status,"suspended"))
            {
                cout<<"Memeber Number: "<<to_comp
                    <<"\nAccount Status: "<<status<<endl;
                to_comp = 0;
            }
            else if(!strcmp(status,"NA"))
            {
                cout<<"Memeber Number: "<<to_comp
                    <<"\nAccount Status: New Provider. Account data not set up"<<endl;
                to_comp = 3;
            }
            found = false;
        }
    }
    to_find.clear();
    to_find.close();
    if(to_comp == 3 || to_comp == 0 || !found)
        return to_comp;
    return 2;
}
int Terminal::provide_service(information &info, char *file)
{
    int input;
    do{
        cout<<"\nEnter a member number to view status\n"
            <<"Member Number :";
        cin>>input;
        cin.ignore(100,'\n');
        member_numbers = member_number_validation(input, member_valid_f);
        if(member_numbers == 2)
            cout<<"\nMember does not exist or a wrong entry\n";
        if(member_numbers == 3)
            cout<<"\nMember is newly added - mmember acount need verifcation \n";

    }while(!member_numbers || member_numbers == 2);
    if(!member_numbers || member_numbers == 3)
        return 0;
    else if(member_numbers == 1)
    {
        cout<<"\nMember Status: Valid\n\nProceed with providing a service\n";
        member_numbers = input;
    }

    do{
        cout<<"\nEnter a member number to report a service\n"
            <<"Member Number :";
        cin>>input;
        cin.ignore(100,'\n');
    }while(input != member_numbers);

    //get member and provider number
    info.member_number = member_numbers; info.provider_number = provider_numbers;

    //get member name and provider name
    member.get_member_name(info); provider.get_provider_name(info); 

    time_t now = time(0);
    char choice;
    tm * ltm = localtime(&now);

    do
    {
       cout << "Please enter current service month (MM): ";
       cin >> info.service_month;
       cin.ignore();
    }while(valid(info.service_month, 2) && (info.service_month != (1+ ltm->tm_mon)));

   do
   {
       cout << "Please enter current service day (DD): ";
       cin >> info.service_day;
       cin.ignore();
   }while(valid(info.service_day, 2) && (info.service_day != ltm->tm_mday));

   do
   {
       cout << "Please enter current service year (YYYY): ";
       cin >> info.service_year;
       cin.ignore();
   }while(valid(info.service_year, 4) && (info.service_year != (1900 + ltm->tm_year)));


    //logging the current date and time from the computer
   info.current_month = 1 + ltm->tm_mon; info.current_day = ltm->tm_mday; info.current_year = 1900 + ltm->tm_year;
   info.current_hour = ltm->tm_hour; info.current_min = 1 + ltm->tm_min; info.current_sec = 1 + ltm->tm_sec;

   //service code display
   cout << "\nThe Provider's Directory: " << endl;
   directory.display_services();

   int read_success = 0;
   do
   {
       do
       {
           cout << "Please type in the service code for the service provided: ";
           cin >> info.service_code;
           cin.ignore();
       }while(!valid(info.service_code, 5));
       
       if(directory.verify_service(info.service_code) == 1)
       {
           read_success = 1;
           directory.copy_info(info, info.service_code);
           cout << "Service Name: " << info.service_name << endl;
       }
       
       else
           cout << "No service of such code was found!" << endl;

       cout << "Verified (y/n): ";
       cin >> choice;
       cin.ignore();
   }while(choice == 'n' || !valid(info.service_code, 5) || !read_success);

   cout << "\nAny Additional Comments: ";
   cin.get(info.comments, SIZE, '\n');
   cin.ignore(100,'\n');


   //send member info to be added to forms
   member.adding_extra(info, info.member_number);

   //send provider info to be added to forms
   provider.adding_extra(info, info.provider_number);

   //at very end
   return get_disk_info(info);
}

int Terminal::get_disk_info(information& info)
{
   if(!write_to_file(info, disk))
       cout << "Unable to write information to file" << endl;


    return write_provider_verification(info);

}

int Terminal::write_to_file(information info, const char * file)
{
   ofstream output;
   output.open(file, ios::app);

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
    write.close();
    write.clear();
    return 1;
}

int Terminal::add_members(common_info &to_add, char *file, char *check_file)
{
    int member_number;

    cout << "Full Name: ";
    getline(cin, to_add.Name);

    do
    {
        member_number = (rand() % 9999999) + 900000000;
    }while(!check_generated(member_number, check_file));

    to_add.Number = member_number;  
    add_new(to_add.Number, check_file);

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

    return write_to_file(to_add, file);    //sent to ACME to update new members at 9pm
    //member.read_forms(file);        //add members to bst
    //member.display();
}

int Terminal::add_new(int num_to_add, char *file)
{
    ofstream output;
    output.open(file, ios::app);

    if(!output)
        return 0;

    //NA = Not Available since they are new members not yet approved by ACME
    output << num_to_add << ":" << "NA" << ":" << endl;
    output.close();
    return 1;

}

int Terminal::check_generated(int to_check, char *check_file)
{
    int num_from_file;
    int success = 1;
    ifstream infile;
    infile.open(check_file);

    if(!infile)
    {
        cout << "File couldnt be opened" << endl;
        return 0;
    }

    while(infile >> num_from_file && !infile.eof())
    {
        if(num_from_file == to_check)
            success = 0;

        infile.ignore(100, '\n');
    }

    return success;
}

int Terminal::write_to_file(common_info to_add, const char *file)
{
    ofstream output;
    output.open(file, ios::app);

    if(!output)
        return 0;

    output << to_add.Name << ":" << to_add.Number << ":" << to_add.Street_address << ":" << to_add.City << ":" << to_add.State << 
        ":" << to_add.Zip << '\n';
    output.close();
    return 1;
}

int Terminal::add_providers(common_info &to_add, char *file, char *check_file)
{
    int provider_number;

    cout << "Full Name: ";
    getline(cin, to_add.Name);

    
    //generate provider number
    do
    {
        provider_number = (rand() % 9999999) + 910000000;
    }while(!check_generated(provider_number, check_file));
    to_add.Number = provider_number;
    add_new(to_add.Number, check_file);

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

    return write_to_file(to_add, file);
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
