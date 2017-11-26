#include <iostream>
#include <cstring>
#include <ctime>
#include <fstream>
const char menues[][150]= {"0 - QUIT\n1 - provide a service to a member\n2 - Look up a service code\n3 - Request a copy of provider directory\n","0 - QUIT\n1 - View summary report\n2 - Run individual reports\n","0 - QUIT\n1 - Add new members\n2 - Add new providers\n3 - Update\n4 - Delete\n"};
class Terminal
{
    public:
        Terminal();

        //Terminal start screen
        int terminal_access(int user_entry);

        //User specific menus
        int menu(int user_type);
        void providers(int choice);
        void managers(int choice);
        void operators(int choice);

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
};
