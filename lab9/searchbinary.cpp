#include<iostream>
using namespace std;
class binary{
    struct node {
        int data;
        node *left;
        node *right;
    };
   public:
   node *root;
    binary(){
        root = NULL;
    }
    
int insert(int);
void preorder(node *root);
void inorder(node *root);
void postorder(node *root);
int search(int);

};
int main(){
    binary obj;
    int choice,value,target;
    do{
        printf("\n=====MENU CARD=====\n");
        printf("Enter 1: To Insert the element into the BinaryTree.\n");
        printf("Enter 2: To Perform Preorder Traversal.\n");
        printf("Enter 3: To Perform Inorder Traversal.\n");
        printf("Enter 4: To Perform Postorder Traversal.\n");
        printf("Enter 5: To search a Element in the Binary Tree\n");
        printf("Enter 6: To Exit the Program\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the value to insert: ");
            scanf("%d",&value) ;
            obj.insert(value);
            break;
            case 2:
            printf("The Preorder traversal: ");
            obj.preorder(obj.root);
            printf("\n");
            break;
            case 3:
            printf("The Inorder traversal: ");
            obj.inorder(obj.root);
            printf("\n");
            break;
            case 4:
            printf("The Postorder traversal: ");
            obj.postorder(obj.root);
            printf("\n");
            break;
            case 5:
            printf("Enter the value to search in the List: ");
            scanf("%d",&target);
            value = obj.search(target);
            break;
            case 6:
            printf("Program Ended");
            break;
            default:
            printf("Invalid Choice\n");
            printf("Enter your choice between 1 to 6\n");
        }
}while(choice!=6);
}
// Function to insert the character into the Binary tree
int binary::insert(int val){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    if(root==NULL){
        root = newnode;
        return 0;
    }
    node *temp = root;
    node *parent = NULL;
    int choice =0;
    while(temp!=NULL){
        parent = temp;
        if(temp->data > val){
            temp = temp->left;
            choice =0;
        }
        else{
            temp = temp->right;
            choice =1;
        }
    }
    if(choice ==0){
        parent->left = newnode;
    }
    if(choice ==1){
        parent->right = newnode;
    }
}
// Function to Perform preorder Traversal 
void binary :: preorder(node *temp){
    if(temp){
        printf("%d  ",temp->data);
        preorder(temp->left);
        preorder(temp->right);
     }
}


// Function to perform Inorder Traversal 
void binary :: inorder(node *temp){
    if(temp){
        inorder(temp->left);
        printf("%d ",temp->data);
        inorder(temp->right);
    }
}


// Function to perform Postorder Traversal 
void binary :: postorder(node *temp){
    if(temp){   
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ",temp->data);

    }}


// Function to serach an element in the Binary Tree
int  binary :: search(int target){
   
    if(root==NULL){
        printf("The tree is empty!\n");
        return 0;
    }
    node *temp = root;
    while(temp!=NULL){
        if(temp->data==target){
            printf("The element is found in the binary tree\n");
            return 0;
        }
        if(temp->data >target){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    printf("The element is not found in the binary tree\n");


}