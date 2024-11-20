#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};


void insertFront(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = (*head);
    newNode->prev = NULL;
    if ((*head) != NULL)
    (*head)->prev = newNode;
    (*head) = newNode;
}

void deleteAtPosition(struct Node** head, int position)
{
    if (*head == NULL)
        {
    printf("The list is already empty.\n");
    return;
    }
    struct Node* temp = *head;

for (int i = 1; temp != NULL && i < position; i++)
    {
    temp = temp->next;
    }
    if (temp == NULL)
     {
    printf("Position is greater than the number of nodes.\n");
    return;
    }
    if (temp->next != NULL)
    {
    temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL)
     {
    temp->prev->next = temp->next;
    }
    free(temp);
}


void displayList(struct Node* node)
{
    struct Node* last;
    while (node != NULL)
    {
    printf("%d->", node->data);
    last = node;
    node = node->next;
    }
    if (node == NULL)
    printf("NULL\n");
}

int main()
{
struct Node* head = NULL;
insertFront(&head, 1);
insertFront(&head, 6);
insertFront(&head, 10);
insertFront(&head, 20);
insertFront(&head, 203);
displayList(head);
deleteAtPosition(&head,3);
displayList(head);
deleteAtPosition(&head,2);
displayList(head);
return 0;
}
