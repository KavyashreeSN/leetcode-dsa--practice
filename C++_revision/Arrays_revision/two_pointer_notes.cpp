/* Concept Overview:
Two pointers are used when the array is sorted and you need to find relationships between pairs or subarrays — instead of using nested loops (O(n²)), you can solve it in O(n).

Key Idea:

1)Keep two pointers — one at start (left), one at end (right).
2)Move pointers based on the condition.

Example Problem:
--Find if there exists a pair whose sum = target.

Approach:
1)Sort the array (if not sorted).

2)Initialize left = 0, right = n - 1.

3)While left < right:

--If sum = target → found.

--If sum < target → move left forward.

--If sum > target → move right backward.*/

//Code (two-pointer sum):
#include <bits/stdc++.h>
using namespace std;

// Problem: Find if there exists a pair with given sum using two pointers
int main() {
    vector<int> arr = {2, 7, 11, 15, 20, 25};
    int target = 22;
    int left = 0, right = arr.size() - 1;
    bool found = false;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            cout << "Pair found: (" << arr[left] << ", " << arr[right] << ")\n";
            found = true;
            break;
        } else if (sum < target) left++;
        else right--;
    }

    if (!found) cout << "No pair found.\n";
}

/* Output:
Pair found: (7, 15)*/