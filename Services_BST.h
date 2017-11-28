
#ifndef SERVICES_BST_H
#define SERVICES_BST_H

#include <iostream>
#include <fstream>

using namespace std;


class Services_BST
{
public:
    Services_BST();
    ~Services_BST();
    int set_name(string &);
    int set_code(string &);
    int set_cost(string &);
    int compare_name(string &);
    int compare_code(string &);
    int display_service();
    int remove();
    Services_BST *& go_left();
    Services_BST *& go_right();
    
protected:
    string service_name;
    string service_code;
    string service_cost;
    Services_BST * left;
    Services_BST * right;
};

#endif
