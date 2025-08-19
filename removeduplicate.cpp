#include <bits/stdc++.h>
using namespace std;
//problem 26
class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0; 

        int i = 0;
        for (int j = 1; j < n; j++) {
            if (arr[j] != arr[i]) {
                i++;
                arr[i] = arr[j];
            }
        }
        return i + 1;  
    }
};

int main() {
    Solution s;

    vector<int> arr = {1,1,2,2,3,3,4};
    int newLength = s.removeDuplicates(arr);

    cout << "New length: " << newLength << endl;
    cout << "Modified array: ";
    for (int i = 0; i < newLength; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
