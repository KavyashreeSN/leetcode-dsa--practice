/*Priority Queue

By default a max heap.*/

//Code example:

#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;
    pq.push(30);
    pq.push(10);
    pq.push(50);

    cout << "Top element: " << pq.top() << "\n"; // 50
}
