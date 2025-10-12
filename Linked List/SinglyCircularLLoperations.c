#include <stdio.h>
#include <stdlib.h>

// Node Structure
struct Node {
    int data;
    struct Node* next;
};

// Helper: Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) { exit(1); }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Helper: Print the list
void printList(struct Node* head) {
    if (head == NULL) { printf("List is EMPTY.\n"); return; }

    struct Node* current = head;
    printf("SCLL: ");
    // Loop until we return to head
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(Head %d)\n", head->data);
}

// 1. Insertion at the beginning
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        newNode->next = newNode; 
        return newNode;
    }

    struct Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

    newNode->next = head; 
    last->next = newNode; 
    return newNode;       // New node is the new head
}

// 2. Insertion at the end
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    struct Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

    last->next = newNode; // Last points to new node
    newNode->next = head; // New node points to head
    return head;
}

// 3. Insertion at any position (0-based)
struct Node* insertAtPosition(struct Node* head, int value, int position) {
    if (position == 0) { return insertAtBeginning(head, value); }
    if (head == NULL) { 
        printf("Error: List is empty, position > 0 is invalid.\n"); 
        return NULL;
    }

    struct Node* newNode = createNode(value);
    struct Node* current = head;
    int count = 0;

    // Traverse to the node *before* the desired position
    while (current->next != head && count < position - 1) {
        current = current->next;
        count++;
    }

    // Check if we are at the end and the position is out of bounds
    if (count < position - 1) {
        printf("Error: Invalid position for insertion: %d\n", position);
        free(newNode);
        return head;
    }
    
    // Link the new node
    newNode->next = current->next;
    current->next = newNode;

    return head;
}

// 4. Deletion at the beginning
struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) { printf("Error: List is empty.\n"); return NULL; }

    // Case 1: Only one node
    if (head->next == head) {
        free(head);
        return NULL;
    }

    // Case 2: Multiple nodes
    struct Node* temp = head;
    struct Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

    head = head->next;    
    last->next = head;    
    free(temp);           
    return head;
}

// 5. Deletion at the end
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) { return NULL; }

    // Case 1: Only one node
    if (head->next == head) {
        free(head);
        return NULL;
    }

    struct Node* current = head;
    struct Node* previous = NULL;

    // Traverse to the second-to-last node (previous)
    while (current->next != head) {
        previous = current;
        current = current->next;
    }

    previous->next = head; 
    free(current);         
    return head;
}

// 6. Deletion at any position (0-based)
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) { return NULL; }
    if (position == 0) { return deleteAtBeginning(head); }

    struct Node* current = head;
    struct Node* previous = NULL;
    int count = 0;

    // Find the node *at* the desired position (current)
    do {
        previous = current;
        current = current->next;
        count++;
    } while (current != head && count < position);

    if (current == head) {
        printf("Error: Invalid position for deletion: %d\n", position);
        return head;
    }

    previous->next = current->next; 
    free(current);                 
    return head;
}

int main() {
    struct Node* head = NULL;
    int choice, value, position;
    
    printf("--- Singly Circular Linked List Interactive Program ---\n");

    do {
        printf("\n====================================\n");
        printf("CURRENT LIST: "); printList(head);
        printf("------------------------------------\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Exit\n");
        printf("Enter your choice (1-7): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;
            case 3:
                printf("Enter position (0-based index): ");
                scanf("%d", &position);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                head = insertAtPosition(head, value, position);
                break;
            case 4:
                head = deleteAtBeginning(head);
                break;
            case 5:
                head = deleteAtEnd(head);
                break;
            case 6:
                printf("Enter position (0-based index) to delete: ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                break;
            case 7:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
