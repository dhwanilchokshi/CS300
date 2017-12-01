#include "tree.h"
#include "Provider_Directory.h"
/*
#include <iostream>
#include <cstring>
#include <ctime>
#include <fstream>
*/
const char menues[][150]= {"1 - provide a service to a member\n2 - Look up a service code\n3 - Request a copy of provider directory\n","1 - View summary report\n2 - Run individual reports\n","1 - Add new members\n2 - Add new providers\n3 - Update\n4 - Delete\n","1 - Search by service name\n2 - Search by service number\n3 - Display all services\n"};
const char disk[] = "disk_record.txt";
const char provider_valid_f[] = "provider_validation.txt";
const char member_valid_f[] = "provider_validation.txt";
const char operator_valid_f[] = "operator_validation.txt";
const char manager_valid_f[] = "manager_validation.txt";


class Terminal
{
    public:
        Terminal();

        //Terminal start screen
        int terminal_access();

        //User menus
        int menu(int user_type);
        int menu_selector(int menu_choice, bool sub_menu);
        void providers(int choice);
        void managers(int choice);
        void operators(int choice);

        //Provider funtions
        int read_validation(char *, int);
        int write_validation(int, int *, string[], float *, char*);
        int VERIFY_NUMBER_TEST(int, int);
        int directory_file_request();
        int provide_service(struct information&, char *);
        int get_disk_info(struct information&);
        int write_to_file(struct information, const char *);
        int write_provider_verification(struct information); 
        int valid(int, int);

        //Manager funtions

        //Operators funtions
        int add_members(struct common_info &, char *, char *);
        int add_new(int, char *);
        int check_generated(int, char *);
        int add_providers(struct common_info &, char *, char *);
        int write_to_file(struct common_info,const char *);
        int remove(int);
        //other functionality are in others classes
        //User number validation functions
        //Read Provider/member/mamager/oprator numbers
        int member_number_validation(int user_entry, const char * file);
        int account_number_validation(int user_entry, const char * provider_f, const char * operator_f, const char * mamager_f);

    private:
        int member_numbers;
        int provider_numbers;
        int ** manager_numbers;
        int ** operator_numbers;
        char ** member_status;
        manage member;
        manage provider;
        Provider_Directory directory;
};
