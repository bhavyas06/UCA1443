#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <assert.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void selectionSort(int arr[], int n) {
    for(int i=0; i<n; i++) {
        int min1 = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[min1])
                min1 = j;
        }
        swap(arr, i, min1);
    }
}

long long time_elapsed(int n) {
    int *arr = (int *)malloc(n * sizeof(int));
    srand(time(NULL));

    for(int i=0; i<n; i++)
        arr[i] = rand();

    struct timeval before;
    gettimeofday(&before, NULL);
    long long before_millis = before.tv_sec*1000LL + before.tv_usec/1000;

    selectionSort(arr, n);

    struct timeval after;
    gettimeofday(&after, NULL);
    long long after_millis = after.tv_sec*1000LL + after.tv_usec/1000;

    return after_millis - before_millis;
}

void test_sample_input() {
    int input[] = {3,1,7,9,5};
    int expected_ouput[] = {1,3,5,7,9};
    int n = sizeof(input)/sizeof(input[0]);

    selectionSort(input, n);

    for(int i=0; i<n; i++) 
        assert(input[i] == expected_ouput[i]);
}

int main() {
    test_sample_input();

    long long t1 = time_elapsed(32000);
    long long t2 = time_elapsed(64000);
    // TC(2N)/ TC(N) ~~ 4.

    printf("%lf ", t2*1.0 / t1);

    return 0;
}