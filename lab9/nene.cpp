#include<iostream>
using namespace std;
int game(int arr[],int seq[],int size);
int main(){
    int cases,length,num;
    printf("Enter the number of Testcases: ");
    scanf("%d",&cases);
    for(int i =1;i<=cases;i++){
        printf("Enter the details of the Testcase %d:-\n",i);
        printf("Enter the length of Sequence:");
        scanf("%d",&length);
        int seq[length];
        printf("Enter the number of groups in the game: ");
        scanf("%d",&num);
        int arr[num];
        printf("Enter the poitions to check in the game: ");
        for(int j =0;j<length;j++){
            scanf("%d",&seq[j]);
        }
        printf("Enter the participants in each team: ");
        for(int j =0;j<num;j++){
            scanf("%d",&arr[j]);
        }
        game(arr,seq,num);
}}

// Function to Calculate number of Winners in the Game
int game(int arr[],int seq[],int size){
    printf("The number of Winners From each team is : ");
    for(int i =0;i<size;i++){
        if(arr[i]>=seq[0]){
            printf("%d " ,seq[0]-1);
        }
        else{
            printf("%d ",arr[i]);
        }
    }
    printf("\n\n");
    return 0;
}