#include<stdio.h>
#define MAX 5

void dfs(int adj[][MAX], int visited[], int start)
{
    int stack[MAX];
    int top = -1, i, k;


    for(k = 0; k < MAX; k++) {
        visited[k] = 0;
    }


    stack[++top] = start;
    visited[start] = 1;


    while(top != -1)
    {
        start = stack[top--];
        printf("%d -> ", start);


        for(i = 0; i < MAX; i++)
        {
            if(adj[start][i] && visited[i] == 0)
            {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int visited[MAX] = {0};
    int adj[MAX][MAX], i, j;
    int option, size;

    do {
        printf("\n ********* Main Menu ************\n");
        printf("\n 1. Enter values in graph ");
        printf("\n 2. DFS Traversal");
        printf("\n 3. Exit");
        printf("\n \n Enter your choice: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("\n Enter the adjacency matrix:\n");
                for(i = 0; i < MAX; i++) {
                    for(j = 0; j < MAX; j++) {
                        scanf("%d", &adj[i][j]);
                    }
                }
                break;

            case 2:
                printf("\n DFS Traversal: ");
                dfs(adj, visited, 0);
                printf("\n");
                break;

            case 3:
                printf("\n Exiting program.\n");
                break;

            default:
                printf("\n Invalid option. Please try again.\n");
        }
    } while(option != 3);

    return 0;
}
