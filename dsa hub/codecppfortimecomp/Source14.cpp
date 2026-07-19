#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        swap(arr[i], arr[minIdx]);
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 6};
    selectionSort(arr, 5);

    for (int x : arr) cout << x << " ";
    return 0;
}
