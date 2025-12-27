#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    if (rear == NULL)
        front = rear = temp;
    else {
        rear->next = temp;
        rear = temp;
    }
    printf("Inserted %d\n", x);
}

void dequeue() {
    if (front == NULL)
        printf("Queue Empty\n");
    else {
        struct node *t = front;
        printf("Deleted %d\n", front->data);
        front = front->next;
        free(t);
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    dequeue();
    return 0;
}
