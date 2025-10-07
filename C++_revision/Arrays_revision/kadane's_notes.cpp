/*-->Concept Overview:
One of the most famous interview questions!
Find the maximum sum of any contiguous subarray in O(n) time.

-->Key Idea:
At each index, decide:
Continue the current subarray OR start a new one.

-->Example Problem:
Given arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4], find max subarray sum.*/

//Example Code:

#include <bits/stdc++.h>
using namespace std;

// Problem: Kadane's Algorithm (Maximum Subarray Sum)
int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int currentSum = arr[0], maxSum = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
    }

    cout << "Maximum Subarray Sum = " << maxSum << endl;
}

//Output :
//Maximum Subarray Sum = 6
