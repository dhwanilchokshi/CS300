#include "terminal_UnitTest.h"

int main()
{
    UNIT_TEST test;
    test.TEST_check_generated();
    test.TEST_valid();
    test.TEST_add_new();
    test.display();
    test.reading();
    test.remove();
    test.testing_add();

return 0;
}
