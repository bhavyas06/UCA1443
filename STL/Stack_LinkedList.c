#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include "Stack.h"

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;
Node* head = NULL;
int N = 0;

void push(int data) {
    Node* oldHead = head;
    head = (Node *)malloc(sizeof(Node));
    head->data = data;
    head->next = oldHead;
    N++;
}

int pop() {
    if(N==0)
        return INT_MIN;
    int data = head->data;
    Node *temp = head;
    head = head->next;
    N--;
    free(temp);
    return data;
}

int size() {
    return N;
}

bool isEmpty() {
    if(N==0)
        return true;
    return false;
}

int testStack() {
    push(3);
    push(10);
    push(19);

    assert(pop() == 19);
    assert(isEmpty() == false);
}

int main() {
    testStack();

    return 0;
}