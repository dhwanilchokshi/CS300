#include "terminal.h"
#include "forms.h"


class UNIT_TEST
{
    public:
        int TEST_EQUALS(int, int);
        void TEST_check_generated();
        void TEST_valid();
        void TEST_add_new();
        void TEST_read_validation();
        void display();
        void reading();
        void remove();
        void testing_add();

    protected:
        Terminal TEST;
        manage check;
    private:
};
