/*Multiset

Like set but allows duplicates.*/

//Code example:
#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<int> ms = {1, 1, 2, 3};
    ms.insert(2);

    cout << "Multiset elements: ";
    for (int x : ms) cout << x << " ";
    cout << "\n";
}

