/*Unordered Map

Stores key-value pairs but not sorted, faster (average O(1)).*/

//Code example:
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, string> um;
    um[10] = "Ten";
    um[20] = "Twenty";

    for (auto &p : um) cout << p.first << " -> " << p.second << "\n";
}
