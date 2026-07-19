#include <iostream>
using namespace std;

int main() {
    int n = 10;
    int arr[100];

    for (int i = 0; i < n; i++) {
        arr[i] = i * i;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
