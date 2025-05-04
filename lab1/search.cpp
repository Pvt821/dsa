#include<stdio.h>
#include "sort.h"

int  LinearSearch(int arr[],int len,int target);
int BinarySearch(int arr[],int size,int target );
int main(){
     int length;
     int target;
     printf("Enter the size of the Array");
     scanf("%d",&length);
     int array[length];
     
     printf("Enter the %d numbers ",length);
     for(int i =0;i<length;i++){
        scanf("%d",&array[i]);
     }
     printf("Enter the number to search in the array");
     scanf("%d",&target);
     int choice;int result ;

do{
    printf("MENU CARD\n");
    printf("1.Binary search\n");
    printf("2. Linear search\n");
    printf("3. Exit\n");
    printf("Enter the choice: ");
    scanf("%d",&choice);

switch(choice){
    case 1:
    SelectionSort(array,length);
     result = BinarySearch(array,length,target);
     if( result !=-1){
        printf("The given number found\n");
        printf("The index of the number is %d\n\n",result);

    }
    else
    printf("The number is not found\n\n");

    break;

    case 2:
     result = LinearSearch(array,length,target);
     if(result == 1){
        printf("Number found\n\n");
     }
     else {
        printf("Number is not found\n\n");
     }
    break;

    case 3:
    printf("Program Ended");
    break;
    default :
    printf("Enter valid number\n");


}
}
while(choice!=3);

    return 0;}

// code for Linear Search
    int  LinearSearch(int arr[],int len,int target){
        for(int i =0;i<len;i++){
            if(arr[i]== target){
                return 1;
            }
        }
        return 0;
    }

// code for Binary Search
int BinarySearch(int arr[],int size,int target ){
    int left = 0;
    int right = size-1;
    while(left<=right){
        int middle = (left+right)/2;
        if(arr[middle]==target){
            return middle;
        } 
        if(arr[middle]<target){
            left = middle +1;
        }
        if(arr[middle]>target){
            right = middle-1;
        }
    }
    return -1;

}

    