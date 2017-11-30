#include "terminal_UnitTest.h"

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
    int test_value = TEST.check_generated(mock_num, mock_file);
    //function should return 0
    int mock_num2 = 902000000; 
    int test_value2 = TEST.check_generated(mock_num2, mock_file);

    if(TEST_EQUALS(1, test_value) && TEST_EQUALS(0, test_value2))
        cout << "UNIT TEST PASSED" << endl;
    else
        cout << "UNIT TEST FAILED" << endl;
}

void UNIT_TEST::TEST_valid()
{
    int pass_value = 10000;
    int test_value = TEST.valid(pass_value, 5);

    int fail_value = 100;
    int test_value2 = TEST.valid(fail_value, 5);

    if(TEST_EQUALS(1, test_value) && TEST_EQUALS(0, test_value2))
        cout << "UNIT TEST PASSED" << endl;
    else
        cout << "UNIT TEST FAILED" << endl;

}

void UNIT_TEST::TEST_add_new()
{
    int mock_num = 909000000;
    char mock_file[] = "mock_member.txt";
    char fail_file[] = "";

    int test_value = TEST.add_new(mock_num, mock_file);

    int test_value2 = TEST.add_new(mock_num, fail_file);

    if(TEST_EQUALS(1, test_value) && TEST_EQUALS(0, test_value2))
        cout << "UNIT TEST PASSED" << endl;
    else
        cout << "UNIT TEST FAILED" << endl;
}

void UNIT_TEST::TEST_read_validation()
{

}
