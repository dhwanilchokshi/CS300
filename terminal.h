#include "tree.h"
/*
#include <iostream>
#include <cstring>
#include <ctime>
#include <fstream>
*/
const char menues[][150]= {"0 - QUIT\n1 - provide a service to a member\n2 - Look up a service code\n3 - Request a copy of provider directory\n","0 - QUIT\n1 - View summary report\n2 - Run individual reports\n","0 - QUIT\n1 - Add new members\n2 - Add new providers\n3 - Update\n4 - Delete\n"};
class Terminal
{
    public:
        Terminal();

        //Terminal start screen
        int terminal_access(int user_entry);

        //User menus
        int menu(int user_type);
        void providers(int choice);
        void managers(int choice);
        void operators(int choice);

        //Provider funtions
        int VERIFY_NUMBER_TEST(int, int);
        int get_disk_info(struct information&, char *);
        int write_to_file(struct information);
        int write_provider_verification(struct information); 
        int valid(int, int);

        //Manager funtions

        //Operators funtions
        int add_members(struct common_info &, char *);
        int add_providers(struct common_info &, char *);
        int write_to_file(struct common_info, char *);
        int remove(int);
        //other functionality are in others classes


    protected:
        //User number validation functions
        int member_number_validation(int user_entry);
        int account_number_validation(int user_entry);

        //Read Provider/member/mamager/oprator numbers
        int read();

    private:
        int ** member_numbers;
        int ** provider_numbers;
        int ** manager_numbers;
        int ** operator_numbers;
        char ** member_status;
        manage member;
        manage provider;
};
