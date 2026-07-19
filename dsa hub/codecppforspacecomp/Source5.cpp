#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int matrix[5][5];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = i * j;
        }
    }

    return 0;
}
