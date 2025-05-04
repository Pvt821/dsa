#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

class graph {
    struct node {
        int vertex;
        node* next;
    };
    int vertices;
    node* adjList[20];

public:
    graph(int numvertices) {
        if (numvertices > 20) {
            printf("Max allowed vertices is 20\n");
            numvertices = 20;
        }
        vertices = numvertices;
        for (int i = 0; i < vertices; i++) {
            adjList[i] = NULL;
        }
    }

    int insert(int, int);
    int deleteEdge(int, int);
    int search(int, int);
    void display();
};

int main() {
    int choice;
    int src;
    int dest;
    int vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    graph obj(vertices);

    do {
        printf("\n===Graph Menu===\n");
        printf("Enter 1 : To Insert an Edge\n");
        printf("Enter 2 : To Delete an Edge\n");
        printf("Enter 3 : To Search for an Edge\n");
        printf("Enter 4 : To Display the Graph\n");
        printf("Enter 5 : Exit the program\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the Source vertex to Insert: ");
            scanf("%d", &src);
            printf("Enter the Destination vertex to Insert: ");
            scanf("%d", &dest);
            obj.insert(src, dest);
            break;
        case 2:
            printf("Enter the Source vertex to Delete: ");
            scanf("%d", &src);
            printf("Enter the Destination vertex to Delete: ");
            scanf("%d", &dest);
            obj.deleteEdge(src, dest);
            break;
        case 3:
            printf("Enter the Source vertex to Search: ");
            scanf("%d", &src);
            printf("Enter the Destination vertex to Search: ");
            scanf("%d", &dest);
            obj.search(src, dest);
            break;
        case 4:
            obj.display();
            break;
        case 5:
            printf("Ending the Program\n");
            break;
        default:
            printf("Invalid choice\n");
            printf("Enter the choice between 1 to 5\n");
        }
    } while (choice != 5);
}

//Function to Insert Edge
int graph::insert(int src, int dest) {
    if (src < 0 || src >= vertices) {
        printf("Invalid source value\n");
        return -1;
    }
    if (dest < 0 || dest >= vertices) {
        printf("Invalid destination value\n");
        return -1;
    }

    node* newNode = (node*)malloc(sizeof(node));
    newNode->vertex = dest;
    newNode->next = adjList[src];
    adjList[src] = newNode;

    newNode = (node*)malloc(sizeof(node));
    newNode->vertex = src;
    newNode->next = adjList[dest];
    adjList[dest] = newNode;

    printf("Inserted Successfully\n");
    return 0;
}

//function to Delete Edge
int graph::deleteEdge(int src, int dest) {
    if (src < 0 || src >= vertices) {
        printf("Invalid source value\n");
        return -1;
    }
    if (dest < 0 || dest >= vertices) {
        printf("Invalid destination value\n");
        return -1;
    }

    int deleted = 0; // flag to track if we deleted

    node** curr = &adjList[src];
    while (*curr != NULL) {
        if ((*curr)->vertex == dest) {
            node* temp = *curr;
            *curr = (*curr)->next;
            free(temp);
            deleted = 1; // deleted from src
            break;
        }
        curr = &(*curr)->next;
    }

    curr = &adjList[dest];
    while (*curr != NULL) {
        if ((*curr)->vertex == src) {
            node* temp = *curr;
            *curr = (*curr)->next;
            free(temp);
            break;
        }
        curr = &(*curr)->next;
    }

    if (deleted) {
        printf("Edge deleted successfully between %d and %d\n", src, dest);
    } else {
        printf("Edge does not exist between %d and %d\n", src, dest);
    }
    
    return 0;
}


//Function to  Search Edge
int graph::search(int src, int dest) {
    if (src < 0 || src >= vertices) {
        printf("Invalid source value\n");
        return -1;
    }
    if (dest < 0 || dest >= vertices) {
        printf("Invalid destination value\n");
        return -1;
    }

    node* temp = adjList[src];
    while (temp != NULL) {
        if (temp->vertex == dest) {
            printf("Edge exists between %d and %d\n", src, dest);
            return 1;
        }
        temp = temp->next;
    }
    printf("Edge does not exist between %d and %d\n", src, dest);
    return 0;
}

// Function to Display Graph
void graph::display() {
    for (int i = 0; i < vertices; i++) {
        printf("%d --> ", i);
        node* temp = adjList[i];
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
