/*Set

Stores unique elements in sorted order.

Operations (insert, find, erase) → O(log n).*/

//Code example:
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s = {5, 1, 3, 5};
    s.insert(2);

    cout << "Set elements: ";
    for (int x : s) cout << x << " ";
    cout << "\n";

    if (s.find(3) != s.end()) cout << "3 is present\n";
}
