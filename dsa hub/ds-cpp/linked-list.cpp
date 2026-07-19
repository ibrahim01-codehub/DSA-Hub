// ============================================
// LINKED LIST - a chain of nodes
// Each node holds a value and a pointer/arrow to the next node.
// Think of a treasure hunt: each clue tells you where the next one is.
// ============================================
#include <iostream>
using namespace std;

// A single link in the chain.
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head; // points to the first node in the chain

public:
    LinkedList() : head(nullptr) {}

    // ---- Insert at the head (front) - O(1) ----
    // Fast because we just point the new node at the old first node.
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // ---- Insert at the tail (end) - O(n) ----
    // We have to walk the whole chain to find the last node.
    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // ---- Delete the first node matching a value - O(n) ----
    void deleteValue(int value) {
        if (!head) return;

        if (head->data == value) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Node* toDelete = current->next;
            current->next = toDelete->next;
            delete toDelete;
        }
    }

    // ---- Search for a value - O(n) ----
    bool search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) return true;
            current = current->next;
        }
        return false;
    }

    // ---- Print the whole chain - O(n) ----
    void print() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    // Free every node so we don't leak memory.
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LinkedList list;

    list.insertAtHead(20);
    list.insertAtHead(10);
    list.insertAtTail(30);

    cout << "List: ";
    list.print(); // 10 -> 20 -> 30 -> nullptr

    cout << "Contains 20? " << (list.search(20) ? "Yes" : "No") << endl;

    list.deleteValue(20);
    cout << "After deleting 20: ";
    list.print(); // 10 -> 30 -> nullptr

    return 0;
}
