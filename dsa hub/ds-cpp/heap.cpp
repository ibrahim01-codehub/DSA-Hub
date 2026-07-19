// ============================================
// HEAP - a tree where the "most important" item is always on top
// Max Heap: biggest value on top. Min Heap: smallest value on top.
// Think of a company org chart: the CEO (highest authority) is
// always at the top and easy to find.
// ============================================
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {

    // ---- Max Heap: biggest value always on top ----
    priority_queue<int> maxHeap;

    maxHeap.push(10);
    maxHeap.push(40);
    maxHeap.push(20);

    cout << "Max Heap top (biggest): " << maxHeap.top() << endl; // 40
    maxHeap.pop(); // removes 40 - O(log n)

    cout << "Max Heap after pop, new top: " << maxHeap.top() << endl; // 20

    // ---- Min Heap: smallest value always on top ----
    // We flip the comparison using greater<int>.
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(10);
    minHeap.push(40);
    minHeap.push(20);

    cout << "Min Heap top (smallest): " << minHeap.top() << endl; // 10
    minHeap.pop(); // removes 10 - O(log n)

    cout << "Min Heap after pop, new top: " << minHeap.top() << endl; // 20

    return 0;
}
