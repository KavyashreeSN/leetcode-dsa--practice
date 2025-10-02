/*Stack

LIFO (Last In, First Out).*/
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;
    st.push(10);
    st.push(20);

    cout << "Top element: " << st.top() << "\n";
    st.pop();
    cout << "Top after pop: " << st.top() << "\n";
}
