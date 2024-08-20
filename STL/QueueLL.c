#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Queue.h"

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node Node;
Node *head = NULL;
Node *last = NULL;

void enqueue(int val) {
    if(head == NULL) {
        head = (Node *)malloc(sizeof(Node));
        head->data = val;
        head->next = NULL;
        last = head;
        return;
    }
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = val;
    temp->next = NULL;
    last->next = temp;
    last = temp;
}

int dequeue() {
    if(isEmpty())
        return -1;
    Node *p = head;
    head = head->next;
    p->next = NULL;
    int x = p->data;
    free(p);
    return x;
}

bool isEmpty() {
    if(head == NULL)
        return true;
    return false;
}

int size() {
    int count=0;
    Node *p = head;
    while(p) {
        count++;
        p = p->next;
    }
    free(p);
    return count;
}

void traversal() {
    Node *p = head;
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    free(p);
}

int testQueue() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    traversal();    
    assert(dequeue() == 10);
    traversal();
    assert(isEmpty() == false);
}

int main() {
    testQueue();

    return 0;
}