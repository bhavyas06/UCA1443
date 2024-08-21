#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <assert.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
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

    insertionSort(arr, n);

    struct timeval after;
    gettimeofday(&after, NULL);
    long long after_millis = after.tv_sec*1000LL + after.tv_usec/1000;

    return after_millis - before_millis;
}

void test_sample_input() {
    int input[] = {3,1,7,9,5};
    int expected_ouput[] = {1,3,5,7,9};
    int n = sizeof(input)/sizeof(int);

    insertionSort(input, n);

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