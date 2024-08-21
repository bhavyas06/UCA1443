#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char arr[64];

void init(char arr[]) {
    char start = 'A';
    int i=0;
    for(i=0; i<26; i++) {
        arr[i] = start;
        start++;
    }
    start = 'a';
    for(; i<52; i++) {
        arr[i] = start;
        start++;
    }
    
    start = '0';
    for(; i<62; i++) {
        arr[i] = start;
        start++;
    }

    arr[62] = '+';
    arr[63] = '/';
}

int power(int num, int exp) {
    if(exp == 0)
        return 1;
    return num * power(num, exp-1);
}

char* binary(int num) {
    char *bin = (char *)malloc(sizeof(char)*8);
    int j=0;
    for(int i=7; i>=0; i--) {
        int k = num >> i;
        if(k&1)
            bin[j++] = '1'-'0';
        else    
            bin[j++] = '0'-'0';
    }
    return bin;
}

char deci(char bin[]) {
    int num = 0;
    int i=0;
    // for(int i=0; i<6; i++)
    //     printf("%d ", bin[i]);
    // printf("\n");
    for(int j=5; j>=0; j--) {
        num = num + (bin[j]*power(2,i));
        i++;
    }
    // printf("%d ", num);
    // printf("\n");
    char c = arr[num];
    // printf("%c ", c);
    return c;
}

char* encoding(char s[], int n) {
    char *ans = (char *)malloc(sizeof(char)*(n*8));
    char *encode = (char *)malloc(sizeof(char)*(n*9));
    int k=0;
    for(int i=0; i<n; i++) {
        int num = s[i];
        char *res = binary(num);

        for(int j=0; j<8; j++)
            ans[k++] = res[j];
    }


    int rem = n*8 % 6;
    for(int i=0; i<rem; i++)
        ans[k++] = '0'-'0';
    rem = 0;

    // for(int j=0; j<8*3; j++)
    //         printf("%d ", ans[j]);
    // printf("\n\n");

    int l=0;
    for(int i=0; i<=n; i++) {
        char bin[6];
        for(int j=0; j<6; j++) {
            bin[j] = ans[l];
            l++;
        }
        char c = deci(bin);
        encode[rem++] = c;
    }
    
    return encode;
}


int main() {
    char s[] = {'h', 'e', 'l', 'l', 'o', 'a'};
    int n = sizeof(s)/sizeof(s[0]);

    init(arr);

    char *res = encoding(s, n);
    int size = sizeof(res)/ sizeof(res[0]);
    for(int i=0; i<size; i++)
        printf("%c", res[i]);

    return 0;
}