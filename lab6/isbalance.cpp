#include<cstdio>
#include<iostream>
using namespace std;
#define max 100

class stack{
    char stackarr[max];
    int top;
    public:
    stack(){
        top =-1;}
    
    bool isbalance(string);
    bool push(char);
    bool pop();
};
int main(){
    stack obj;
    int choice,result,value;
    string str;
    do{
        cout << "\n ====Menu Card:====\n";
        cout << "Enter 1 : To check whether the string is balanced" << endl;
        cout << "Enter 2 : To End the program\n" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
    switch(choice){
        case 1: 
        cout <<"Enter the string with paranthesis: ";
        cin >> str;
        if(obj.isbalance(str)){
            cout << "The given input is balanced.\n";
        } else {
            cout << "The given input is NOT balanced.\n";
        }
        break;
        case 2:
        cout<< "program ended\n" << endl;
        break;
        default:
        cout << "Invalid choice"<<endl;
        cout <<" Enter the choice between 1 to 10"<< endl;
        break;
    }
}while(choice!=2);
return 0;
}

// Function to check if parentheses are balanced
bool stack :: isbalance(string str){
    int i =0;
    while(str[i]!='\0'){
        if (str[i]== '('){
            if (!push(str[i])){
                return false;
            } 
        }
        else if (str[i]== ')') {
            if (top < 0 ){
                return false;  } 
        pop();}
        i++;
}
return (top ==-1);
}
// Function to Add into the stack
bool  stack :: push (char ch){
    if(top == max-1){
        cout << "Error: Stack overflow! Cannot add " << ch << " to the stack.\n";
        return false;
    }
    else{
        top ++;
        stackarr[top] = ch;
    }
    return true;
}

// Function to remove from the Stack
bool stack :: pop() {
    if (top == -1) {
        cout << "Error: Stack underflow! Nothing to pop.\n";
        return false;
    }
    top--;
    return true;
}
