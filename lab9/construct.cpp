
#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;

class Node {
public:
    char data;
    Node *left, *right;
    Node(char value) {
        data = value;
        left = right = NULL;
    }
};

class ExpressionTree {
public:
    Node* constructTree(char postfix[]);
    void inorder(Node* root);
    void preorder(Node* root);
    void postorder(Node* root);
    bool isAlnum(char c);
};

bool ExpressionTree::isAlnum(char c) {
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

Node* ExpressionTree::constructTree(char postfix[]) {
    stack<Node*> st;
    Node *t, *t1, *t2;
    
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isAlnum(postfix[i])) {
            t = new Node(postfix[i]);
            st.push(t);
        } else {
            t = new Node(postfix[i]);
            
            t1 = st.top();
            st.pop();
            t2 = st.top();
            st.pop();
            
            t->right = t1;
            t->left = t2;
            
            st.push(t);
        }
    }
    return st.top();
}

void ExpressionTree::inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

void ExpressionTree::preorder(Node* root) {
    if (root) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void ExpressionTree::postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

int main() {
    ExpressionTree t;
    char postfix[50];
    int choice;
    Node* root = NULL;
    
    do {
        printf("\n=====MENU CARD=====\n");
        printf("Enter 1: To Enter the Postfix Expression.\n");
        printf("Enter 2: To Construct the Expression tree\n");
        printf("Enter 3: To Perform Preorder Traversal.\n");
        printf("Enter 4: To Perform Inorder Traversal.\n");
        printf("Enter 5: To Perform Postorder Traversal.\n");
        printf("Enter 6: To Exit the Program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter postfix expression: ");
                scanf("%s", postfix);
                break;
            case 2:
                root = t.constructTree(postfix);
                printf("Expression tree constructed successfully.\n");
                break;
            case 3:
                if (root) {
                    printf("\nPreorder traversal: ");
                    t.preorder(root);
                    printf("\n");
                } else {
                    printf("\nTree not constructed yet!\n");
                }
                break;
            case 4:
                if (root) {
                    printf("\nInorder traversal: ");
                    t.inorder(root);
                    printf("\n");
                } else {
                    printf("\nTree not constructed yet!\n");
                }
                break;
            case 5:
                if (root) {
                    printf("\nPostorder traversal: ");
                    t.postorder(root);
                    printf("\n");
                } else {
                    printf("\nTree not constructed yet!\n");
                }
                break;
            case 6:
                printf("Program Ended\n");
                break;
            default:
                printf("Invalid Choice\n");
                printf("Enter your choice between 1 to 6\n");
        }
    } while(choice != 6); 
    
    return 0;
}