/*Notes for map in C++

Stores data in key-value pairs.

Keys are unique and stored in sorted order.

Implemented using Red-Black Tree internally.

Operations (insert, find, erase) → O(log n).

Use unordered_map for faster average O(1) operations (not sorted).

*/
//Code example:
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> students;

    students[1] = "Alia";
    students[2] = "John";
    students[3] = "Charlie";

    cout << "Student list:\n";
    for (auto &p : students) {
        cout << p.first << " -> " << p.second << "\n";
    }
    // Access and search
    cout << "Student with roll 2: " << students[2] << "\n";

    if (students.find(3) != students.end()) {
        cout << "Found roll number 3\n";
    }
}
