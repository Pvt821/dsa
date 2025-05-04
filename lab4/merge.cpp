//Program to insert elements in ascending order and merge two elements from the linked list
#include "linkedlist.h"
int main(){
    int choice;
    list l1;
    list l2;
    list list3;
    int value;
    printf("\n");
    do{
        printf("MENU CARD\n");
        printf("Enter 1: To insert the element into list1\n");
        printf("Enter 2: To insert the element into list2\n");
        printf("Enter 3: To merging lists\n");
        printf("Enter 4: To display the elements in the list\n");
        printf("Enter 5: To exit the program\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the value to insert: ");
            scanf("%d",&value);
            l1.insert(value);
            printf("\n");
            break;
            case 2:
            printf("Enter the value to insert: ");
            scanf("%d",&value);
            l2.insert(value);
            printf("\n");
            break;
            case 3:
            list3 = list3.merge(l1,l2);
            printf("\n");
            break;
            case 4:
            printf("list 1: ");
            l1.display();
            printf("list 2: ");
            l2.display();
            printf("list 3: ");
            list3.display();
            printf("\n");
            break;
            case 5:
            printf("Ending the program\n");
            printf("\n");
            return 0;
            default:
            printf("Enter valid choice\n");
            printf("\n");
        }
    }
    while(choice!=5);
}
//Function to insert elements in ascending order in linked list
int list ::insert(int value){
     node *newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;
     node *temp = head;
    if (head == NULL){
        newnode->next = NULL;
        head = newnode;
        return 1;
    }
    if (temp->data>=value){
        newnode->next = head;
        head = newnode;
    }
    while(temp->next!=NULL && temp->next->data<value ){
        temp = temp->next;
    } 
    newnode->next = temp->next;
    temp->next = newnode;
    return 1;
}
//Function to merge two lists
list list ::merge(list lst1,list lst2){
     node *list1 = lst1.gethead();
     node *list2 = lst2.gethead();
    list list3;
    while(list1!=NULL && list2!=NULL){
        if (list1->data > list2->data){
            list3.insert(list2->data);
            list2= list2->next;
        }
        else{
            list3.insert(list1->data);
            list1=list1->next;
        }
    }
    while(list1!=NULL){
        list3.insert(list1->data);
        list1=list1->next; 
    }
    while(list2!=NULL){
        list3.insert(list2->data);
        list2= list2->next;
    }
    list3.display();
    return list3;
}
//Function to display lists
void list :: display(){
    if(head==NULL){
        printf("The list is empty.\n");
        return;
    }
     node *temp = head;
    while(temp!=NULL){
        printf("%d   ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}