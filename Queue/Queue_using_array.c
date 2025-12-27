#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1)
        printf("Queue Full\n");
    else {
        if (front == -1) front = 0;
        queue[++rear] = x;
        printf("Inserted %d\n", x);
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        printf("Queue Empty\n");
    else
        printf("Deleted %d\n", queue[front++]);
}

int main() {
    enqueue(10);
    enqueue(20);
    dequeue();
    return 0;
}
