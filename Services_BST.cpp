#include "Services_BST.h"



//default constructor
Services_BST::Services_BST(): service_code(0), service_cost(0), left(NULL), right(NULL)
{
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
/*
 Test Cases:
 - code is empty
 - code is has spaces
 - code is not a numerical input
 - code is very long
 */
/*
 Test Cases:
 - cost is empty
 - cost is not od double type
 - cost is too high
 */
int Services_BST::set_data(string & name, int code, float cost)
{
    service_name = name;
    service_code = code;
    service_cost = cost;
    return 1;
}


/*
 Test Cases:
 - nothing to comparE
 */
int Services_BST::bst_compare_name(string & name)
{
    return !(name <= service_name);
}
int Services_BST::compare_name(string & name)
{
    return name == service_name;
}


/*
 Test Cases:
 - nothing to compare
 */
int Services_BST::compare_code(int code)
{
    if(code == service_code)
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
int Services_BST::directory_copy(ofstream & write)
{
    write<<service_name<<'\n'
        <<service_code<<'\n'
        <<service_cost<<endl;
    return 1;
}

int Services_BST::info_copy(struct information & copy)
{
    copy.service_code = service_code;
    copy.service_fee = service_cost;
    copy.service_name = service_name;
    return 1;
}

/*
 Test Cases:
 - nothing to remove
 */
int Services_BST::remove()
{
    service_name.clear();
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
