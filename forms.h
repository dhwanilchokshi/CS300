#ifndef FORMS_H
#define FORMS_H
#include <iostream>
#include <cctype>
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
using namespace std;

const int SIZE = 100;
const char summary[] = "summary.txt";

struct information{
    information();
    int service_month, service_day, service_year;
    int current_month, current_day, current_year, current_hour, current_min, current_sec;
    int member_number, provider_number, service_code;
    int total_consults;
    float service_fee;
    float weekly_fee;
    char comments[SIZE];
    string member_name;
    string provider_name;
    string service_name;
};

struct common_info{
    string Name;
    int Number;
    string Street_address;
    string City;
    string State;
    int Zip;
};

class data
{
    public:
        data();
        ~data();
        data(data&);
        void createMember(information & to_copy);
        void createProvider(information & copy_provider);
        void copy();
        void write_extra(char * filename);
        void display();
        void display_total();
    protected:
        information extra;
        //member information:
        //
        /*
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
        */
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
        int check_pro_equal(struct information&);
        int generate();
        void insert(information &);
        void write_summary();

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
        string status;
        int fee;

        float total_fees;
        int consult;
};
#endif
