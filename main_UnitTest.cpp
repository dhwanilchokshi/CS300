#include "terminal_UnitTest.h"

int main()
{
    UNIT_TEST test;
    test.TEST_check_generated();
    test.TEST_valid();
    test.TEST_add_new();
    test.TEST_read_write_validation();

return 0;
}
