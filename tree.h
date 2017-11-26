#include "forms.h"
class t_node:public info
{

    public:
        t_node();
        ~t_node();
        t_node *& get_left();
        t_node *& get_right();


    protected:
        t_node * left;
        t_node * right;
};
class manage
{
    public:
        manage();
        ~manage();
        manage(const manage &);
        int read_forms(char formFile[]);
        int insert(info&);
        int display();
        int remove(int);
        int get_member_name(struct information &);

    protected:
        t_node * root;
        int insert(t_node *& root, info&);
        int display(t_node * root);
        int remove(t_node *& root,int);
        int get_member_name(t_node *&, struct information &);
};


