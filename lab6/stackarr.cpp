#include<cstdio>
#define max 5
class stack{
    int stackarr[max];
    int top;
    public:
    stack(){
        top =-1;}
   
    int push(int);  
    int peek();
    int pop();
};

int main(){
    stack obj;
    int choice,result,value;
    do{
        printf("\n===Stack Menu===\n");
        printf("Enter 1 : To push the element into the stack\n");
        printf("Enter 2 : To pop the element from the stack\n");
        printf("Enter 3 : To peek the element in the stack\n");
        printf("Enter 4 : Exit the program\n");
        printf("enter the choice: ");
        scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("Enter the value: ");
        scanf("%d",&value);
        obj.push(value);
        break;
        case 2:
        value = obj.pop();
        if(value!= -1){
            printf("The element poped is %d",value);
        }
        break;
        case 3:
        value =obj.peek();
        if(value!= -1){
            printf("The element at the last  is %d",value);
        }
        break;
        case 4:
        printf("Program ended");
        break;
        default:
        printf("Invalid choice\n");
        printf("Enter the choice between 1 to 4\n");

    }}
    while(choice !=4);
}


// Function to Add the element into the stack
int  stack :: push (int val){
    if(top == max-1){
        printf ("Error: stack overflow!");
        printf("Cannot add the %d into the stack\n",val);
        return -1;
    }
    else{
        top ++;
        stackarr[top] = val;
    }
    return 0;
}


// Function to Delete the element from the stack
int stack :: pop(){
    if(top == -1){
        printf("Error: stack underflow!\n");
        return -1;
    }
    int value ;
    value = stackarr[top];
    top --;
    return value;
}


// Function to Display the top element in the stack
int stack :: peek(){
    if (top == -1){
        printf("Error: Stack underflow!\n");
        return -1;
    }
    return stackarr[top];
}
