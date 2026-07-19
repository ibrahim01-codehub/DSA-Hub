#include <iostream>
using namespace std;

int findMax(int arr[], int n) {
    int maxVal = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    return maxVal;
}

int main() {
    int arr[] = {3, 7, 2, 9, 4};
    cout << "Maximum: " << findMax(arr, 5) << endl;
    return 0;
}
