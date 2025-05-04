#include<iostream>
using namespace std;
int strength(int arr[],int size,int max1,int max2);
int main(){
      int cases,length,max1,max2;
    printf("Enter the number of Testcases: ");
    scanf("%d",&cases);
    for(int i =1;i<=cases;i++){
        printf("Enter the details of the Testcase %d:-\n",i);
        printf("Enter the number of Participants:");
        scanf("%d",&length);
        int arr[length];
        printf("Enter the Strength of each participants: ");
        for(int j =0;j<length;j++){
            scanf("%d", &arr[j]);
        }
        int seq[length];
        int j =0;
        while(j<length){
            seq[j]= arr[j];
            j++;
        }
        j =1;
        max1 = arr[0];
        max2 = arr[0];
        while(j<length){
            if(arr[j]>max1){
                max1= arr[j];
            }j++;  
        }
        j =0;
        while(j<length){
            if(max1>arr[j]&& arr[j]>max2){
                max2= arr[j];
            } j++;
        }
        strength(arr,length,max1,max2);
}
}
// Function to Calculate the Strength of the Participants
int strength(int arr[],int size,int max1,int max2){
    printf("The strengths of the Participants is: ");
    for(int i =0;i<size;i++){
        int max = max1;
        if(arr[i]== max1){
            max = max2;
        }
        printf("%d ",arr[i]-max);
    }
    printf("\n\n");
    return 0;}
