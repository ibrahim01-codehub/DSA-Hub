// ============================================
// ARRAY - a row of boxes, each with a number (index)
// ============================================
#include <iostream>
#include <vector>
using namespace std;

int main() {

    // A fixed-size array: the size (5) can never change once created.
    int fixedArr[5] = {10, 20, 30, 40, 50};

    // A dynamic array (vector): it can grow or shrink while the
    // program is running. This is what most C++ programmers use.
    vector<int> arr = {10, 20, 30, 40, 50};

    // ---- Access by index: O(1) ----
    // Jumping straight to a locker number - no searching needed.
    cout << "Element at index 2: " << arr[2] << endl;

    // ---- Traverse (visit every element): O(n) ----
    cout << "All elements: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // ---- Insert at the end: O(1) ----
    // Adding a new box at the end of the row is fast.
    arr.push_back(60);

    // ---- Insert at the start: O(n) ----
    // Everything else has to shift over by one to make room.
    arr.insert(arr.begin(), 0);

    // ---- Delete an element: O(n) ----
    // Removing one box means shifting the rest to close the gap.
    arr.erase(arr.begin() + 3);

    cout << "After insert/delete: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
