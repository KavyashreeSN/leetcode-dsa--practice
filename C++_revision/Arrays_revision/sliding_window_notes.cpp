/*-->Concept Overview:
Used when you need to find something (sum, max, count, etc.) in contiguous subarrays of fixed or variable length.

-->Key Idea :
Keep a window (range of elements) and slide it across the array — add the new element and remove the old one efficiently.

-->Example Problem:
Find the maximum sum of a subarray of size k.

-->Approach:

1)Calculate sum of first k elements.
2)Slide window by 1 step each time.
3)Subtract element going out, add element coming in.
4)Track the maximum sum.*/ 

// Example Code :

#include <bits/stdc++.h>
using namespace std;

// Problem: Find maximum sum subarray of size k (Sliding Window)
int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;
    int windowSum = 0, maxSum = INT_MIN;

    // First window
    for (int i = 0; i < k; i++) windowSum += arr[i];
    maxSum = windowSum;

    // Slide the window
    for (int i = k; i < arr.size(); i++) {
        windowSum += arr[i] - arr[i - k];
        maxSum = max(maxSum, windowSum);
    }

    cout << "Maximum sum of subarray of size " << k << " = " << maxSum << endl;
}

/*Output:
Maximum sum of subarray of size 3 = 9*/
