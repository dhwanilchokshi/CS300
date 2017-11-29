#include "terminal.h"
#include "Provider_Directory.h"

int main()
{  
    Terminal terminal;
    manage obj;
    obj.read_forms("member_info.txt");
    obj.display();

    information info; 

    int count = 0;

    terminal.menu(0);
    terminal.menu(2);
/*
    1) after service has been provided, provider checks member validity again
    2) provider is asked to write the date (MM-DD-YYYY)
    3) provider uses the provider directory to look up service code
    4) service code has to be typed in to check that the correct service name comes up

    WRITE TO DISK RECORD:
        - Current date and time (MM-DD-YYYY HH:MM:SS)
        - Date service was provided (MM-DD-YYYY) --> keyed in by the provider after service
        - Provider Number (9 digits) --> already stored
        - Member Number (9 digits) --> already stored
        - Service Code (6 digits) --> already stored
        - Comments (100 chars) (optional)
    
    5) look up fee to be paid for the service and display it on terminal
*/
    //manage_member.read_forms(file);
    //manage_member.display();
    //get_disk_info(info);
    
/*
    6) Use Service Code to look up fee and display it (+save it) 
*/

/*
    7) get information from provider to enter on the provider verification form

    WRITE TO PROVIDER VERIFICATION FORM:
        - Enter current date and time (MM-DD-YYYY HH:MM:SS)
        - Date service was provided (MM-DD-YYYY)
        - Member Name and Number (Member Name from Member BST, Number already stored)
        - Service Code (already stored)
        - Service Fee (already stored)
*/


return 0;
}
