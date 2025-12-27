#include <stdio.h>
#define MAX 5

int cq[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if ((rear + 1) % MAX == front)
        printf("Queue Full\n");
    else {
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        cq[rear] = x;
        printf("Inserted %d\n", x);
    }
}

void dequeue() {
    if (front == -1)
        printf("Queue Empty\n");
    else {
        printf("Deleted %d\n", cq[front]);
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    dequeue();
    return 0;
}
