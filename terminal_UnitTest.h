#include <iostream>
#include "terminal.h"
#include "forms.h"

class UNIT_TEST
{
    public:
        UNIT_TEST();
        int TEST_check_generated();














        //Zack's part
        int INTERFACE();
        int TEST_member_number_validation();
        int TEST_account_number_validation();
        int TEST_directory_file_report();
        int TEST_write_to_file_common_info();
        int TEST_write_to_file_information();

    protected:
        manage MEMBER_TEST;
        manage PROVIDER_TEST;
        Terminal TERMINAL_TEST;
    private:
        void read(int * mocked_data,const char * mock_file);
        typedef int (UNIT_TEST:: *fptr)();
        fptr TO_TEST[10];
        const int limit;
};
