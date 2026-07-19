// ============================================
// STRING - a sequence of characters
// Think of a word written on a strip of paper, one letter per box.
// ============================================
#include <iostream>
#include <string>
using namespace std;

int main() {

    string name = "Hello";

    // ---- Access a character by index - O(1) ----
    cout << "First character: " << name[0] << endl;

    // ---- Traverse every character - O(n) ----
    cout << "Letters: ";
    for (char ch : name) {
        cout << ch << " ";
    }
    cout << endl;

    // ---- Concatenation (joining strings) - O(n) ----
    string greeting = name + ", World!";
    cout << "Concatenated: " << greeting << endl;

    // ---- Substring - O(k), where k is the length of the piece ----
    string firstThree = greeting.substr(0, 3);
    cout << "Substring (first 3 chars): " << firstThree << endl;

    // ---- Search for a character or word - O(n) ----
    size_t pos = greeting.find("World");
    if (pos != string::npos) {
        cout << "'World' found at position: " << pos << endl;
    }

    // ---- Insertion / deletion - O(n), because characters shift ----
    greeting.insert(0, ">> ");
    greeting.erase(greeting.length() - 1, 1); // remove last char '!'
    cout << "After insert/delete: " << greeting << endl;

    return 0;
}
