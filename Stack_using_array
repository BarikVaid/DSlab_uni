#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;

void push(int x) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else {
        stack[++top] = x;
        printf("Pushed %d\n", x);
    }
}

void pop() {
    if (top == -1)
        printf("Stack Underflow\n");
    else
        printf("Popped %d\n", stack[top--]);
}

int main() {
    push(10);
    push(20);
    pop();
    return 0;
}
