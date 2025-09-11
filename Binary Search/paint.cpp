/*Painter's Partition
You are given A painters and an array C of N integers where C[i] denotes the length of the ith board. Each painter takes B units of time to paint 1 unit of board. You must assign boards to painters such that:

-->Each painter paints only contiguous segments of boards.
-->No board can be split between painters.
-->The goal is to minimize the time to paint all boards.

TC -->O(n * log(sum(C)))
SC -->O(1)*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int> &nums, int maxSum) {
        int partitions = 1;
        int subarraySum = 0;
        for (int num : nums) {
            if (subarraySum + num <= maxSum) {
                subarraySum += num;
            } else {
                partitions++;
                subarraySum = num;
            }
        }
        return partitions;
    }

    int paint(int A, int B, vector<int>& C) {
        int low = *max_element(C.begin(), C.end());
        int high = accumulate(C.begin(), C.end(), 0);

        while (low <= high) {
            int mid = (low + high) / 2;
            int partitions = countPartitions(C, mid);

            if (partitions > A) {
                low = mid + 1;   
            } else {
                high = mid - 1;
            }
        }
        return (int)(((long long)low * B) % 10000003);
    }
};

int main() {
    Solution sol;

    // Example input
    int A = 2;  // number of painters
    int B = 5;  // time per unit length
    vector<int> C = {1, 10};  // board lengths

    int result = sol.paint(A, B, C);
    cout << "Minimum time required = " << result << endl;

    return 0;
}
