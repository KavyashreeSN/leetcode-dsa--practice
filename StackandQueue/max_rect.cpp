/*84.Maximal Rectangle

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
TC -->O(N*(M+N))
SC -->O(N)*/


#include <bits/stdc++.h>
using namespace std;

// Class containing the solution functions
class Solution {
public:

    // Function to calculate largest rectangle area in a histogram
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix[0].size();
        vector<int> height(m, 0);
        int maxArea = 0;

        
        for (auto& row : matrix) {

            
            for (int i = 0; i < m; i++) {
                if (row[i] == '1') height[i]++;
                else height[i] = 0;
            }

           
            maxArea = max(maxArea, largestRectangleArea(height));
        }

        return maxArea;
    }
};


int main() {

    
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    Solution sol;

  
    cout << sol.maximalRectangle(matrix) << endl;

    return 0;
}
