#include <iostream>
using namespace std;

class Solution {
    int func1(int n){
        if(n % 4 == 1) return 1;
        else if(n % 4 == 2) return n + 1;
        else if(n % 4 == 3) return 0;
        else return n;   // n % 4 == 0
    }

public:
    int findRangeXOR(int l, int r){
        return func1(l - 1) ^ func1(r);
    }
};

int main() {
    Solution obj;

    int l, r;
    cout << "Enter l and r: ";
    cin >> l >> r;

    int result = obj.findRangeXOR(l, r);
    cout << "XOR from " << l << " to " << r << " = " << result << endl;

    return 0;
}