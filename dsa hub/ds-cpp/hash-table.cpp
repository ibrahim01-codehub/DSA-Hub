// ============================================
// HASH TABLE - stores data as key -> value pairs
// A hash function turns each key into a "shelf number" so lookups
// don't need to search shelf by shelf.
// ============================================
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {

    unordered_map<string, int> age;

    // ---- Insert - O(1) average ----
    age["Ali"] = 20;
    age["Ahmed"] = 22;
    age["Sara"] = 19;

    // ---- Search / access by key - O(1) average ----
    cout << "Ali's age: " << age["Ali"] << endl;

    // ---- Check if a key exists before using it ----
    if (age.find("Bilal") == age.end()) {
        cout << "Bilal is not in the table." << endl;
    }

    // ---- Update a value - O(1) average ----
    age["Ali"] = 21; // Ali just had a birthday

    // ---- Delete a key - O(1) average ----
    age.erase("Sara");

    // ---- Traverse all key-value pairs - O(n) ----
    cout << "All entries:" << endl;
    for (const auto& pair : age) {
        cout << "  " << pair.first << " -> " << pair.second << endl;
    }

    return 0;
}
