#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;

void push(int val)
{
    struct node *newNode=malloc(sizeof(struct node));
    newNode->data=val;
    newNode->next=head;
    head=newNode;
}

void pop()
{
    struct node *temp;
    if(head==NULL)
        printf("Stack is empty \n");
    else
    {
        printf("Popped element is %d,",head->data);
        temp=head;
        head=head->next;
        free(temp);
    }
}

void printList()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("Null \n");
}


struct Node
{
    int data;
    struct Node *next;
};

struct Node *front=NULL, *rear=NULL;
void enqueue(int value)
{
    struct Node *newNode=malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    if(front==NULL && rear==NULL)
        front=rear=newNode;
    else
    {
        rear->next=newNode;
        rear=newNode;
    }
}

void dequeue()
{
    struct Node *temp;
    if(front==NULL)
        printf("Queue is empty:\n");
    else
    {
        temp=front;
        front=front->next;
        if(front==NULL)
            rear=NULL;
        free(temp);
    }
}

void printList1()
{
    struct Node *temp=front;
    while(temp)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("Null\n");
}

int main()
{
    push(10);
    push(20);
    push(30);
    printf("Stack elements are:\n");
    printList();
    pop();
    printf("Stack after popped:\n");
    printList();
    pop();
    printf("Stack after popped:\n");
    printList();

    enqueue(40);
    enqueue(50);
    enqueue(60);
    printf("Queue elements are:\n");
    printList1();
    dequeue();
    printf("Queue after dequeued:\n");
    printList1();
    dequeue();
    printf("Queue after dequeued:\n");
    printList1();

    return 0;
}
