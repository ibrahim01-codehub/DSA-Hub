// ============================================
// DEQUE - Double-Ended Queue
// Like a train where passengers can board or leave from EITHER end.
// ============================================
#include <iostream>
#include <deque>
using namespace std;

int main() {

    deque<int> dq;

    // ---- Insert at the front and back - both O(1) ----
    dq.push_back(20);   // dq: [20]
    dq.push_front(10);  // dq: [10, 20]
    dq.push_back(30);   // dq: [10, 20, 30]
    dq.push_front(5);   // dq: [5, 10, 20, 30]

    // ---- Peek at both ends - O(1) ----
    cout << "Front: " << dq.front() << endl; // 5
    cout << "Back: " << dq.back() << endl;   // 30

    // ---- Remove from both ends - both O(1) ----
    dq.pop_front(); // removes 5
    dq.pop_back();  // removes 30

    cout << "After popping both ends: ";
    for (int x : dq) cout << x << " ";
    cout << endl; // 10 20

    return 0;
}
