#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {1,2,2,3,1,1,4}; 
    unordered_map<int,int> freq;

    
    for (int x : nums) {
        freq[x]++;
    }

    int maxFreq = 0;
    int element = -1;
    for (auto it : freq) {
        if (it.second > maxFreq) {
            maxFreq = it.second;
            element = it.first;
        }
    }

    cout << "Element with max frequency = " << element 
         << " (frequency = " << maxFreq << ")" << endl;

    return 0;
}

