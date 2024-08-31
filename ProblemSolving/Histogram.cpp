#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        // to check if stack is empty
        int max_area = 0;
        
        /*
            st: -1 1 2
            max_area = 2
        */
        for(int i=0; i<heights.size(); i++) {
            while(st.top()!=-1 && heights[i] <= heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = i - st.top() -1;
                max_area = max(max_area, height*width);
            }
            st.push(i);
        }

        while(st.top() != -1) {
            int height = heights[st.top()];
            st.pop();
            int width = heights.size() - st.top() -1;
            max_area = max(max_area, height*width);
        }
        return max_area;
    }
};

int main() {
    Solution obj;
    vector<int> heights = {2,1,5,6,2,3};
    int ans = obj.largestRectangleArea(heights);
    cout<< ans<< endl;

    return 0;
}