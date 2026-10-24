
#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue();
void dequeue();
void frontElement();
void rearElement();
void display();

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front\n");
        printf("4. Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
            return 0;

        switch (choice)
        {
            case 1: enqueue();
                    break;
          
            case 2: dequeue();
                    break;
          
           case 3: frontElement();
                   break;
                
            case 4: rearElement();
                    break;
            
            case 5: display();
                    break;

            case 6: return 0;        
               
           default: printf("Invalid choice!\n");
        }
    }

    return 0;
}

void enqueue()
{
    int data;

    if (rear == SIZE - 1)
    {
        printf("Queue overflow!\n");
    }
    else
    {
        printf("Enter the element: ");

        if (scanf("%d", &data) != 1)
            return;

        if (front == -1)
            front = 0;

        rear = rear + 1;
        queue[rear] = data;

        printf("Element inserted successfully.\n");
    }
}

void dequeue()
{
    int data;

    if (front == -1 || front > rear)
    {
        printf("Queue underflow!\n");
    }
    else
    {
        data = queue[front];
        printf("Deleted element = %d\n", data);

        front = front + 1;

        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}

void frontElement()
{
    if (front == -1)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Front element = %d\n", queue[front]);
    }
}

void rearElement()
{
    if (rear == -1)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Rear element = %d\n", queue[rear]);
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Queue elements:\n");

        for (i = front; i <= rear; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
}
