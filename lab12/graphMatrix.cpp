#include<iostream>
using namespace std;
class graph{
    int vertices;
    int matrix[20][20];
    public:
    graph(int numvertices){
        if (numvertices>20){
            printf("Max allowed vertices is 20\n");
            numvertices =20;
        }
        vertices = numvertices;
        for (int i =0;i<vertices;i++){
            for (int j =0;j<vertices;j++){
                matrix[i][j]=0;
            }
        }
    }
    int insert(int,int);
    int deleteEdge(int,int);
    int search(int ,int);
    void display();
};

int main(){
    int choice;
    int src;
    int dest;
    int vertices;
    printf("Enter the number of vertices: ");
    scanf("%d",&vertices);
    graph obj(vertices);
    do{
        printf("\n===Graph Menu===\n");
        printf("Enter 1 : To Insert an Edge\n");
        printf("Enter 2 : To Delete an Edge\n");
        printf("Enter 3 : To Search for an Edge\n");
        printf("Enter 4 : To Display the Graph\n");
        printf("Enter 5 : Exit the program\n");
        printf("enter the choice: ");
        scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("Enter the Source vertex to Insert:");
        scanf("%d",&src);
        printf("Enter the Destination vertex to Insert");
        scanf("%d",&dest);
        obj.insert(src,dest);
        break;
        case 2:
        printf("Enter the Source vertex to Delete:");
        scanf("%d",&src);
        printf("Enter the Destination vertex to Delete");
        scanf("%d",&dest);
        obj.deleteEdge(src,dest);
        break;
        case 3:
        printf("Enter the Source vertex to Search:");
        scanf("%d",&src);
        printf("Enter the Destination vertex to Search:");
        scanf("%d",&dest);
        obj.search(src,dest);
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

    }}
    while(choice!=5);
}
//Function to Insert Edge
int graph::insert(int src,int dest){
    if(src<0||src>vertices){
        printf("Invalid source value\n");
        return -1;
    }
    if(dest<0||src>vertices){
        printf("Invalid Destination value\n");
        return -1;
    }
    matrix[src][dest]= 1;
    matrix[dest][src]= 1;
    printf("Inserted Successfully\n");
    return 0;
}
//Function to Delete Edge
int graph::deleteEdge(int src,int dest){
    if(src<0||src>vertices){
        printf("Invalid source value\n");
        return -1;
    }
    if(dest<0||src>vertices){
        printf("Invalid Destination value\n");
        return -1;
    }
    if(matrix[src][dest]!=1){
        printf("Edge does not exists between %d and %d\n",src,dest);
        return -1;
    }
    matrix[src][dest]= 0;
    matrix[dest][src]= 0;
    return 0;
}
//Function to search Edge
int graph::search(int src,int dest){
    if(src<0||src>vertices){
        printf("Invalid source value\n");
        return -1;
    }
    if(dest<0||src>vertices){
        printf("Invalid Destination value\n");
        return -1;
    }
    if(matrix[src][dest]==1){
        printf("Edge exists between %d and %d\n",src,dest);
        return -1;
    } 
    else{
        printf("Edge does not exists between %d and %d\n",src,dest);
    }

}
//Function to Display the graph
void graph::display(){
    for (int i =0;i<vertices;i++){
        printf("%d   ",i);
    }
    printf("\n");
    for(int i =0;i<vertices;i++){
        for (int j =0;j<vertices;j++){
            printf("%d   ",matrix[i][j]);
        }
        printf("\n");
    }
    
}