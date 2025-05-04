// header file code
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
     printf("\n");
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
     printf("\n");
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
     printf("\n");
}
