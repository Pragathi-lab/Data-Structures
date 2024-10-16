#include <stdio.h>
#define size 100
int front=-1,rear=-1;
int queue[size];

void enqueue(int x)
{
    if(rear==size-1){
        printf("Queue overflow\n");
    }
    else 
    {
        if(front==-1)
        {
            front=0;
        }
        rear++;
        queue[rear]=x;
        printf("Inserted %d\n",x);
    }
}
    
void dequeue()
{
    if(front==-1||front>rear)
    {
        printf("Queue underflow\n");
    }
    
    else{
        printf("Deleted %d\n",queue[front]);
        front++;
        if(front>rear)
        {
            front=-1;
            rear=-1;
        }
    }
}

void display(){
    if(front==-1)
    {
        printf("Queue is empty\n");
    }
    else{
        printf("Queue elements are:\n");
        for(int i=front;i<=rear;i++)
        {
            printf("%d\n",queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    enqueue(45);
    enqueue(40);
    enqueue(30);
    display();
    dequeue();
    enqueue(29);
    display();
    dequeue();
    display();
}