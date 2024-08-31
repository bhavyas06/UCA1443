#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(int row, int col, int n, vector<string> &path) {
        int r = row, c = col;
        
        while(row>=0 && col>=0) {
            if(path[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        row = r;
        col = c;

        while(col >=0) {
            if(path[row][col] == 'Q')
                return false;
            col--;
        }
        col = c;

        while(row<n && col>=0) {
            if(path[row][col] == 'Q')
                return false;
            row++;
            col--;
        }
        return true;
    }

    void solve(int col, int n, vector<vector<string>> &ans, vector<string> &path) {
        if(col == n) {
            ans.push_back(path);
            return;
        }

        for(int row=0; row<n; row++) {
            if(check(row, col, n, path)) {
                path[row][col] = 'Q';
                solve(col+1, n, ans, path);
                path[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> path(n);
        string s(n, '.');
        for(int i=0; i<n; i++)
            path[i] = s;
        solve(0, n, ans, path);
        return ans;
    }
};

int main() {
    vector<vector<string>> ans;
    ans = solveNQueens(4);
    
    return 0;
}