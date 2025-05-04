#include<cstdio>
#include<cstdlib>
class list{
    private:
    typedef struct node{
        int data;
        node *next;
    }node;
    node* head;
    public:
    // constructor
    list(){
        head= NULL;
    }
    void insertBegin(int);
    void insertend(int );
    void insertpos(int ,int );
    int deletebegin();
    int deleteEnd();
    int deletepos(int );
    int search(int );
    void display();
    void displayReverse();
    int reverselist();
};
int main(){
    list l;
    int choice;
    int value;
    int pos;
    int target;
    int result;
    printf("\n");
    do{
        printf("MENU CARD\n");
        printf("Enter 1: To insert the node at the Beginning\n");
        printf("Enter 2: To insert the node at the Ending\n");
        printf("Enter 3: To insert the node at the Specific Position\n");
        printf("Enter 4: To Delete the node at the Beginning\n");
        printf("Enter 5: To Delete the node at the Ending\n");
        printf("Enter 6: To Delete the node at the Specific Position\n");
        printf("Enter 7: To Search the node in the List\n");
        printf("Enter 8: To Display the List\n");
        printf("Enter 9: To Display the List in Reverse Order\n");
        printf("Enter 10: To Reverse the List\n");
        printf("Enter 11: TO End the Program\n\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the value to insert: ");
            scanf("%d",&value) ;
            l.insertBegin(value);
            break;
            case 2:
            printf("Enter the value to insert: ");
            scanf("%d",&value) ;
            l.insertend(value);
            break;
            case 3:
            printf("Enter the value to insert: ");
            scanf("%d",&value) ;
            printf("Enter the position of the node to insert the Given value: ");
            scanf("%d",&pos);
            l.insertpos(value,pos);
            break;
            case 4:
            result = l.deletebegin();
            if(result!=0){
            printf("The value of the deleted node is:%d\n\n",result);}
            break;
            case 5:
            result = l.deleteEnd();
            if (result!=0){
            printf("The value of the deleted node is:%d\n\n",result);}
            break;
            case 6:
            printf("Enter the position of the node to Delete: ");
            scanf("%d",&pos);
            result = l.deletepos(pos);
             if (result!=0){
            printf("The value of the deleted node is:%d\n\n",result);}
            break;
            case 7:
            printf("Enter the value to search in the List: ");
            scanf("%d",&target);
             result = l.search(target);
             if(result!=-1){
                printf("The target found\n The position of the node in the list is : %d\n",result);

             }
             if (result == -1){
                printf("The element is not found\n");
             }
            break;
            case 8:
            l.display();
            break;
            case 9:
            l.displayReverse();
            break;
            case 10:
            result = l.reverselist();
            if(result!=0){
                printf("The list is reversed successfully\n");
            }
            break;
            case 11:
            printf("Program ended\n");
            printf("Thank You\n\n");
            break;
            default:
            printf("Invalid choice\nPlease Enter your choice between 1 to 11\n");
        }

}while(choice!=11);
}

// Function to insert the node at the begin
void list :: insertBegin(int value){
    node * newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = head;
    head = newnode;
    printf("\n\n");
}
// Function to display the list
void list :: display(){
    if(head== NULL){
        printf("The List is empty\n");
        return;
    }
    node *temp = head;
    printf("The elements in the List is :");
    while(temp !=NULL){
        printf("%d  ",temp->data);
        temp = temp->next;    }
        printf("\n\n");
}

// Function to insert the node at the end
void list:: insertend(int value){
    if(head==NULL){
        insertBegin(value);
        return;
    }
     node * newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;
    node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp -> next = newnode;

}
// Function to insert the node at the specific position 
void list :: insertpos(int value,int pos){
    if (pos<1){
        printf("Invalid node's position\n");
        return;
    }
    if (pos==1){
        insertBegin(value);
        return;
    }
    int i =1;
    node * newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;

    node *temp = head;
    while(i<pos-1 &&temp!=NULL){
        temp = temp->next;
        i++;
    }
    if(temp== NULL){
        printf("position is not available in the list\n");
        printf("Enter valid position number\n\n");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    temp ->next = newnode;}



// Function to delete the first node in the list
int list :: deletebegin(){
    if(head==NULL){
        printf("The list is empty\n");
        return 0;
    }
    node *temp = head;
    int result = temp ->data;
    head = temp->next;
    free(temp);
    return result;

}
// Function to delete the last node in the list
int list :: deleteEnd(){
    if (head == NULL){
        printf("The List is Empty\n ");
        return 0;
    }
    node *temp = head;
    while(temp ->next ->next!=NULL){
        temp = temp->next;
    }
    
    node *del = temp->next;
    int result = del->data;
    temp->next = NULL;
    free(del);
    return result;

} 
// Function to delete at specific position in the list
int list :: deletepos(int pos){
     if (pos<1){
        printf("Invalid node's position\n");
        return 0;
    }
    if (pos==1){
        deletebegin();
        return 0;

    }
    int i =1;
    node *temp = head;
    while(i<pos-1 && temp!=NULL){
        temp = temp->next;
        i++;
    }
    if(temp==NULL||temp->next==NULL){
        printf("The node is not available to delete\n Inavlid position\n");
        return 0;
    }
    node *del = temp->next;
    int result = del->data;
    temp->next = del->next;
    free(del);
    return result;

}

// Function to find the target in the list
int list :: search(int target){
    node *temp = head;
    int count =0;
    while(temp!=NULL){
        count++;
        

        if(temp->data == target){
            return count;
        }
        temp = temp->next;

    }return -1;
}
//  Function to dispaly the link in reverse order
void list :: displayReverse(){
    if(head==NULL){
        printf("The list is empty\n");
        return;
    }
    node *temp = head;
    int count =0;
    while(temp!=NULL){
        temp = temp->next;
        count++;

    }
   for (int i=count;i>0;i--){
    temp = head;
    int  j = i-1;
    while(j>0){
        temp = temp->next;
        j--;
    } 
    printf("%d\t",temp->data);
   }
   printf("\n\n");
}
// Function to reverse the list 
int list:: reverselist(){
    if(head==NULL){
        printf("The list is empty\n");
        return 0;
    }
node * temp = head;
node *next = NULL;
node * prev = NULL;
while(temp!=NULL){
    next = temp->next;
    temp->next = prev;
    prev = temp;
    temp = next;
}head = prev;
return 1;
}
