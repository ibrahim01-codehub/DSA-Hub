#include <iostream>
using namespace std;

int countOccurrences(int arr[], int n, int target) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            count++;
        }
    }

    return count;
}

int main() {
    int arr[] = {2, 4, 2, 5, 2, 8};
    cout << "Occurrences of 2: " << countOccurrences(arr, 6, 2) << endl;
    return 0;
}
