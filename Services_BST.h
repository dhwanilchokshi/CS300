#include "forms.h"
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
    int set_data(string &, int, float);
    int bst_compare_name(string &);
    int compare_name(string &);
    int compare_code(int);
    int display_service();
    int info_copy(struct information &);
    int directory_copy(ofstream &);
    int remove();
    Services_BST *& go_left();
    Services_BST *& go_right();
    
protected:
    string service_name;
    int service_code;
    float service_cost;
    Services_BST * left;
    Services_BST * right;
};

#endif
