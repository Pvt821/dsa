#include <cstdio>
#include<iostream>
#include<cmath>
#include "stack.h"
using namespace std;
string infix,postfix;
int getinfix();
void convertinfix();
int precedence(char symbol);
int evaluatePostfix() ;
int main(){
    int choice,result;
    do{
        cout << "\n ====Menu Card:====\n";
        cout <<"Enter 1: To Enter the Infix Expression."<< endl;
        cout<<"Enter 2: To Construct the Postfix Expression"<< endl;
        cout <<"Enter 3: To Evaluate the Postfix expression" << endl;
        cout << "Enter 4: Exit the program\n" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
    switch(choice){
        case 1:
        getinfix();
        break;
        case 2:
        convertinfix();
        cout << "Postfix Expression: " << postfix << endl;
        break;
        case 3:
        result = evaluatePostfix() ;
        cout << "Evaluation Result: " <<result << endl; 
        break;
        case 4:
        cout<< "program ended\n" << endl;
        break;
        default:
        cout << "Invalid choice"<<endl;
        cout <<" Enter the choice between 1 to 10"<< endl;
}
}while(choice!=4);
return 0;
}
// Function to get the infix expression
int getinfix(){
    cout << "Enter the Infix expression: ";
    cin >> infix;
    return 0;
}
// Function to convert infix expression to postfix expression
void convertinfix(){
    stack s;
    char next;
    postfix = "";
    for(int i =0;i<infix.length();i++){
        char symbol = infix[i];
        switch(symbol){
            case '(':
            s.push(symbol);
             break;
            case ')':
            while(!s.isempty()  && s.peek() != '('){
            postfix +=s.pop();}
            if (!s.isempty()) s.pop();
            break;
            case '+':
            case '^':
            case '/':
            case '*':
            case '-':
            while(!s.isempty() && precedence(s.peek())>=precedence(symbol)){
                postfix += s.pop();
            }s.push(symbol);
            break;
            default :
            postfix +=symbol;
            break;
        }
    }
    while (!s.isempty()) {
        postfix += s.pop();
    }
}
// Function to compute the postfix expression
int evaluatePostfix() {
    stack s;
    for (int i =0;i<postfix.length();i++){
        if (isdigit(postfix[i])) { 
            s.push(postfix[i] - '0');
        }
        else{
            if (s.isempty()) {
                cout << "Error: Invalid postfix expression!\n";
                return -1;
            }
            int a=s.pop();
            int b=s.pop();
            switch(postfix[i]){
                case '+':
                s.push(b+a);
                break;
                case '-':
                s.push(b-a);
                break;
                case '*':
                s.push(b*a);
                break;
                case '/':
                if (a == 0) {
                    cout << "Error: Division by zero!\n";
                    return -1;
                }
                s.push(b/a);
                break;
                case '^':
                s.push(pow(b,a));
                break ;
                default:
                cout << "Error: Invalid operator encountered!\n";
                return -1;
             }
        }

    }
    if (!s.isempty()) {  
        return s.pop(); 
    } else {
        cout << "Error: Malformed expression!\n";
        return -1;
    }
} 

//  Function to check the Precedence order
int precedence(char symbol){
    switch(symbol){
        case '^':
        return 3;
        case '/':
        case '*':
        return 2;
        case '+':
        case '-':
        return 1;
        default :
        return 0;

    }
}
