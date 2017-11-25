#include "string.h"

class data
{
    public:
        data();
        ~data();
        void create(String * read, int, int, int);
        void copy();
    protected:
};

class node:public data
{
    public:
        node();
        ~node();
        node *&get_next();

    protected:
        node * next;
};


class info
{
    public:
        info();
        ~info();
        void create(String *,int,int);
        void copy(info &);
        void get_info(info &);
        int check(info &);
        int check_id(int);
        void show();
        int copy_lll(info &);

    protected:
        node * head;
        void clear_all(node *&);
        int copy_lll(node *& dest, node * source);
        String name;
        int number;
        String address;
        String city;
        String state;
        int zip_code;

};

