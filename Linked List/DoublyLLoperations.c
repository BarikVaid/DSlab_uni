#include <stdio.h>
#include <stdlib.h>

// --- Node Structure for Doubly Linked List ---
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// --- Helper function to create a new node ---
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// --- Helper function to print the list ---
void printList(struct Node* head) {
    struct Node* current = head;
    if (head == NULL) {
        printf("List is EMPTY.\n");
        return;
    }
    printf("DLL: NULL <-> ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 1. Insertion at the beginning
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    return newNode; 
}

// 2. Insertion at the end
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
    return head;
}

// 3. Insertion at any position (0-based index)
struct Node* insertAtPosition(struct Node* head, int value, int position) {
    if (position == 0) {
        return insertAtBeginning(head, value);
    }

    struct Node* newNode = createNode(value);
    struct Node* current = head;
    int count = 0;

    // Find the node *at* the position (current)
    while (current != NULL && count < position) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        // Handle insert at end case (if position == count)
        if (count == position) {
            // Find the last node and link
            struct Node* last = head;
            while(last->next != NULL) { last = last->next; }
            last->next = newNode;
            newNode->prev = last;
            return head;
        }
        printf("Error: Invalid position for insertion: %d\n", position);
        free(newNode);
        return head;
    }

    // Link the new node
    newNode->prev = current->prev;
    newNode->next = current;

    // Update neighbors' links
    current->prev->next = newNode;
    current->prev = newNode;

    return head;
}

// 4. Deletion at the beginning
struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) {
        printf("Error: List is empty, nothing to delete.\n");
        return NULL;
    }

    struct Node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

// 5. Deletion at the end
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("Error: List is empty, nothing to delete.\n");
        return NULL;
    }
    
    // If only one node
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* current = head;
    // Traverse to the last node
    while (current->next != NULL) {
        current = current->next;
    }

    // The second-to-last node's 'next' pointer must become NULL
    current->prev->next = NULL;
    free(current);
    return head;
}

// 6. Deletion at any position (0-based index)
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("Error: List is empty, cannot delete.\n");
        return NULL;
    }
    if (position == 0) {
        return deleteAtBeginning(head);
    }

    struct Node* current = head;
    int count = 0;

    // Find the node *at* the desired position
    while (current != NULL && count < position) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Error: Invalid position for deletion: %d\n", position);
        return head;
    }
    
    // Update the 'next' pointer of the previous node
    current->prev->next = current->next;

    // If the node being deleted is NOT the last node, update the 'prev' pointer of the next node
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
    return head;
}


int main() {
    struct Node* head = NULL;
    int choice, value, position;

    printf("--- Doubly Linked List Interactive Program ---\n");
    
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
