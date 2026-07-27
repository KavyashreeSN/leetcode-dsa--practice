#include <iostream>
#include <vector>
using namespace std;

int maxProduct(vector<int>& nums) {
    int first = 0, second = 0;

    for (int x : nums) {
        if (x > first) {
            second = first;
            first = x;
        } 
        else if (x > second) {
            second = x;
        }
    }

    return (first - 1) * (second - 1);
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Maximum Product = " << maxProduct(nums);

    return 0;
}