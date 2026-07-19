#include <iostream>
using namespace std;

int binarySearchRec(int arr[], int low, int high, int target) {
    if (low > high) return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) return binarySearchRec(arr, mid + 1, high, target);
    else return binarySearchRec(arr, low, mid - 1, target);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    cout << binarySearchRec(arr, 0, 5, 7) << endl;
    return 0;
}
