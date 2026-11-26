
#include <bits/stdc++.h>
using namespace std;

bool canAliceWin(int n) {
    int stones = 10;
    bool alice = true;

    while (n >= stones) {
        n -= stones;
        alice = !alice;
        stones--;
    }

    return !alice;
}

int main() {
    int n;
    cin >> n;

    if (canAliceWin(n))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
