#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtFront(struct Node** head, int data)
{
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data)
{
     struct Node* newNode = createNode(data);
     if (*head == NULL)
     {
         *head = newNode;
         return;
     }

     struct Node* temp = *head;
     while (temp->next != NULL)
     {
         temp = temp->next;
     }
     temp->next = newNode;
}

void insertAtPosition(struct Node** head, int data, int position)
{
    if (position == 0)
    {
        insertAtFront(head, data);
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("List out of range\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void printList(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node* head = NULL;

    insertAtFront(&head, 10);
    printList(head);

    insertAtEnd(&head, 20);
    printList(head);

    insertAtEnd(&head, 30);
    printList(head);

    insertAtEnd(&head, 40);
    printList(head);

    insertAtPosition(&head, 15, 2);
    printList(head);

    return 0;
}
