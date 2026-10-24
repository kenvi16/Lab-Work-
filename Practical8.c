
#include <stdio.h>
#include <stdlib.h>

// Linked List Node
struct node {
    int info;
    struct node *prev, *next;
};

struct node* start = NULL;

// Function to traverse the linked list
void traverse(void) {
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }

    struct node* temp = start;

    while (temp != NULL) {
        printf("Data = %d\n", temp->info);
        temp = temp->next;
    }
}

// Function to create a new node
struct node* createNode(int data) {
    struct node* temp =
        (struct node*)malloc(sizeof(struct node));

    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    temp->info = data;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

// Function to insert at the front
void insertAtFront(void) {
    int data;

    printf("\nEnter number to be inserted: ");
    if (scanf("%d", &data) != 1)
        return;

    struct node* temp = createNode(data);

    temp->next = start;

    if (start != NULL)
        start->prev = temp;

    start = temp;
}

// Function to insert at the end
void insertAtEnd(void) {
    int data;

    printf("\nEnter number to be inserted: ");
    if (scanf("%d", &data) != 1)
        return;

    struct node* temp = createNode(data);

    if (start == NULL) {
        start = temp;
        return;
    }

    struct node* trav = start;

    while (trav->next != NULL)
        trav = trav->next;

    trav->next = temp;
    temp->prev = trav;
}

// Function to insert at a specified position
void insertAtPosition(void) {
    int data, pos, i = 1;

    printf("\nEnter position: ");
    if (scanf("%d", &pos) != 1)
        return;

    if (pos < 1) {
        printf("\nInvalid position\n");
        return;
    }

    if (pos == 1) {
        insertAtFront();
        return;
    }

    struct node* temp = start;

    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("\nPosition is out of bounds\n");
        return;
    }

    printf("\nEnter number to be inserted: ");
    if (scanf("%d", &data) != 1)
        return;

    struct node* newnode = createNode(data);

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;
}

// Function to delete from the front
void deleteFirst(void) {
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }

    struct node* temp = start;
    start = start->next;

    if (start != NULL)
        start->prev = NULL;

    free(temp);
}

// Function to delete from the end
void deleteEnd(void) {
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }

    struct node* temp = start;

    if (start->next == NULL) {
        start = NULL;
        free(temp);
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}

// Function to delete from a specified position
void deletePosition(void) {
    int pos, i = 1;

    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }

    printf("\nEnter position: ");
    if (scanf("%d", &pos) != 1)
        return;

    if (pos < 1) {
        printf("\nInvalid position\n");
        return;
    }

    struct node* temp = start;

    while (i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("\nPosition is out of bounds\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        start = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

// Driver Code
int main(void) {
    int choice;

    while (1) {
        printf("\n1 To see list\n");
        printf("2 For insertion at starting\n");
        printf("3 For insertion at end\n");
        printf("4 For insertion at any position\n");
        printf("5 For deletion of first element\n");
        printf("6 For deletion of last element\n");
        printf("7 For deletion of element at any position\n");
        printf("8 To exit\n");
        printf("\nEnter Choice: ");

        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
            case 1:
                traverse();
                break;
            case 2:
                insertAtFront();
                break;
            case 3:
                insertAtEnd();
                break;
            case 4:
                insertAtPosition();
                break;
            case 5:
                deleteFirst();
                break;
            case 6:
                deleteEnd();
                break;
            case 7:
                deletePosition();
                break;
            case 8: {
                struct node* temp;

                while (start != NULL) {
                    temp = start;
                    start = start->next;
                    free(temp);
                }

                return 0;
            }
            default:
                printf("Incorrect Choice. Try Again\n");
        }
    }

    return 0;
}
