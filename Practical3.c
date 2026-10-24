
#include <stdio.h>
#define SIZE 5

int a[SIZE], top = -1, i, ch;

void push();
void pop();
void peep();
void change();
void display();

int main()
{
    while (1)
    {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peep\n");
        printf("4. Change\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1: push();
                    break;
                
            case 2: pop();
                    break;
        
            case 3: peep();
                    break;
                
            case 4: change();
                    break;
  
           case 5: display();
                   break;  
            
          case 6: return 0;
                  
          default: printf("Invalid choice!\n");
        }
    }

    return 0;
}

void push()
{
    int data;

    printf("Enter the element: ");
    scanf("%d", &data);

    if (top >= SIZE - 1)
    {
        printf("Stack overflow!\n");
    }
    else
    {
        top = top + 1;
        a[top] = data;
        printf("Element pushed successfully.\n");
    }
}

void pop()
{
    int del;

    if (top == -1)
    {
        printf("Stack underflow!\n");
    }
    else
    {
        del = a[top];
        top = top - 1;
        printf("Deleted element = %d\n", del);
    }
}

void peep()
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("TOP = %d\n", top);
        printf("TOP Element = %d\n", a[top]);
    }
}

void change()
{
    int pos, val;

    printf("Enter position from top: ");
    scanf("%d", &pos);

    printf("Enter new value: ");
    scanf("%d", &val);

    if (pos <= 0 || pos > top + 1)
    {
        printf("Invalid position!\n");
    }
    else
    {
        a[top - pos + 1] = val;
        printf("Value updated.\n");
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack elements:\n");

        for (i = top; i >= 0; i--)
        {
            printf("%d\n", a[i]);
        }
    }
}
