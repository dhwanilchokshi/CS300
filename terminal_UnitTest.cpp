#include "terminal_UnitTest.h"

char check[SIZE] = "ChocAn_providers.txt";
const char memberCHOC_AN[] = "ChocAn_members.txt";

int UNIT_TEST::TEST_EQUALS(int expected, int received)
{
    if(expected == received)
        return 1;
    return 0;
}

void UNIT_TEST::TEST_check_generated()
{
    char mock_file[] = "mock_member.txt";
    
    //function should return 1
    int mock_num = 901000000;
    int test_value = TERMINAL_TEST.check_generated(mock_num, mock_file);
    //function should return 0
    int mock_num2 = 902000000; 
    int test_value2 = TERMINAL_TEST.check_generated(mock_num2, mock_file);

    if(TEST_EQUALS(1, test_value) && TEST_EQUALS(0, test_value2))
        cout << "TEST PASSED" << endl;
    else
        cout << "TEST FAILED" << endl;
}

void UNIT_TEST::TEST_valid()
{
    int pass_value = 10000;
    int test_value = TERMINAL_TEST.valid(pass_value, 5);
    int fail_value = 100;
    int test_value2 = TERMINAL_TEST.valid(fail_value, 5);

    if(TEST_EQUALS(1, test_value) && TEST_EQUALS(0, test_value2))
        cout << "TEST PASSED" << endl;
    else
        cout << "TEST FAILED" << endl;
}


UNIT_TEST::UNIT_TEST(): limit(5)
{
    TO_TEST[0] = &UNIT_TEST::TEST_member_number_validation;
    TO_TEST[1] = &UNIT_TEST::TEST_account_number_validation;
    TO_TEST[2] = &UNIT_TEST::TEST_directory_file_report;
    TO_TEST[3] = &UNIT_TEST::TEST_write_to_file_common_info;
    TO_TEST[4] = &UNIT_TEST::TEST_write_to_file_information;
}
int UNIT_TEST::INTERFACE()
{

    for(int i = 0; i < limit; ++i)
    {
        if((this->*TO_TEST[i])())
            cout << "TEST PASSED" << endl;
        else 
            cout << "TEST FAILED" << endl;
    }
    TEST_check_generated();
    TEST_valid();
    TEST_add_new();
    TEST_read_write_validation();
    TEST_check_generated();
    TEST_valid();
    TEST_add_new();
    display();
    reading();
    remove();
    testing_add();


    return 1;
}
void UNIT_TEST::TEST_add_new()
{
    int mock_num = 909000000;
    char mock_file[] = "mock_member.txt";
    char fail_file[] = "";

    int test_value = TERMINAL_TEST.add_new(mock_num, mock_file);

    int test_value2 = TERMINAL_TEST.add_new(mock_num, fail_file);

    if(TEST_EQUALS(1, test_value) && TEST_EQUALS(0, test_value2))
        cout << "TEST PASSED" << endl;
    else
        cout << "TEST FAILED" << endl;
}

void UNIT_TEST::TEST_read_write_validation()
{
    char mock_file[] = "mock_info_read.txt";
    char fail_file[] = "";
    int test_value = TERMINAL_TEST.read_validation(mock_file, 3); 
    int test_value2 = TERMINAL_TEST.read_validation(fail_file, 3);
    
    if(TEST_EQUALS(1, test_value) && TEST_EQUALS(0, test_value2))
        cout << "TEST PASSED" << endl;
    else
        cout << "TEST FAILED" << endl;
}
int UNIT_TEST::TEST_member_number_validation()
{
    int test = 0, to_return = 0, mocked_input[5], expected[5];
    read(mocked_input, "member_TEST_Mock.txt");
    read(expected, "member_TEST_expected.txt");
    for(int i = 0 ; i < 6; ++i)
    {
        test = TERMINAL_TEST.member_number_validation(mocked_input[i], "member_TEST.txt");
        if(test == expected[i])
            ++to_return;
    }
    if(to_return == 5)
        return 1;
    return 0;
}
void UNIT_TEST::read(int * mocked_data,const char * mock_file)
{
    ifstream load;
    load.open(mock_file);
    for(int i = 0; !load.eof(); ++i)
    {
        load>>mocked_data[i];
        load.ignore(100, '\n');
    }
    load.clear();
    load.close();
}
int UNIT_TEST::TEST_account_number_validation()
{
    int test = 0, to_return = 0, mocked_input[5], expected[5];
    read(mocked_input, "account_TEST_Mock.txt");
    read(expected, "account_TEST_expected.txt");

    for(int i = 0 ; i < 6; ++i)
    {

        test = TERMINAL_TEST.account_number_validation(mocked_input[i], "account_TEST.txt","account_TEST.txt","account_TEST.txt");
        if(test == expected[i])
            ++to_return;
    }
    if(to_return == 5)
        return 1;
    return 0;
}
int UNIT_TEST::TEST_directory_file_report()
{
    return TERMINAL_TEST.directory_file_request();
}
int UNIT_TEST::TEST_write_to_file_common_info()
{
    common_info TEST_OBJECT;
    TEST_OBJECT.Name = "Chris";
    TEST_OBJECT.Number = 909999999;
    TEST_OBJECT.Street_address = "Zack's st";
    TEST_OBJECT.City = "Zack's Kingdom";
    TEST_OBJECT.State = "magoolistaand";;
    TEST_OBJECT.Zip = 99999;
    
    return TERMINAL_TEST.write_to_file(TEST_OBJECT, "MOCK_TEST_1.txt");
}
int UNIT_TEST::TEST_write_to_file_information()
{
    information TEST_OBJECT;
    TEST_OBJECT.member_name = "Chris";
    TEST_OBJECT.provider_name = "Chris";
    TEST_OBJECT.service_name = "Chris";
    TEST_OBJECT.service_month = 11;
    TEST_OBJECT.service_day = 30;
    TEST_OBJECT.service_year = 2017;
    TEST_OBJECT.current_month = 11;
    TEST_OBJECT.current_day = 30;
    TEST_OBJECT.current_year = 2017;
    TEST_OBJECT.current_hour = 15;
    TEST_OBJECT.current_min = 10;
    TEST_OBJECT.current_sec = 56;
    TEST_OBJECT.member_number = 909999999;
    TEST_OBJECT.provider_number = 919999999;
    TEST_OBJECT.total_consults = 330;
    TEST_OBJECT.service_fee = 1000;
    TEST_OBJECT.weekly_fee = 34500;
    TEST_OBJECT.service_code = 55555;

    return TERMINAL_TEST.write_to_file(TEST_OBJECT, "MOCK_TEST_2.txt");
}

void UNIT_TEST::display()
{
    cout << "\n\nTesting displaying with no data stored" << endl << endl;
    int success = check.display();
    if(success == 0)
        cout << "TEST PASSED" << endl;
    else
        cout << "TEST FAILD" << endl;
}

void UNIT_TEST::reading()
{
    cout << "\n\nTesting reading from invalid txt file" << endl << endl;
    //testing reading from invalid file
    char test_empty [SIZE];
    int success = check.read_forms(test_empty);
    if(success == 0)
        cout << "TEST PASSED" << endl;
    else
        cout << "TEST FAILD" << endl;
}
void UNIT_TEST::remove()
{
    cout << "\n\nTesting removing with no data stored" << endl << endl;
    int success = check.remove(0);
    if(success == 0)
        cout << "TEST PASSED" << endl;
    else
        cout << "TEST FAILD" << endl;
}
void UNIT_TEST::testing_add()
{
    cout << "Testing adding to the BST of the meembers/providers information" << endl << endl;
    int success =0;
    char temp [SIZE];
    strcpy(temp, "ChocAn_providers.txt");
    check.read_forms(temp);
    success = check.display();
    if(success == 1)
        cout << "TEST PASSED" << endl;
    else
        cout << "TEST FAILD" << endl;
}
