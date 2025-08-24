/*Given an array of integers nums, return the second-largest element in the array.
 If the second-largest element does not exist, return -1*/
#include <bits/stdc++.h>
using namespace std;

int secondLargest(vector <int> &a,int n){
    int largest = a[0];
    int slargest = -1;
    for (int i = 1; i<n;i++){
        if (a[i]>largest){
            slargest = largest;
            slargest = a[i];

        }
        else if (a[i]<largest && a[i]>slargest){
            slargest = a[i];
        }
        return slargest;
    }
}
int main() {
    vector<int> arr = {3, 5, 1, 8, 2};
    cout << secondLargest(arr, arr.size());
    
      
}