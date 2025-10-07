/*Goal: Understand how arrays work — declaration, initialization, traversal.

Key points:

Static array declaration

Input/output

Traversal using loops*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    cout << "Array elements are: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
