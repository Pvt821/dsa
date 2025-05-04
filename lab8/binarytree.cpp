#include<iostream>
#include<cstdlib>
using namespace std;
class binary{
    struct node{
    char data;
    node *left;
    node *right;

    };
    
public:
node *root;
binary(){
    root = NULL;
}
int insert(char);
void preorder(node* temp);
int inorder(node* temp);
int postorder(node* temp);
int search(node *temp,char);
    
};
int main(){
    binary obj;
    int choice,result;char value;
    do{
        printf("\n\n===Binary Menu===\n");
        printf("Enter 1 : To insert the element into the Tree\n");
        printf("Enter 2 : For Preorder Traversal\n");
        printf("Enter 3 : For Inorder Traversal\n");
        printf("Enter 4 : For Postorder Traversal\n");
        printf("Enter 5 : To serach a element\n");
        printf("Enter 6 : Exit the program\n");
        printf("enter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the character to be inserted:");
            scanf(" %c",&value);
            obj.insert(value);
            break;
            case 2:
            obj.preorder(obj.root);
            break;
            case 3:
            obj.inorder(obj.root);
            break;
            case 4:
            obj.postorder(obj.root);
            break;
            case 5:
            printf("Enter the character to Search:");
            scanf(" %c",&value);
            result = obj.search(obj.root,value);
            if(result ==1){
                printf("The given character is found in the tree\n");

            }
            else{
                printf("The character is not found in the tree\n");
            }

            break;
            case 6:
            printf("Program Ended\n");
            break;
            default:
            printf("Invalid choice\n");
            printf("Enter your choice between 1 to 6\n");
        }
    }while(choice!=6);
}
// Function to insert the character into the Binary tree
int binary :: insert(char value){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    if(root == NULL){
        root = newnode;
        printf("Inserted %c as root node",value);
        return 0;
    }
    node *temp = root;
    node *parent = NULL;
    int choice;
    while(temp!=NULL){
        parent = temp;
        printf("insert %c to the left or right of %c\n",value ,temp->data);
        printf("Enter 0 for left and 1 for right ");
        scanf("%d",&choice);
        if(choice==0){
            temp = temp->left;
        }
        else if(choice==1){
            temp = temp->right;

        }
        else {
            printf("Invalid choice! Try again.\n");
            return 0;
       }}
       if(choice==0){
        parent->left = newnode;
       }
       else if(choice==1){
        parent->right = newnode;
       }
    return 0;

}
// Function to Perform preorder Traversal 
void binary :: preorder(node *temp){
    if(temp){
        printf("%c  ",temp->data);
        preorder(temp->left);
        preorder(temp->right);

    }

}
// Function to perform Inorder Traversal 
int binary :: inorder(node *temp){
    if(temp){
        inorder(temp->left);
        printf("%c  ",temp->data);
        inorder(temp->right);
    }

}
// Function to perforn Postorder Traversal 
int binary :: postorder(node *temp){
    if(temp){   
        postorder(temp->left);
        postorder(temp->right);
        printf("%c  ",temp->data);

    }

}
// Function to Search a Character in the binary tree
int binary :: search(node *temp,char value){
    if(temp==NULL){
        return 0;
    }
    if (temp == NULL) 
    return 0;   
    if (temp->data == value) 
    return 1;   

    return search(temp->left, value) || search(temp->right, value);
}