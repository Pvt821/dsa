#include<cstdio>
#include<cstdlib>
class stack{
   
    struct node {
        int data;
        node *next ;
    };
    node *top;

public: 
stack(){
    top = NULL;
}
int peek();
int pop();
int push(int);
};
int main(){
    stack obj;
    int choice,result,val;
    do{
        printf("\n===Stack Menu===\n");
        printf("Enter 1 : To push the element into the stack\n");
        printf("Enter 2 : To pop the element from the stack\n");
        printf("Enter 3 : To peek the element in the stack\n");
        printf("Enter 4 : Exit the program\n\n");
        printf("enter the choice: ");
        scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("Enter the value to be pushed: ");
        scanf("%d",&val);
         obj.push(val);
        break;
        case 2:
        val = obj.pop();
        if(val!=-1){
            printf("The element poped is %d",val);
        }
        break;
        case 3:
        val = obj.peek();
        if(val!=-1){
            printf("The element poped is %d",val);
        }
        break;
        case 4:
        printf("Program Ended\n");
        break;
        default:
        printf("Invalid choice\n");
        printf("Enter the choice between 1 to 4\n");
}
}while(choice!=4);
return 0;
}


// Function to Add the element into the stack
int stack :: push(int val){
    node *newnode =(node*)malloc(sizeof(node));
    newnode -> data  = val;
    newnode-> next = top;
    top = newnode;
 return 0;
}


// Function to Delete the element from the stack
int stack :: pop(){
    if(top == NULL){
        printf("Stack underflow\n") ;
        return -1;
    }
    node *temp = top;
    int val = top->data;
    top = top->next;
    free(temp);
    return val;
}

// Function to Display the top element in the stack
int stack :: peek (){
    if(top == NULL){
        printf("Stack underflow\n") ;
        return -1;
    }
    return top->data;

}




























