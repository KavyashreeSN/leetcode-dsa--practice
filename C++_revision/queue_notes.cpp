/*Queue

FIFO (First In, First Out).*/

#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front: " << q.front() << ", Back: " << q.back() << "\n";
}
