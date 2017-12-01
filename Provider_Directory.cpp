
#include "Provider_Directory.h"



//constructor
Provider_Directory::Provider_Directory() : root(NULL)
{
    ifstream file;
    
    file.open("Provider_Directory.txt");
    
    if (!file.is_open())
        cout << "Unable to find/open the test file!";
    else if (file.eof())
        cout << "The file is empty!\n";
    else
    {
        while (!file.eof())
        {
            string name;    int code;
            float cost;
            getline(file, name);
            file>>code;
            file.ignore(100,'\n');
            file>>cost;
            file.ignore(100,'\n');
            if(!file.eof())
                insert_service(name, code, cost); //add a service to the list of services (tree)
        }
    }
    file.close();
    file.clear();

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
int Provider_Directory::insert_service(string & name, int code, float cost)
{
    return insert_service(name, code, cost, root); //insert service in alphabatical order
}
int Provider_Directory::insert_service(string & name, int code, float cost, Services_BST *& current)
{
    if (!current)
    {
        current = new Services_BST;
        current->set_data(name, code, cost);
        return 1;
    }
    if (current->bst_compare_name(name) <= 0)
        return insert_service(name, code, cost, current->go_left()); //recurse left sub-tree
    return insert_service(name, code, cost, current->go_right()); //recurse right sub-tree
}



/*
 Test Cases:
 - empty list
 - scanned code is not a numerical code
 */
int Provider_Directory::verify_service(int scanned_code)
{
    return verify_service(scanned_code, root);
}
int Provider_Directory::verify_service(int scanned_code, Services_BST *& current)
{
    if (!current) 
        return 0;

    if (current->compare_code(scanned_code))
        return 1; //there is a service that matches the scanned code
    return verify_service(scanned_code, current->go_left()) + verify_service(scanned_code, current->go_right());
}

int Provider_Directory::copy_info(struct information & to_populate, int scanned_code)
{
    return copy_info(to_populate, scanned_code, root);
}
int Provider_Directory::copy_info(struct information & to_populate, int scanned_code, Services_BST *& root)
{
    if(!root)
        return 0;
    if (root->compare_code(scanned_code))
    {
        root->info_copy(to_populate);
        return 1;
    }
    return copy_info(to_populate, scanned_code, root->go_left()) + copy_info(to_populate, scanned_code, root->go_right());
 
}


/*
 Test Cases:
 - empty list
 - scanned code is not a numerical code
 */
int Provider_Directory::display_service(string & to_comp, int scanned_code)
{
    return display_service(to_comp, scanned_code, root);
}
int Provider_Directory::display_service(string & to_comp, int scanned_code, Services_BST *& current)
{
    int valid_code = 0;
    if (current) {
        if (current->compare_name(to_comp) ^ current->compare_code(scanned_code))
        {
            current->display_service();
            return 1; //there is a service that matches the scanned codes
        }
        valid_code = display_service(to_comp, scanned_code, current->go_left()) + display_service(to_comp, scanned_code, current->go_right());
    }
    return valid_code;
}

int Provider_Directory::copy(ofstream & write)
{
    return copy(write, root);
}
int Provider_Directory::copy(ofstream & write, Services_BST *& root)
{
    if(!root)
        return 0;
   copy(write, root->go_left());
   root->directory_copy(write);
   return copy(write, root->go_right());
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
    if (!current)
        return 1;
    display_services(current->go_left());
    current->display_service();
    return display_services(current->go_right());
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
    if (!current) 
        return 1;
    remove_services(current->go_left());
    remove_services(current->go_right());
    if(current)
        delete current;
return 1;
}

//end
