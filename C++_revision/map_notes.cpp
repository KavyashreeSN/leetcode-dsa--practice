/*Notes for vector in C++

Dynamic array (can change size at runtime).

Stores elements in contiguous memory.

Provides random access in O(1).

Insert/delete at end → O(1) (amortized).

Insert/delete at middle/front → O(n).

Common functions: push_back, pop_back, size, capacity, begin, end.

*/

//Code example:
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3};

    v.push_back(4); // Add element at end
    v.push_back(5);

    cout << "Vector elements: ";
    for (int x : v) cout << x << " ";

    cout << "\nSize: " << v.size();
    cout << "\nFirst element: " << v.front();
    cout << "\nLast element: " << v.back();

    return 0;
}
