#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* next;
};


void display(struct node* head) {
    struct node* temp = head;
    int count = 0;


    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
        count++;
    }

    printf("NULL\n");
    printf("Total nodes are: %d\n", count);


    if (count % 2 == 0) {

        int mid1 = count / 2;
        int mid2 = mid1 + 1;
        temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (pos == mid1) {
                printf("Middle node is: %d and %d\n", temp->data, temp->next->data);
                return;
            }
            temp = temp->next;
            pos++;
        }
    } else {

        int middle = count / 2;
        temp = head;
        int pos = 0;
        while (temp != NULL) {
            if (pos == middle) {
                printf("Middle node is: %d\n", temp->data);
                return;
            }
            temp = temp->next;
            pos++;
        }
    }
}

int main() {
    struct node *newNode, *head = NULL, *temp;
    int choice = 1;

    while (choice) {
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;


        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
          printf("Enter choice (1 to continue, 0 to stop): ");
        scanf("%d", &choice);
    }


    display(head);

    return 0;
}
