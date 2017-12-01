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

void UNIT_TEST::display()
{
    cout << "\n\nTesting displaying with no data stored" << endl << endl;
    int success = check.display();
    if(success == 0)
        cout << "UNIT TEST PASSED" << endl;
    else
        cout << "UNIT TEST FAILD" << endl;
}

void UNIT_TEST::reading()
{
    cout << "\n\nTesting reading from invalid txt file" << endl << endl;
    //testing reading from invalid file
    char test_empty [SIZE];
    int success = check.read_forms(test_empty);
    if(success == 0)
        cout << "UNIT TEST PASSED" << endl;
    else
        cout << "UNIT TEST FAILD" << endl;
}
void UNIT_TEST::remove()
{
    cout << "\n\nTesting removing with no data stored" << endl << endl;
    int success = check.remove(0);
    if(success == 0)
        cout << "UNIT TEST PASSED" << endl;
    else
        cout << "UNIT TEST FAILD" << endl;
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
        cout << "UNIT TEST PASSED" << endl;
    else
        cout << "UNIT TEST FAILD" << endl;
}
