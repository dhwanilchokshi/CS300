#include "forms.h"

//info functions 
info::info():head(NULL){}
info::~info()
{
    if(head)
        clear_all(head);
}
void info::clear_all(node *&head)
{
    if(!head)
        return;
    clear_all(head->get_next());
    if(head)
    {
        delete head;
        head= NULL;
    }
}
void info::create(String read[],int num, int zip)
{
    name = read[0];
    number = num;
    address = read[1];
    city = read [2];
    state = read [3];
    zip_code = zip;
}

void info::copy(info & source)
{
    name = source.name;
    number = source.number;
    address = source.address;
    city = source.city;
    state = source.state;
    zip_code = source.zip_code;
}
void info::get_info(info & to_get)
{
    to_get.name = name;
    to_get.number = number;
    to_get.address = address;
    to_get.city = city;
    to_get.state = state;
    to_get.zip_code = zip_code;
    if(head)
        copy_lll(to_get);
}
int info::copy_lll(info & to_get)
{
    if(!head)
        return 0;
    else
        return copy_lll(to_get.head,head);
}
int info::copy_lll(node *& dest, node * source)
{
    if(!source)
        return 0;
    node * temp = new node(*source);
    temp->get_next() = dest;
    dest = temp;
    return copy_lll(dest,source->get_next());
}
int info::check(info & to_check)
{
    if(to_check.number < number)
        return 0;
    else 
        return 1;
}
int info::check_id(int to_check)
{
    if(to_check == number)
        return 1;
    else 
        return 0;
}

void info::show()
{
    cout << "The Name is: " << name << endl;
    cout << "ID Number: " << number << "\nStreet Address: " << address
        << "\nCity And State of Residence: " << city << ", " << state << ", "
        << zip_code << endl;
}
//data functions
data::data(){}
data::~data(){}
//node Functions
node::node():next(NULL){}
node::~node(){}
node *& node::get_next()
{
    return this->next;
}


