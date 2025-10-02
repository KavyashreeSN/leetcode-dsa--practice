/*deque (Double Ended Queue)
Use case: Sliding window / double-ended operations (like processing tasks from both ends).*/

#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    // Push at both ends
    dq.push_back(10);   // [10]
    dq.push_front(5);   // [5, 10]
    dq.push_back(15);   // [5, 10, 15]

    // Pop from both ends
    dq.pop_front();     // [10, 15]
    dq.pop_back();      // [10]

    // Add again
    dq.push_front(1);   // [1, 10]
    dq.push_back(20);   // [1, 10, 20]

    cout << "Deque elements: ";
    for (int x : dq) cout << x << " ";
    cout << "\n";

    cout << "Front: " << dq.front() << ", Back: " << dq.back() << "\n";
}


