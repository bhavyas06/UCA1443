#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Queue.h"

int N = 0;
int max_size = 1;
int *arr = NULL;
int f=0, l=0;

void resize_array(int newsize) {
    int *newArray = (int *)malloc(newsize*sizeof(int));
    for(int i=0; i<N; i++)
        newArray[i] = arr[i];
    int *temp = arr;
    arr= newArray;
    free(temp);
}

void enqueue(int val) {
    if(N==0)
        resize_array(N);
    else if(max_size == N) {
        resize_array(max_size*2);
        max_size *= 2;
    }
    arr[l] = val;
    l++;
    N++;
}

int dequeue() {
    if(isEmpty())
        return -1;
    int x = arr[f];
    f++;
    N--;
    if(N == max_size/4) {
        resize_array(max_size/2);
        max_size = max_size/2;
    }
    return x;
}

bool isEmpty() {
    if(f == l)
        return true;
    return false;
}

void traversal() {
    for(int i=f; i<l; i++)
        printf("%d ", arr[i]);
    printf("\n");
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
}

int main() {
    testQueue();

    return 0;
}