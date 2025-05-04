#include<stdio.h>
void SelectionSort(int arr[],int len);
void BubbleSort(int arr[],int len);
void InsertionSort(int arr[],int len);

int main(){
    int length;
    printf("Enter the size of the Array");
     scanf("%d",&length);
     int array[length];
     printf("Enter the %d numbers ",length);
     for(int i =0;i<length;i++){
        scanf("%d",&array[i]);
     }

    int choice;

do{
    printf("MENU CARD\n");
    printf("1.Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Exit\n");
    printf("Enter the choice: ");
    scanf("%d",&choice);

switch(choice){
    case 1:
    BubbleSort(array,length);
    break;

    case 2:
    SelectionSort(array,length);
    break;

    case 3:
    InsertionSort(array,length);
    break;

    case 4:
    printf("Program Ended");
    break;
    default :
    printf("Enter valid number\n\n");


}
}
while(choice!=4);


return 0;
}
// code for Selection Sort
void SelectionSort(int arr[],int len){
    for(int i =0;i<len-1;i++){
        int min = i;
        for(int j =i+1;j<len;j++){
            if(arr[min]>arr[j]){
                min = j;
            }

        }
        if(arr[min]!= arr[i]){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    for(int i =0;i<len;i++){
        printf("%d\t",arr[i]);
    }
     printf("\n\n");
}

// code for Bubble Sort
void BubbleSort(int arr[],int len){
    for(int i =0;i<len-1;i++){
        for(int j=0;j<len-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]= arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i =0;i<len;i++){
        printf("%d\t",arr[i]);
    }
     printf("\n\n");
}

// code for Insertion Sort
void InsertionSort(int arr[],int len){
    for(int i =0;i<len;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0&& arr[j]>key){
            arr[j+1]= arr[j];
           j = j-1;}
         arr[j+1]= key;
        
    }
    for(int i =0;i<len;i++){
        printf("%d\t",arr[i]);
    }
     printf("\n\n");



}



