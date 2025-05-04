#include<iostream>
using namespace std;
#define size 5
class list{
private:
int arr[size];
int length;
int current ;
public:
 list(){
    current =0;
}
void insertBegin(int value);
void insertend(int value);
void insertpos(int value,int pos);
int deletebegin();
int deleteEnd();
int deletepos(int pos);
int search(int target);
void display();
void rotate1(int number);
void rotate2(int number);
void rotate3(int number);
void reverse (int start,int end);
};

int main(){
    list obj;
    int choice;
    int value;
    int l;
    int pos;
    int result;
    int target;

    do{
    cout << "Menu card" << endl;
    cout << "Enter 1 : To Insert at the Beginning" << endl;
    cout << "Enter 2 : To Insert at the End" << endl;
    cout << "Enter 3 : To Insert at the Position" << endl;
    cout << "Enter 4 : To Delete at the Beginning" << endl;
    cout << "Enter 5 : To Delete at the End" << endl;
    cout << "Enter 6 : To Delete at the Position" << endl;
    cout << "Enter 7 : To Search" << endl;
    cout << "Enter 8 : To Display" << endl;
    cout << "Enter 9 : To Rotate" << endl;
    cout << "Enter 10 : To Exit the Program" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch(choice){
        case 1:
        cout<< "Enter the value to insert: ";
        cin >> value;
        obj.insertBegin(value);
        obj.display();
        break;
        case 2:
        cout<< "Enter the value to insert: ";
        cin >> value;
        obj.insertend(value);
        obj.display();
        break;
        case 3:
        cout<< "Enter the value to insert: ";
        cin >> value;
        cout << "Enter the position to insert: ";
        cin >> pos;
        obj.insertpos(value,pos);
        obj.display();
        break;
        case 4:
        result = obj.deletebegin();
        cout << "The deleted elemenet is "<< result << endl;
        break;
        case 5:
        result = obj.deleteEnd();
        cout << "The deleted elemenet is "<< result << endl;
        break;
        case 6:
        cout << "Enter the position to delete: ";
        cin >> pos;
        result = obj.deletepos(pos);
        cout << "The deleted elemenet is "<< result << endl;
        break;
        case 7:
        cout << "Enter the value to search: ";
        cin >> target;
        result = obj.search(target);
        if (result == -1){
            cout<< "Target not found" << endl;
        }
        else {
            cout << "The position of the Target in the Array is "<< result+1 << endl;
        }
        break;
        case 8:
        obj.display();
        break;
        case 9:
        cout << "Enter the number of times you want to rotate: ";
        cin >> l;
        obj.rotate1(l);
        obj.display();
        break;
        case 10:
        cout << "program Ended" << "\nThank You" << endl;
        break;
        default :
        cout << "Invalid choice \n Enter the choice between 1 to 10"<< endl;


    }
   
    }
    while(choice!=10);
    return 0;
}
// insertion at the beginning
void list :: insertBegin(int value){
    if (size == current){
        cout << "The array is full \n cannot insert more elements" << endl;
    }
    else{
         for(int i=current-1;i>=0;i--){
            arr[i+1] = arr[i];
         }
         arr[0]= value;
         current++;

    }
}
// insertion at the ending
void list :: insertend(int value){
if (size == current){
    cout << "The array is full \n cannot insert more elements" << endl;
}
arr[current] = value;
current ++;
}


// insertion at a specific position
void list :: insertpos(int value,int pos){
 if (size == current){
    cout << "The array is full \n cannot insert more elements" << endl;
}
if (pos>size || pos<0){
    cout << "Invalid position \nEnter valid position"<< endl;
}   
for (int i =current -1;i>=pos-1;i--){
    arr[i+1]= arr[i];
} 
arr[pos-1]= value;
current ++;

}
// deleting the element at the beginning
int list :: deletebegin(){
    if (current ==0){
        cout << "Array is empty!"<< endl;
    }
    int value = arr[0];
    for (int i =0;i<current-1;i++){
        arr[i]= arr[i+1];
    }
    arr[current -1]=0;
    current --;
    return value;

}
// deleting the element at the ending
int list :: deleteEnd(){
    if (current ==0){
        cout << "Array is empty!"<< endl;
    }
    int value = arr[current-1];
    arr[current -0]=0;
    current --;
    return value;

}
// deleting the element at the specific position
int list :: deletepos(int pos){
    if (current ==0){
        cout << "Array is empty!"<< endl;
    }
    int value = arr[pos-1];
    if (pos>size || pos<0){
         cout << "Invalid position \nEnter valid position"<< endl;
    }
    for(int i =pos-1;i<current-1;i++){
        arr[i]= arr[i+1];
    }
    arr[current -1] = 0;
    current --;
    return value;
}

int list :: search(int target){
    for(int i =0;i<size;i++){
        if(arr[i]== target){
            return i;
        }
    }
    return -1;

}
void list :: display(){
    if (current ==0){
        cout <<"The array is empty"<< endl;
    }
    for (int i =0;i<current;i++){
        cout << arr[i]<<" ";
    }
    cout << "\n";

}
void list :: rotate1(int number){
    if (current <=1){
        cout <<"No need of rotating the elements"<< endl;

    }
    number = number%size;
    for (int i =0;i<number;i++){
        int temp = arr[current -1];
        for(int j = current -1;j>0;j--){
            arr[j]= arr[j-1];
        }
        arr[0]= temp;
    }

}
void list :: reverse(int start,int end){
    while(start<=end){
     int temp = arr[start];
     arr[start] = arr[end];
     arr[end] = temp;
        start++;
        end--;
    }

}

void list :: rotate2(int number){
number = number%size;
reverse(0,current-1);
reverse(0,number-1);
reverse(number,current-1);


}

void list :: rotate3(int number){
    number =  number%size;
    int count =0;
    for(int i =0;count <size;i++){
        int current =i;
        int prev = arr[i];
    
    do {
        int next = (current+number)%size;
        swap(arr[next],prev);
        current = next;
        count++;
    }
    while(i!=current);
}}