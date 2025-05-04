#include<cstdio>
#include<cstdlib>
#include<iostream>
class stack{
    struct node {
        char data;
        node *next ;
    };
    node *top;

public: 
stack(){
    top = NULL;
}
char peek();
char pop();
char push(char);
bool isempty();
};
// Function to Add the element into the stack
char stack :: push(char value){
    node *newnode =(node*)malloc(sizeof(node));
    newnode -> data  = value;
    newnode-> next = top;
    top = newnode;
 return 0;
}


// Function to Delete the element from the stack
char stack :: pop(){
    if(top == NULL){
        printf("Stack underflow\n") ;
        return -1;
    }
    node *temp = top;
    char value = top->data;
    top = top->next;
    free(temp);
    return value;
}



// Function to Display the top element in the stack
char stack :: peek (){
    if(top == NULL){
        printf("Stack underflow\n") ;
        return -1;
    }
    return top->data;

}
// Function to check the stack is empty
bool stack :: isempty() {
    return (top == NULL);
}





























