
#include "Services_BST.h"



//default constructor
Services_BST::Services_BST()
{
    service_name = "";
    service_code = "";
    service_cost = "";
    left = NULL;
    right = NULL;
}



//destructor
Services_BST::~Services_BST()
{
    remove();
}



/*
 Test Cases:
 - name is empty
 - name is only spaces
 - name has no alphabatical characters
 - name is very long
 */
int Services_BST::set_name(string & name)
{
    service_name = name;
    return 1;
}



/*
 Test Cases:
 - code is empty
 - code is has spaces
 - code is not a numerical input
 - code is very long
 */
int Services_BST::set_code(string & code)
{
    service_code = code;
    return 1;
}



/*
 Test Cases:
 - cost is empty
 - cost is not od double type
 - cost is too high
 */
int Services_BST::set_cost(string & cost)
{
    service_cost = cost;
    return 1;
}



/*
 Test Cases:
 - nothing to compare
 */
int Services_BST::compare_name(string & name)
{
    if (name <= service_name)
        return 0; //go left
    return 1; //go right
}



/*
 Test Cases:
 - nothing to compare
 */
int Services_BST::compare_code(string & code)
{
    if (code == service_code)
        return 1;
    return 0;
}



/*
 Test Cases:
 - empty node
 - missing parts
 */
int Services_BST::display_service()
{
    cout << "Service Name: " << service_name << endl;
    cout << "Service Code: " << service_code << endl;
    cout << "Service Cost: " << service_cost << endl;
    return 1;
}



/*
 Test Cases:
 - nothing to remove
 */
int Services_BST::remove()
{
    service_name.clear();
    service_code.clear();
    service_cost.clear();
    left = NULL;
    right = NULL;
    return 1;
}



/*
 Test Cases:
 - an object of a node is not initialized
 */
Services_BST *& Services_BST::go_left()
{
    return left;
}



/*
 Test Cases:
 - an object of a node is not initialized
 */
Services_BST *& Services_BST::go_right()
{
    return right;
}

//end
