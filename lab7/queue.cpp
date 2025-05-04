#include<cstdio>
#include<cstdlib>
class queue{
    struct node{
        int data;
        node *next;
    };
    node *front;
    node *rear;
public:
queue(){
    front = NULL;
    rear = NULL;
}
int enqueue(int);
int dequeue();
void display();
int peek();
};

int main(){
    queue obj;
    int choice,result,value;
    do{
        printf("\n===Queue Menu===\n");
        printf("Enter 1 : To insert the element into the Queue\n");
        printf("Enter 2 : To delete the element from the Queue\n");
        printf("Enter 3 : To display the first element in the Queue\n");
        printf("Enter 4 : Exit the program\n");
        printf("enter the choice: ");
        scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("Enter the value: ");
        scanf("%d",&value);
        obj.enqueue(value);
        break;
        case 2:
        value = obj.dequeue();
        if(value!= 0){
            printf("The element dequeue is %d",value);
        }
        break;
        case 3:
        value =obj.peek();
        if(value!= 0){
            printf("The element at the front  is %d",value);
        }
        break;
        case 4:
        printf("program Ended\n");
        break;
        default:
        printf("Invalid choice\n");
        printf("Enter the choice between 1 to 4\n");

    }}
    while(choice!=4);
}
// Function to insert the element at the end of the queue
int queue:: enqueue(int value){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;
    if(front==NULL){
        front = newnode;
        rear = newnode;
        return 0;
    }
        rear->next = newnode;
        rear = newnode;
        return 0;
    
}
// Function to Delete a element from the front of the Queue
int queue :: dequeue(){
    if(front==NULL){
        printf("The queue is empty\n");
        return 0;
    }
    if(front == rear){
        int result = front->data;
        front = NULL;
         rear = NULL;
         return result;

    }
    node *temp = front;
    int result = front->data;
    front = temp->next;
    free(temp);
    return result;
}
// Function to Display the First element of the Queue
int queue::peek(){
    if(front==NULL){
        printf("The queue is empty\n");
        return 0;
    }
    return front->data;

}