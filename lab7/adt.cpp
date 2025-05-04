#include "stack.h"
using namespace std;
int main(){
    stack obj;
    string str;
    cout << "Enter the string: ";
    cin >> str; 
    int i =0;
    while(str[i]!='\0'){
        if(str[i]=='+'){
            if(!obj.isempty()){
                obj.pop();
            }
        }
        else{
            obj.push(str[i]);
        }
        i++;

    }
    string result ="";
    cout << "Modified string: ";
    while (!obj.isempty()) {
        result += obj.pop();
    }
    int len  = result.length();
    int start = 0;
    int end = len - 1;
    while (start < end) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
    }
    cout << result;
    
    return 0;
}