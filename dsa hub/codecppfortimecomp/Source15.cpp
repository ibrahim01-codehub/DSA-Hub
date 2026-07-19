#include <iostream>
using namespace std;

void findDuplicates(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                cout << "Duplicate found: " << arr[i] << endl;
            }
        }
    }
}

int main() {
    int arr[] = {1, 3, 5, 3, 7, 1};
    findDuplicates(arr, 6);
    return 0;
}
