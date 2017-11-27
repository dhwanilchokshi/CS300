#include "tree.h"

t_node::t_node()
{
}

t_node::~t_node()
{
}
t_node *& t_node::get_left()
{
    return this->left;
}
t_node *& t_node::get_right()
{
    return this->right;
}






// manage class 
manage::manage():root(NULL),track(0) { }
manage::~manage() { }
manage::manage(const manage & obj)
{

}

int manage::read_forms(char formFile [])
{
    ifstream in;

    in.open(formFile);
    string * read = NULL;
    info source;
    char temp [SIZE];
    int id_num = 0;
    int zip_code = 0;
    if(!in)
        return 0;
    else if(in)
    {
        read = new string [4];
        while(!in.eof() && in.get(temp,SIZE,':'))
        {
            in.ignore(100,':'); read[0] = temp;
            in >> id_num; in.ignore(100,':');
            in.get(temp,SIZE,':');
            in.ignore(100,':'); read[1] = temp;
            in.get(temp,SIZE,':');
            in.ignore(100,':'); read[2] = temp;
            in.get(temp,SIZE,':');
            in.ignore(100,':'); read[3] = temp;
            in >> zip_code; in.ignore(100,'\n');
            source.create(read,id_num,zip_code);
            insert(source);
            }
    }

    return 1;
}

int manage::read_providers(char formFile [])
{
    ifstream in;

    in.open(formFile);
    string * read = NULL;
    info source;
    char temp [SIZE];
    int id_num = 0;
    int zip_code = 0;
    if(!in)
        return 0;
    else if(in)
    {
        read = new string [4];
        while(!in.eof() && in.get(temp,SIZE,':'))
        {
            in.ignore(100,':'); read[0] = temp;
            in >> id_num; in.ignore(100,':');
            in.get(temp,SIZE,':');
            in.ignore(100,':'); read[1] = temp;
            in.get(temp,SIZE,':');
            in.ignore(100,':'); read[2] = temp;
            in.get(temp,SIZE,':');
            in.ignore(100,':'); read[3] = temp;
            in >> zip_code; in.ignore(100,'\n');
            source.create(read,id_num,zip_code);
            insert(source);
            }
    }

    return 1;
}
int manage::insert(info & source)
{
   return insert(root,source);
}

int manage::insert(t_node *& root, info & source)
{
    if(!root)
    {
        root = new t_node;
        track+=1;
        root->copy(source);
        root->get_left() = root->get_right() = NULL;
        return 1;
    }
    if(!root->check(source))
        return insert(root->get_left(),source);
    else
        return insert(root->get_right(),source);
}

int manage::display()
{
    if(!root)
    {
        cout << "ERROR !! NO DATA TO DISPLAY !!" << endl << endl;
        return 0;
    }
    else
        return display(root);
}

int manage::display(t_node * root)
{
    if (!root)
        return 1;
    root->show();
    display(root->get_left());
    return display(root->get_right());
}

int manage::remove(int id_to_remove)
{
    if(!root)
    {
        cout << "ERROR !! NO DATA !! " << endl;
        return 0;
    }
    else
        return remove(root,id_to_remove);
}

int manage::remove(t_node *& root,int id_to_remove)
{
    if(!root)
        return 0;
    if(root->check_id(id_to_remove))
    {
      if(!root->get_left() && !root->get_right()) //if its a leaf
        {
            delete root;
            root=NULL;
            track-=1;
            return 1;
        }
        if(!root->get_left())//if it has one child
        {
            t_node * current = root;
            root=root->get_right();
            delete current;
            current =NULL;
            track-=1;
            return 1;
        }
        if(!root->get_right())//if it has one child
        {
            t_node * current = root;
            root= root->get_left();
            delete current;
            current = NULL;
            track-=1;
            return 1;
        }
        else//to find the ios
        {
            info get;
            t_node * current = root->get_right();
            if(!current->get_left())
            {
                current->get_info(get);
                root->copy(get);
                if(current->get_right())
                {
                        root->get_right() = current->get_right();
                        delete current;
                        track-=1;
                        return 1;
                }
                else
                {
                        delete current;
                        track -=1;
                        return 1;
                }
            }
            else
            {
                current->get_info(get);
                root->copy(get);
                delete current;
                track-=1;
                return 1;
            }
        }
    }
        remove(root->get_left(),id_to_remove);
        return remove(root->get_right(),id_to_remove);
}

int manage::get_member_name(information &info)
{
    if(!root)
        return 0;

    return get_member_name(root, info);
}
int manage::get_member_name(t_node *&root, information &info)
{
    if(!root)
        return 0;

    if(root->check_mem_equal(info))
        return 1;

    else if(!root->check_bst_move(info.member_number))
        return get_member_name(root->get_left(), info);
    else
        return get_member_name(root->get_right(), info);

}
<<<<<<< HEAD
=======
int manage::create_forms()
{
    if(!root)
    {
        cout << "ERROR !! NO DATA !!" << endl;
        return 0;
    }
    else
        return create_forms(root);
}

//this function will be responsible of creating member and providers forms based 
//
int manage::create_forms(t_node * root)
{
    if(!root)
        return 1;
    root->generate();
    create_forms(root->get_left());
    return create_forms(root->get_right());
}

//to add the extra information for the providers and the members
int manage::adding_extra(information & to_add,int to_find)
{
    if(!root)
    {
        cout << "ERROR !! NO DATA AVILABLE !!" << endl << endl;
        return 0;
    }

    t_node * found = find(root,to_find);

    if(found)
        found->insert(to_add);
    else
        cout << "ERROR !! ID NUMBER WAS NOT FOUND !!" << endl << endl;
    return 1;
}
// a function to traverse and find the ID node
t_node *& manage:: find(t_node * root, int to_find)
{
    if(!root)
        return this->root;
    if(root->check_id(to_find))
        return this->root;
    find(root->get_left(),to_find);
    return find(root->get_right(),to_find);
}
>>>>>>> be3b80ee59d21b84dedbc1780ad16cc6834747fb
