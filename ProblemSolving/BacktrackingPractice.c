#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int max(int a, int b) {
    if(a>b)
        return a;
    return b;
}

int min(int a, int b) {
    if(a<b)
        return a;
    return b;
}

bool isValid(int row, int col, int m, int n) {
    if(row>m || col>n)
        return false;
    return true;
}

int minPoints(int i, int j, int grid[3][4], int m, int n) {
    if(i==m && j==n)
        return grid[i][j];
    bool choice1 = isValid(i+1, j, m, n);
    bool choice2 = isValid(i, j+1, m, n);

    if(choice1 && choice2) {
        int ch1 = minPoints(i+1, j, grid, m, n);
        int ch2 = minPoints(i, j+1, grid, m, n);
        return grid[i][j] + min(ch1, ch2);
    }

    if(choice1 && !choice2)
        return grid[i][j] + minPoints(i+1, j, grid, m, n);
    return grid[i][j] + minPoints(i, j+1, grid, m, n);
}

int maxPoints(int i, int j, int grid[3][4], int m, int n) {
    if(i==m && j==n)
        return grid[i][j];
    bool choice1 = isValid(i+1, j, m, n);
    bool choice2 = isValid(i, j+1, m, n);

    if(choice1 && choice2) {
        int ch1 = maxPoints(i+1, j, grid, m, n);
        int ch2 = maxPoints(i, j+1, grid, m, n);
        return grid[i][j] + max(ch1, ch2);
    }

    if(choice1 && !choice2)
        return grid[i][j] + maxPoints(i+1, j, grid, m, n);
    return grid[i][j] + maxPoints(i, j+1, grid, m, n);
}

void printPath(int i, int j, int m, int n) {
    if(i>m || j>m) 
        return;
    if(i==m && j==n) {
        printf("%d,%d\n", i, j);
        return;
    }
    printf("%d,%d ", i,j);
    printPath(i+1, j, m, n);
    printPath(i, j+1, m, n);
}

int main() {
    int grid[3][4] = { {1,1,1,1},
                       {1,1,1,1},
                       {0,0,0,0}};
    int m = sizeof(grid)/sizeof(grid[0][0]);
    int n = sizeof(grid[0])/sizeof(grid[0][0]);
    printPath(0,0,m-1, n-1);
    printf("\n");
    
    return 0;
}