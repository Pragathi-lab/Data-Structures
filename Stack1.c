#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5  

int stack[MAX_SIZE];
int top = -1;  

void push() {
    if (top == MAX_SIZE - 1) {
        printf("Stack is Full\n");
    } else {
        int item;
        printf("Enter the element to push: ");
        scanf("%d", &item);
        stack[++top] = item;  
        printf("%d has been pushed onto the stack.\n", item);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack is Empty\n");
    } else {
        int item = stack[top--];  
        printf("The deleted element is: %d\n", item);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is Empty\n");
    } else {
        printf("Stack elements (top to bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("1-Push 2-POP 3-DISPLAY 4-EXIT Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
