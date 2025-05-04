// Program to calculate the number of Blocks in the tower 1
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int towers,cases;
    printf("Enter the number of Testcases: ");
    scanf("%d",&cases);
    for(int i =1;i<=cases;i++){
        printf("\nEnter the details of the Testcase %d:-\n",i);
        printf("Enter the number of towers:");
        scanf("%d",&towers);
        int arr[towers];
        for(int i =0;i<towers;i++){
            printf("Enter the number of blocks in the Tower %d: ",i+1);
            scanf("%d",&arr[i]);
        }
        sort(arr+1,arr+towers);
        for(int i =1;i<towers;i++){
            if(arr[0]<arr[i]){
                if((arr[0]+arr[i])%2==0){
                    arr[0]= (arr[0]+arr[i])/2;
                }
                else{
                    arr[0]= ((arr[0]+arr[i])/2) +1;

                }
            }

        }
        printf("The number of blocks in the tower 1 is %d\n",arr[0]);
    
}
return 0;
}