#include "forms.h"
information::information():member_number(0),provider_number(0){}
//info functions 
info::info():head(NULL),number(0),zip_code(0),total_fees(0.0),consult(0){}
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
void info::create(string read[],int num, int zip)
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
    /*
    if(head)
        copy_lll(to_get);
        */
}
int info::copy_lll(info & to_get)
{
    if(!to_get.head)
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
    cout << "\n\nThe Name is: " << name << endl;
    cout << "\nID Number: " << number << "\nStreet Address: " << address
        << "\nCity And State of Residence: " << city << ", " << state << ", "
        << zip_code << endl;
    if(head)
    {
        node * current = head;
        
        while(current)
        {
            current->display();
            current = current->get_next();

        }
        head->display_total();
    }
}
int info::check_bst_move(int num_to_check)
{
    if(num_to_check < number)
        return 0;
    
    return 1;
}

int info::check_mem_equal(information& info)
{
    if(info.member_number == number)
    {
        info.member_name = name;
        return 1;
    }
    
return 0;
}

int info::check_pro_equal(information &info)
{
    if(info.provider_number == number)
    {
        info.provider_name = name;
        return 1;
    }
return 0;
}

int info::generate()
{
    ofstream out;
    char filename [SIZE]; 
    string temp = name;
    time_t now = time(0);
    tm * localtm = localtime(&now);
    temp += "-";
    temp += asctime(localtm);
    temp.copy(filename,50,0);

    out.open(filename);
    

        out << name << ':' << number << ':' << address << ':' << city 
            << ':' << state << ':' << zip_code;
        if(head)
        {
            node * current = head;
            while(current)
            {
                current->write_extra(filename);
                current = current->get_next();
            }
        }
        out.close();
        return 0;

}
void info::insert(information & to_add)
{
    node * hold = new node;
    if(to_add.member_number != 0)
    {
        hold->createProvider(to_add);
        consult+=1;
        to_add.total_consults = consult;
        total_fees+=to_add.service_fee;
        to_add.weekly_fee = total_fees;
    }
    else
        hold->createMember(to_add);
    hold->get_next() = head;
    head = hold;
}
void info::write_summary()
{
    ofstream out;
    out.open(summary);
    
    out << "Provider Name: " << name << '\n' << "ID Number: " << number << '\n'
        << "Total Consultations: " << consult << '\n' 
        << "Total Fee For The Week: " << total_fees <<'\n';
    out.close();
}

//data functions
data::data() {}
data::~data(){}
data::data(data & source)
{

    if(source.extra.member_number !=0)
        createProvider(source.extra);
    else
        createMember(source.extra);
}
void data::createMember(information & to_copy)
{
    extra.service_month = to_copy.service_month;
    extra.service_day = to_copy.service_day;
    extra.service_year = to_copy.service_year;
    extra.provider_name = to_copy.provider_name;
    extra.service_name = to_copy.service_name;
}
void data::createProvider(information & copy_provider)
{
    extra.service_month = copy_provider.service_month;
    extra.service_day = copy_provider.service_day;
    extra.service_year = copy_provider.service_year;
    extra.member_name = copy_provider.member_name;
    extra.member_number = copy_provider.member_number;
    extra.service_code = copy_provider.service_code;
    extra.service_fee = copy_provider.service_fee;
    extra.total_consults = copy_provider.total_consults;
    extra.weekly_fee = copy_provider.weekly_fee;
} 

void data::write_extra(char * filename)
{
    ofstream out;
    out.open(filename);

    if(extra.member_number != 0)
    {
        out << extra.service_month << '/' << extra.service_day <<  '/' <<  extra.service_year
        << ':' << extra.member_name << ':' <<  extra.member_number << ':' 
        <<  extra.service_code
        << ':' <<  extra.service_fee << ':' <<  extra.total_consults << ':' 
        << extra.weekly_fee;

    }
    else
    {   out << extra.service_month << '/' << extra.service_day <<  '/' <<  extra.service_year
        << ':' << extra.provider_name << ':' << extra.service_name;
    }
    out.close();
}
void data::display()
{
    cout << "\n\nDate of The Service: " << extra.service_month << "/" << extra.service_day << "/"
        << extra.service_year<< "\n----\nThe Member The Service Was Provided To Details: "
        << "\nName: " << extra.member_name << "\nMember ID: " << extra.member_number
        << "\n----" << "\nService That Was Provided Code: " << extra.service_code
        << "\nService Fee: " << extra.service_fee << endl;
}
void data::display_total()
{
    cout<<"\nConsults: "<< extra.total_consults << "\nTotal fees: "<< extra.weekly_fee << endl;
}
//node Functions
node::node():next(NULL){}
node::~node(){}
node *& node::get_next()
{
    return this->next;
}


