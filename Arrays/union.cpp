#include<bits/stdc++.h>
using namespace std;
 class solution{
    public:
    vector<int> unionn(vector<int>&nums1, vector<int>&nums2){
        set<int>s;
        for(int x :nums1){
            s.insert(x);
        
        }
        for (int x:nums2){
            s.insert(x);
        }
        vector<int>result;
        for(auto it:s){
            result.push_back(it);
        }
        return result;

    }
 };
 int main(){
    solution sol;
    vector<int> nums1 = {1, 2, 4, 5, 6};
    vector<int> nums2 = {2, 3, 5, 7};

    vector<int> ans = sol.unionn(nums1, nums2);

    cout << "Union of arrays: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
 }