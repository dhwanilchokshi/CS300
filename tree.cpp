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
manage::manage()
{
}
manage::~manage()
{
}
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
int manage::insert(info & source)
{
   return insert(root,source);
}

int manage::insert(t_node *& root, info & source)
{
    if(!root)
    {
        root = new t_node;
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
            return 1;
        }
        if(!root->get_left())//if it has one child
        {
            t_node * current = root;
            root=root->get_right();
            delete current;
            current =NULL;
            return 1;
        }
        if(!root->get_right())//if it has one child
        {
            t_node * current = root;
            root= root->get_left();
            delete current;
            current = NULL;
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
                        return 1;
                }
                else
                {
                        delete current;
                        return 1;
                }
            }
            else
            {
                current->get_info(get);
                root->copy(get);
                delete current;
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
