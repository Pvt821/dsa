// Program to create List ADT using Doubly linked list

#include<cstdio>
#include<cstdlib> 
class list{
    struct node{
    int data;
    node *next;
    node *prev;
   };
node *head;
node *tail;
   public:
list(){ 
    head = NULL;
    tail = NULL; }

// Function prototypes
   int insertBegin(int);
   int insertend(int);
   int insertpos(int,int);
   int deleteBegin();
   int deleteEnd();
   int deletepos(int);
   void display();
   int search(int);
};
int main(){
    int choice,value,pos,result,target;
    list obj;
    printf("\n");
    do{
        printf("MENU CARD\n");
        printf("Enter 1: To Insert the element at the Beginning of the List\n");
        printf("Enter 2: To Insert the element at the End of the List\n");
        printf("Enter 3: To Insert the element at a Specific Positon of the List\n");
        printf("Enter 4: To Delete the element at the Beginning of the List\n");
        printf("Enter 5: To Delete the element at the End of the List\n");
        printf("Enter 6: To Delete the element at a Specific Positon of the List\n");
        printf("Enter 7: To search the element in the List\n");
        printf("Enter 8: To Display the elements of the List\n");
        printf("Enter 9: To Exit the Program\n\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the element to insert in the List: ");
            scanf("%d",&value);
            obj.insertBegin(value);
            break;
            case 2:
            printf("Enter the element to insert in the List: ");
            scanf("%d",&value);
            obj.insertend(value);
            break;
            case 3:
            printf("Enter the element to insert in the List: ");
            scanf("%d",&value);
            printf("Enter the position to insert: ");
            scanf("%d",&pos);
            obj.insertpos(pos,value);
            break;
            case 4:
            result = obj.deleteBegin();
            if(result!=0){
                printf("The value of the node deleted is :%d\n",result);
            }
            break;
            case 5:
            result = obj.deleteEnd();
            if(result!=0){
                printf("The value of the node deleted is :%d\n",result);
            }
            break;
            case 6:
            printf("Enter the position to delete: ");
            scanf("%d",&pos);
            result = obj.deletepos(pos);
            if(result!=0){
                printf("The value of the node deleted is :%d\n",result);
            }
            break;
            case 7:
            printf("Enter the element to search: ");
            scanf("%d",&target);
            result = obj.search(target);
            if (result!=-1){
                printf("The element found in the list\n");
                printf("The position of the element in the list is: %d\n",result);
            }
            else if (result == -1){
                printf("Element not found in the list\n");
            }
            break;
            case 8:
            obj.display();
            break;
            case 9:
            printf("Program Ended\n");
            break;
            default:
            printf("Invalid choice\n");
            printf("Enter the choice between 1 to 9\n");
            break;
        }
    }
    while(choice!=9);
    return 0;
}
// Function to Insert the element at the Beginning of the List
int list :: insertBegin(int value){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = head;
    newnode->prev = NULL;
    if (head==NULL){
        head =  newnode;
        tail = newnode;
        return 0;}
    head->prev = newnode;
    head = newnode;
    return 0;
}
// Function to Display the elements of the List
void list :: display(){
    if(head == NULL){
        printf("The List is empty\n");
        return;
    }
    printf("The elements in the List are : ");
    node *temp = head;
    while(temp!= NULL){
        printf("%d  ",temp->data);
        temp = temp->next;
    }
    printf("\n");
    printf("The list is in reverse order: ");
    temp = tail;
    while(temp!= NULL){
        printf("%d  ",temp->data);
        temp = temp->prev;
    }
    printf("\n\n");
    
}

// Function to Insert the element at the end of the List
int list :: insertend(int value){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;
    if(tail==NULL){
        head = newnode;
        tail = newnode;
        return 0;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
     return 0;}

// Function to Insert the element at a Specific Position of the List
int list :: insertpos(int pos,int value){
    if(pos<1){
        printf("Invalid position\n");
        return 0 ;
    }
    if (pos==1){
        insertBegin(value);
        return 0;
    }
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;
    node *temp = head;
    int i =1;
    while(i<pos-1 && temp!=NULL){
        temp = temp->next;
        i++;
}
if(temp==NULL){
    printf("position is not available in the list\n");
    printf("Enter valid position number\n\n");
    free(newnode);
    return 0;
}
if (temp==tail){
    insertend(value);
    return 0;
}
newnode->next = temp->next;
newnode->prev = temp;
temp->next = newnode;
temp = newnode->next;
temp->prev  = newnode;
return 0;
}
// Function to Delete the node at the Beginning of the List
int list :: deleteBegin(){
    if(head == NULL){
        printf("The list is empty\n");
        return 0;
    }
    if(head==tail){
        node *temp = head;
        int result = head->data;
        head = NULL;
        tail= NULL;
        free(temp); 

        printf("All the elements in the list are deleted\n");
        return result ;
    }
    node *temp = head;
    head = head->next;
    head->prev = NULL;
    int result = temp->data;
    free(temp);
    return result;

}
// Function to Delete the Element at the End of the List
int list :: deleteEnd(){
    if(tail==NULL){
        printf("the list is empty\n");
        return 0;
    }
    if(tail==head){
        int result = head->data;
        deleteBegin();
        return result;
    }
    node *temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    int result = temp->data;
    free(temp);
    return result;
}
// Function to Delete the node at a Specific Position of the List
int list :: deletepos(int pos){
    if(pos<1){
        printf("Invalid position\n");
        return 0;
    }
    if (pos==1){
        int result = head->data;
        deleteBegin();
        return result;
    }
    node *temp = head;
    int i =1;
    while(i<pos-1 && temp!=NULL){
        temp = temp->next;
        i++;
    }
    if(temp==NULL||temp==tail){
        printf("There is no such position in the list to delete\n");
        printf("Enter valid position\n");
        return 0;
    }
    if(tail==temp->next){// what if there are only 2 nodes
        temp = temp->next;
        int result = temp->data;
        deleteEnd();
        return result;
    }
    node *del = temp->next;
    temp->next = del->next;
    int result = del->data;
    temp = del->next;
    temp->prev = del->prev;
     return result;

}
// Function to Search the element in the List
int list :: search(int target){
    if(head==NULL){
        printf("the list is empty\n");
        return 0;
    }
    node * temp = head;
    int count=1;
    while(temp!=NULL){

        if(temp->data==target){
            return count;
        }
        temp = temp->next;
        count++;
    }
    return -1;
}

