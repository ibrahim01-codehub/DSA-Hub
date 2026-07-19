#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {6, 1, 9, 3, 7};
    cout << "Index: " << linearSearch(arr, 5, 3) << endl;
    return 0;
}
