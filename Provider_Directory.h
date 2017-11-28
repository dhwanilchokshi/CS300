
#ifndef PROVIDER_DIRECTORY_H
#define PROVIDER_DIRECTORY_H

#include "Services_BST.h"



class Provider_Directory : public Services_BST
{
public:
    Provider_Directory();
    ~Provider_Directory();
    int insert_service(string &, string &, string &);
    int verify_service(string &);
    int display_service(string &);
    int display_services();
    int remove_services();
    
protected:
    Services_BST * root;
    int insert_service(string &, string &, string &, Services_BST *&);
    int verify_service(string &, Services_BST *&);
    int display_service(string &, Services_BST *&);
    int display_services(Services_BST *&);
    int remove_services(Services_BST *&);
};

#endif