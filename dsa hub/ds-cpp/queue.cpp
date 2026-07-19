// ============================================
// QUEUE - First In, First Out (FIFO)
// Think of a line at a coffee shop: first person in line is served first.
// ============================================
#include <iostream>
#include <queue>
using namespace std;

int main() {

    queue<int> line;

    // ---- Enqueue: join the back of the line - O(1) ----
    line.push(10);
    line.push(20);
    line.push(30);

    // ---- Peek at the front (who's next) - O(1) ----
    cout << "Front of line: " << line.front() << endl; // 10

    // ---- Dequeue: serve the person at the front - O(1) ----
    line.pop(); // removes 10
    cout << "Front after dequeue: " << line.front() << endl; // 20

    // ---- Check if empty ----
    cout << "Is the line empty? " << (line.empty() ? "Yes" : "No") << endl;

    // ---- Serve everyone in order ----
    cout << "Serving order: ";
    while (!line.empty()) {
        cout << line.front() << " ";
        line.pop();
    }
    cout << endl;

    return 0;
}
