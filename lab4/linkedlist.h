//Header file 
#include <cstdio>
#include <cstdlib>
class list{
    private:
    typedef struct node {
        int data;
        struct node *next;
    }node;
    node *head;

     node* gethead(){
        return head;
    }
    public:
    list (){
        head = NULL;
    }
    int insert(int value);
    list merge(list lst1,list lst2);
    void display();
};

