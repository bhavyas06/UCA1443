#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "LinkedList.h"

struct Node {
    int data;
    struct Node* next;
};
typedef struct Node Node;
Node *head = NULL;
Node *last = NULL;

void insert(int val) {
    if(head == NULL) {
        head = (Node*)malloc(sizeof(Node));
        head->data = val;
        head->next = NULL;
        last = head;
        return;
    }
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->next = NULL;
    last->next = temp;
    last = temp;
}

int rem(int key) {
    Node *p = head;
    Node *q = NULL;
    bool flag = false;
    while(p) {
        if(p->data == key) {
            flag = true;
            break;
        }
        q = p;
        p = p->next;
    }
    if(flag == false)
        return -1;

    if(p == head) {
        head = head->next;
        p->next = NULL;
        free(p);
        return key;
    }
    q->next = p->next;
    p->next = NULL;
    free(p);
    return key;
}

int length() {
    int count = 0;
    Node *p = head;
    while(p) {
        count++;
        p = p->next;
    }
    return count;
}

bool search(int key) {
    Node *p = head;
    bool flag = false;
    while(p) {
        if(p->data == key) {
            flag = true;
            break;
        }
    }
    return flag;
}

void traversal() {
    Node* p = head;
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    free(p);
}

int testList() {
    insert(10);
    insert(20);
    insert(30);
    traversal();

    // assert(rem(20) == 20);
    // assert(rem(10) == 10);
    // traversal();
}

int main() {
    testList();

    return 0;
}