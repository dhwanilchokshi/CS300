#include <iostream>
#include <cctype>
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

const int SIZE = 100;

struct information{
    int service_month, service_day, service_year;
    int current_month, current_day, current_year, current_hour, current_min, current_sec;
    int member_number, provider_number, service_code;
    int total_consults;
    float service_fee;
    double weekly_fee;
    char comments[SIZE];
    string member_name;
    string provider_name;
    string service_name;
};



class data
{
    public:
        data();
        ~data();
        void create(string * read, int, int, int);
        void copy();
    protected:
        //member information:
        int month;
        int day;
        int year;
        string provider_name;
        string service_name;

        //provider information
        int service_month;
        int service_day;
        int service_year;
        string mem_name;
        int mem_num;
        int serv_code;
        float serv_fee;
        int total_consults;
        double total_week_fee;
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
        void create(string *,int,int);
        void copy(info &);
        void get_info(info &);
        int check(info &);
        int check_id(int);
        void show();
        int copy_lll(info &);
        int check_bst_move(int);
        int check_mem_equal(struct information&);

    protected:
        node * head;
        void clear_all(node *&);
        int copy_lll(node *& dest, node * source);
        string name;
        int number;
        string address;
        string city;
        string state;
        int zip_code;

};

