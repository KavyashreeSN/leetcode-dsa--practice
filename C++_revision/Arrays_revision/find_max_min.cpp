/*Goal: Learn traversal logic and comparison.

Key points:

Initialize max and min with first element

Traverse array and update*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int maxi = arr[0], mini = arr[0];

    for (int i = 1; i < n; i++) {
        maxi = max(maxi, arr[i]);
        mini = min(mini, arr[i]);
    }

    cout << "Maximum: " << maxi << "\nMinimum: " << mini << endl;
    return 0;
}
