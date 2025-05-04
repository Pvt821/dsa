#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void Palindrome(int * num);
void Armstrong(int *num);
void Perfect(int * num);
int main (){
int *choice = (int *)malloc(sizeof(int));
int *number = (int *)malloc(sizeof(int));
 do {
        printf("Menu Card\n");
        printf("Enter 1:To chcek for Palindrome number\n");
        printf("Enter 2:To check for Armstrong number\n");
        printf("Enter 3: to check for Perfect number\n");
        printf("Enter 4 : To Exit the program\n");
        printf("Enter your choice:");
        scanf("%d",choice);
 switch(*choice){
     case 1:
         printf("Enter the number: ");
         scanf("%d",number);
         if (*number< 0){
            printf("Invalid number\nEnter positive number\n\n");
         }
         else{
          Palindrome(number);
         }break;
         case 2:
         printf("Enter the number: ");
         scanf("%d",number);
         if (*number< 0){
            printf("Invalid number\nEnter positive number\n\n");
         }
            else{
                Armstrong(number);
            }break;
            case 3:
             printf("Enter the number: ");
            scanf("%d",number);
            if (*number< 0){
                printf("Invalid number\nEnter positive number\n\n");
            }
            else{
                Perfect(number);
            }break;
            case 4:
            printf("Program ended\n");
            printf("Thank you\n\n");
            break;
        default :
         printf("Inavlid choice\n");
         printf("Please enter number between 1 to 4\n\n");}
     }
     while(*choice!=4);
free(number);
free(choice);
}
void Palindrome(int * num){
    int *temp = (int *) malloc (sizeof(int)); 
    int *rem = (int *) malloc (sizeof(int));
    int *num2 = (int *) malloc (sizeof(int));
    *num2 =0;
    *rem = 0;
    *temp = *num;
    while(*temp !=0){
        *rem = (*temp)%10;
        *num2 = (*num2)*10+ *rem;
        (*temp )= (*temp)/10;
    }
    if (*num2 == *num){
        printf("It is a Palindrome number\n\n");
    }
    else {
        printf("It is not a Palindrome number\n\n");
    }
    free(temp);
    free(rem);
    free(num2);

}
void Armstrong(int *num){
int *temp = (int *) malloc (sizeof(int)); 
int *rem = (int *) malloc (sizeof(int));    
int *num2 = (int *) malloc (sizeof(int));
int *count =(int *)malloc(sizeof(int));
*temp = *num;
*count =0;
*rem =0;
*num2 = 0;
while(*temp!=0){
    (*count)++;
    *temp = (*temp)/10;
}
*temp = *num;
while(*temp !=0){
    *rem = *temp %10;
    *num2 = (*num2)+ pow(*rem,*count);
    *temp = (*temp)/10; 
}
if(*num2 == *num){
    printf("Its a Armstrong number\n\n");
}
else {
    printf("Its not a Armstrong number\n\n");
}
 free(temp);
 free(rem);
 free(num2);
 free(count);
}


void Perfect(int * num){
int *i = (int *) malloc (sizeof(int));    
int *sum = (int *) malloc (sizeof(int));
*i =1;
*sum =0;
while(*i<(*num)){
    if(*num % (*i)==0){
        *sum += *i;
    }
(*i)++;
}
if(*sum == *num){
        printf("Its a Perfect number\n\n");
    }
else{
        printf("Its not a Perfect number\n\n");
    }
free(sum);
 free(i);

}
