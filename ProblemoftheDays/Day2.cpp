/*3754.Concatenate Non Zero Digits and Multiply by Sum 

You are given an integer n.

Form a new integer x by concatenating all the non-zero digits of n in their original order. If there are no non-zero digits, x = 0.

Let sum be the sum of digits in x.

Return an integer representing the value of x * sum.

TC -->O(N)
SC -->O(1)*/


#include <iostream>
using namespace std;

long long findValue(int n) {
    long long x = 0;
    int sum = 0;
    long long place = 1;

    if (n == 0) return 0;

    while (n > 0) {
        int d = n % 10;

        if (d != 0) {
            x += d * place;
            sum += d;
            place *= 10;
        }

        n /= 10;
    }

    return x * sum;
}

int main() {
    int n;
    cin >> n;

    cout << findValue(n);
    return 0;
}