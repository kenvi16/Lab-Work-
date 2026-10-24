
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Helper function to dynamically allocate a new node
struct Node* createNode(int value) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insertion at the beginning (Head)
void insertAtBeginning(struct Node** headRef, int value) {
    struct Node* newNode = createNode(value);

    newNode->next = *headRef;
    *headRef = newNode;

    printf("Inserted %d at the beginning.\n", value);
}

// Insertion at the end (Tail)
void insertAtEnd(struct Node** headRef, int value) {
    struct Node* newNode = createNode(value);

    if (*headRef == NULL) {
        *headRef = newNode;
        printf("Inserted %d at the end (list was empty).\n", value);
        return;
    }

    struct Node* temp = *headRef;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    printf("Inserted %d at the end.\n", value);
}

// Insertion at a specified position (1-indexed)
void insertAtPosition(struct Node** headRef,
                      int value, int position) {
    if (position < 1) {
        printf("Invalid position! Position is out of bounds.\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(headRef, value);
        return;
    }

    struct Node* temp = *headRef;

    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Invalid position! The list is shorter than expected.\n");
            return;
        }

        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position! Position is out of bounds.\n");
        return;
    }

    struct Node* newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Inserted %d at position %d.\n", value, position);
}

// Function to print the entire linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is currently empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Memory cleanup routine
void freeList(struct Node* head) {
    struct Node* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function demonstrating functionality
int main(void) {
    struct Node* head = NULL;

    // Insert at beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    displayList(head);

    // Insert at end
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    displayList(head);

    // Insert at specified position
    insertAtPosition(&head, 15, 2);
    displayList(head);

    insertAtPosition(&head, 5, 1);
    displayList(head);

    // Attempt an out-of-bounds position
    insertAtPosition(&head, 100, 10);

    freeList(head);
    return 0;
}
