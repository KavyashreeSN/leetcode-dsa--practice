

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int func(int mid, int n, int m) {
        long long ans = 1;
        for (int i = 1; i <= n; i++) {
            ans *= mid;
            if (ans > m) return 2;  
        }
        if (ans == m) return 1;      
        return 0;                    
    }

    int NthRoot(int N, int M) {
        int low = 1, high = M;
        while (low <= high) {
            int mid = (low + high) / 2;
            int midN = func(mid, N, M);

            if (midN == 1) return mid;    
            else if (midN == 0) low = mid + 1; 
            else high = mid - 1;               
        }
        return -1; // no integer Nth root exists
    }
};

int main() {
    Solution sol;

    int N, M;
    cout << "Enter N (root power): ";
    cin >> N;
    cout << "Enter M (number): ";
    cin >> M;

    int result = sol.NthRoot(N, M);

    if (result == -1)
        cout << "No integer " << N << "th root exists for " << M << endl;
    else
        cout << "The " << N << "th root of " << M << " is: " << result << endl;

    return 0;
}
