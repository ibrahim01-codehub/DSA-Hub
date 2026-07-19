// ============================================
// STACK - Last In, First Out (LIFO)
// Think of a stack of plates: you only add/remove from the top.
// ============================================
#include <iostream>
#include <stack>
using namespace std;

int main() {

    stack<int> plates;

    // ---- Push: add to the top - O(1) ----
    plates.push(10);
    plates.push(20);
    plates.push(30);

    // ---- Peek: look at the top without removing it - O(1) ----
    cout << "Top plate: " << plates.top() << endl; // 30

    // ---- Pop: remove the top item - O(1) ----
    plates.pop(); // removes 30
    cout << "Top after pop: " << plates.top() << endl; // 20

    // ---- Check if empty ----
    cout << "Is the stack empty? " << (plates.empty() ? "Yes" : "No") << endl;

    // ---- Print everything by popping one by one ----
    cout << "Remaining plates (top to bottom): ";
    while (!plates.empty()) {
        cout << plates.top() << " ";
        plates.pop();
    }
    cout << endl;

    return 0;
}
