/*239.Sliding Window Maximum

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

TC -->O(2N)
SC -->O(K)+O(N-K)*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;

        for (int i = 0; i < nums.size(); i++) {

            // Remove elements out of window
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Maintain decreasing order in deque
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);

            // Store result when window is valid
            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }

        return result;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = obj.maxSlidingWindow(nums, k);

    cout << "Sliding Window Maximum: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}