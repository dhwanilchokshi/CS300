#include "terminal.h"
using namespace std;

//Terminal class

Terminal::Terminal(): member_numbers(0), provider_numbers(0), manager_numbers(NULL), operator_numbers(NULL), member_status(NULL)
{
    read();
    srand(time(0));
    char memberCHOC_AN[] = "ChocAn_members.txt";
    char providerCHOC_AN[] = "ChocAn_providers.txt";
    member.read_forms(memberCHOC_AN);
    provider.read_forms(providerCHOC_AN); 
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
        cout<<"What would you like to do? - Please choose a number corresponding to the menu item:"
            <<"\n0 - LOGOUT"<<endl;
        cout<<menues[user_type];
        cout<<"CHOICE: ";
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
    char file[] = "ChocAn_members.txt";
    read_validation(file, 0);

    char file2[] = "ChocAn_providers.txt";
    read_validation(file2, 1);

    information info;

    if(choice == 1)
    {
        cout << "You are about to provide a service!" << endl;
        char file[] = "ChocAn_members.txt";
        provide_service(info, file);
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

int Terminal::read_validation(char *file, int who)
{
    char file2[SIZE];
    if(who == 0)
    {
        strcpy(file2, "member_validation.txt");
    }
    else
        strcpy(file2, "provider_validation.txt");


    int count_lines = 0;
    string line;
    ifstream in;
    in.open(file);

    if(!in)
    {
        cout << "Sorry no such file to open!" << endl;
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

    /*
    for(int i = 0; i < count_lines; ++i)
    {
        cout << "number: " << numbers[i] << endl;
        cout << "status: " << status[i] << endl;
        cout << "fee: " << suspended[i] << endl; 

    }
    */

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
            output << status[index] << endl;

        ++index;
        ++count;
    }
    output.close();

    return 1;

    
}

int Terminal::member_number_validation(int user_entry)
{return 1;}
int Terminal::account_number_validation(int user_entry)
{return 1;}


int Terminal::provide_service(information &info, char *file)
{
    //member.read_forms(file);
    //member.display();
    //temporary
    info.member_number = 903678233; info.provider_number = 910344322; info.service_code = 661390; 
    info.service_fee = 45.25; 
    info.member_name = "John Smith";

    //get member name
    member.get_member_name(info);
    provider.get_provider_name(info); 
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

   //if(!write_to_file(info))
       //cout << "Unable to write information to file" << endl;

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
    

    //return write_provider_verification(info);

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

    write_to_file(to_add, file);    //sent to ACME to update new members at 9pm
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
    output << num_to_add << ":" << "NA" << ":" << "NA" << endl;

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

    while(!infile.eof() && infile >> num_from_file)
    {
        cout << "num: " << num_from_file << endl;
        if(num_from_file == to_check)
            success = 0;

        infile.ignore(100, '\n');
        
    }

    return success;
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
    int provider_number;

    cout << "Full Name: ";
    getline(cin, to_add.Name);

    
    //generate provider number
    provider_number = (rand() % 9999999) + 910000000;
    to_add.Number = provider_number;

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
