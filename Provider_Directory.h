
#ifndef PROVIDER_DIRECTORY_H
#define PROVIDER_DIRECTORY_H

#include "Services_BST.h"



class Provider_Directory : public Services_BST
{
public:
    Provider_Directory();
    ~Provider_Directory();
    int insert_service(string &, int, float);
    int verify_service(int);
    int display_service(string &,int);
    int copy_info(struct information &, int);
    int display_services();
    int remove_services();
    int copy(ofstream &);
    
protected:
    Services_BST * root;
    int copy(ofstream &, Services_BST *&);
    int copy_info(struct information &, int, Services_BST *&);
    int insert_service(string &, int, float, Services_BST *&);
    int verify_service(int, Services_BST *&);
    int display_service(string &, int, Services_BST *&);
    int display_services(Services_BST *&);
    int remove_services(Services_BST *&);
};

#endif
