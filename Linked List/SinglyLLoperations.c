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
    struct Node* current = head;
    if (head == NULL) { printf("List is EMPTY.\n"); return; }
    printf("SLL: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 1. Insertion at the beginning
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    return newNode; 
}

// 2. Insertion at the end
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) { return newNode; }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// 3. Insertion at any position (0-based)
struct Node* insertAtPosition(struct Node* head, int value, int position) {
    if (position == 0) { return insertAtBeginning(head, value); }

    struct Node* newNode = createNode(value);
    struct Node* current = head;
    int count = 0;

    // Traverse to the node *before* the desired position
    while (current != NULL && count < position - 1) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Error: Invalid position for insertion: %d\n", position);
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// 4. Deletion at the beginning
struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) { printf("Error: List is empty.\n"); return NULL; }
    struct Node* temp = head; 
    head = head->next;      
    free(temp);             
    return head;
}

// 5. Deletion at the end
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL || head->next == NULL) { 
        if(head) free(head); 
        return NULL; 
    }

    struct Node* current = head;
    struct Node* previous = NULL;

    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    previous->next = NULL; 
    free(current);         
    return head;
}

// 6. Deletion at any position (0-based)
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) { printf("Error: List is empty.\n"); return NULL; }
    if (position == 0) { return deleteAtBeginning(head); }

    struct Node* current = head;
    struct Node* previous = NULL;
    int count = 0;

    while (current != NULL && count < position) {
        previous = current;
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Error: Invalid position for deletion: %d\n", position);
        return head;
    }

    previous->next = current->next; 
    free(current);                 
    return head;
}

// 7. Reverse the list
struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL) {
        next = current->next; 
        current->next = prev; 
        prev = current;       
        current = next;       
    }
    printf("List successfully reversed.\n");
    return prev; // 'prev' is the new head
}

// 8. Concatenate two lists (Appends list2 to list1)
struct Node* concatenateLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) { return head2; }

    struct Node* current = head1;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = head2;
    printf("Lists successfully concatenated.\n");
    return head1;
}

// 9. Merge two sorted lists (using recursion)
struct Node* mergeSortedLists(struct Node* head1, struct Node* head2) {
    struct Node* result = NULL; 

    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    // Pick smaller and recurse
    if (head1->data <= head2->data) {
        result = head1;
        result->next = mergeSortedLists(head1->next, head2);
    } else {
        result = head2;
        result->next = mergeSortedLists(head1, head2->next);
    }

    return result;
}


int main() {
    struct Node* head = NULL;
    struct Node* head2 = NULL; 
    int choice, value, position;
    int num_nodes, i;
    
    printf("--- Singly Linked List Interactive Program ---\n");
    
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
        printf("7. Reverse List\n");
        printf("8. Concatenate with a new list (List 2)\n");
        printf("9. Merge with a new SORTED list (List 2)\n");
        printf("10. Exit\n");
        printf("Enter your choice (1-10): ");
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
                head = reverseList(head);
                break;
            case 8: // Concatenation
                printf("\n--- CONCATENATION: Creating List 2 ---\n");
                printf("Enter number of nodes for List 2: ");
                scanf("%d", &num_nodes);
                head2 = NULL;
                for (i = 0; i < num_nodes; i++) {
                    printf("Enter value for List 2, node %d: ", i + 1);
                    scanf("%d", &value);
                    head2 = insertAtEnd(head2, value);
                }
                head = concatenateLists(head, head2);
                head2 = NULL; // List 2 is now part of List 1
                break;
            case 9: // Merge
                printf("\n--- MERGE: Creating SORTED List 2 ---\n");
                printf("NOTE: Both lists must be sorted for correct merging.\n");
                printf("Enter number of nodes for List 2: ");
                scanf("%d", &num_nodes);
                head2 = NULL;
                for (i = 0; i < num_nodes; i++) {
                    printf("Enter value for List 2, node %d (Keep it sorted!): ", i + 1);
                    scanf("%d", &value);
                    head2 = insertAtEnd(head2, value);
                }
                head = mergeSortedLists(head, head2);
                printf("Lists successfully merged and sorted.\n");
                head2 = NULL; // Nodes are now part of the merged list
                break;
            case 10:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 10);
    
    return 0;
}
