#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <assert.h>
#include "Stack.h"

int *arr = NULL;
int N = 0;
int max_size = 1;

void resize_array(int newsize) {
    int *newArray = (int *)malloc(newsize*sizeof(int));
    for(int i=0; i<N; i++)
        newArray[i] = arr[i];
    int *temp = arr;
    arr= newArray;
    free(temp);
}

void push(int data) {
    if(N==0)
        resize_array(max_size);
    else if(max_size == N) {
        resize_array(max_size*2);
        max_size *= 2;
    }
    arr[N++] = data;
}

int pop() {
    int data = -1;
    if(isEmpty())
        return data;
    data = arr[N];
    N--;
    if(N == max_size/4) {
        resize_array(max_size/2);
        max_size = max_size/2;
    }
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

    return 0;
}

int main() {
    testStack();

    return 0;
}