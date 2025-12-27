#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
    printf("Pushed %d\n", x);
}

void pop() {
    if (top == NULL)
        printf("Stack Empty\n");
    else {
        struct node *t = top;
        printf("Popped %d\n", top->data);
        top = top->next;
        free(t);
    }
}

int main() {
    push(10);
    push(20);
    pop();
    return 0;
}
