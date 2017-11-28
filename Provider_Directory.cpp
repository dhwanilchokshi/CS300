
#include "Provider_Directory.h"



//constructor
Provider_Directory::Provider_Directory() : root(NULL)
{
}



//destructor
Provider_Directory::~Provider_Directory()
{
    remove_services();
}



/*
    Test Cases:
  - getline() gets evoked on an empty file
  - text file of services is not on the right order (name -> code -> cost)
  - the service code is not a numerical code
  - the cost is not in doubel form
*/
int Provider_Directory::insert_service(string & name, string & code, string & cost)
{
    return insert_service(name, code, cost, root); //insert service in alphabatical order
}
int Provider_Directory::insert_service(string & name, string & code, string & cost, Services_BST *& current)
{
    if (current == NULL)
    {
        current = new Services_BST;
        current->set_name(name);
        current->set_code(code);
        current->set_cost(cost);
        return 1;
    }
    if (current->compare_name(name) <= 0)
        return insert_service(name, code, cost, current->go_left()); //recurse left sub-tree
    return insert_service(name, code, cost, current->go_right()); //recurse right sub-tree
}



/*
 Test Cases:
 - empty list
 - scanned code is not a numerical code
 */
int Provider_Directory::verify_service(string & scanned_code)
{
    return verify_service(scanned_code, root);
}
int Provider_Directory::verify_service(string & scanned_code, Services_BST *& current)
{
    int valid_code = 0;
    if (current) {
        if (current->compare_code(scanned_code))
            return 1; //there is a service that matches the scanned code
        valid_code = verify_service(scanned_code, current->go_left()) + verify_service(scanned_code, current->go_right());
    }
    return valid_code;
}



/*
 Test Cases:
 - empty list
 - scanned code is not a numerical code
 */
int Provider_Directory::display_service(string & scanned_code)
{
    return display_service(scanned_code, root);
}
int Provider_Directory::display_service(string & scanned_code, Services_BST *& current)
{
    int valid_code = 0;
    if (current) {
        if (current->compare_code(scanned_code))
        {
            current->display_service();
            return 1; //there is a service that matches the scanned codes
        }
        valid_code = display_service(scanned_code, current->go_left()) + display_service(scanned_code, current->go_right());
    }
    return valid_code;
}



/*
 Test Cases:
 - empty list
 */
int Provider_Directory::display_services()
{
    return display_services(root);
}
int Provider_Directory::display_services(Services_BST *& current)
{
    if (current) {
        display_services(current->go_left());
        current->display_service();
        display_services(current->go_right());
    }
    return 1;
}



/*
 Test Cases:
 - empty list
 */
int Provider_Directory::remove_services()
{
    return remove_services(root);
}
int Provider_Directory::remove_services(Services_BST *& current)
{
    if (current) {
        remove_services(current->go_left());
        remove_services(current->go_right());
        current->remove();
    }
    return 1;
}

//end