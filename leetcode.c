#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct Stack {
    int array[MAX];
    int top;
};

// Function to push an element into a stack
void Push(int element, struct Stack *ps) {
    if (ps->top == MAX - 1) {
        printf("Stack overflow!\n");
        return;
    }
    ps->top++;
    ps->array[ps->top] = element;
}

// Helper function to pop an element from a single stack
int Pop1(struct Stack *ps) {
    if (ps->top == -1) {
        printf("No elements in stack.\n");
        return -1;
    }
    int value = ps->array[ps->top];
    ps->top--;
    return value;
}

// Function to pop an element from the "queue"
int Pop(struct Stack *ps1, struct Stack *ps2) {
    if (ps2->top != -1) {
        return Pop1(ps2);
    }
    if (ps1->top == -1) {
        printf("Queue underflow!\n");
        return -1;
    }
    while (ps1->top != -1) {
        int temp = Pop1(ps1);
        Push(temp, ps2);
    }
    return Pop1(ps2);
}

// Function to display elements in the queue
void Display(struct Stack *ps1, struct Stack *ps2) {
    if (ps1->top == -1 && ps2->top == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements:\n");

    // Print elements from `ps2` stack
    for (int i = ps2->top; i >= 0; i--) {
        printf("%d\n", ps2->array[i]);
    }

    // Print elements from `ps1` stack
    for (int i = 0; i <= ps1->top; i++) {
        printf("%d\n", ps1->array[i]);
    }
}

int main() {
    int element, choice;
    struct Stack s1, s2;
    s1.top = -1;
    s2.top = -1;

    while (1) {
        printf("\nQueue using stack operations\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be enqueued: ");
                scanf("%d", &element);
                Push(element, &s1);
                break;

            case 2:
                element = Pop(&s1, &s2);
                if (element != -1) {
                    printf("Dequeued element: %d\n", element);
                }
                break;

            case 3:
                Display(&s1, &s2);
                break;

            case 4:
                exit(0);

            default:
                printf("Please enter a valid choice.\n");
                break;
        }
    }
    return 0;
}
